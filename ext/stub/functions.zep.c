
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(Stub_Functions)
{
	ZEPHIR_REGISTER_CLASS(Stub, Functions, stub, functions, stub_functions_method_entry, 0);

	return SUCCESS;
}

/**
 * @issue https://github.com/zephir-lang/zephir/issues/658
 */
PHP_METHOD(Stub_Functions, filterVar1)
{
	zval ret, _0, _1, _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&ret);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);


	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&ret);
	ZVAL_STRING(&ret, "0");
	ZVAL_LONG(&_0, 259);
	ZVAL_LONG(&_1, 20480);
	ZEPHIR_CALL_FUNCTION(&_2, "filter_var", NULL, 44, &ret, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_FALSE_IDENTICAL(&_2));
}

/**
 * @issue https://github.com/zephir-lang/zephir/issues/658
 */
PHP_METHOD(Stub_Functions, filterVar2)
{
	zval ret, _0, _1, _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&ret);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);


	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&ret);
	ZVAL_STRING(&ret, "0");
	ZVAL_LONG(&_0, 259);
	ZVAL_LONG(&_1, 20480);
	ZEPHIR_CALL_FUNCTION(&_2, "filter_var", NULL, 44, &ret, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_FALSE(&_2));
}

PHP_METHOD(Stub_Functions, passByVariableReference)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *i, i_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&i_sub);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL_EX(i, 0, 1)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &i);
	ZVAL_DEREF(i);
	SEPARATE_ZVAL_NOREF(i);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_LONG(&_0, 10);
	ZEPHIR_ADD_ASSIGN(i, &_0);
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Stub_Functions, passByTypedReference)
{
	zval *i_param = NULL;
	zend_long i;
	zval *this_ptr = getThis();

#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG_EX(i, _dummy, 0, 1)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &i_param);
	i = zephir_get_intval(i_param);


	i += 10;
}

