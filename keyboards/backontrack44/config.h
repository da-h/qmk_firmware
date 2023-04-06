// Copyright 2023 David Hartmann (@da-h)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once


#define RGB_DI_PIN D3
#define RGBLED_SPLIT { 28, 28 }
#define RGBLED_NUM 56
#define RGBLIGHT_SPLIT
#define RGBLIGHT_LIMIT_VAL 221

#define USB_MAX_POWER_CONSUMPTION 400
#define RGBLIGHT_EFFECT_BREATHING
#define RGBLIGHT_EFFECT_KNIGHT
#define RGBLIGHT_EFFECT_RAINBOW_MOD
#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#define RGBLIGHT_EFFECT_STATIC_GRADIENT
#define RGBLIGHT_EFFECT_TWINKLE

/* -------- */
/* Features */
/* -------- */
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD  

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT



#define SPLIT_POINTING_ENABLE
#define POINTING_DEVICE_LEFT
// #define POINTING_DEVICE_COMBINED

#define CIRQUE_PINNACLE_POSITION_MODE CIRQUE_PINNACLE_ABSOLUTE_MODE
// #define CIRQUE_PINNACLE_POSITION_MODE CIRQUE_PINNACLE_RELATIVE_MODE
#define CIRQUE_PINNACLE_DIAMETER_MM 40
#define CIRQUE_PINNACLE_ADDR 0x2A
#define CIRQUE_PINNACLE_TAP_ENABLE
#define POINTING_DEVICE_GESTURES_SCROLL_ENABLE
#define POINTING_DEVICE_GESTURES_CURSOR_GLIDE_ENABLE
//
//
