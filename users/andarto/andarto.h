#pragma once

#ifndef ANDARTO
#define ANDARTO

#include "quantum.h"

#if defined(UNICODEMAP_ENABLE)
#    include "unicode.h"
#endif

#define LAYOUT_preonic_grid_wrapper(...)    LAYOUT_preonic_grid(__VA_ARGS__)
#define LAYOUT_planck_grid_wrapper(...)    LAYOUT_planck_grid(__VA_ARGS__)

#define _________________NUMBER_L1_________________        KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define _________________NUMBER_R1_________________        KC_6,    KC_7,    KC_8,    KC_9,    KC_0

#define ______NUMBER_B13______                             DE_1,    DE_2,    DE_3
#define ______NUMBER_B46______                             DE_4,    DE_5,    DE_6
#define ______NUMBER_B46______                             DE_4,    DE_5,    DE_6
#define ______NUMBER_B79______                             DE_7,    DE_8,    DE_9
#define ______NUMBER_B00______                             _______, DE_0, _______

#define _________________SYMBOL_L1_________________        KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC
#define _________________SYMBOL_R1_________________        KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN

#define _________________QWERTY_L1_________________        DE_Q,    DE_W,    DE_E,    DE_R,    DE_T
#define _________________QWERTY_L2_________________        DE_A,    DE_S,    DE_D,    DE_F,    DE_G
#define _________________QWERTY_L3_________________        DE_Z,    DE_X,    DE_C,    DE_V,    DE_B

#define _________________QWERTY_R1_________________        DE_Y,    DE_U,    DE_I,    DE_O,    DE_P
#define _________________QWERTY_R2_________________        DE_H,    DE_J,    DE_K,    DE_L,    DE_SCLN
#define _________________QWERTY_R3_________________        DE_N,    DE_M,    DE_COMM, DE_DOT,  DE_SLSH

#define _________________QWERTZ_L3_________________        DE_Y,    DE_X,    DE_C,    DE_V,    DE_B
#define _________________QWERTZ_R1_________________        DE_Z,    DE_U,    DE_I,    DE_O,    DE_P

#define _________________KAYNEO_L1_________________        DE_K,    DE_DOT,  DE_A,    DE_COMM, DE_Y
#define _________________KAYNEO_L2_________________        DE_H,    DE_O,    DE_E,    DE_I,    DE_U
#define _________________KAYNEO_L3_________________        DE_Z,    DE_Q,    N_HS,    DE_X,    DE_SLSH

#define _________________KAYNEO_R1_________________        DE_P,    DE_D,    DE_L,    DE_M,    DE_J
#define _________________KAYNEO_R2_________________        DE_G,    DE_T,    DE_R,    DE_N,    DE_S
#define _________________KAYNEO_R3_________________        DE_B,    DE_C,    DE_W,    DE_V,    DE_F

#define __________________GAME_L1__________________        KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define __________________GAME_L2__________________        DE_Q,    DE_W,    DE_E,    DE_R,    DE_T
#define __________________GAME_L3__________________        DE_A,    DE_S,    DE_D,    DE_F,    DE_G
#define __________________GAME_L4__________________        DE_Z,    DE_X,    DE_C,    DE_V,    KC_SPC

#define __________________GAME_R1__________________        KC_6,    KC_7,    KC_8,    KC_9,    KC_0
#define __________________GAME_R2__________________        DE_Y,    DE_U,    DE_I,    DE_O,    DE_P
#define __________________GAME_R3__________________        DE_H,    DE_J,    DE_K,    DE_L,    DE_SCLN
#define __________________GAME_R4__________________        DE_B,    DE_N,    DE_M,    DE_COMM, DE_DOT

#define __________________SYMB_L1__________________        N_DEGRE, N_COLN,  N_LSQBR, N_RSQBR, N_DLR
#define __________________SYMB_L2__________________        N_BSLS,  N_SLSH,  N_LCUBR, N_RCUBR, N_ASTR
#define __________________SYMB_L3__________________        N_GRAVE, N_DLR,   N_PIPE,  N_TILD,  N_HASH

#define __________________SYMB_R1__________________        N_EXKL,  N_LT,    N_GT,    N_EQ,    N_AMP
#define __________________SYMB_R2__________________        N_QUES,  N_LPARN, N_RPARN, N_MINS,  N_PLUS
#define __________________SYMB_R3__________________        N_AT,    N_QUOT,  N_SING,  N_USC,   N_PERC

#define __________________NAVI_L1__________________        QK_LOCK, KC_PGUP, KC_UP,   KC_PGDN,  _______
#define __________________NAVI_L2__________________        KC_HOME, KC_LEFT, KC_DOWN, KC_RIGHT, KC_END
#define __________________NAVI_L3__________________        KC_UNDO, _______, OK_CTP,  OK_CPP,   KC_APP

#define __________________NAVI_R1__________________        DE_SLSH, DE_7,    DE_8,  DE_9,    DE_MINS
#define __________________NAVI_R2__________________        DE_ASTR, DE_4,    DE_5,  DE_6,    DE_PLUS
#define __________________NAVI_R3__________________        DE_0,    DE_1,    DE_2,  DE_3,    DE_DOT
#define __________________NAVI_R4__________________        _______, _______, DE_0,  _______, DE_COMM

#define __________________PROG_L1__________________        _______, N_COLN,  COLCOM,  N_SEMI,   _______
#define __________________PROG_L2__________________        _______, _______, SHVAR,   GOCUBR,   _______
#define __________________PROG_L3__________________        _______, _______, _______, HOMESLSH, CWDTAB

#define __________________PROG_R1__________________        _______, _______, PLUSEQ,  COLEQ,   MINUSEQ
#define __________________PROG_R2__________________        _______, SHCMD,   _______, _______, _______
#define __________________PROG_R3__________________        _______, _______, _______, _______, _______

#if defined(UNICODEMAP_ENABLE)
#define __________________LANG_L1__________________        _______, N_UNIDOT, N_AE,   _______, _______
#define __________________LANG_L2__________________        N_HBULL, N_OE,     N_EURO, _______, N_UE
#define __________________LANG_L3__________________        _______, _______,  N_EAC,  _______, _______

#define __________________LANG_R1__________________        N_PARA,  _______, _______, N_NEQ,   N_MU
#define __________________LANG_R2__________________        N_IRONY, N_TBULL, _______, N_EMDSH, N_SS
#define __________________LANG_R3__________________        N_CROSS, N_YESNO, _______, _______, DE_COMM
#define __________________LANG_R4__________________        N_VSPC,  _______, N_ARRLF, N_ARRDN, N_ARRUP, N_ARRRT
#endif

#define __________________OSM_L2___________________        OS_LGUI, OS_LALT, OS_LCTL, OS_LSFT, _______
#define __________________OSM_L3___________________        _______, _______, OS_HYPR, OS_MEH,  _______

#define __________________OSM_R2___________________        _______, OS_RSFT, OS_RCTL, OS_RALT,  OS_RGUI
#define __________________OSM_R3___________________        _______, OS_MEH,  OS_HYPR, _______, _______

#define ____________FUNCTION_1____________                 KC_F1,   KC_F2,   KC_F3,   KC_F4
#define ____________FUNCTION_2____________                 KC_F5,   KC_F6,   KC_F7,   KC_F8
#define ____________FUNCTION_3____________                 KC_F9,   KC_F10,  KC_F11,  KC_F12

#define ___SQBRACKETS___                                   KT_LBRC, KT_RBRC
#define _____PARENS_____                                   KC_LPRN, KC_RPRN
#define ____CRBRACES____                                   KC_LCBR, KC_RCBR
#define ___ANBRACKETS___                                   KC_LT,   KC_GT

#define KC_SFTENT MT(MOD_LSFT, KC_ENT)

#endif
