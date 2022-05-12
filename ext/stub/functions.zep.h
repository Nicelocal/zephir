
extern zend_class_entry *stub_functions_ce;

ZEPHIR_INIT_CLASS(Stub_Functions);

PHP_METHOD(Stub_Functions, filterVar1);
PHP_METHOD(Stub_Functions, filterVar2);
PHP_METHOD(Stub_Functions, passByVariableReference);
PHP_METHOD(Stub_Functions, passByTypedReference);
PHP_METHOD(Stub_Functions, passByTypedArrayReference);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_stub_functions_filtervar1, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_stub_functions_filtervar2, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_stub_functions_passbyvariablereference, 0, 1, IS_VOID, 0)

	ZEND_ARG_INFO(1, i)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_stub_functions_passbytypedreference, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(1, i, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_stub_functions_passbytypedarrayreference, 0, 1, IS_VOID, 0)

	ZEND_ARG_ARRAY_INFO(1, i, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(stub_functions_method_entry) {
	PHP_ME(Stub_Functions, filterVar1, arginfo_stub_functions_filtervar1, ZEND_ACC_PUBLIC)
	PHP_ME(Stub_Functions, filterVar2, arginfo_stub_functions_filtervar2, ZEND_ACC_PUBLIC)
	PHP_ME(Stub_Functions, passByVariableReference, arginfo_stub_functions_passbyvariablereference, ZEND_ACC_PUBLIC)
	PHP_ME(Stub_Functions, passByTypedReference, arginfo_stub_functions_passbytypedreference, ZEND_ACC_PUBLIC)
	PHP_ME(Stub_Functions, passByTypedArrayReference, arginfo_stub_functions_passbytypedarrayreference, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
