
extern zend_class_entry *stub_arrayiteratoraggregate_ce;

ZEPHIR_INIT_CLASS(Stub_ArrayIteratorAggregate);

PHP_METHOD(Stub_ArrayIteratorAggregate, getIterator);

ZEND_BEGIN_ARG_INFO_EX(arginfo_stub_arrayiteratoraggregate_getiterator, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(stub_arrayiteratoraggregate_method_entry) {
#if PHP_VERSION_ID >= 80000
	PHP_ME(Stub_ArrayIteratorAggregate, getIterator, arginfo_stub_arrayiteratoraggregate_getiterator, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Stub_ArrayIteratorAggregate, getIterator, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_FE_END
};
