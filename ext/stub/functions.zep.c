
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
#include "kernel/array.h"


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


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &i);
	ZEPHIR_SEPARATE_PARAM(i);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_LONG(&_0, 10);
	ZEPHIR_ADD_ASSIGN(i, &_0);
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Stub_Functions, passByVariableReferenceNested)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *i, i_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&i_sub);


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &i);


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "passbyvariablereference", NULL, 0, i);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Stub_Functions, passByVariableDefaultReference)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *i = NULL, i_sub, __$null, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&i_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &i);
	if (!i) {
		i = &i_sub;
		ZEPHIR_CPY_WRT(i, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(i);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_LONG(&_0, 10);
	ZEPHIR_ADD_ASSIGN(i, &_0);
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Stub_Functions, passByVariableArrayReference)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *i, i_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&i_sub);
	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &i);
	ZEPHIR_SEPARATE_PARAM(i);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_LONG(&_0, 20);
	zephir_array_update_long(i, 0, &_0, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Stub_Functions, passByTypedReference)
{
	zval *i_param = NULL;
	zend_long i;
	zval *this_ptr = getThis();



	zephir_fetch_params_without_memory_grow(1, 0, &i_param);
	i = zephir_get_intval(i_param);


	i += 10;
}

PHP_METHOD(Stub_Functions, passByTypedArrayReference)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *i_param = NULL, _0;
	zval i;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&i);
	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &i_param);
	zephir_get_arrval(&i, i_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_LONG(&_0, 10);
	zephir_array_update_long(&i, 0, &_0, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Stub_Functions, postInc)
{
	zend_long _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *number = NULL, number_sub, old;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&number_sub);
	ZVAL_UNDEF(&old);


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &number);
	ZEPHIR_SEPARATE_PARAM(number);


	ZEPHIR_CPY_WRT(&old, number);
	_0 = (zephir_get_numberval(number) + 1);
	ZEPHIR_INIT_NVAR(number);
	ZVAL_LONG(number, _0);
	RETURN_CCTOR(&old);
}

