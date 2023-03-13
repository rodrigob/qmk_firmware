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


// Accents short names from quantum/keymap_extras/keymap_bepo.h
enum unicode_names {
    BANG,
    IRONY,
    SNEK,
    //  diacritics on left side: Circumflex,Grave,Two overdots,Acute,Tilde, (lower row: Cedilla); right side mirrored
    DCIR, // ^ (dead)
    DGRV, // ` (dead)
    DIAE, // ¨ (dead) diaeresis	 
    ACUT, // ´ (dead)
    DTIL, // ~ (dead)
    CDEL, // ¸ (dead)
    // Additional punctuation https://www.compart.com/en/unicode/category/Po
    IEXLM, // ¡
    IQUES, // ¿
    // Additional currency symbols https://www.compart.com/en/unicode/category/Sc
    EURO,
};

const uint32_t unicode_map[] PROGMEM = {
    [BANG]  = 0x203D,  // ‽
    [IRONY] = 0x2E2E,  // ⸮
    [SNEK]  = 0x1F40D, // 🐍
    // UTF8 codes from Modifier Symbol category https://www.compart.com/en/unicode/category/Sk
    [DCIR] = 0x005E, // ^ (dead)
    [DGRV] = 0x0060, // ` (dead)
    [DIAE] = 0x00A8, // ¨ (dead)	 
    [ACUT] = 0x00B4, // ´ (dead)
    [DTIL] = 0x02DC, // ~ (dead)
    [CDEL] = 0x00B8, // ¸ (dead)
    // UTF8 from Other Punctuation category https://www.compart.com/en/unicode/category/Po
    [IEXLM] = 0x00A1, // ¡
    [IQUES] = 0x00BF, // ¿
    // UTF8 from Currency Symbol category https://www.compart.com/en/unicode/category/Sc
    [EURO] = 0x20AC, // €

};



enum layer_names {
    L_ALPHA,
    L_COMMANDS,
    L_SYMBOLS,
    L_NUMFN,
    L_MOTION,
    L_LOWER,
    L_RAISE,
    L_EMPTY
};

/*enum custom_keycodes {
    ALPHA = SAFE_RANGE,
    COMMANDS,
    SYMBOLS,
    NUMFN,
    MOTION,
    LOWER,
    RAISE,
    EMPTY
};*/

#define CTL_TAB CTL_T(KC_TAB)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [L_ALPHA] = LAYOUT(
	KC_GRV, KC_Q,          KC_W,        KC_E,        KC_R, KC_T, KC_LBRC,          KC_RBRC,   KC_Y,        KC_U,        KC_I,        KC_O,     KC_P, KC_BSPC,
     // KC_ESC, KC_A,   ALT_T(KC_S), CTL_T(KC_D), SFT_T(KC_F), KC_G, KC_LPRN,          KC_RPRN,   KC_H, SFT_T(KC_J), CTL_T(KC_K), ALT_T(KC_L),  KC_SCLN,  KC_ENT,
        KC_ESC, KC_A,   ALT_T(KC_S), CTL_T(KC_D), SFT_T(KC_F), KC_G, KC_LPRN,          KC_RPRN,   KC_H, SFT_T(KC_J), CTL_T(KC_K), ALT_T(KC_L),  KC_ENT,  KC_ENT,
     // KC_LSFT, KC_Z, ALGR_T(KC_X),        KC_C,        KC_V, KC_B, MO(L_LOWER) ,       MO(L_RAISE), KC_N,        KC_M, KC_COMMA, ALGR_T(KC_DOT),  KC_SLSH, KC_QUOT,
        KC_LSFT, KC_Z, ALGR_T(KC_X),        KC_C,        KC_V, KC_B, MO(L_LOWER) ,      MO(L_RAISE), KC_N,        KC_M, KC_COMMA, ALGR_T(KC_DOT), KC_MINUS, KC_QUOT,

             _______, LT(L_NUMFN, KC_ESC), LT(L_SYMBOLS, KC_E), LT(L_NUMFN, KC_ESC),       LT(L_COMMANDS, KC_BSPC), SFT_T(KC_SPC), LT(L_COMMANDS, KC_BSPC), _______
    ),
    
    //  diacritics on left side: Circumflex,Grave,Two overdots/Diaeresis,Acute,Tilde, (lower row: Cedilla); right side mirrored
    [L_COMMANDS] = LAYOUT(
        _______, X(DCIR),       X(DGRV),       X(DIAE),       X(ACUT), X(DTIL), _______,      _______, _______,       _______,       _______,       _______, _______, _______,
        _______, KC_LGUI, OSM(MOD_LALT), OSM(MOD_LCTL), OSM(MOD_LSFT),  KC_TAB, _______,       _______,  KC_TAB, OSM(MOD_LSFT), OSM(MOD_LCTL), OSM(MOD_LALT), KC_LGUI, _______,
        _______, KC_APP,  OSM(MOD_RALT),       KC_MRWD,       KC_MFFD, X(CDEL), _______,      _______, _______,       KC_VOLD,       KC_VOLU, OSM(MOD_RALT), KC_APP, _______,
                                              // _______, KC_DELETE, KC_BSPC, KC_DELETE,      _______, _______, _______, _______ // handles Enter+Esc and Enter+E
                                           _______, DF(L_MOTION), KC_BSPC, DF(L_MOTION),      _______, _______, _______, _______ // handles Enter+Esc and Enter+E
    ),

    [L_SYMBOLS] = LAYOUT(
        _______, KC_CIRCUMFLEX,  KC_PERC,  KC_ASTR, KC_PLUS,   KC_EXLM, _______,       _______, KC_QUES, KC_MINUS, KC_SLASH, KC_EQUAL,   KC_AT, _______,
        _______,         KC_LT,    KC_GT,  KC_LCBR, KC_RCBR,   KC_AMPR, _______,       _______, KC_PIPE,  KC_LPRN,  KC_RPRN,  KC_LBRC, KC_RBRC, _______,
        _______,  KC_BACKSLASH, KC_TILDE, KC_SLASH, KC_UNDS, KC_DOLLAR, _______,       _______,  KC_TAB,   KC_DQT, KC_QUOTE, KC_GRAVE, KC_HASH, _______,
                                             _______, _______, _______, _______,       KC_BSPC, _______,  KC_BSPC, _______  // handles E+Enter
    ),

    [L_NUMFN] = LAYOUT(
        _______, KC_F1,    KC_F2,       KC_F3,    KC_F4,   KC_F5, _______,    _______,        KC_F6,   KC_F7,       KC_F8,   KC_F9, KC_F10, _______,
        _______,  KC_1,     KC_2, CTL_T(KC_3),     KC_4,    KC_5, _______,    _______,         KC_6,    KC_7, CTL_T(KC_8),    KC_9,   KC_0, _______,
        _______, KC_F11, _______,      KC_DOT, KC_COMMA, _______, _______,    _______,      KC_LEFT, KC_DOWN,       KC_UP, KC_RGHT, KC_F12, _______,
                                    //_______,  _______, _______, _______,    _______,    KC_DELETE, _______, KC_DELETE // handles Esc+Enter
                                      _______,  _______, _______, _______,    _______, DF(L_MOTION), _______, DF(L_MOTION) // handles Esc+Enter
    ),

    [L_MOTION] = LAYOUT(
       _______,    KC_PPLS,  KC_P7, KC_P8, KC_P9, KC_PMNS, _______,       _______,  KC_MRWD, KC_VOLD, KC_VOLU, KC_MFFD, KC_MPLY, _______,
       _______,    KC_PDOT,  KC_P4, KC_P5, KC_P6,   KC_P0, _______,       _______,  KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, _______, _______,
       _______,    KC_PSLS,  KC_P1, KC_P2, KC_P3, KC_PAST, _______,       _______,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______,
                         _______, DF(L_ALPHA), _______, DF(L_ALPHA),       _______, _______, _______, _______
    ),

    [L_EMPTY] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
                                   _______, _______, _______, _______,    _______, _______, _______, _______
    ),


    [L_LOWER] = LAYOUT(
       KC_TRNS,    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,     KC_MSTP,  KC_MRWD,  KC_MFFD,  KC_MPLY,  KC_VOLD,  KC_VOLU,   KC_DEL,
       KC_TRNS,    KC_F7,    KC_F8,    KC_F9,   KC_F10,   KC_F11,   KC_F12,    _______,  KC_LEFT,  KC_DOWN,    KC_UP,  KC_RGHT, _______, _______,
       DT_PRNT,    DT_UP,  DT_DOWN,  _______,  _______,  _______,  _______,    _______,  KC_HOME,  KC_PGDN,  KC_PGUP,   KC_END,   KC_INS, _______,
                                     _______, _______, _______, _______,    _______, _______, _______, _______
    ),

    [L_RAISE] = LAYOUT(
        KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , _______,    _______, KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_BSLS,
        _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, KC_MINS, KC_EQL , _______,
        _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
                                   _______, _______, _______, _______,    _______, _______, _______, _______
    ),
};

const key_override_t 
	shift_bspc_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL), // shift+backspace becomes delete
	shift_lbspc_override = ko_make_basic(MOD_MASK_SHIFT, LT(L_COMMANDS, KC_BSPC), KC_DEL), // shift+layer backspace becomes delete
	shift_lprn_override = ko_make_basic(MOD_MASK_SHIFT, KC_LPRN, KC_LABK), // shift+( becomes <
	shift_rprn_override = ko_make_basic(MOD_MASK_SHIFT, KC_RPRN, KC_RABK), // shift+) becomes >
	shift_exml_override = ko_make_basic(MOD_MASK_SHIFT, KC_EXLM, X(IEXLM)), // shift+! becomes ¡
	shift_ques_override = ko_make_basic(MOD_MASK_SHIFT, KC_QUES, X(IQUES)), // shift+? becomes ¿
	shift_dollar_override = ko_make_basic(MOD_MASK_SHIFT, KC_DOLLAR, X(EURO)), // shift+$ becomes €
        // mimic swiss qwertz
	shift_comma_override = ko_make_basic(MOD_MASK_SHIFT, KC_COMMA, KC_SEMICOLON), // shift+, becomes ;
	shift_dot_override = ko_make_basic(MOD_MASK_SHIFT, KC_DOT, KC_COLON), // shift+. becomes :
	shift_lalt_dot_override = ko_make_basic(MOD_MASK_SHIFT, ALGR_T(KC_DOT), KC_COLON); // shift+. becomes : too

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
	&shift_bspc_override,
	&shift_lbspc_override,
	&shift_lprn_override,
	&shift_rprn_override,
	&shift_exml_override,
	&shift_ques_override,
	&shift_rprn_override,
	&shift_dollar_override,
	&shift_comma_override,
	&shift_dot_override,
	&shift_lalt_dot_override,
	NULL // Null terminate the array of overrides!
};

// Thumb key combos
// COMBO_TERM defaults to 50ms, which means simultaneous hit
// in practice Backspace and Delete are best accessed via E+something,
// thus best implemented via the layers

const uint16_t PROGMEM combo_e_enter[] = {KC_E, KC_ENTER, COMBO_END};
const uint16_t PROGMEM combo_esc_enter[] = {KC_ESC, KC_ENTER, COMBO_END};
const uint16_t PROGMEM combo_rwd_ffd[] = {KC_MRWD, KC_MFFD, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
// backspace/delete combos not needed, since available in the alpha layer.
    //COMBO(combo_e_enter, KC_BACKSPACE),
    //COMBO(combo_esc_enter, KC_DELETE), 
    COMBO(combo_rwd_ffd, KC_MPLY),  // Rewind+Foward=Play
};


uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SFT_T(KC_SPC):
            return 150; // rather speedy since used everywhere
        default:
#ifdef DYNAMIC_TAPPING_TERM_ENABLE
	    return g_tapping_term;
#elif
            return TAPPING_TERM;
#endif
    }
}



bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        // set_timelog();
    }

    switch (keycode) {
        /* case LOWER:
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
            break; */

    }
    return true;
}

void numlock_on(void) {
  // Based on https://github.com/qmk/qmk_firmware/issues/10890#issuecomment-927222187
  led_t led_state = host_keyboard_led_state();
  bool b = led_state.num_lock;
  if (!b) {
      register_code(KC_NUM_LOCK);
      unregister_code(KC_NUM_LOCK);
  }
}

// Functions called when keyboard starts
void keyboard_post_init_user() {
  numlock_on();
}

