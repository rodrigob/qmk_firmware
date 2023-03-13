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


// ??
#define TAPPING_FORCE_HOLD

// default tapping term of 200 feels off
// #define TAPPING_TERM 200
// Using DYNAMIC_TAPPING_TERM_ENABLE to fix the timing
#define TAPPING_TERM 150


// retro tapping: pressing and releasing a taphold key super slow, 
// always triggers the underlying key.
// See https://github.com/qmk/qmk_firmware/blob/master/docs/tap_hold.md#retro-tapping
#define RETRO_TAPPPING

// we keep QUICK_TAP_TERM to default TAPPING_TERM to enable repeating of held keys
// (important for HJKL keys)
// See https://github.com/qmk/qmk_firmware/blob/master/docs/tap_hold.md#retro-tapping

// We use permissive hold to make it easy to have long tapping_term,
// and to long hold keys like SHIFT or CTRL while we type the combo
// See https://github.com/qmk/qmk_firmware/blob/master/docs/tap_hold.md#permissive-hold
#define PERMISSIVE_HOLD

// Ignore mod tap interrupt is key to handling well long presses for the tap-hold keys,
// it makes permissive_hold apply to mod keys too.
// See https://github.com/qmk/qmk_firmware/blob/master/docs/tap_hold.md#ignore-mod-tap-interrupt
#define IGNORE_MOD_TAP_INTERRUPT



