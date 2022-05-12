
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
#include "kernel/memory.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(Stub_Namespaces_ClassEntry)
{
	ZEPHIR_REGISTER_CLASS(Stub\\Namespaces, ClassEntry, stub, namespaces_classentry, stub_namespaces_classentry_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Stub_Namespaces_ClassEntry, setParam)
{
	zval *param, param_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&param_sub);


	zephir_fetch_params_without_memory_grow(1, 0, &param);


	RETVAL_ZVAL(param, 1, 0);
	return;
}

PHP_METHOD(Stub_Namespaces_ClassEntry, setParamImported)
{
	zval *param, param_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&param_sub);


	zephir_fetch_params_without_memory_grow(1, 0, &param);


	RETVAL_ZVAL(param, 1, 0);
	return;
}

