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

// We use Switch German keyboard layout,
// because it covers all the symbols we need
// and matches the physical keyboard of some of my laptops,
// thus reducing the layouts switch.
// (Had started with French Bepo,
// however older Androids seem not support this layout.)

#include "keymap_swiss_de.h"
#include "sendstring_swiss_de.h"


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
    L_AL, // Alpha
    L_ALPHA,
    L_COMMANDS,
    L_SYMBOLS,
    L_NUMFN,
    L_MOTION,
    L_LOWER,
    L_RAISE,
    L_EMPTY,
    // v2 layers
    L_DI, // Diacritics
    L_SA, // Symbols A
    L_SB, // Symbols B
    L_NU, // Numbers
    L_FN,
    L_MO, // Motion
};

enum custom_keycodes {
    K_NTILDE = SAFE_RANGE, // n tilde is not part of bepo, we thus use a macro that sends tilde+n
    K_IEXLM, // inverted exclamation mark is not part of swiss_de, we use a macro
    K_IQUES, // inverted question mark is not part of swiss_de, we use a macro
    K_ESZ, // ß Eszett
};

#define NEXT_TAB C(KC_TAB)
#define PREV_TAB S(C(KC_TAB))
#define NEXT_WIN A(KC_TAB)
#define PREV_WIN S(A(KC_TAB))
#define SHOW_WINS G(KC_F5)
#define CTL_C C(CH_C)
#define CTL_V C(CH_V)
#define LT_DI(K) LT(L_DI, K)
#define LT_SA(K) LT(L_SA, K)
#define LT_SB(K) LT(L_SB, K)
#define LT_NU(K) LT(L_NU, K)
#define LT_FN(K) LT(L_FN, K)
#define LT_MO(K) LT(L_MO, K)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [L_AL] = LAYOUT(
	CH_GRV,  CH_Q,        LT_NU(CH_W),  LT_SA(CH_E), LT_SB(CH_R), CH_T,        CH_LBRC,           CH_RBRC,     CH_Y,        LT_SB(CH_U), LT_SA(CH_I), LT_NU(CH_O),    CH_P,          KC_BSPC,
        KC_ESC,  LT_FN(CH_A), ALT_T(CH_S),  CTL_T(CH_D), LT_DI(CH_F), SFT_T(CH_G),  CH_LPRN,           CH_RPRN,    SFT_T(CH_H), LT_DI(CH_J),  CTL_T(CH_K), ALT_T(CH_L),    LT_FN(KC_ENT), KC_ENT,
        KC_LSFT, CH_Z,        ALGR_T(CH_X), CH_C,        LT_MO(CH_V), CH_B,        MO(L_LOWER),       MO(L_RAISE), CH_N,        LT_MO(CH_M), CH_COMM,     ALGR_T(CH_DOT), CH_MINS,       CH_QUOT,
          _______, LT(L_NUMFN, KC_TAB), LT(L_SYMBOLS, KC_ESC), LT(L_NUMFN, KC_TAB),       LT(L_COMMANDS, KC_BSPC), SFT_T(KC_SPC), LT(L_COMMANDS, KC_BSPC), _______
    ),
    [L_ALPHA] = LAYOUT(
	CH_GRV, CH_Q,          CH_W,        CH_E,        CH_R, CH_T, CH_LBRC,               CH_RBRC, CH_Y,        CH_U,        CH_I,        CH_O,   CH_P, KC_BSPC,
        KC_ESC, CH_A,   ALT_T(CH_S), CTL_T(CH_D), SFT_T(CH_F), CH_G, CH_LPRN,               CH_RPRN, CH_H, SFT_T(CH_J), CTL_T(CH_K), ALT_T(CH_L), KC_ENT,  KC_ENT,
        KC_LSFT, CH_Z, ALGR_T(CH_X),        CH_C,        CH_V, CH_B, MO(L_LOWER),       MO(L_RAISE), CH_N,        CH_M,  CH_COMM, ALGR_T(CH_DOT), CH_MINS, CH_QUOT,

          _______, LT(L_NUMFN, KC_ESC), LT(L_SYMBOLS, CH_E), LT(L_NUMFN, KC_ESC),       LT(L_COMMANDS, KC_BSPC), SFT_T(KC_SPC), LT(L_COMMANDS, KC_BSPC), _______
    ),

     [L_NU] = LAYOUT(
       _______,    KC_PPLS, KC_P7, KC_P8, KC_9, KC_PEQL,  _______,       _______, CH_COMM, KC_P7, KC_P8, KC_9, KC_PPLS, _______,
       _______,    KC_P0,   KC_P4, KC_P5, KC_P6, KC_PDOT, _______,       _______, KC_P0,   KC_P4, KC_P5, KC_P6, KC_PEQL,   _______,
       _______,    KC_PMNS, KC_P1, KC_P2, KC_P3, CH_COMM, _______,       _______, KC_PDOT, KC_P1, KC_P2, KC_P3, KC_PMNS, _______,
                               _______, _______, _______, _______,       _______, _______, _______, _______ 
    ),

  
    //  diacritics on left side: Circumflex,Grave,Two overdots/Diaeresis,Acute,Tilde, (lower row: Cedilla); right side mirrored
    [L_COMMANDS] = LAYOUT(
		    // UTF8 will draw the symbols but will not generate the dead diacritics as desired.
        _______, CH_CIRC,       CH_GRV,       CH_DIAE,       CH_ACUT, CH_TILD, _______,      _______, CH_TILD,       CH_ACUT,       CH_DIAE,       CH_GRV, CH_CIRC, _______,
        _______, KC_LGUI, OSM(MOD_LALT), OSM(MOD_LCTL), OSM(MOD_LSFT),  KC_TAB, _______,      _______,  KC_TAB, OSM(MOD_LSFT), OSM(MOD_LCTL), OSM(MOD_LALT), KC_LGUI, _______,
        _______, KC_APP,  OSM(MOD_RALT),       CH_CCED,       _______, _______, _______,      _______, _______,       KC_VOLD,       KC_VOLU, OSM(MOD_RALT), KC_APP, _______,
                                              // _______, KC_DELETE, KC_BSPC, KC_DELETE,      _______, _______, _______, _______ // handles Enter+Esc and Enter+E
                                           _______, DF(L_MOTION), KC_BSPC, DF(L_MOTION),      _______, _______, _______, _______ // handles Enter+Esc and Enter+E
    ),

    [L_DI] = LAYOUT(
        _______, CH_CIRC, CH_GRV, CH_DIAE, CH_ACUT, CH_TILD, _______,      _______, CH_TILD,  CH_ACUT, CH_DIAE, CH_GRV, CH_CIRC, _______,
        _______, KC_LGUI, KC_LEFT, KC_DOWN,    KC_UP,   KC_RGHT, _______,      _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_LGUI, _______,
        _______, KC_APP,  K_ESZ, CH_CCED, K_NTILDE,  KC_TAB,  _______,      _______, KC_TAB,  K_NTILDE,  CH_CCED, K_ESZ, KC_APP,  _______,
                                   _______, _______, KC_SPC, _______,      _______, _______, _______, _______ 
    ),

    [L_SYMBOLS] = LAYOUT(
        _______, CH_CIRC, CH_PERC, CH_ASTR, CH_PLUS,   CH_EXLM, _______,       _______, CH_QUES, CH_MINS, CH_SLSH,  CH_EQL,   CH_AT, _______,
        _______, CH_LABK, CH_RABK, CH_LCBR, CH_RCBR,   CH_AMPR, _______,       _______, CH_PIPE, CH_LPRN, CH_RPRN, CH_LBRC, CH_RBRC, _______,
        _______, CH_BSLS, CH_TILD, CH_SLSH, CH_UNDS,    CH_DLR, _______,       _______,  KC_TAB, CH_DQUO, CH_QUOT,  CH_GRV, CH_HASH, _______,
                                     _______, _______, _______, _______,       KC_BSPC, _______,  KC_BSPC, _______  // handles E+Enter),
  ),

    [L_SA] = LAYOUT(
	// Exception to rule of symmetric left and right hands
        _______, CH_RABK, CH_RCBR, CH_RPRN, CH_RBRC, CH_EXLM, _______,       _______, X(IEXLM), CH_RBRC, CH_RPRN, CH_RCBR, CH_RABK, _______,
        _______, CH_LABK, CH_LCBR, CH_LPRN, CH_LBRC, CH_QUES, _______,       _______, X(IQUES), CH_LBRC, CH_LPRN, CH_LCBR, CH_LABK, _______,
        _______, CH_BSLS,  CH_TILD, CH_SLSH, CH_UNDS, CH_DLR,  _______,       _______,  CH_DLR, CH_UNDS, CH_SLSH, CH_TILD, CH_BSLS, _______,
                                   _______, _______, _______, _______,      _______, _______, _______, _______ 
   ),

    [L_SB] = LAYOUT(
        _______, CH_PERC, CH_AT,   CH_PIPE, CH_AMPR, CH_CIRC, _______,       _______, CH_CIRC, CH_AMPR, CH_PIPE, CH_AT,   CH_PERC, _______,
        _______, CH_SLSH, CH_ASTR, CH_MINS, CH_PLUS, CH_EQL,  _______,       _______, CH_EQL,  CH_PLUS, CH_MINS, CH_ASTR, CH_SLSH, _______,
        _______, CH_HASH, CH_GRV,  CH_QUOT, CH_DQUO, KC_TAB,  _______,       _______, KC_TAB,  CH_DQUO, CH_QUOT, CH_GRV,  CH_HASH, _______,
                                     _______, _______, _______, _______,      _______, _______, _______, _______ 
    ),

    [L_NUMFN] = LAYOUT(
        _______, KC_F1,    KC_F2,         KC_F3,    KC_F4,   KC_F5, _______,    _______,        KC_F6,   KC_F7,       KC_F8,   KC_F9, KC_F10, _______,
      //_______,  CH_1,     CH_2,   CTL_T(CH_3),     CH_4,    CH_5, _______,    _______,         CH_6,    CH_7, CTL_T(CH_8),    CH_,   CH_0, _______,
      //_______, KC_F11, _______,        CH_DOT,  CH_COMM, _______, _______,    _______,      KC_LEFT, KC_DOWN,       KC_UP, KC_RGHT, KC_F12, _______,
        _______, KC_F11, _______, CTL_T(CH_DOT),  CH_COMM, _______, _______,    _______,      KC_LEFT, KC_DOWN,       KC_UP, KC_RGHT, KC_F12, _______,
        _______,  CH_1,     CH_2,          CH_3,     CH_4,    CH_5, _______,    _______,         CH_6,    CH_7,        CH_8,    CH_9,   CH_0, _______,
                                    //_______,  _______, _______, _______,    _______,    KC_DELETE, _______, KC_DELETE // handles Esc+Enter
                                      _______,  _______, _______, _______,    _______, DF(L_MOTION), _______, DF(L_MOTION) // handles Esc+Enter
    ),

    [L_FN] = LAYOUT(
        _______, KC_F1, KC_F2,  KC_F3,  KC_F4,  KC_MPLY, _______,    _______, KC_MPLY, KC_F1, KC_F2,  KC_F3,  KC_F4,  _______,
        _______, KC_F5, KC_F6,  KC_F7,  KC_F8,  KC_VOLU, _______,    _______, KC_VOLU, KC_F5, KC_F6,  KC_F7,  KC_F8,  _______,
        _______, KC_F9, KC_F10, KC_F11, KC_F12, KC_VOLD, _______,    _______, KC_VOLD, KC_F9, KC_F10, KC_F11, KC_F12, _______,          
                              _______, _______, _______, _______,    _______, _______, _______, _______
    ),

    [L_MOTION] = LAYOUT(
       _______,    KC_PPLS,  KC_P7, KC_P8, KC_P9, KC_PMNS, _______,       _______,  KC_MRWD, KC_VOLD, KC_VOLU, KC_MFFD, KC_MPLY, _______,
       _______,    KC_PDOT,  KC_P4, KC_P5, KC_P6,   KC_P0, _______,       _______,  KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, _______, _______,
       _______,    KC_PSLS,  KC_P1, KC_P2, KC_P3, KC_PAST, _______,       _______,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______,
                         _______, DF(L_ALPHA), _______, DF(L_ALPHA),       _______, _______, _______, _______
    ),

    [L_MO] = LAYOUT( 
       _______, SHOW_WINS, PREV_WIN, PREV_TAB, NEXT_TAB, NEXT_WIN, _______,      _______, PREV_WIN, PREV_TAB, NEXT_TAB, NEXT_WIN, SHOW_WINS, _______,
       _______, CTL_C,     KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  _______,      _______, KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  CTL_C,     _______,
       _______, CTL_V,     KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,   _______,      _______, KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,   CTL_V,     _______,
                                        _______, _______, _______, _______,      _______, _______, _______, _______
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
        CH_GRV , CH_1   , CH_2   , CH_3   , CH_4   , CH_5   , _______,    _______, CH_6   , CH_7   , CH_8   , CH_9   , CH_0   , CH_BSLS,
        _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, CH_MINS, CH_EQL , _______,
        _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
                                   _______, _______, _______, _______,    _______, _______, _______, _______
    ),
};

const key_override_t 
	shift_bspc_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL), // shift+backspace becomes delete
	shift_lbspc_override = ko_make_basic(MOD_MASK_SHIFT, LT(L_COMMANDS, KC_BSPC), KC_DEL), // shift+layer backspace becomes delete
	//shift_lprn_override = ko_make_basic(MOD_MASK_SHIFT, CH_LPRN, CH_LABK), // shift+( becomes <
	shift_lprn_override = ko_make_basic(MOD_MASK_SHIFT, CH_LPRN, KC_LT), // shift+( becomes <
	//shift_rprn_override = ko_make_basic(MOD_MASK_SHIFT, CH_RPRN, CH_RABK), // shift+) becomes >
	shift_rprn_override = ko_make_basic(MOD_MASK_SHIFT, CH_RPRN, KC_GT), // shift+) becomes >
	// ko_make_basic(...) does not work with X(...) thus we must use macros
	shift_exml_override = ko_make_basic(MOD_MASK_SHIFT, CH_EXLM, K_IEXLM), // shift+! becomes ¡
	//shift_exml_override = ko_make_basic(MOD_MASK_SHIFT, CH_EXLM, X(IEXLM)), // shift+! becomes ¡
	shift_ques_override = ko_make_basic(MOD_MASK_SHIFT, CH_QUES, K_IQUES), // shift+? becomes ¿
	//shift_ques_override = ko_make_basic(MOD_MASK_SHIFT, CH_QUES, X(IQUES)), // shift+? becomes ¿
	shift_dollar_override = ko_make_basic(MOD_MASK_SHIFT, CH_DLR, X(EURO)), // shift+$ becomes €
        // mimic swiss qwertz
	shift_comma_override = ko_make_basic(MOD_MASK_SHIFT, CH_COMM, CH_SCLN), // shift+, becomes ;
	shift_dot_override = ko_make_basic(MOD_MASK_SHIFT, CH_DOT, CH_COLN), // shift+. becomes :
	shift_lalt_dot_override = ko_make_basic(MOD_MASK_SHIFT, ALGR_T(CH_DOT), CH_COLN), // shift+. becomes : too
	shift_mins_override = ko_make_basic(MOD_MASK_SHIFT, CH_MINS, CH_UNDS), // shift+-, becomes _
	//shift_mmns_override = ko_make_basic(MOD_MASK_SHIFT, CH_MMNS, CH_UNDS), // shift+-, becomes _ too
	// Shift volume up/down = move forward/backwards 
	shift_vold_override = ko_make_basic(MOD_MASK_SHIFT, KC_VOLD, KC_MRWD), // shift+volume down becomes rewind media
	shift_volu_override = ko_make_basic(MOD_MASK_SHIFT, KC_VOLU, KC_MFFD); // shift+volume up becomes forward media


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
	&shift_mins_override,
	//&shift_mmns_override,
	&shift_vold_override,
	&shift_volu_override,
	NULL // Null terminate the array of overrides!
};

// Thumb key combos
// COMBO_TERM defaults to 50ms, which means simultaneous hit
// in practice Backspace and Delete are best accessed via E+something,
// thus best implemented via the layers

const uint16_t PROGMEM combo_e_enter[] = {CH_E, KC_ENTER, COMBO_END};
const uint16_t PROGMEM combo_esc_enter[] = {KC_ESC, KC_ENTER, COMBO_END};
const uint16_t PROGMEM combo_rwd_ffd[] = {KC_MRWD, KC_MFFD, COMBO_END};
const uint16_t PROGMEM combo_vold_volu[] = {KC_VOLD, KC_VOLU, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
// backspace/delete combos not needed, since available in the alpha layer.
    //COMBO(combo_e_enter, KC_BACKSPACE),
    //COMBO(combo_esc_enter, KC_DELETE), 
    COMBO(combo_rwd_ffd, KC_MPLY),  // Rewind+Foward=Play
    COMBO(combo_vold_volu, KC_MPLY),  // Volume Up+Down=Play
};


uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SFT_T(KC_SPC):
            return g_tapping_term - 50; // rather speedy since used everywhere
        default:
	    return g_tapping_term;
    }
}



bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        // set_timelog();
    }

    switch (keycode) {
	    case K_NTILDE:
		    if(record->event.pressed) {
		      // CH_TILD + n, CH_TILD ALGR(CH_CIRC) 
		      // CH_CIRC == KC_EQL
		      //SEND_STRING(SS_ALGR(X_KC_EQL) "n");
		      //SEND_STRING(SS_ALGR(X_KC_EQL) "n");
		      //SEND_STRING("ñ");
		      send_unicode_string("ñ");
		    }
		    break;

	    case K_IEXLM: 
		    if(record->event.pressed) {
		      //SEND_STRING("¡");
		      send_unicode_string("¡");
		    }
		    // [IEXLM] = 0x00A1, // ¡
		    break;

	    case K_IQUES: 
		    if(record->event.pressed) {
		      //SEND_STRING("¿");
		      send_unicode_string("¿");
		    // [IQUES] = 0x00BF, // ¿
		    }
		    break;
	    case K_ESZ:
		    // ß Eszett
		    SEND_STRING(SS_ALGR(X_S));
		    break;

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

