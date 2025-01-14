
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/string.h"
#include "kernel/array.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Formats messages using JSON encoding
 */
ZEPHIR_INIT_CLASS(Phalcon_Logger_Formatter_Json)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Logger\\Formatter, Json, phalcon, logger_formatter_json, phalcon_logger_formatter_abstractformatter_ce, phalcon_logger_formatter_json_method_entry, 0);

	return SUCCESS;
}

/**
 * Json constructor.
 *
 * @param string $dateFormat
 * @param string $interpolatorLeft
 * @param string $interpolatorRight
 */
PHP_METHOD(Phalcon_Logger_Formatter_Json, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *dateFormat_param = NULL, *interpolatorLeft_param = NULL, *interpolatorRight_param = NULL;
	zval dateFormat, interpolatorLeft, interpolatorRight;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&dateFormat);
	ZVAL_UNDEF(&interpolatorLeft);
	ZVAL_UNDEF(&interpolatorRight);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 3)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(dateFormat)
		Z_PARAM_STR(interpolatorLeft)
		Z_PARAM_STR(interpolatorRight)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &dateFormat_param, &interpolatorLeft_param, &interpolatorRight_param);
	if (!dateFormat_param) {
		ZEPHIR_INIT_VAR(&dateFormat);
		ZVAL_STRING(&dateFormat, "c");
	} else {
		zephir_get_strval(&dateFormat, dateFormat_param);
	}
	if (!interpolatorLeft_param) {
		ZEPHIR_INIT_VAR(&interpolatorLeft);
		ZVAL_STRING(&interpolatorLeft, "%");
	} else {
		zephir_get_strval(&interpolatorLeft, interpolatorLeft_param);
	}
	if (!interpolatorRight_param) {
		ZEPHIR_INIT_VAR(&interpolatorRight);
		ZVAL_STRING(&interpolatorRight, "%");
	} else {
		zephir_get_strval(&interpolatorRight, interpolatorRight_param);
	}


	zephir_update_property_zval(this_ptr, ZEND_STRL("dateFormat"), &dateFormat);
	zephir_update_property_zval(this_ptr, ZEND_STRL("interpolatorLeft"), &interpolatorLeft);
	zephir_update_property_zval(this_ptr, ZEND_STRL("interpolatorRight"), &interpolatorRight);
	ZEPHIR_MM_RESTORE();
}

/**
 * Applies a format to a message before sent it to the internal log
 *
 * @param Item $item
 *
 * @return string
 * @throws JsonException
 */
PHP_METHOD(Phalcon_Logger_Formatter_Json, format)
{
	zval _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *item, item_sub, message, options, _0, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&item_sub);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(item, phalcon_logger_item_ce)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &item);


	ZEPHIR_CALL_METHOD(&_0, item, "getmessage", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&message, this_ptr, "getinterpolatedmessage", NULL, 0, item, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&options);
	ZVAL_LONG(&options, (((((1 + 4) + 2) + 8) + 64) + 4194304));
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 3, 0);
	ZEPHIR_CALL_METHOD(&_2, item, "getlevelname", NULL, 0);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("level"), &_2, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_1, SL("message"), &message, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getformatteddate", NULL, 0, item);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("timestamp"), &_2, PH_COPY | PH_SEPARATE);
	zephir_json_encode(return_value, &_1, zephir_get_intval(&options) );
	RETURN_MM();
}

