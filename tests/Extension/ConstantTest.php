<?php

/**
 * This file is part of the Zephir.
 *
 * (c) Phalcon Team <team@zephir-lang.com>
 *
 * For the full copyright and license information, please view
 * the LICENSE file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Extension;

use PHPUnit\Framework\TestCase;
use ReflectionClass;
use ReflectionException;
use Stub\Issue1134;

/**
 * @issue https://github.com/zephir-lang/zephir/issues/1134
 */
final class ConstantTest extends TestCase
{
    public function test() {
        $this->assertEquals(-1, \Stub\Constants\Cl1::ERROR_LEVEL);
        $this->assertEquals(-2, \Stub\Constants\Cl2::ERROR_LEVEL);
    }
}
