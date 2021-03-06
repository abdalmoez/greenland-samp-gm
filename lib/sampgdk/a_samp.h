/* Copyright (C) 2011-2013 Zeex
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

#ifndef SAMPGDK_A_SAMP_H
#define SAMPGDK_A_SAMP_H

#include <sampgdk/bool.h>
#include <sampgdk/compatibility.h>
#include <sampgdk/export.h>
#include <sampgdk/plugin.h>

typedef void (SAMPGDK_TIMER_CALL *TimerCallback)(int timerid, void *param);

#include <sampgdk/a_samp-decl.h>

#ifdef __cplusplus
  #include <sampgdk/a_samp.hpp>
#endif

#endif /* !SAMPGDK_A_SAMP_H */
