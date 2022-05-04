
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
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/object.h"


/**
 * FortyTwo
 */
ZEPHIR_INIT_CLASS(Stub_FortyTwo)
{
	ZEPHIR_REGISTER_CLASS(Stub, FortyTwo, stub, fortytwo, stub_fortytwo_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Stub_FortyTwo, proof)
{
	zend_bool _5$$3, _9$$6;
	zval _0;
	zval box, side, _1, *_2, _3, _4, _8$$4, _12$$7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, i = 0, j = 0, _6$$3, _7$$3, _10$$6, _11$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&box);
	ZVAL_UNDEF(&side);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&box);
	zephir_create_array(&box, 15, 0);
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 3, 0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_LONG(&_1, 10);
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_LONG(&_1, 24);
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_LONG(&_1, 8);
	zephir_array_fast_append(&_0, &_1);
	zephir_array_fast_append(&box, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_array(&_0, 3, 0);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_LONG(&_1, 8);
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_LONG(&_1, 15);
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_LONG(&_1, 19);
	zephir_array_fast_append(&_0, &_1);
	zephir_array_fast_append(&box, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_array(&_0, 3, 0);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_LONG(&_1, 19);
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_LONG(&_1, 17);
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_LONG(&_1, 6);
	zephir_array_fast_append(&_0, &_1);
	zephir_array_fast_append(&box, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_array(&_0, 3, 0);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_LONG(&_1, 6);
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_LONG(&_1, 16);
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_LONG(&_1, 20);
	zephir_array_fast_append(&_0, &_1);
	zephir_array_fast_append(&box, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_array(&_0, 3, 0);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_LONG(&_1, 20);
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_LONG(&_1, 13);
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_LONG(&_1, 9);
	zephir_array_fast_append(&_0, &_1);
	zephir_array_fast_append(&box, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_array(&_0, 3, 0);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_LONG(&_1, 9);
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_LONG(&_1, 11);
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_LONG(&_1, 22);
	zephir_array_fast_append(&_0, &_1);
	zephir_array_fast_append(&box, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_array(&_0, 3, 0);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_LONG(&_1, 22);
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_LONG(&_1, 2);
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_LONG(&_1, 18);
	zephir_array_fast_append(&_0, &_1);
	zephir_array_fast_append(&box, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_array(&_0, 3, 0);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_LONG(&_1, 18);
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_LONG(&_1, 4);
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_LONG(&_1, 20);
	zephir_array_fast_append(&_0, &_1);
	zephir_array_fast_append(&box, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_array(&_0, 3, 0);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_LONG(&_1, 5);
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_LONG(&_1, 21);
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_LONG(&_1, 16);
	zephir_array_fast_append(&_0, &_1);
	zephir_array_fast_append(&box, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_array(&_0, 3, 0);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_LONG(&_1, 16);
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_LONG(&_1, 3);
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_LONG(&_1, 23);
	zephir_array_fast_append(&_0, &_1);
	zephir_array_fast_append(&box, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_array(&_0, 3, 0);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_LONG(&_1, 23);
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_LONG(&_1, 7);
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_LONG(&_1, 12);
	zephir_array_fast_append(&_0, &_1);
	zephir_array_fast_append(&box, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_array(&_0, 3, 0);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_LONG(&_1, 12);
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_LONG(&_1, 25);
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_LONG(&_1, 5);
	zephir_array_fast_append(&_0, &_1);
	zephir_array_fast_append(&box, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_array(&_0, 3, 0);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_LONG(&_1, 24);
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_LONG(&_1, 7);
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_LONG(&_1, 11);
	zephir_array_fast_append(&_0, &_1);
	zephir_array_fast_append(&box, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_array(&_0, 3, 0);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_LONG(&_1, 11);
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_LONG(&_1, 27);
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_LONG(&_1, 4);
	zephir_array_fast_append(&_0, &_1);
	zephir_array_fast_append(&box, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_array(&_0, 3, 0);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_LONG(&_1, 11);
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_LONG(&_1, 27);
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_LONG(&_1, 4);
	zephir_array_fast_append(&_0, &_1);
	zephir_array_fast_append(&box, &_0);
	zephir_is_iterable(&box, 0, "stub/fortytwo.zep", 32);
	if (Z_TYPE_P(&box) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&box), _2)
		{
			ZEPHIR_INIT_NVAR(&side);
			ZVAL_COPY(&side, _2);
			j = 0;
			_7$$3 = 2;
			_6$$3 = 0;
			_5$$3 = 0;
			if (_6$$3 <= _7$$3) {
				while (1) {
					if (_5$$3) {
						_6$$3++;
						if (!(_6$$3 <= _7$$3)) {
							break;
						}
					} else {
						_5$$3 = 1;
					}
					i = _6$$3;
					zephir_array_fetch_long(&_8$$4, &side, i, PH_NOISY | PH_READONLY, "stub/fortytwo.zep", 26);
					j += zephir_get_numberval(&_8$$4);
				}
			}
			if (j != 42) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(stub_exception_ce, "not true", "stub/fortytwo.zep", 29);
				return;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		if (zephir_instance_of_ev(&box, (const zend_class_entry *)zend_ce_iterator)) {
			ZVAL_COPY(&_4, &box);
		} else {
			ZEPHIR_CALL_METHOD(&_4, &box, "getIterator", NULL, 0);
		}
		ZEPHIR_CALL_METHOD(NULL, &_4, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_3, &_4, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_3)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&side, &_4, "current", NULL, 0);
			zephir_check_call_status();
				j = 0;
				_11$$6 = 2;
				_10$$6 = 0;
				_9$$6 = 0;
				if (_10$$6 <= _11$$6) {
					while (1) {
						if (_9$$6) {
							_10$$6++;
							if (!(_10$$6 <= _11$$6)) {
								break;
							}
						} else {
							_9$$6 = 1;
						}
						i = _10$$6;
						zephir_array_fetch_long(&_12$$7, &side, i, PH_NOISY | PH_READONLY, "stub/fortytwo.zep", 26);
						j += zephir_get_numberval(&_12$$7);
					}
				}
				if (j != 42) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(stub_exception_ce, "not true", "stub/fortytwo.zep", 29);
					return;
				}
			ZEPHIR_CALL_METHOD(NULL, &_4, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&side);
	ZEPHIR_MM_RESTORE();
}

