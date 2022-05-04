namespace Stub;

class ArrayIteratorAggregate implements \IteratorAggregate
{
	public function getIterator() -> iterable {
		return new \Stub\ArrayIterator;
	}
}
