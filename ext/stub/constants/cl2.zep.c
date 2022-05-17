
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


ZEPHIR_INIT_CLASS(Stub_Constants_Cl2)
{
	ZEPHIR_REGISTER_CLASS_EX(Stub\\Constants, Cl2, stub, constants_cl2, stub_constants_cl1_ce, NULL, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zephir_declare_class_constant_long(stub_constants_cl2_ce, SL("ERROR_LEVEL"), -2);

	return SUCCESS;
}

