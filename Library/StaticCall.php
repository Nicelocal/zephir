<?php

/**
 * This file is part of the Zephir.
 *
 * (c) Phalcon Team <team@zephir-lang.com>
 *
 * For the full copyright and license information, please view
 * the LICENSE file that was distributed with this source code.
 */

namespace Zephir;

use ReflectionException;
use Zephir\Detectors\ReadDetector;
use Zephir\Exception\CompilerException;

use function count;
use function in_array;
use function is_string;

/**
 * StaticCall.
 *
 * Call methods in a static context
 */
class StaticCall extends Call
{
    /**
     * Compiles a static method call.
     *
     * @param Expression         $expr
     * @param CompilationContext $compilationContext
     *
     * @return CompiledExpression
     *
     * @throws ReflectionException
     */
    public function compile(Expression $expr, CompilationContext $compilationContext): CompiledExpression
    {
        $expression = $expr->getExpression();

        $methodName = strtolower($expression['name']);
        $dynamicMethod = $expression['dynamic'] ?? false;

        $symbolVariable = null;

        /**
         * Create temporary variable if needed.
         */
        $mustInit = false;
        $isExpecting = $expr->isExpectingReturn();
        if ($isExpecting) {
            $symbolVariable = $expr->getExpectingVariable();
            if (\is_object($symbolVariable)) {
                $readDetector = new ReadDetector($expression);
                if ($readDetector->detect($symbolVariable->getName(), $expression)) {
                    $symbolVariable = $compilationContext->symbolTable->getTempVariableForObserveOrNullify('variable', $compilationContext, $expression);
                } else {
                    $mustInit = true;
                }
            } else {
                $symbolVariable = $compilationContext->symbolTable->getTempVariableForObserveOrNullify('variable', $compilationContext, $expression);
            }
        }

        /**
         * Method calls only return zvals so we need to validate the target variable is also a zval
         */
        if ($isExpecting) {
            /**
             * At this point, we don't know the exact dynamic type returned by the static method call
             */
            $symbolVariable->setDynamicTypes('undefined');

            if (!$symbolVariable->isVariable()) {
                throw new CompilerException('Returned values by functions can only be assigned to variant variables', $expression);
            }
        }

        /**
         * Include fcall header
         */
        $compilationContext->headersManager->add('kernel/fcall');

        $compiler = $compilationContext->compiler;

        $dynamicClass = $expression['dynamic-class'];
        if (!$dynamicClass) {
            $className = $expression['class'];
            $classDefinition = false;

            if (!in_array($className, ['self', 'static', 'parent'])) {
                if (is_string($className)) {
                    $className = $compilationContext->getFullName($className);
                    if ($compiler->isClass($className)) {
                        $classDefinition = $compiler->getClassDefinition($className);
                    } else {
                        if ($compiler->isBundledClass($className)) {
                            $classDefinition = $compiler->getInternalClassDefinition($className);
                        } else {
                            throw new CompilerException('Class name: '.$className.' does not exist', $expression);
                        }
                    }
                } else {
                    foreach ($className as $singleClass) {
                        $className = $compilationContext->getFullName($singleClass);
                        if ($compiler->isClass($singleClass)) {
                            $classDefinition = $compiler->getClassDefinition($singleClass);
                        } else {
                            throw new CompilerException('Class name: '.$className.' does not exist', $expression);
                        }
                    }
                }
            } else {
                $classDefinition = $compilationContext->classDefinition;

                if ('parent' === $className) {
                    $extendsClass = $classDefinition->getExtendsClass();
                    if (!$extendsClass) {
                        throw new CompilerException('Cannot call method "'.$methodName.'" on parent because class '.$classDefinition->getCompleteName().' does not extend any class', $expression);
                    }
                    $currentClassDefinition = $classDefinition;
                    $classDefinition = $classDefinition->getExtendsClassDefinition();
                }
            }
        }

        /**
         * Check if the class implements the method
         */
        if (!$dynamicMethod && !$dynamicClass) {
            // TODO: Consider to check instance of ClassDefinitionRuntime and throw another error, telling that class was not found.
            // TODO: This will give false if external class does not exists!
            if (!$classDefinition->hasMethod($methodName)) {
                $possibleMethod = $classDefinition->getPossibleMethodName($methodName);
                if ($possibleMethod) {
                    throw new CompilerException("Class '".$classDefinition->getCompleteName()."' does not implement static method: '".$expression['name']."'. Did you mean '".$possibleMethod."'?", $expression);
                } else {
                    throw new CompilerException("Class '".$classDefinition->getCompleteName()."' does not implement static method: '".$expression['name']."'", $expression);
                }
            } else {
                $method = $classDefinition->getMethod($methodName);

                if ($method->isPrivate() && $method->getClassDefinition() !== $compilationContext->classDefinition) {
                    throw new CompilerException("Cannot call private method '".$methodName."' out of its scope", $expression);
                }

                if (!in_array($className, ['self', 'static', 'parent']) && !$method->isStatic()) {
                    throw new CompilerException("Cannot call non-static method '".$methodName."' in a static way", $expression);
                }

                if (!$classDefinition->hasMethod('__callStatic')) {
                    if ($method instanceof ClassMethod && !$method->isBundled()) {
                        /**
                         * Try to produce an exception if method is called with a wrong number of parameters
                         */
                        $callNumberParameters = isset($expression['parameters']) ? count($expression['parameters']) : 0;

                        $classMethod = $classDefinition->getMethod($methodName);
                        $expectedNumberParameters = $classMethod->getNumberOfRequiredParameters();

                        if (!$expectedNumberParameters && $callNumberParameters > 0) {
                            $numberParameters = $classMethod->getNumberOfParameters();
                            if ($callNumberParameters > $numberParameters) {
                                throw new CompilerException("Method '".$classDefinition->getCompleteName().'::'.$expression['name']."' called with a wrong number of parameters, the method has: ".$expectedNumberParameters.', passed: '.$callNumberParameters, $expression);
                            }
                        }

                        if ($callNumberParameters < $expectedNumberParameters) {
                            //throw new CompilerException("Method '".$classDefinition->getCompleteName().'::'.$expression['name']."' called with a wrong number of parameters, the method has: ".$expectedNumberParameters.', passed: '.$callNumberParameters, $expression);
                        }
                    }
                } else {
                    if (!isset($method)) {
                        $method = $classDefinition->getMethod('__callStatic');
                        if ($method->isPrivate() && $method->getClassDefinition() !== $compilationContext->classDefinition) {
                            throw new CompilerException("Cannot call private magic method '__call' out of its scope", $expression);
                        }
                    }
                }
            }
        }

        /**
         * Call static methods in the same class, use the special context 'self' or special context 'static'
         * Call static methods in the 'self' context
         */
        if (!$dynamicMethod) {
            if ($dynamicClass) {
                $this->callFromDynamicClass($methodName, $expression, $symbolVariable, $mustInit, $isExpecting, $compilationContext);
            } else {
                if (in_array($className, ['self', 'static']) || $classDefinition == $compilationContext->classDefinition) {
                    $this->call(strtoupper($className), $methodName, $expression, $mustInit, $isExpecting, $compilationContext, $symbolVariable, $method ?? null);
                } else {
                    if ('parent' == $className) {
                        $this->callParent($methodName, $expression, $symbolVariable, $mustInit, $isExpecting, $currentClassDefinition, $compilationContext, $method ?? null);
                    } else {
                        $this->callFromClass($methodName, $expression, $symbolVariable, $mustInit, $isExpecting, $classDefinition, $compilationContext, $method ?? null);
                    }
                }
            }
        } else {
            if ($dynamicClass) {
                $this->callFromDynamicClassDynamicMethod($expression, $symbolVariable, $mustInit, $isExpecting, $compilationContext);
            }
        }

        /**
         * Add the last call status to the current symbol table
         */
        $this->addCallStatusFlag($compilationContext);

        /**
         * Transfer the return type-hint to the returned variable
         */
        if ($isExpecting && isset($method) && $method instanceof ClassMethod) {
            $symbolVariable->setDynamicTypes('object');
            foreach ($method->getReturnClassTypes() as $classType) {
                $symbolVariable->setClassTypes($compilationContext->getFullName($classType));
            }

            foreach ($method->getReturnTypes() as $dataType => $returnType) {
                $symbolVariable->setDynamicTypes($dataType);
            }
        }

        /**
         * We can mark temporary variables generated as idle here
         */
        foreach ($this->getTemporalVariables() as $tempVariable) {
            $tempVariable->setIdle(true);
        }

        if ($isExpecting) {
            return new CompiledExpression('variable', $symbolVariable->getRealName(), $expression);
        }

        return new CompiledExpression('null', null, $expression);
    }

    /**
     * Calls static methods on the 'self/static' context.
     *
     * @param string             $context            SELF / STATIC
     * @param string             $methodName
     * @param array              $expression
     * @param Variable|null      $symbolVariable
     * @param bool               $mustInit
     * @param bool               $isExpecting
     * @param CompilationContext $compilationContext
     * @param ClassMethod|null   $method
     */
    protected function call(
        string $context,
        string $methodName,
        array $expression,
        bool $mustInit,
        bool $isExpecting,
        CompilationContext $compilationContext,
        ?Variable $symbolVariable = null,
        ?ClassMethod $method = null
    ) {
        if (!in_array($context, ['SELF', 'STATIC'])) {
            $context = 'SELF';
        }

        /**
         * Do not optimize static:: calls, to allow late static binding
         */
        if ('SELF' === $context) {
            $method = $method->getOptimizedMethod();
        }

        $codePrinter = $compilationContext->codePrinter;

        /**
         * Call static methods must grown the stack
         */
        $compilationContext->symbolTable->mustGrownStack(true);

        if ($mustInit) {
            $symbolVariable->setMustInitNull(true);
            $symbolVariable->trackVariant($compilationContext);
        }

        /**
         * Check if the  method call can have an inline cache.
         */
        $methodCache = $compilationContext->cacheManager->getStaticMethodCache();
        $cachePointer = $methodCache->get($compilationContext, $method ?? null, false);

        $params = [];
        if (isset($expression['parameters']) && count($expression['parameters'])) {
            $params = $this->getResolvedParams($expression['parameters'], $compilationContext, $expression);
        }

        $isInternal = false;
        if (isset($method)) {
            $isInternal = $method->isInternal();
        }

        if ($symbolVariable) {
            $symbol = $compilationContext->backend->getVariableCodePointer($symbolVariable);
        }

        $paramCount = count($params);
        $paramsStr = $paramCount ? ', '.implode(', ', $params) : '';
        if (!$isInternal) {
            if ($isExpecting) {
                if ('return_value' == $symbolVariable->getName()) {
                    $codePrinter->output('ZEPHIR_RETURN_CALL_'.$context.'("'.$methodName.'", '.$cachePointer.$paramsStr.');');
                } else {
                    $codePrinter->output('ZEPHIR_CALL_'.$context.'('.$symbol.', "'.$methodName.'", '.$cachePointer.$paramsStr.');');
                }
            } else {
                $codePrinter->output('ZEPHIR_CALL_'.$context.'(NULL, "'.$methodName.'", '.$cachePointer.$paramsStr.');');
            }
        } else {
            $ce = $method->getClassDefinition()->getClassEntry($compilationContext);
            if ($isExpecting) {
                if ('return_value' == $symbolVariable->getName()) {
                    $macro = $compilationContext->backend->getFcallManager()->getMacro(true, true, $paramCount);
                    $codePrinter->output($macro.'('.$ce.', '.$method->getInternalName().$paramsStr.');');
                } else {
                    $macro = $compilationContext->backend->getFcallManager()->getMacro(true, 2, $paramCount);
                    $codePrinter->output($macro.'('.$symbol.', '.$ce.', '.$method->getInternalName().$paramsStr.');');
                }
            } else {
                $macro = $compilationContext->backend->getFcallManager()->getMacro(true, false, $paramCount);
                $codePrinter->output($macro.'('.$ce.', '.$method->getInternalName().$paramsStr.');');
            }
        }

        // Temporary variables must be copied back to avoid issues with references
        foreach ($this->mustCopyBack as $stmt) {
            $codePrinter->output($stmt);
        }

        $this->addCallStatusOrJump($compilationContext);
    }

    /**
     * Calls static methods on the 'parent' context.
     *
     * @param string             $methodName
     * @param array              $expression
     * @param Variable           $symbolVariable
     * @param bool               $mustInit
     * @param bool               $isExpecting
     * @param ClassDefinition    $classDefinition
     * @param CompilationContext $compilationContext
     * @param ClassMethod        $method
     */
    protected function callParent($methodName, array $expression, $symbolVariable, $mustInit, $isExpecting, ClassDefinition $classDefinition, CompilationContext $compilationContext, ClassMethod $method)
    {
        $codePrinter = $compilationContext->codePrinter;
        $classCe = $classDefinition->getClassEntry($compilationContext);

        /**
         * Call static methods must grown the stack
         */
        $compilationContext->symbolTable->mustGrownStack(true);

        if ($mustInit) {
            $symbolVariable->setMustInitNull(true);
            $symbolVariable->trackVariant($compilationContext);
        }

        /**
         * Check if the  method call can have an inline cache.
         */
        $methodCache = $compilationContext->cacheManager->getStaticMethodCache();
        $cachePointer = $methodCache->get($compilationContext, isset($method) ? $method : null);

        $params = [];
        if (isset($expression['parameters']) && count($expression['parameters'])) {
            $params = $this->getResolvedParams($expression['parameters'], $compilationContext, $expression);
        }

        if (!count($params)) {
            if ($isExpecting) {
                if ('return_value' == $symbolVariable->getName()) {
                    $codePrinter->output('ZEPHIR_RETURN_CALL_PARENT('.$classCe.', getThis(), "'.$methodName.'", '.$cachePointer.');');
                } else {
                    $codePrinter->output('ZEPHIR_CALL_PARENT(&'.$symbolVariable->getName().', '.$classCe.', getThis(), "'.$methodName.'", '.$cachePointer.');');
                }
            } else {
                $codePrinter->output('ZEPHIR_CALL_PARENT(NULL, '.$classCe.', getThis(), "'.$methodName.'", '.$cachePointer.');');
            }
        } else {
            if ($isExpecting) {
                if ('return_value' == $symbolVariable->getName()) {
                    $codePrinter->output('ZEPHIR_RETURN_CALL_PARENT('.$classCe.', getThis(), "'.$methodName.'", '.$cachePointer.', '.implode(', ', $params).');');
                } else {
                    $codePrinter->output('ZEPHIR_CALL_PARENT(&'.$symbolVariable->getName().', '.$classCe.', getThis(), "'.$methodName.'", '.$cachePointer.', '.implode(', ', $params).');');
                }
            } else {
                $codePrinter->output('ZEPHIR_CALL_PARENT(NULL, '.$classCe.', getThis(), "'.$methodName.'", '.$cachePointer.', '.implode(', ', $params).');');
            }
        }

        // Temporary variables must be copied back to avoid issues with references
        foreach ($this->mustCopyBack as $stmt) {
            $codePrinter->output($stmt);
        }

        $this->addCallStatusOrJump($compilationContext);
    }

    /**
     * Calls static methods on the some class context.
     *
     * @param string             $methodName
     * @param array              $expression
     * @param Variable           $symbolVariable
     * @param bool               $mustInit
     * @param bool               $isExpecting
     * @param ClassDefinition    $classDefinition
     * @param CompilationContext $compilationContext
     * @param ClassMethod        $method
     */
    protected function callFromClass($methodName, array $expression, $symbolVariable, $mustInit, $isExpecting, ClassDefinition $classDefinition, CompilationContext $compilationContext, ClassMethod $method)
    {
        $codePrinter = $compilationContext->codePrinter;

        if ($classDefinition->isBundled()) {
            $classEntryVariable = $compilationContext->symbolTable->addTemp('zend_class_entry', $compilationContext);
            $compilationContext->backend->fetchClass($classEntryVariable, 'SL("'.str_replace('\\', '\\\\', $classDefinition->getName()).'")', false, $compilationContext);
            $classEntry = $classEntryVariable->getName();
        } else {
            $classEntry = $classDefinition->getClassEntry($compilationContext);
        }

        /**
         * Call static methods must grown the stack
         */
        $compilationContext->symbolTable->mustGrownStack(true);

        if ($mustInit) {
            $symbolVariable->setMustInitNull(true);
            $symbolVariable->trackVariant($compilationContext);
        }

        if ($method) {
            $method = $method->getOptimizedMethod();
        }

        /**
         * Check if the  method call can have an inline cache.
         */
        $methodCache = $compilationContext->cacheManager->getStaticMethodCache();
        $cachePointer = $methodCache->get($compilationContext, isset($method) ? $method : null);

        $params = [];
        if (isset($expression['parameters']) && count($expression['parameters'])) {
            $params = $this->getResolvedParams($expression['parameters'], $compilationContext, $expression);
        }

        if ($symbolVariable) {
            $symbol = $compilationContext->backend->getVariableCodePointer($symbolVariable);
        }

        $paramCount = count($params);
        $paramsStr = $paramCount ? ', '.implode(', ', $params) : '';

        if ($method->isInternal()) {
            $ce = $classDefinition->getClassEntry($compilationContext);
            if ($isExpecting) {
                if ('return_value' == $symbolVariable->getName()) {
                    $macro = $compilationContext->backend->getFcallManager()->getMacro(true, true, $paramCount);
                    $codePrinter->output($macro.'('.$ce.', '.$method->getInternalName().$paramsStr.');');
                } else {
                    $macro = $compilationContext->backend->getFcallManager()->getMacro(true, 2, $paramCount);
                    $codePrinter->output($macro.'('.$symbol.', '.$ce.', '.$method->getInternalName().$paramsStr.');');
                }
            } else {
                $macro = $compilationContext->backend->getFcallManager()->getMacro(true, false, $paramCount);
                $codePrinter->output($macro.'('.$ce.', '.$method->getInternalName().$paramsStr.');');
            }
        } else {
            if ($isExpecting) {
                if ('return_value' == $symbolVariable->getName()) {
                    $codePrinter->output('ZEPHIR_RETURN_CALL_CE_STATIC('.$classEntry.', "'.$methodName.'", '.$cachePointer.$paramsStr.');');
                } else {
                    $codePrinter->output('ZEPHIR_CALL_CE_STATIC('.$symbol.', '.$classEntry.', "'.$methodName.'", '.$cachePointer.$paramsStr.');');
                }
            } else {
                $codePrinter->output('ZEPHIR_CALL_CE_STATIC(NULL, '.$classEntry.', "'.$methodName.'", '.$cachePointer.$paramsStr.');');
            }
        }

        // Temporary variables must be copied back to avoid issues with references
        foreach ($this->mustCopyBack as $stmt) {
            $codePrinter->output($stmt);
        }

        $this->addCallStatusOrJump($compilationContext);
    }

    /**
     * Calls static methods on using a dynamic variable as class.
     *
     * @param string             $methodName
     * @param array              $expression
     * @param Variable           $symbolVariable
     * @param bool               $mustInit
     * @param bool               $isExpecting
     * @param CompilationContext $compilationContext
     */
    protected function callFromDynamicClass($methodName, array $expression, $symbolVariable, $mustInit, $isExpecting, CompilationContext $compilationContext)
    {
        $codePrinter = $compilationContext->codePrinter;

        /**
         * Call static methods must grown the stack
         */
        $compilationContext->symbolTable->mustGrownStack(true);

        if ($mustInit) {
            $symbolVariable->setMustInitNull(true);
            $symbolVariable->trackVariant($compilationContext);
        }

        $cachePointer = 'NULL, 0';

        $params = [];
        if (isset($expression['parameters']) && count($expression['parameters'])) {
            $params = $this->getResolvedParams($expression['parameters'], $compilationContext, $expression);
        }

        /**
         * Obtain the class entry from the variable.
         */
        $classNameVariable = $compilationContext->symbolTable->getVariableForRead($expression['class'], $compilationContext, $expression);
        if ($classNameVariable->isNotVariableAndString()) {
            throw new CompilerException('Only dynamic/string variables can be used in dynamic classes', $expression);
        }

        $compilationContext->headersManager->add('kernel/object');

        $classEntryVariable = $compilationContext->symbolTable->addTemp('zend_class_entry', $compilationContext);
        $codePrinter->output(
            sprintf(
                '%s = zephir_fetch_class(%s);',
                $classEntryVariable->getName(),
                $compilationContext->backend->getVariableCode($classNameVariable)
            )
        );
        $classEntry = $classEntryVariable->getName();

        if ($symbolVariable) {
            $symbol = $compilationContext->backend->getVariableCodePointer($symbolVariable);
        }

        if (!count($params)) {
            if ($isExpecting) {
                if ('return_value' == $symbolVariable->getName()) {
                    $codePrinter->output('ZEPHIR_RETURN_CALL_CE_STATIC('.$classEntry.', "'.$methodName.'", '.$cachePointer.');');
                } else {
                    $codePrinter->output('ZEPHIR_CALL_CE_STATIC('.$symbol.', '.$classEntry.', "'.$methodName.'", '.$cachePointer.');');
                }
            } else {
                $codePrinter->output('ZEPHIR_CALL_CE_STATIC(NULL, '.$classEntry.', "'.$methodName.'", '.$cachePointer.');');
            }
        } else {
            if ($isExpecting) {
                if ('return_value' == $symbolVariable->getName()) {
                    $codePrinter->output('ZEPHIR_RETURN_CALL_CE_STATIC('.$classEntry.', "'.$methodName.'", '.$cachePointer.', '.implode(', ', $params).');');
                } else {
                    $codePrinter->output('ZEPHIR_CALL_CE_STATIC('.$symbol.', '.$classEntry.', "'.$methodName.'", '.$cachePointer.', '.implode(', ', $params).');');
                }
            } else {
                $codePrinter->output('ZEPHIR_CALL_CE_STATIC(NULL, '.$classEntry.', "'.$methodName.'", '.$cachePointer.', '.implode(', ', $params).');');
            }
        }

        // Temporary variables must be copied back to avoid issues with references
        foreach ($this->mustCopyBack as $stmt) {
            $codePrinter->output($stmt);
        }

        $this->addCallStatusOrJump($compilationContext);
    }

    /**
     * Calls static methods on using a dynamic variable as class and a dynamic method.
     *
     * @param array              $expression
     * @param Variable           $symbolVariable
     * @param bool               $mustInit
     * @param bool               $isExpecting
     * @param CompilationContext $compilationContext
     */
    protected function callFromDynamicClassDynamicMethod(array $expression, $symbolVariable, $mustInit, $isExpecting, CompilationContext $compilationContext)
    {
        $codePrinter = $compilationContext->codePrinter;

        /**
         * Call static methods must grown the stack
         */
        $compilationContext->symbolTable->mustGrownStack(true);

        if ($mustInit) {
            $symbolVariable->setMustInitNull(true);
            $symbolVariable->trackVariant($compilationContext);
        }

        $cachePointer = 'NULL, 0';

        $params = [];
        if (isset($expression['parameters']) && count($expression['parameters'])) {
            $params = $this->getResolvedParams($expression['parameters'], $compilationContext, $expression);
        }

        /**
         * Obtain the class entry from the variable.
         */
        $classNameVariable = $compilationContext->symbolTable->getVariableForRead($expression['class'], $compilationContext, $expression);
        if ($classNameVariable->isNotVariableAndString()) {
            throw new CompilerException('Only dynamic/string variables can be used in dynamic classes', $expression);
        }

        $compilationContext->headersManager->add('kernel/object');

        $classEntryVariable = $compilationContext->symbolTable->addTemp('zend_class_entry', $compilationContext);

        $codePrinter->output(
            sprintf(
                '%s = zephir_fetch_class(%s);',
                $classEntryVariable->getName(),
                $compilationContext->backend->getVariableCode($classNameVariable)
            )
        );

        $classEntry = $classEntryVariable->getName();

        /**
         * Obtain the method name from the variable.
         */
        $methodNameVariable = $compilationContext->symbolTable->getVariableForRead($expression['name'], $compilationContext, $expression);
        if ($methodNameVariable->isNotVariableAndString()) {
            throw new CompilerException('Only dynamic/string variables can be used in dynamic methods', $expression);
        }

        if ($symbolVariable) {
            $symbol = $compilationContext->backend->getVariableCodePointer($symbolVariable);
        }

        if (!count($params)) {
            if ($isExpecting) {
                if ('return_value' === $symbolVariable->getName()) {
                    $codePrinter->output('ZEPHIR_RETURN_CALL_CE_STATIC_ZVAL('.$classEntry.', '.$methodNameVariable->getName().', '.$cachePointer.');');
                } else {
                    $codePrinter->output('ZEPHIR_CALL_CE_STATIC_ZVAL('.$symbol.', '.$classEntry.', '.$methodNameVariable->getName().', '.$cachePointer.');');
                }
            } else {
                $codePrinter->output('ZEPHIR_CALL_CE_STATIC_ZVAL(NULL, '.$classEntry.', '.$methodNameVariable->getName().', '.$cachePointer.');');
            }
        } else {
            if ($isExpecting) {
                if ('return_value' === $symbolVariable->getName()) {
                    $codePrinter->output('ZEPHIR_RETURN_CALL_CE_STATIC_ZVAL('.$classEntry.', '.$methodNameVariable->getName().', '.$cachePointer.', '.implode(', ', $params).');');
                } else {
                    $codePrinter->output('ZEPHIR_CALL_CE_STATIC_ZVAL('.$symbol.', '.$classEntry.', '.$methodNameVariable->getName().', '.$cachePointer.', '.implode(', ', $params).');');
                }
            } else {
                $codePrinter->output('ZEPHIR_CALL_CE_STATIC_ZVAL(NULL, '.$classEntry.', '.$methodNameVariable->getName().', '.$cachePointer.', '.implode(', ', $params).');');
            }
        }

        // Temporary variables must be copied back to avoid issues with references
        foreach ($this->mustCopyBack as $stmt) {
            $codePrinter->output($stmt);
        }

        $this->addCallStatusOrJump($compilationContext);
    }
}
