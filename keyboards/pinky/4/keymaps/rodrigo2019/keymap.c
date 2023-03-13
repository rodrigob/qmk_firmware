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
KC_GRV,     KC_1,     KC_2,     KC_3,     KC_4,     KC_5,                  KC_6,                      KC_7,     KC_8,     KC_9,     KC_0,  KC_MINS,   KC_EQL,    KC_BSPC,
KC_TAB,     KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,               KC_LBRC,                   KC_RBRC,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,    KC_BSLS,
KC_ESC,     KC_A,     KC_S,     KC_D,     KC_F,     KC_G,  KC_LPRN,                          KC_RPRN,      KC_H,     KC_J,     KC_K,     KC_L,  KC_SCLN,    KC_ENTER,
KC_LSFT,     KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,              MO(LOWER),               MO(LOWER),     KC_N,     KC_M,  KC_COMM,   KC_DOT,  KC_SLSH,  KC_QUOT,
 KC_LGUI,   KC_LALT, LSFT_T(KC_SPC), KC_LCTL,                                                      KC_RCTL, RSFT_T(KC_SPC), KC_RALT,   KC_APP
    ),
    [_LOWER] = LAYOUT(
       KC_TRNS,    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,     KC_MSTP,  KC_MRWD,  KC_MFFD,  KC_MPLY,  KC_VOLD,  KC_VOLU,   KC_DEL,
       KC_TRNS,    KC_F7,    KC_F8,    KC_F9,   KC_F10,   KC_F11,   KC_F12,    _______,  KC_HOME,  KC_PGDN,  KC_PGUP,   KC_END,   KC_INS, _______,
      _______, _______, _______, _______, _______, _______, _______,    _______,  KC_LEFT,  KC_DOWN,    KC_UP,  KC_RGHT, _______, _______,
       // _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
       DT_PRNT, DT_UP, DT_DOWN, KC_LGUI, KC_APP, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
                                   _______, _______, _______, _______,    _______, _______, _______, _______
    ),
    [_RAISE] = LAYOUT(
      _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
                                   _______, _______, _______, _______,    _______, _______, _______, _______
    ),
    [_ADJUST] = LAYOUT(
      _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
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


// See https://github.com/qmk/qmk_firmware/blob/master/docs/tap_hold.md#ignore-mod-tap-interrupt for context
bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case  LSFT_T(KC_SPC):
            // Do not force the mod-tap key press to be handled as a modifier
            // if any other key was pressed while the mod-tap key is held down.
            return false;
        case RSFT_T(KC_SPC):
            return false;
        default:
            // Force the dual-role key press to be handled as a modifier if any
            // other key was pressed while the mod-tap key is held down.
            return true;
    }
}
