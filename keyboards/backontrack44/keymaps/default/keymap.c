// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
//#include "keymap_german.h"
#include "sendstring_german.h"


enum layers {
    _ADNW,
    _PROG,
    _NAVI,
    _SPECIAL,
};


#define M_PROG MO(_PROG)
#define M_NAVI MO(_NAVI)

// define M_SPECIAL = M_NAVI + M_PROG
layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _NAVI, _PROG, _SPECIAL);
}



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
        KC_TAB,      KC_K,       KC_U,       DE_UDIA,    KC_DOT,     DE_ADIA,                KC_V,       KC_G,       KC_C,    KC_L,    KC_J,    KC_F,
        M_PROG,      KC_H,       KC_I,       KC_E,       KC_A,       KC_O,                   KC_D,       KC_T,       KC_R,    KC_N,    KC_S,    M_PROG,
        KC_LSFT,     KC_X,       KC_Y,       DE_ODIA,    KC_COMMA,   KC_Q,                   KC_B,       KC_P,       KC_W,    KC_M,    KC_Z,    KC_RSFT,
                                 KC_LCTL,    KC_LGUI,    M_NAVI,     KC_SPC,                 KC_ENT,     M_NAVI,     M_PROG,  KC_LALT,
                                                         KC_1,       KC_2,                   KC_3,       KC_4
    ),

    [_PROG] = LAYOUT_split_3x6_4_2(
        KC_ESC,      _______, KC_UNDERSCORE, KC_LBRC,    KC_RBRC,    KC_CIRC,                KC_EXLM,    KC_LT,      KC_GT,   KC_EQL,     KC_AMPR, KC_BSPC,
        _______,     KC_BSLS, KC_SLASH,      KC_LCBR,    KC_RCBR,    KC_ASTR,                KC_QUES,    KC_LPRN,    KC_RPRN, KC_MINUS,   KC_COLON,KC_AT,
        _______,     KC_HASH, KC_DOLLAR,     KC_PIPE,    KC_TILDE,   KC_GRAVE,               KC_PLUS,    KC_PERC,    KC_DQUO, KC_QUOTE,   KC_SCLN, _______,
                                 _______,    _______,    _______,    _______,                _______,    _______,    _______, _______,
                                                         _______,    _______,                _______,    _______
    ),

    [_NAVI] = LAYOUT_split_3x6_4_2(
        KC_ESC,      KC_PAGE_UP, KC_BSPC,    KC_UP,      KC_DEL,     KC_PAGE_DOWN,           _______,    KC_7,       KC_8,    KC_9,    KC_PLUS, KC_BSPC,
        _______,     KC_HOME,    KC_LEFT,    KC_DOWN,    KC_RIGHT,   KC_END,                 _______,    KC_4,       KC_5,    KC_6,    KC_DOT,  _______,
        _______,     KC_ESC,     KC_TAB,     KC_INSERT,  KC_ENT,     KC_UNDO,                _______,    KC_1,       KC_2,    KC_3,    KC_SCLN, _______,
                                 _______,    _______,    _______,    _______,                KC_0,       _______,    _______, _______,
                                                         _______,    _______,                _______,    _______
    ),

    [_SPECIAL] = LAYOUT_split_3x6_4_2(
        KC_MUTE,     KC_MPLY,    KC_MPRV,    KC_MNXT,    KC_VOLU,    KC_VOLD,                _______,    DM_REC1,    DM_REC2, _______,  _______, _______,
        _______,     _______,    _______,    _______,    _______,    _______,                _______,    DM_PLY1,    DM_PLY2, _______,  _______, _______,
        _______,     _______,    _______,    _______,    _______,    _______,                _______,    _______,    _______, _______,  _______, _______,
                                 _______,    _______,    _______,    _______,                _______,    _______,    _______, _______,
                                                         _______,    _______,                _______,    _______
    )
};


