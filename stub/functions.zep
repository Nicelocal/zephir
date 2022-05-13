
namespace Stub;

class Functions
{
    /**
     * @issue https://github.com/zephir-lang/zephir/issues/658
     */
    public function filterVar1() -> bool
    {
        var ret;
        let ret = "0";

        return false === filter_var(ret, FILTER_VALIDATE_FLOAT, 20480);
    }

    /**
     * @issue https://github.com/zephir-lang/zephir/issues/658
     */
    public function filterVar2() -> bool
    {
        var ret;
        let ret = "0";

        return false == filter_var(ret, FILTER_VALIDATE_FLOAT, 20480);
    }

    public function passByVariableReference(var& i) -> void
    {
        let i += 10;
    }

    public function passByVariableArrayReference(var& i) -> void
    {
        let i[0] = 20;
    }

    public function passByTypedReference(int& i) -> void
    {
        let i += 10;
    }

    public function passByTypedArrayReference(array& i) -> void
    {
        let i[0] += 10;
    }

    public static function postInc(var &number)
    {
        var old;
        let old = number;
        let number = number + 1;
        return old;
    }
}
