/*
 * Copyright 2015, alex at staticlibs.net
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/* 
 * File:   assert_test.cpp
 * Author: alex
 *
 * Created on November 22, 2015, 9:33 PM
 */

#include "staticlib/config/assert.hpp"

#include <iostream>
#include <stdexcept>
#include <string>

#include "staticlib/config/staticlib_exception.hpp"

namespace sc = staticlib::config;

void test_assert() {
    bool catched = false;
    try {
        int a = 0;
        int b = 1;
        slassert(a > b);
    } catch (const sc::assert_exception&) {
        catched = true;
    }
    if (!catched) throw std::runtime_error("Assert not thrown");
}

int main() {
    try {
        test_assert();
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
        return 1;
    }
    return 0;
}

