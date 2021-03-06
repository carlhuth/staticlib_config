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
 * File:   noexcept.hpp
 * Author: alex
 *
 * Created on November 21, 2015, 6:40 PM
 */

#ifndef STATICLIB_CONFIG_NOEXCEPT_HPP
#define	STATICLIB_CONFIG_NOEXCEPT_HPP

// http://stackoverflow.com/a/18387764/314015
#if !defined(_MSC_VER) || _MSC_VER >= 1900
#define STATICLIB_NOEXCEPT noexcept
#define STATICLIB_NOEXCEPT_FALSE noexcept(false)
#define STATICLIB_NOEXCEPT_SUPPORTED
#else
#define STATICLIB_NOEXCEPT
#define STATICLIB_NOEXCEPT_FALSE
#endif // _MSC_VER

#endif	/* STATICLIB_CONFIG_NOEXCEPT_HPP */

