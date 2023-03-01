/* Copyright 2018 'Masayuki Sunahara'
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

//#define USE_MATRIX_I2C

/* Select hand configuration */

// #define MASTER_LEFT
// #define MASTER_RIGHT
#define EE_HANDS

#define TAPPING_FORCE_HOLD
// default tapping term of 200 feels off
// #define TAPPING_TERM 200
// Using DYNAMIC_TAPPING_TERM_ENABLE to fix the timing
#define TAPPING_TERM 200

// See https://github.com/qmk/qmk_firmware/blob/master/docs/tap_hold.md#ignore-mod-tap-interrupt
// #define IGNORE_MOD_TAP_INTERRUPT
// See get_hold_on_other_key_press(...) in keymap.c
// #define HOLD_ON_OTHER_KEY_PRESS_PER_KEY


// See https://github.com/qmk/qmk_firmware/blob/master/docs/tap_hold.md#retro-tapping
#define RETRO_TAPPPING
