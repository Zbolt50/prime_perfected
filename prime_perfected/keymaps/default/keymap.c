// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

enum layer_names {
    _QWERTY_DEFAULT,
    _QWERTY_CODE,
    _GAMING,
};

#include QMK_KEYBOARD_H

#ifdef OLED_ENABLE

// Rotate OLED
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_90;  
}

// Draw to OLED
bool oled_task_user() {
    // Set cursor position
    oled_set_cursor(0, 1);
    
    // Write text to OLED
    oled_write("Hello World!", false);
    
    return false;
}

#endif
/*#ifdef OLED_ENABLE
bool oled_task_user(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case _QWERTY_DEFAULT:
            oled_write_P(PSTR("Default\n"), false);
            break;
        case _QWERTY_CODE:
            oled_write_P(PSTR("FN\n"), false);
            break;
        case _GAMING
            oled_write_P(PSTR("ADJ\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }
    return false;
}
#endif
*/
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT(
        QK_GESC, KC_1, KC_2,   KC_3,   KC_4,   KC_5,                  KC_6,   KC_7,   KC_8,   KC_9,   KC_0,    KC_BSPC,
        KC_TAB,  KC_Q, KC_W,   KC_E,   KC_R,   KC_T,                  KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,    KC_BSLS,
        KC_LSFT, KC_A, KC_S,   KC_D,   KC_F,   KC_G,                  KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN, KC_ENTER,
        KC_LCTL, KC_Z, KC_X,   KC_C,   KC_V,   KC_B,                  KC_N,   KC_M,   KC_COMMA, KC_DOT, KC_SLSH, KC_RCTL,  
                                       LT(1,KC_LSFT), KC_SPACE,       KC_SPACE, LT(1,KC_BSPC)  
    ),

    [1] = LAYOUT(
        QK_GESC, KC_F1,KC_F2,  KC_F3,  KC_F4,  KC_F5,                 KC_F6,     KC_F7,     KC_F8,    KC_F9,     KC_F10,  KC_PSCR,
        KC_TAB,  KC_Q, KC_W,   KC_E,   KC_R,   KC_T,                  KC_TILD,   KC_MINS,   KC_EQL,   KC_LBRC,   KC_RBRC, KC_RGUI,
        _______, KC_A, KC_S,   KC_D,   KC_F,   KC_G,                  KC_LEFT,   KC_RIGHT,   KC_UP,   KC_DOWN,   KC_SCLN, KC_ENTER,
        _______, KC_Z, KC_X,   KC_C,   KC_V,   KC_B,                  KC_N,      KC_M,   KC_COMMA, KC_DOT, KC_SCLN, KC_RCTL,  
                                       _______, TT(2),                KC_SPACE, _______  
    ),
            // Gaming Layer (TODO: Disable All keys on RIGHT half)
    [2] = LAYOUT( 
        KC_ESC,    KC_F1,   KC_1,   KC_2,   KC_3,   KC_4,               KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10, KC_PSCR,
        KC_ENTER,  KC_TAB,  KC_Q,   KC_W,   KC_E,   KC_R,               KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,    KC_BSLS,
        KC_LALT,  KC_LCTL, KC_A,   KC_S,   KC_D,   KC_F,                KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN, KC_ENTER,
        KC_LGUI,  KC_LSFT, KC_Z,   KC_X,   KC_C,   KC_V,                KC_N,   KC_M,   KC_COMMA, KC_DOT, KC_SCLN, KC_RCTL,  
                                           KC_B, KC_SPACE,              KC_SPACE, KC_BSPC  
    ) 
};

