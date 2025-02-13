<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Integration\Filter\Validation;

use IntegrationTester;
use Phalcon\Filter\Validation;
use Phalcon\Filter\Validation\Validator\PresenceOf;
use Phalcon\Messages\Message;
use Phalcon\Messages\Messages;
use stdClass;

/**
 * Class GetMessagesCest
 */
class GetMessagesCest
{
    /**
     * Tests Phalcon\Filter\Validation :: getMessages()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-04-16
     */
    public function filterValidationGetMessages(IntegrationTester $I)
    {
        $I->wantToTest('Validation - getMessages()');

        $validator  = new PresenceOf();
        $validation = new Validation();

        $validation->bind(
            new stdClass(),
            [
                'day'   => date('d'),
                'month' => date('m'),
                'year'  => (string)(intval(date('Y')) + 1),
            ]
        );

        $validator->validate($validation, 'foo');

        $expected = new Messages(
            [
                new Message(
                    'Field foo is required',
                    'foo',
                    PresenceOf::class,
                    0
                ),
            ]
        );

        $actual = $validation->getMessages();
        $I->assertEquals($expected, $actual);
    }
}
