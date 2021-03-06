/*
 * Copyright 2016, alex at staticlibs.net
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
 * File:   int_utils_test.cpp
 * Author: alex
 *
 * Created on June 13, 2016, 10:41 PM
 */

#include "staticlib/config/is_integer.hpp"

#include <iostream>
#include <cstring>

#include "staticlib/config/assert.hpp"

namespace sc = staticlib::config;

void test_is_int32() {
    slassert(sc::is_int32(-1));
    slassert(sc::is_int32(0));
    slassert(sc::is_int32(1));
    slassert(!sc::is_int32(std::numeric_limits<uint32_t>::max()));
    slassert(!sc::is_int32(static_cast<int64_t> (std::numeric_limits<uint32_t>::max())));
    slassert(sc::is_int32(std::numeric_limits<int32_t>::min()));
    slassert(!sc::is_int32(static_cast<int64_t> (std::numeric_limits<int32_t>::min()) - 1));
}

void test_is_uint32() {
    slassert(sc::is_uint32(0));
    slassert(sc::is_uint32(1));
    slassert(sc::is_uint32(static_cast<int64_t>(std::numeric_limits<uint32_t>::max())));
    slassert(sc::is_uint32(static_cast<uint64_t>(std::numeric_limits<uint32_t>::max())));
    slassert(!sc::is_uint32(static_cast<uint64_t>(std::numeric_limits<uint32_t>::max()) + 1));
}

void test_is_uint32_positive() {
    slassert(!sc::is_uint32_positive(0));
    slassert(sc::is_uint32_positive(1));
    slassert(sc::is_uint32_positive(static_cast<int64_t> (std::numeric_limits<uint32_t>::max())));
    slassert(sc::is_uint32_positive(static_cast<uint64_t> (std::numeric_limits<uint32_t>::max())));
    slassert(!sc::is_uint32_positive(static_cast<uint64_t> (std::numeric_limits<uint32_t>::max()) + 1));
}

void test_is_int16() {
    slassert(sc::is_int16(-1));
    slassert(sc::is_int16(0));
    slassert(sc::is_int16(1));
    slassert(!sc::is_int16(std::numeric_limits<uint16_t>::max()));
    slassert(!sc::is_int16(static_cast<int32_t> (std::numeric_limits<uint16_t>::max())));
    slassert(sc::is_int16(std::numeric_limits<int16_t>::min()));
    slassert(!sc::is_int16(static_cast<int32_t> (std::numeric_limits<int16_t>::min()) - 1));
}

void test_is_uint16() {
    slassert(sc::is_uint16(0));
    slassert(sc::is_uint16(1));
    slassert(sc::is_uint16(static_cast<int32_t> (std::numeric_limits<uint16_t>::max())));
    slassert(sc::is_uint16(static_cast<uint32_t> (std::numeric_limits<uint16_t>::max())));
    slassert(!sc::is_uint16(static_cast<uint32_t> (std::numeric_limits<uint16_t>::max()) + 1));
}

void test_is_uint16_positive() {
    slassert(!sc::is_uint16_positive(0));
    slassert(sc::is_uint16_positive(1));
    slassert(sc::is_uint16_positive(static_cast<int32_t> (std::numeric_limits<uint16_t>::max())));
    slassert(sc::is_uint16_positive(static_cast<uint32_t> (std::numeric_limits<uint16_t>::max())));
    slassert(!sc::is_uint16_positive(static_cast<uint32_t> (std::numeric_limits<uint16_t>::max()) + 1));
}

void test_is_streamsize() {
    slassert(sc::is_streamsize(-1));
    slassert(sc::is_streamsize(0));
    slassert(sc::is_streamsize(1));
    slassert(!sc::is_streamsize(std::numeric_limits<size_t>::max()));
    slassert(sc::is_streamsize(std::numeric_limits<std::streamsize>::min()));
}

void test_is_sizet() {
    slassert(sc::is_sizet(0));
    slassert(sc::is_sizet(1));
    slassert(!sc::is_sizet(-1));
    slassert(sc::is_sizet(std::numeric_limits<size_t>::max()));
    slassert(sc::is_sizet(std::numeric_limits<size_t>::min()));
}

void test_is_sizet_positive() {
    slassert(!sc::is_sizet_positive(0));
    slassert(sc::is_sizet_positive(1));
    slassert(!sc::is_sizet_positive(-1));
    slassert(sc::is_sizet_positive(std::numeric_limits<size_t>::max()));
    slassert(!sc::is_sizet_positive(std::numeric_limits<size_t>::min()));
}

int main() {
    try {
        test_is_int32();
        test_is_uint32();
        test_is_uint32_positive();
        test_is_int16();
        test_is_uint16();
        test_is_uint16_positive();
        test_is_streamsize();
        test_is_sizet();
        test_is_sizet_positive();
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
        return 1;
    }
    return 0;
}
