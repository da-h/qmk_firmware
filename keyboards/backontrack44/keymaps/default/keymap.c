// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "keymap_german.h"
// #include "sendstring_german.h"


enum layers {
    _ADNW,
    _SHIFT,
    _PROG,
    _NAVI,
    _SPECIAL,
};


#define M_PROG MO(_PROG)
#define M_NAVI MO(_NAVI)
#define M_LSFT LM(_SHIFT, MOD_LSFT)
#define M_RSFT LM(_SHIFT, MOD_RSFT)

// define M_SPECIAL = M_NAVI + M_PROG
layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _NAVI, _PROG, _SPECIAL);
}

#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD  

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │Tab│ Q │ W │ E │ R │ T │       │ Y │ U │ I │ O │ P │Bsp│
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Ctl│ A │ S │ D │ F │ G │       │ H │ J │ K │ L │ ; │ ' │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Sft│ Z │ X │ C │ V │ B │       │ N │ M │ , │ . │ / │Sft│
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *
      *         ┌───┬───┬───┬───┐       ┌───┬───┬───┬───┐
      *         │Sft│ Z │ X │ B │       │ N │ . │ / │Sft│
      *         └───┴───┴───┴───┘       └───┴───┴───┴───┘
      * ─────────────────────────────────────────────────────────
      *                 ┌───┬───┐       ┌───┬───┐
      *        Mouse    │Sft│ B │       │ N │Sft│
      *                 └───┴───┘       └───┴───┘

      *
      */
    [_ADNW] = LAYOUT_split_3x6_4_2(
        KC_TAB,      DE_K,       DE_U,       DE_UDIA,    DE_DOT,     DE_ADIA,                DE_V,       DE_G,       DE_C,    DE_L,    DE_J,    DE_F,
        M_PROG,      DE_H,       DE_I,       DE_E,       DE_A,       DE_O,                   DE_D,       DE_T,       DE_R,    DE_N,    DE_S,    M_PROG,
        M_LSFT,      DE_X,       DE_Y,       DE_ODIA,    DE_COMM,    DE_Q,                   DE_B,       DE_P,       DE_W,    DE_M,    DE_Z,    M_RSFT,
                                 KC_LCTL,    KC_LGUI,    M_NAVI,     KC_SPC,                 KC_ENT,     M_NAVI,     M_PROG,  KC_LALT,
                                                         KC_1,       KC_2,                   KC_3,       KC_4
    ),

    [_SHIFT] = LAYOUT_split_3x6_4_2(
        _______,     _______,    _______,    _______,    _______,    _______,                _______,    _______,    _______, _______,  _______, _______,
        _______,     _______,    _______,    _______,    _______,    _______,                _______,    _______,    _______, _______,  _______, DE_SS,
        _______,     _______,    _______,    _______,    _______,    _______,                _______,    _______,    _______, _______,  _______, _______,
                                 _______,    _______,    _______,    _______,                _______,    _______,    _______, _______,
                                                         _______,    _______,                _______,    _______
    ),

    [_PROG] = LAYOUT_split_3x6_4_2(
        KC_ESC,      _______,    DE_UNDS,       DE_LBRC,    DE_RBRC,    DE_CIRC,                DE_EXLM,    DE_LABK,    DE_RABK, DE_EQL,     DE_AMPR, KC_BSPC,
        _______,     DE_BSLS,    DE_SLSH,       DE_LCBR,    DE_RCBR,    DE_ASTR,                DE_QUES,    DE_LPRN,    DE_RPRN, DE_MINS,    DE_COLN, DE_AT,
        _______,     DE_HASH,    DE_DLR,        DE_PIPE,    DE_TILD,    DE_GRV,                 DE_PLUS,    DE_PERC,    DE_DQUO, DE_QUOT,    DE_SCLN, _______,
                                 _______,       _______,    _______,    _______,                _______,    _______,    _______, _______,
                                                            _______,    _______,                _______,    _______
    ),

    [_NAVI] = LAYOUT_split_3x6_4_2(
        KC_ESC,      KC_PAGE_UP, KC_BSPC,    KC_UP,      KC_DEL,     KC_PAGE_DOWN,           _______,    KC_7,       KC_8,    KC_9,    KC_F23, KC_BSPC,
        _______,     KC_HOME,    KC_LEFT,    KC_DOWN,    KC_RIGHT,   KC_END,                 _______,    KC_4,       KC_5,    KC_6,    KC_F22, _______,
        _______,     KC_ESC,     KC_TAB,     KC_INSERT,  KC_ENT,     KC_UNDO,                _______,    KC_1,       KC_2,    KC_3,    KC_F21, _______,
                                 _______,    _______,    _______,    _______,                KC_0,       _______,    _______, _______,
                                                         _______,    _______,                _______,    _______
    ),

    [_SPECIAL] = LAYOUT_split_3x6_4_2(
        KC_MUTE,     KC_MPLY,    KC_MPRV,    KC_MNXT,    KC_VOLD,    KC_VOLU,                _______,    DM_REC1,    DM_REC2, _______,  _______, _______,
        _______,     _______,    _______,    _______,    _______,    _______,                _______,    DM_PLY1,    DM_PLY2, _______,  _______, _______,
        _______,     _______,    _______,    _______,    _______,    _______,                _______,    _______,    _______, _______,  _______, _______,
                                 _______,    _______,    _______,    _______,                _______,    _______,    _______, _______,
                                                         _______,    _______,                _______,    _______
    )
};


