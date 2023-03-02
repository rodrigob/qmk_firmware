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

//#define MASTER_LEFT
// #define MASTER_RIGHT
#define EE_HANDS

#define TAPPING_TERM 200
//#define RETRO_TAPPPING
// Let us try the Ferris approach 
#define PERMISSIVE_HOLD
#define IGNORE_MOD_TAP_INTERRUPT
#define QUICK_TAP_TERM 0

// manna-harbour_miryoku/config.h
// #define TAPPING_TERM 200

// Prevent normal rollover on alphas from accidentally triggering mods.
// #define IGNORE_MOD_TAP_INTERRUPT

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
// #define TAPPING_FORCE_HOLD


// Auto Shift
// #define NO_AUTO_SHIFT_ALPHA
// #define AUTO_SHIFT_TIMEOUT TAPPING_TERM
// #define AUTO_SHIFT_NO_SETUP

// ferris/keymaps/default/config.h
// #define PERMISSIVE_HOLD
// #define IGNORE_MOD_TAP_INTERRUPT
// #define QUICK_TAP_TERM 0

