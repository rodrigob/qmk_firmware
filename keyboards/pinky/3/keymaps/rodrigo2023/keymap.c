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
#include QMK_KEYBOARD_H

enum layer_names {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST
};

enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    LOWER,
    RAISE,
    ADJUST
};

#define CTL_TAB CTL_T(KC_TAB)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
		KC_GRV , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_LBRC,                KC_RBRC, KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_BSPC,
        KC_ESC, KC_A   , ALT_T(KC_S)   , CTL_T(KC_D)   , SFT_T(KC_F)   , KC_G   , KC_LPRN,    KC_RPRN, KC_H   , SFT_T(KC_J)   , CTL_T(KC_K)   , ALT_T(KC_L)   , KC_SCLN, KC_ENT,
        KC_LSFT, KC_Z   , ALGR_T(KC_X)   , KC_C   , KC_V   , KC_B   , MO(LOWER) ,   MO(RAISE) , KC_N   , KC_M   , KC_COMM, ALGR_T(KC_DOT) , KC_SLSH, KC_QUOT ,
                                   //KC_LALT, LOWER  , KC_LGUI, KC_SPC ,    KC_SPC , KC_RGUI, RAISE  , KC_RALT
                                   _______, _______  , _______, _______ ,   KC_ENT , SFT_T(KC_SPC), _______  , _______
    ),
    [_LOWER] = LAYOUT(
       KC_TRNS,    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,     KC_MSTP,  KC_MRWD,  KC_MFFD,  KC_MPLY,  KC_VOLD,  KC_VOLU,   KC_DEL,
       KC_TRNS,    KC_F7,    KC_F8,    KC_F9,   KC_F10,   KC_F11,   KC_F12,    _______,  KC_LEFT,  KC_DOWN,    KC_UP,  KC_RGHT, _______, _______,
       DT_PRNT,    DT_UP,  DT_DOWN,  _______,  _______,  _______,  _______,    _______,  KC_HOME,  KC_PGDN,  KC_PGUP,   KC_END,   KC_INS, _______,
                                     _______, _______, _______, _______,    _______, _______, _______, _______
    ),
    [_RAISE] = LAYOUT(
        KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , _______,    _______, KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_BSLS,
        _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, KC_MINS, KC_EQL , _______,
        _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
                                   _______, _______, _______, _______,    _______, _______, _______, _______
    ),
    [_ADJUST] = LAYOUT(
        _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_LCBR,    KC_RCBR, KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , _______,
        _______, KC_F11 , KC_F12 , _______, _______, _______, KC_LCBR,    KC_RCBR, KC_HOME, KC_PGDN, KC_PGUP, KC_END , _______, _______,
        _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
                                   _______, _______, _______, _______,    _______, _______, _______, _______
    )
};

const key_override_t 
	shift_bspc_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL), // shift+backspace becomes delete
	shift_lprn_override = ko_make_basic(MOD_MASK_SHIFT, KC_LPRN, KC_LABK), // shift+( becomes <
	shift_rprn_override = ko_make_basic(MOD_MASK_SHIFT, KC_RPRN, KC_RABK); // shift+) becomes >

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
	&shift_bspc_override,
	&shift_lprn_override,
	&shift_rprn_override,
	NULL // Null terminate the array of overrides!
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        // set_timelog();
    }

    switch (keycode) {
        case LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
            break;
        case RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
            break;
        case ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return false;
            break;
    }
    return true;
}
