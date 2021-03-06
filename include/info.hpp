/*
 * Copyright 2013 Matthew Harvey
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

#ifndef GUARD_info_hpp_6414792601212297
#define GUARD_info_hpp_6414792601212297

/// @file

#include "version_fwd.hpp"

namespace jewel
{

/**
 * Provides information about the Jewel library.
 */
class Info
{
public:

    /**
     * @returns a Version object representing the library version.
     *
     * Exception safety: <em>nothrow guarantee</em>.
     */
    static Version version();

    Info() = delete;
    Info(Info const& rhs) = delete;
    Info(Info&& rhs) = delete;
    Info& operator=(Info const& rhs) = delete;
    Info& operator=(Info&& rhs) = delete;
    ~Info() = delete;

};  // class Info

}  // namespace jewel

#endif  // GUARD_info_hpp_6414792601212297
