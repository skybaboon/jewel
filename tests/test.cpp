/*
 * Copyright 2012, 2013 Matthew Harvey
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "assert.hpp"
#include "capped_string.hpp"
#include "checked_arithmetic.hpp"
#include "decimal.hpp"
#include "decimal_exceptions.hpp"
#include "decimal_special_tests.hpp"
#include "exception.hpp"
#include "exception_special_tests.hpp"
#include "log.hpp"
#include "num_digits.hpp"
#include <boost/numeric/conversion/cast.hpp>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <UnitTest++/UnitTest++.h>
using boost::numeric_cast;
using jewel::Decimal;
using jewel::detail::decimal_csv_test;
using jewel::detail::decimal_speed_test;
using jewel::detail::test_exception_macros;
using jewel::multiplication_is_unsafe;
using jewel::Log;
using jewel::NumDigits;
using std::cout;
using std::endl;
using std::ios;
using std::numeric_limits;
using std::ostringstream;
using std::setprecision;
using std::string;

int main()
{
    int num_failures = 0;

    Log::set_filepath("test.log");
    Log::set_threshold(Log::trace);

    #ifndef NDEBUG
        cout << "Compiled in debugging mode (NDEBUG not defined)."
             << endl;
    #else
        cout << "Compiled in release mode (NDEBUG is defined)."
             << endl;
    #endif

    // TODO MEDIUM PRIORITY Find a better way of testing Decimal output
    // failure handling.
    #ifdef JEWEL_PERFORM_DECIMAL_OUTPUT_FAILURE_TEST
        cout << "Compiled with JEWEL_PERFORM_DECIMAL_OUTPUT_FAILURE_TEST "
             << "defined.\n"
             << "Normal tests for jewel::Decimal will be "
             << "eschewed in order to test a sabotaged version of the "
             << "output function, to ensure it handles errors as expected.\n"
             << "DO NOT USE the library except for testing on this build. "
             << "(Rebuild with this macro undefined, before using the library.)."
             << endl;
    #endif

    num_failures += decimal_csv_test();
    num_failures += test_exception_macros();
    cout << "Now running various unit tests using UnitTest++..." << endl;
    num_failures += UnitTest::RunAllTests();

    if (num_failures == 0)
    {
        cout << "SUCCESS. All tests passed." << endl;
    }
    else
    {
        JEWEL_HARD_ASSERT (num_failures > 0);
        cout << "FAILURE. Number of failed tests: " << num_failures << endl;
    }
    return num_failures;
}
