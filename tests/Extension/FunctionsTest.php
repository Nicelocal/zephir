<?php

declare(strict_types=1);

/**
 * This file is part of the Zephir.
 *
 * (c) Phalcon Team <team@zephir-lang.com>
 *
 * For the full copyright and license information, please view
 * the LICENSE file that was distributed with this source code.
 */

namespace Extension;

use PHPUnit\Framework\TestCase;
use Stub\Functions;

class FunctionsTest extends TestCase
{
    public function testFilterVar(): void
    {
        $class = new Functions();

        $this->assertFalse($class->filterVar1());
        $this->assertTrue($class->filterVar2());
    }

    public function testPassByVariableReference(): void
    {
        $class = new Functions();

        $i = 10;
        $class->passByVariableReference($i);
        $this->assertEquals(20, $i);
    }

    public function testPassByVariableReferenceNested(): void
    {
        $class = new Functions();

        $i = 10;
        $class->passByVariableReferenceNested($i);
        $this->assertEquals(20, $i);
    }

    public function testPassByVariableDefaultReference(): void
    {
        $class = new Functions();

        $i = 10;
        $class->passByVariableDefaultReference($i);
        $this->assertEquals(20, $i);
    }

    public function testPassByVariableArrayReference(): void
    {
        $class = new Functions();

        $i = [10];
        $class->passByVariableArrayReference($i);
        $this->assertEquals(20, $i[0]);
    }

    public function testPassByTypedReference(): void
    {
        $class = new Functions();

        $i = 10;
        $class->passByTypedReference($i);
        $this->assertEquals(20, $i);
    }

    public function testPassByTypedArrayReference(): void
    {
        $class = new Functions();

        $i = [10];
        $class->passByTypedArrayReference($i);
        $this->assertEquals(20, $i[0]);
    }

    public function testPostIncrement(): void
    {
        $class = new Functions();

        $i = 2;
        $this->assertEquals(2, $class->postInc($i));
        $this->assertEquals(3, $i);
    }
}
