
extern zend_class_entry *stub_arrayiteratoraggregatetest_ce;

ZEPHIR_INIT_CLASS(Stub_ArrayIteratorAggregateTest);

PHP_METHOD(Stub_ArrayIteratorAggregateTest, test);

ZEND_BEGIN_ARG_INFO_EX(arginfo_stub_arrayiteratoraggregatetest_test, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(stub_arrayiteratoraggregatetest_method_entry) {
#if PHP_VERSION_ID >= 80000
	PHP_ME(Stub_ArrayIteratorAggregateTest, test, arginfo_stub_arrayiteratoraggregatetest_test, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
#else
	PHP_ME(Stub_ArrayIteratorAggregateTest, test, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
#endif
	PHP_FE_END
};
