namespace Stub;

class ArrayIteratorAggregate implements \IteratorAggregate
{
	public function getIterator() {
		return new \Stub\ArrayIterator;
	}
}
