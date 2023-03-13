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

// The keyboard is linux only, because it was easiest way to get things going
// (If this becomes a problem, migth have to convert to use BEPO keyboard keys as plan B)
#define UNICODE_SELECTED_MODES UNICODE_MODE_LINUX


// keymap.c uses 2 combos
// #define COMBO_COUNT 2
// IMPORTANT: if combo count is incorrect, the keyboard will missbehave.
// #define COMBO_COUNT 0
#define COMBO_COUNT 2


// We use tap hold for mods in main layer,
// we use there them only for "slow tiping" we have an extra layers
// for fast commands.
#define TAPPING_TERM 200

// Space/Shift key is handled much faster than all other keys
#define TAPPING_TERM_PER_KEY


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


// Let us try the Ferris approach 
// #define PERMISSIVE_HOLD
// #define IGNORE_MOD_TAP_INTERRUPT
//#define QUICK_TAP_TERM 0

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

