
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
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(Stub_ArrayIteratorAggregate)
{
	ZEPHIR_REGISTER_CLASS(Stub, ArrayIteratorAggregate, stub, arrayiteratoraggregate, stub_arrayiteratoraggregate_method_entry, 0);

	zend_class_implements(stub_arrayiteratoraggregate_ce, 1, zend_ce_aggregate);
	return SUCCESS;
}

PHP_METHOD(Stub_ArrayIteratorAggregate, getIterator)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();



	ZEPHIR_MM_GROW();

	object_init_ex(return_value, stub_arrayiterator_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 4);
	zephir_check_call_status();
	RETURN_MM();
}

