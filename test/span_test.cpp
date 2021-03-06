/*
 * Copyright 2017, alex at staticlibs.net
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
 * File:   span_test.cpp
 * Author: alex
 *
 * Created on February 5, 2017, 5:06 PM
 */

#include "staticlib/config/span.hpp"

#include <cstring>
#include <array>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

#include "staticlib/config/assert.hpp"

namespace sc = staticlib::config;

bool throws_exc(std::function<void() > fun) {
    try {
        fun();
    } catch (const sc::bad_span_access_exception& e) {
        (void) e;
        return true;
    }
    return false;
}

void test_chars() {
    std::array<char, 3> buf;
    buf[0] = 'b';
    buf[1] = 'a';
    buf[2] = 'r';
    auto sp = sc::make_span(buf);
    
    std::string res1;
    for(char ch : sp) {
        res1.push_back(ch);
    }
    slassert("bar" == res1);
    
    std::string res2;
    res2.resize(3);
    std::memcpy(std::addressof(res2.front()), sp.data(), sp.size());
    slassert("bar" == res2);
    
    std::string res3;
    res3.push_back(sp[0]);
    res3.push_back(sp[1]);
    res3.push_back(sp[2]);
    slassert("bar" == res3);
}

void test_throws() {
    bool caught_null = throws_exc([] { sc::make_span<char>(nullptr, 42); });
    slassert(caught_null);
    
    auto str = std::string("foo");
    bool caught_negative = throws_exc([&str] { sc::make_span(str.data(), -1); });
    slassert(caught_negative);

    auto sp = sc::make_span(str.data(), str.length());
    bool caught_idx = throws_exc([&sp] { sp[3]; });
    slassert(caught_idx);
}

void test_elems() {
    std::array<std::pair<int, int>, 2> buf;
    buf[0] = { 41, 42 };
    buf[1] = { 43, 44 };
    auto sp = sc::make_span(buf);
    std::vector<int> res;
    for (auto& pa : sp) {
        res.push_back(pa.first);
        res.push_back(pa.second);
    }
    slassert(4 == res.size());
    slassert(41 == res[0]);
    slassert(42 == res[1]);
    slassert(43 == res[2]);
    slassert(44 == res[3]);
}

void test_const() {
    std::array<char, 3> buf;
    buf[0] = 'b';
    buf[1] = 'a';
    buf[2] = 'r';
    sc::span<const char> sp(buf);
    (void) sp;
    
    std::vector<char> vec;
    vec.push_back('b');
    vec.push_back('a');
    vec.push_back('r');
    sc::span<const char> sp1(vec);
    (void) sp1;
    
}

int main() {
    try {
        test_chars();
        test_throws();
        test_elems();
        test_const();
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
        return 1;
    }
    return 0;
}

