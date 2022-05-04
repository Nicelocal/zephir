
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/concat.h"
#include "kernel/array.h"


/**
 * @issue https://github.com/zephir-lang/zephir/issues/2165
 */
ZEPHIR_INIT_CLASS(Stub_Issue2165_Issue)
{
	ZEPHIR_REGISTER_CLASS(Stub\\Issue2165, Issue, stub, issue2165_issue, stub_issue2165_issue_method_entry, 0);

	zend_declare_property_null(stub_issue2165_issue_ce, SL("m"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(stub_issue2165_issue_ce, SL("n"), ZEND_ACC_PROTECTED);
	zend_class_implements(stub_issue2165_issue_ce, 1, stub_issue2165_issueinterface_ce);
	return SUCCESS;
}

PHP_METHOD(Stub_Issue2165_Issue, build)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *a_param = NULL, _0;
	zval a;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&a);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(a)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &a_param);
	if (!a_param) {
		ZEPHIR_INIT_VAR(&a);
		array_init(&a);
	} else {
		zephir_get_arrval(&a, a_param);
	}


	object_init_ex(return_value, stub_issue2165_issue_ce);
	ZVAL_BOOL(&_0, 1);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 48, &a, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Stub_Issue2165_Issue, __construct)
{
	zend_string *_7$$3;
	zend_ulong _6$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL, *_11 = NULL, *_14 = NULL, *_20 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, m, n;
	zend_bool validate, _18$$6, _24$$8, _38$$12, _43$$14;
	zval *a_param = NULL, *validate_param = NULL, i, rowA, valueA, _0, _49, _1$$3, *_3$$3, _4$$3, _5$$3, _8$$5, _9$$5, _10$$5, _12$$5, _13$$5, *_15$$4, _16$$4, _17$$4, _29$$4, _19$$6, _21$$7, _22$$7, _23$$7, _25$$8, _26$$9, _27$$9, _28$$9, _30$$11, _31$$11, _32$$11, _33$$11, _34$$11, *_35$$10, _36$$10, _37$$10, _48$$10, _39$$12, _40$$13, _41$$13, _42$$13, _44$$14, _45$$15, _46$$15, _47$$15;
	zval a;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&a);
	ZVAL_UNDEF(&i);
	ZVAL_UNDEF(&rowA);
	ZVAL_UNDEF(&valueA);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_49);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_16$$4);
	ZVAL_UNDEF(&_17$$4);
	ZVAL_UNDEF(&_29$$4);
	ZVAL_UNDEF(&_19$$6);
	ZVAL_UNDEF(&_21$$7);
	ZVAL_UNDEF(&_22$$7);
	ZVAL_UNDEF(&_23$$7);
	ZVAL_UNDEF(&_25$$8);
	ZVAL_UNDEF(&_26$$9);
	ZVAL_UNDEF(&_27$$9);
	ZVAL_UNDEF(&_28$$9);
	ZVAL_UNDEF(&_30$$11);
	ZVAL_UNDEF(&_31$$11);
	ZVAL_UNDEF(&_32$$11);
	ZVAL_UNDEF(&_33$$11);
	ZVAL_UNDEF(&_34$$11);
	ZVAL_UNDEF(&_36$$10);
	ZVAL_UNDEF(&_37$$10);
	ZVAL_UNDEF(&_48$$10);
	ZVAL_UNDEF(&_39$$12);
	ZVAL_UNDEF(&_40$$13);
	ZVAL_UNDEF(&_41$$13);
	ZVAL_UNDEF(&_42$$13);
	ZVAL_UNDEF(&_44$$14);
	ZVAL_UNDEF(&_45$$15);
	ZVAL_UNDEF(&_46$$15);
	ZVAL_UNDEF(&_47$$15);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ARRAY(a)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(validate)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &a_param, &validate_param);
	zephir_get_arrval(&a, a_param);
	if (!validate_param) {
		validate = 1;
	} else {
		validate = zephir_get_boolval(validate_param);
	}


	m = zephir_fast_count_int(&a);
	ZEPHIR_CALL_FUNCTION(&_0, "current", NULL, 43, &a);
	zephir_check_call_status();
	n = zephir_fast_count_int(&_0);
	if (validate) {
		ZEPHIR_CALL_FUNCTION(&_1$$3, "array_values", &_2, 49, &a);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&a, &_1$$3);
		zephir_is_iterable(&a, 0, "stub/issue2165/issue.zep", 46);
		if (Z_TYPE_P(&a) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&a), _6$$3, _7$$3, _3$$3)
			{
				ZEPHIR_INIT_NVAR(&i);
				if (_7$$3 != NULL) { 
					ZVAL_STR_COPY(&i, _7$$3);
				} else {
					ZVAL_LONG(&i, _6$$3);
				}
				ZEPHIR_INIT_NVAR(&rowA);
				ZVAL_COPY(&rowA, _3$$3);
				if (UNEXPECTED(zephir_fast_count_int(&rowA) != n)) {
					ZEPHIR_INIT_NVAR(&_8$$5);
					object_init_ex(&_8$$5, spl_ce_InvalidArgumentException);
					ZVAL_LONG(&_9$$5, n);
					ZEPHIR_CALL_FUNCTION(&_10$$5, "strval", &_11, 50, &_9$$5);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_12$$5);
					ZVAL_LONG(&_12$$5, zephir_fast_count_int(&rowA));
					ZEPHIR_INIT_NVAR(&_13$$5);
					ZEPHIR_CONCAT_SSVSVSSVS(&_13$$5, "The number of columns", " must be equal for all rows, ", &_10$$5, " needed but ", &_12$$5, " given", " at row offset ", &i, ".");
					ZEPHIR_CALL_METHOD(NULL, &_8$$5, "__construct", &_14, 51, &_13$$5);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_8$$5, "stub/issue2165/issue.zep", 33);
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_is_iterable(&rowA, 0, "stub/issue2165/issue.zep", 44);
				if (Z_TYPE_P(&rowA) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&rowA), _15$$4)
					{
						ZEPHIR_INIT_NVAR(&valueA);
						ZVAL_COPY(&valueA, _15$$4);
						_18$$6 = !(Z_TYPE_P(&valueA) == IS_LONG);
						if (_18$$6) {
							ZEPHIR_CALL_FUNCTION(&_19$$6, "is_float", &_20, 52, &valueA);
							zephir_check_call_status();
							_18$$6 = !zephir_is_true(&_19$$6);
						}
						if (UNEXPECTED(_18$$6)) {
							ZEPHIR_INIT_NVAR(&_21$$7);
							object_init_ex(&_21$$7, spl_ce_InvalidArgumentException);
							ZEPHIR_INIT_NVAR(&_22$$7);
							zephir_gettype(&_22$$7, &valueA);
							ZEPHIR_INIT_NVAR(&_23$$7);
							ZEPHIR_CONCAT_SSVS(&_23$$7, "Matrix element must", " be an integer or floating point number, ", &_22$$7, " given.");
							ZEPHIR_CALL_METHOD(NULL, &_21$$7, "__construct", &_14, 51, &_23$$7);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_21$$7, "stub/issue2165/issue.zep", 40);
							ZEPHIR_MM_RESTORE();
							return;
						}
					} ZEND_HASH_FOREACH_END();
				} else {
					if (zephir_instance_of_ev(&rowA, (const zend_class_entry *)zend_ce_iterator)) {
						ZVAL_COPY(&_17$$4, &rowA);
					} else {
						ZEPHIR_CALL_METHOD(&_17$$4, &rowA, "getIterator", NULL, 0);
					}
					ZEPHIR_CALL_METHOD(NULL, &_17$$4, "rewind", NULL, 0);
					zephir_check_call_status();
					while (1) {
						ZEPHIR_CALL_METHOD(&_16$$4, &_17$$4, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_16$$4)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&valueA, &_17$$4, "current", NULL, 0);
						zephir_check_call_status();
							_24$$8 = !(Z_TYPE_P(&valueA) == IS_LONG);
							if (_24$$8) {
								ZEPHIR_CALL_FUNCTION(&_25$$8, "is_float", &_20, 52, &valueA);
								zephir_check_call_status();
								_24$$8 = !zephir_is_true(&_25$$8);
							}
							if (UNEXPECTED(_24$$8)) {
								ZEPHIR_INIT_NVAR(&_26$$9);
								object_init_ex(&_26$$9, spl_ce_InvalidArgumentException);
								ZEPHIR_INIT_NVAR(&_27$$9);
								zephir_gettype(&_27$$9, &valueA);
								ZEPHIR_INIT_NVAR(&_28$$9);
								ZEPHIR_CONCAT_SSVS(&_28$$9, "Matrix element must", " be an integer or floating point number, ", &_27$$9, " given.");
								ZEPHIR_CALL_METHOD(NULL, &_26$$9, "__construct", &_14, 51, &_28$$9);
								zephir_check_call_status();
								zephir_throw_exception_debug(&_26$$9, "stub/issue2165/issue.zep", 40);
								ZEPHIR_MM_RESTORE();
								return;
							}
						ZEPHIR_CALL_METHOD(NULL, &_17$$4, "next", NULL, 0);
						zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&valueA);
				ZEPHIR_CALL_FUNCTION(&_29$$4, "array_values", &_2, 49, &rowA);
				zephir_check_call_status();
				zephir_array_append(&rowA, &_29$$4, PH_SEPARATE, "stub/issue2165/issue.zep", 44);
			} ZEND_HASH_FOREACH_END();
		} else {
			if (zephir_instance_of_ev(&a, (const zend_class_entry *)zend_ce_iterator)) {
				ZVAL_COPY(&_5$$3, &a);
			} else {
				ZEPHIR_CALL_METHOD(&_5$$3, &a, "getIterator", NULL, 0);
			}
			ZEPHIR_CALL_METHOD(NULL, &_5$$3, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_4$$3, &_5$$3, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_4$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&i, &_5$$3, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&rowA, &_5$$3, "current", NULL, 0);
				zephir_check_call_status();
					if (UNEXPECTED(zephir_fast_count_int(&rowA) != n)) {
						ZEPHIR_INIT_NVAR(&_30$$11);
						object_init_ex(&_30$$11, spl_ce_InvalidArgumentException);
						ZVAL_LONG(&_31$$11, n);
						ZEPHIR_CALL_FUNCTION(&_32$$11, "strval", &_11, 50, &_31$$11);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_33$$11);
						ZVAL_LONG(&_33$$11, zephir_fast_count_int(&rowA));
						ZEPHIR_INIT_NVAR(&_34$$11);
						ZEPHIR_CONCAT_SSVSVSSVS(&_34$$11, "The number of columns", " must be equal for all rows, ", &_32$$11, " needed but ", &_33$$11, " given", " at row offset ", &i, ".");
						ZEPHIR_CALL_METHOD(NULL, &_30$$11, "__construct", &_14, 51, &_34$$11);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_30$$11, "stub/issue2165/issue.zep", 33);
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_is_iterable(&rowA, 0, "stub/issue2165/issue.zep", 44);
					if (Z_TYPE_P(&rowA) == IS_ARRAY) {
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&rowA), _35$$10)
						{
							ZEPHIR_INIT_NVAR(&valueA);
							ZVAL_COPY(&valueA, _35$$10);
							_38$$12 = !(Z_TYPE_P(&valueA) == IS_LONG);
							if (_38$$12) {
								ZEPHIR_CALL_FUNCTION(&_39$$12, "is_float", &_20, 52, &valueA);
								zephir_check_call_status();
								_38$$12 = !zephir_is_true(&_39$$12);
							}
							if (UNEXPECTED(_38$$12)) {
								ZEPHIR_INIT_NVAR(&_40$$13);
								object_init_ex(&_40$$13, spl_ce_InvalidArgumentException);
								ZEPHIR_INIT_NVAR(&_41$$13);
								zephir_gettype(&_41$$13, &valueA);
								ZEPHIR_INIT_NVAR(&_42$$13);
								ZEPHIR_CONCAT_SSVS(&_42$$13, "Matrix element must", " be an integer or floating point number, ", &_41$$13, " given.");
								ZEPHIR_CALL_METHOD(NULL, &_40$$13, "__construct", &_14, 51, &_42$$13);
								zephir_check_call_status();
								zephir_throw_exception_debug(&_40$$13, "stub/issue2165/issue.zep", 40);
								ZEPHIR_MM_RESTORE();
								return;
							}
						} ZEND_HASH_FOREACH_END();
					} else {
						if (zephir_instance_of_ev(&rowA, (const zend_class_entry *)zend_ce_iterator)) {
							ZVAL_COPY(&_37$$10, &rowA);
						} else {
							ZEPHIR_CALL_METHOD(&_37$$10, &rowA, "getIterator", NULL, 0);
						}
						ZEPHIR_CALL_METHOD(NULL, &_37$$10, "rewind", NULL, 0);
						zephir_check_call_status();
						while (1) {
							ZEPHIR_CALL_METHOD(&_36$$10, &_37$$10, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_36$$10)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&valueA, &_37$$10, "current", NULL, 0);
							zephir_check_call_status();
								_43$$14 = !(Z_TYPE_P(&valueA) == IS_LONG);
								if (_43$$14) {
									ZEPHIR_CALL_FUNCTION(&_44$$14, "is_float", &_20, 52, &valueA);
									zephir_check_call_status();
									_43$$14 = !zephir_is_true(&_44$$14);
								}
								if (UNEXPECTED(_43$$14)) {
									ZEPHIR_INIT_NVAR(&_45$$15);
									object_init_ex(&_45$$15, spl_ce_InvalidArgumentException);
									ZEPHIR_INIT_NVAR(&_46$$15);
									zephir_gettype(&_46$$15, &valueA);
									ZEPHIR_INIT_NVAR(&_47$$15);
									ZEPHIR_CONCAT_SSVS(&_47$$15, "Matrix element must", " be an integer or floating point number, ", &_46$$15, " given.");
									ZEPHIR_CALL_METHOD(NULL, &_45$$15, "__construct", &_14, 51, &_47$$15);
									zephir_check_call_status();
									zephir_throw_exception_debug(&_45$$15, "stub/issue2165/issue.zep", 40);
									ZEPHIR_MM_RESTORE();
									return;
								}
							ZEPHIR_CALL_METHOD(NULL, &_37$$10, "next", NULL, 0);
							zephir_check_call_status();
						}
					}
					ZEPHIR_INIT_NVAR(&valueA);
					ZEPHIR_CALL_FUNCTION(&_48$$10, "array_values", &_2, 49, &rowA);
					zephir_check_call_status();
					zephir_array_append(&rowA, &_48$$10, PH_SEPARATE, "stub/issue2165/issue.zep", 44);
				ZEPHIR_CALL_METHOD(NULL, &_5$$3, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&rowA);
		ZEPHIR_INIT_NVAR(&i);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("a"), &a);
	ZEPHIR_INIT_ZVAL_NREF(_49);
	ZVAL_LONG(&_49, m);
	zephir_update_property_zval(this_ptr, ZEND_STRL("m"), &_49);
	ZEPHIR_INIT_ZVAL_NREF(_49);
	ZVAL_LONG(&_49, n);
	zephir_update_property_zval(this_ptr, ZEND_STRL("n"), &_49);
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Stub_Issue2165_Issue, quick)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *a_param = NULL, _0;
	zval a;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&a);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(a)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &a_param);
	if (!a_param) {
		ZEPHIR_INIT_VAR(&a);
		array_init(&a);
	} else {
		zephir_get_arrval(&a, a_param);
	}


	object_init_ex(return_value, stub_issue2165_issue_ce);
	ZVAL_BOOL(&_0, 0);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 48, &a, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Stub_Issue2165_Issue, ones)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *m_param = NULL, *n_param = NULL, _0, _1, _2;
	zend_long m, n, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(m)
		Z_PARAM_LONG(n)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &m_param, &n_param);
	m = zephir_get_intval(m_param);
	n = zephir_get_intval(n_param);


	ZVAL_LONG(&_0, 1);
	ZVAL_LONG(&_1, m);
	ZVAL_LONG(&_2, n);
	ZEPHIR_RETURN_CALL_SELF("fill", NULL, 0, &_0, &_1, &_2);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Stub_Issue2165_Issue, fill)
{
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_8 = NULL, *_17 = NULL;
	zend_long m, n, ZEPHIR_LAST_CALL_STATUS;
	zval *value, value_sub, *m_param = NULL, *n_param = NULL, _1, _14, _15, _16, _18, _2$$3, _3$$3, _4$$3, _5$$4, _6$$4, _7$$4, _9$$4, _10$$5, _11$$5, _12$$5, _13$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_13$$5);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_ZVAL(value)
		Z_PARAM_LONG(m)
		Z_PARAM_LONG(n)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &value, &m_param, &n_param);
	m = zephir_get_intval(m_param);
	n = zephir_get_intval(n_param);


	_0 = !(Z_TYPE_P(value) == IS_LONG);
	if (_0) {
		ZEPHIR_CALL_FUNCTION(&_1, "is_float", NULL, 52, value);
		zephir_check_call_status();
		_0 = !zephir_is_true(&_1);
	}
	if (UNEXPECTED(_0)) {
		ZEPHIR_INIT_VAR(&_2$$3);
		object_init_ex(&_2$$3, spl_ce_InvalidArgumentException);
		ZEPHIR_INIT_VAR(&_3$$3);
		zephir_gettype(&_3$$3, value);
		ZEPHIR_INIT_VAR(&_4$$3);
		ZEPHIR_CONCAT_SSVS(&_4$$3, "Value must be an", " integer or floating point number, ", &_3$$3, " given.");
		ZEPHIR_CALL_METHOD(NULL, &_2$$3, "__construct", NULL, 51, &_4$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$3, "stub/issue2165/issue.zep", 68);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (UNEXPECTED(m < 1)) {
		ZEPHIR_INIT_VAR(&_5$$4);
		object_init_ex(&_5$$4, spl_ce_InvalidArgumentException);
		ZVAL_LONG(&_6$$4, m);
		ZEPHIR_CALL_FUNCTION(&_7$$4, "strval", &_8, 50, &_6$$4);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_9$$4);
		ZEPHIR_CONCAT_SSVS(&_9$$4, "M must be", " greater than 0, ", &_7$$4, " given.");
		ZEPHIR_CALL_METHOD(NULL, &_5$$4, "__construct", NULL, 51, &_9$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_5$$4, "stub/issue2165/issue.zep", 73);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (UNEXPECTED(n < 1)) {
		ZEPHIR_INIT_VAR(&_10$$5);
		object_init_ex(&_10$$5, spl_ce_InvalidArgumentException);
		ZVAL_LONG(&_11$$5, n);
		ZEPHIR_CALL_FUNCTION(&_12$$5, "strval", &_8, 50, &_11$$5);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_13$$5);
		ZEPHIR_CONCAT_SSVS(&_13$$5, "N must be", " greater than 0, ", &_12$$5, " given.");
		ZEPHIR_CALL_METHOD(NULL, &_10$$5, "__construct", NULL, 51, &_13$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_10$$5, "stub/issue2165/issue.zep", 78);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZVAL_LONG(&_14, 0);
	ZVAL_LONG(&_15, n);
	ZEPHIR_CALL_FUNCTION(&_16, "array_fill", &_17, 5, &_14, &_15, value);
	zephir_check_call_status();
	ZVAL_LONG(&_14, 0);
	ZVAL_LONG(&_15, m);
	ZEPHIR_CALL_FUNCTION(&_18, "array_fill", &_17, 5, &_14, &_15, &_16);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_SELF("quick", NULL, 0, &_18);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Stub_Issue2165_Issue, reciprocal)
{
	zval _0, _1, _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_1, this_ptr, ZEND_STRL("m"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_2, this_ptr, ZEND_STRL("n"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_SELF(&_0, "ones", NULL, 0, &_1, &_2);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_0, "dividematrix", NULL, 0, this_ptr);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Stub_Issue2165_Issue, divideMatrix)
{
	zval c;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *b, b_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&b_sub);
	ZVAL_UNDEF(&c);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(b, zephir_get_internal_ce(SL("stub\\issue2165\\issue")))
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &b);


	ZEPHIR_INIT_VAR(&c);
	array_init(&c);
	ZEPHIR_RETURN_CALL_SELF("quick", NULL, 0, &c);
	zephir_check_call_status();
	RETURN_MM();
}

