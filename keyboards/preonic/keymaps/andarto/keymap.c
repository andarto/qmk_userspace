/* Copyright 2019-2021 Andarto
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
#include <keymap_german.h>
#include <sendstring_german.h>
#include "andarto.h"
#include "version.h"

extern keymap_config_t keymap_config;

enum preonic_layers {
  _QWERTY,
  _KAYNEO,
  _SYMB,
  _NAVI,
  _LANG,
  _FUNC,
  _PROG,
  _OSM,
  _ADJUST
};

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  KAYNEO,
  LA_SYMB,
  LA_NAVI,
  LA_LANG,
  LA_FUNC,
  LA_OSM,
  COLEQ,
  PLUSEQ,
  MINUSEQ,
  HOMESLSH,
  CWDTAB,
  SHCMD,
  SHVAR,
  COLCOM,
  GOCUBR,
  OK_CPP,
  OK_CTP,
  KB_MAKE,
  KB_VRSN
};

#define N_LT KC_NONUS_BACKSLASH
#define N_HS KC_NONUS_HASH
#define N_DOTS RALT(KC_DOT)          // …
#define N_USC LSFT(KC_SLASH)         // _
#define N_LSQBR RALT(KC_8)           // [
#define N_RSQBR RALT(KC_9)           // ]
#define N_CIRC KC_GRAVE              // ^
#define N_EXKL LSFT(KC_1)            // !
#define N_PARA LSFT(KC_3)            // §
#define N_GT LSFT(KC_NONUS_BACKSLASH) // >
#define N_EQ LSFT(KC_0)              // =
#define N_AMP LSFT(KC_6)             // &
#define N_BSLS RALT(KC_MINS)         // \ backslash
#define N_SLSH LSFT(KC_7)            // /
#define N_LCUBR RALT(KC_7)           // {
#define N_RCUBR RALT(KC_0)           // }
#define N_ASTR LSFT(KC_RBRC)         // *
#define N_QUES LSFT(KC_MINS)         // ?
#define N_LPARN LSFT(KC_8)           // (
#define N_RPARN LSFT(KC_9)           // )
#define N_MINS KC_SLASH              // -
#define N_COLN LSFT(KC_DOT)          // :
#define N_HASH KC_BACKSLASH          // #
#define N_DLR LSFT(KC_4)             // $
#define N_PIPE RALT(KC_NONUS_BACKSLASH) // |
#define N_TILD RALT(KC_RBRC)         // ~
#define N_GRAVE LSFT(KC_EQUAL)       // `
#define N_PLUS KC_RBRC               // +
#define N_PERC LSFT(KC_5)            // %
#define N_QUOT LSFT(KC_2)            // "
#define N_SING LSFT(KC_BACKSLASH)    // '
#define N_SEMI LSFT(KC_COMM)         // ;
#define N_EURO RALT(KC_E)            // €
#define N_AT RALT(KC_Q)              // @
#define N_Z KC_Y
#define N_Y KC_Z
#define N_AE KC_QUOTE                // ä
#define N_OE KC_SEMICOLON            // ö
#define N_UE KC_LEFT_BRACKET         // ü
#define N_MU RALT(KC_M)              // µ
#define N_SS KC_MINS                 // ß
#define N_DEGRE LSFT(KC_GRAVE)       // °
#define N_PASTE LCTL(KC_V)           // CTRL+V
#define N_COPY LCTL(KC_C)            // CTRL+C
#define N_CUT LCTL(KC_X)             // CTRL+X
#define N_UNDO LCTL(N_Z)             // CTRL+Z

#define LA_SYMB MO(_SYMB)
#define LA_NAVI MO(_NAVI)
#define LA_LANG MO(_LANG)
#define LA_FUNC MO(_FUNC)
#define LA_OSM MO(_OSM)

#undef UNICODE_KEY_LNX
#define UNICODE_KEY_LNX LCTL(LSFT(DE_U))

// for one key copy paste macro
uint32_t ok_cp_timer = 0;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* empty grid for copying
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
*/

/* Qwerty
 * ,-------------------------------------------------------------------------------------------------------------------------------.
 * | Esc         |    1    |    2    |    3    |    4    |    5    |    6    |    7    |    8    |    9    |    0    | Bksp        |
 * | LA_LANG     |    Q    |    W    |    E    |    R    |    T    |    Y    |    U    |    I    |    O    |    P    | LA_LANG/Del |
 * | LA_SYMB/Tab |    A    |    S    |    D    |    F    |    G    |    H    |    J    |    K    |    L    |    ;    | LA_SYMB/Ent |
 * | Shift/App   |    Z    |    X    |    C    |    V    |    B    |    N    |    M    |    ,    |    .    |    /    | Shift/Ent   |
 * | LCtrl       |   GUI   |   LAlt  | LA_OSM  | LA_NAVI |       Space       | LA_NAVI | LA_OSM  |   RAlt  | LA_FUNC | RCtrl       |
 * `-------------------------------------------------------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_preonic_grid_wrapper(
    KC_ESC,            _________________NUMBER_L1_________________,  _________________NUMBER_R1_________________, KC_BSPC,
    LA_LANG,           _________________QWERTY_L1_________________,  _________________QWERTY_R1_________________, LT(_LANG, KC_DEL),
    LT(_SYMB, KC_TAB), _________________QWERTY_L2_________________,  _________________QWERTY_R2_________________, LT(_SYMB, KC_ENT),
    LSFT_T(KC_APP),    _________________QWERTY_L3_________________,  _________________QWERTY_R3_________________, KC_SFTENT,
    KC_LCTL,           KC_LGUI, KC_LALT, LA_OSM,  LA_NAVI,  KC_SPC,  KC_SPC, LA_NAVI,  LA_OSM,  QK_REP,  LA_FUNC, KC_RCTL
),

/* KayNeo (adapted)
 * ,-------------------------------------------------------------------------------------------------------------------------------.
 * | Esc         |    1    |    2    |    3    |    4    |    5    |    6    |    7    |    8    |    9    |    0    | Bksp        |
 * | LA_LANG     |    K    |    .    |    A    |    ,    |    Y    |    P    |    D    |    L    |    M    |    J    | LA_LANG/Del |
 * | LA_SYMB/Tab |    H    |    O    |    E    |    I    |    U    |    G    |    T    |    R    |    N    |    S    | LA_SYMB/Ent |
 * | Shift/App   |    Z    |    Q    |    #    |    X    |    /    |    B    |    C    |    W    |    V    |    F    | Shift/Ent   |
 * | LCtrl       |   LWin  |   LAlt  | LA_OSM  | LA_NAVI |       Space       | LA_NAVI | LA_OSM  |   RAlt  | LA_FUNC | RCtrl       |
 * `-------------------------------------------------------------------------------------------------------------------------------'
 */
[_KAYNEO] = LAYOUT_preonic_grid_wrapper(
    KC_ESC,            _________________NUMBER_L1_________________,  _________________NUMBER_R1_________________, KC_BSPC,
    LA_LANG,           _________________KAYNEO_L1_________________,  _________________KAYNEO_R1_________________, LT(_LANG, KC_DEL),
    LT(_SYMB, KC_TAB), _________________KAYNEO_L2_________________,  _________________KAYNEO_R2_________________, LT(_SYMB, KC_ENT) ,
    LSFT_T(KC_APP),    _________________KAYNEO_L3_________________,  _________________KAYNEO_R3_________________, KC_SFTENT,
    KC_LCTL,           KC_LGUI, KC_LALT, LA_OSM,  LA_NAVI,  KC_SPC,  KC_SPC, LA_NAVI,  LA_OSM,  QK_REP,  LA_FUNC, KC_RCTL
),

/* KayNeo: Symbols
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |   ^  |   °  |   :  |   [  |   ]  |   $  |   !  |   <  |   >  |   =  |   &  |      |
 * |      |   \  |   /  |   {  |   }  |   *  |   ?  |   (  |   )  |   -  |   +  |      |
 * |      |   `  |   $  |   |  |   ~  |   #  |   @  |   "  |   '  |   _  |   %  |      |
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_SYMB] = LAYOUT_preonic_grid_wrapper(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    N_CIRC,  __________________SYMB_L1__________________, __________________SYMB_R1__________________, _______,
    _______, __________________SYMB_L2__________________, __________________SYMB_R2__________________, _______,
    _______, __________________SYMB_L3__________________, __________________SYMB_R3__________________, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* KayNeo: Navigation
 * ,-----------------------------------------------------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  | DEL  |
 * | NUML |      | PGUP |  UP  | PGDN |      |   /  |   7  |   8  |   9  |   -  |      |
 * |      | HOME | LEFT | DOWN | RGHT | END  |   *  |   4  |   5  |   6  |   +  |      |
 * |      | UNDO | CUT  | COPY | PSTE | APP  |   0  |   1  |   2  |   3  |   .  |      |
 * |      |      |      |      |      |      |      |      |   0  |      |   ,  |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NAVI] = LAYOUT_preonic_grid_wrapper(
    KC_LNUM, KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,   KC_F6,   KC_F7,   KC_F8, KC_F9,   KC_F10,   KC_DEL,
    _______, __________________NAVI_L1__________________, __________________NAVI_R1__________________, _______,
    _______, __________________NAVI_L2__________________, __________________NAVI_R2__________________, _______,
    _______, __________________NAVI_L3__________________, __________________NAVI_R3__________________, _______,
    _______, _______, _______, _______, _______, _______, __________________NAVI_R4__________________, _______
),

/* KayNeo: Programming (NAVI + SYMB) shortcuts/macros (| denotes cursor position)
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |      |      | : |, |      |      |      |      |      |  +=  |  :=  |  -=  | DEL  |
 * |      |      |      | ${|} | go{|}|      |      | $(|) |      |      |      |      |
 * |      |      |      |      |  ~/  |  ./  |      |      |      |      |      |      |
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

[_PROG] = LAYOUT_preonic_grid_wrapper(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, __________________PROG_L1__________________, __________________PROG_R1__________________, KC_DEL,
    _______, __________________PROG_L2__________________, __________________PROG_R2__________________, _______,
    _______, __________________PROG_L3__________________, __________________PROG_R3__________________, _______,
    _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______
),

/* KayNeo: language specific shortcuts
 */
#if defined(UNICODEMAP_ENABLE)
[_LANG] = LAYOUT_preonic_grid_wrapper(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, __________________LANG_L1__________________, __________________LANG_R1__________________, KC_DEL,
    _______, __________________LANG_L2__________________, __________________LANG_R2__________________, _______,
    _______, __________________LANG_L3__________________, __________________LANG_R3__________________, _______,
    _______, _______, _______, _______, _______, _______, __________________LANG_R4__________________
),
#endif

/* KayNeo: function keys
 */
[_FUNC] = LAYOUT_preonic_grid_wrapper(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_INS,
    _______, KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  _______,
    _______, KC_F21,  KC_F22,  KC_F23,  KC_F24,  _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* KayNeo: user space one shot home row mods
 */
[_OSM] = LAYOUT_preonic_grid_wrapper(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, __________________OSM_L2___________________, __________________OSM_R2___________________, _______,
    _______, __________________OSM_L3___________________, __________________OSM_R3___________________, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* KayNeo: Adjust (NAVI + LANG)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |MUSmod|Aud on|Audoff|AGnorm|AGswap|Qwerty|KayNeo|      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|TermOn|TermOf|UCMod |UCMLNX|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_preonic_grid_wrapper(
    _______, KB_VRSN,   KB_MAKE,          _______, _______,  _______, _______, _______, _______, _______, _______, KC_DEL,
    _______, QK_BOOT,   QK_DEBUG_TOGGLE,  RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, KC_DEL,
    _______, _______,   MU_TOGG,          AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  KAYNEO,  _______, _______, _______,
    _______, QK_REBOOT, _______,          MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, UC_NEXT, UC_LINX, _______,
    _______, _______,   _______,          _______, _______, _______, _______, _______, _______,  _______, _______, _______
)

};


#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
  state = update_tri_layer_state(state, _NAVI, _LANG, _ADJUST);
  state = update_tri_layer_state(state, _SYMB, _NAVI, _PROG);
  return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case COLEQ:
      if (record->event.pressed) {
          SEND_STRING(":=");
      }
      return false;
    case MINUSEQ:
      if (record->event.pressed) {
          SEND_STRING("-=");
      }
      return false;
    case PLUSEQ:
      if (record->event.pressed) {
          SEND_STRING("+=");
      }
      return false;
    case HOMESLSH:
      if (record->event.pressed) {
          SEND_STRING("~/");
      }
      return false;
    case CWDTAB:
      if (record->event.pressed) {
          SEND_STRING("./" SS_TAP(X_TAB));
      }
      return false;
    case SHCMD:
      if (record->event.pressed) {
          SEND_STRING("$()" SS_TAP(X_LEFT));
      }
      return false;
    case SHVAR:
      if (record->event.pressed) {
          SEND_STRING("${}" SS_TAP(X_LEFT));
      }
      return false;
    case COLCOM:
      if (record->event.pressed) {
          SEND_STRING(": ," SS_TAP(X_LEFT));
      }
      return false;
    case GOCUBR:
      if (record->event.pressed) {
          SEND_STRING("{}" SS_TAP(X_LEFT) SS_TAP(X_ENTER) SS_TAP(X_TAB) SS_TAP(X_ENTER) SS_TAP(X_UP) SS_TAP(X_END));
      }
      return false;
    case KB_MAKE:
      if (!record->event.pressed) {
        SEND_STRING("make " QMK_KEYBOARD ":" QMK_KEYMAP SS_TAP(X_ENTER));
      }
      return false;
    case KB_VRSN:
      if (!record->event.pressed) {
        SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
    case KAYNEO:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_KAYNEO);
      }
      return false;
    case OK_CPP:
      if (record->event.pressed) {
        ok_cp_timer = timer_read32();
      } else {
        if (timer_elapsed32(ok_cp_timer) > TAPPING_TERM) {  // Hold, copy
          register_code(KC_LCTL);
          tap_code(KC_C);
          unregister_code(KC_LCTL);
        } else {  // Tap, paste
          register_code(KC_LSFT);
          tap_code(KC_INS);
          unregister_code(KC_LSFT);
        }
      }
      return false;
    case OK_CTP:
      if (record->event.pressed) {
        ok_cp_timer = timer_read32();
      } else {
        if (timer_elapsed32(ok_cp_timer) > TAPPING_TERM) {  // Hold, cut
          register_code(KC_LCTL);
          tap_code(KC_X);
          unregister_code(KC_LCTL);
        } else {  // Tap, paste
          register_code(KC_LSFT);
          tap_code(KC_INS);
          unregister_code(KC_LSFT);
        }
      }
      return false;
    default:
      return true;
  }
}

