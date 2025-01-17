
// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// clang-format off
// Tap Dance
enum {
    TD_PAREN,
    TD_BRACK,
    TD_BRACE
};
tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_PAREN] = ACTION_TAP_DANCE_DOUBLE(KC_LPRN, KC_RPRN),
    [TD_BRACK] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_RBRC),
    [TD_BRACE] = ACTION_TAP_DANCE_DOUBLE(KC_LCBR, KC_RCBR)
};
// Layer names
enum layer_names {
    _QWERTY,
    _SYMBOLS,
    _FUNC
};
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT(

        QK_GESC,      KC_1,          KC_2,         KC_3,         KC_4,        KC_5,                KC_6,     KC_7,           KC_8,         KC_9,         KC_0,           KC_DEL,
        KC_TAB,       KC_Q,          KC_W,         KC_E,         KC_R,        KC_T,                KC_Y,     KC_U,           KC_I,         KC_O,         KC_P,           KC_BSLS,
        KC_ESC,       LSFT_T(KC_A),  LCTL_T(KC_S), LALT_T(KC_D), LGUI_T(KC_F),KC_G,                KC_H,     RGUI_T(KC_J),   RALT_T(KC_K), RCTL_T(KC_L), RSFT_T(KC_SCLN),KC_ENT,
        MO(_SYMBOLS), KC_Z,          KC_X,         KC_C,         KC_V,        KC_B,                KC_N,     KC_M,           KC_COMMA,     KC_DOT,       KC_SLSH,        MO(_FUNC),
                                                                 LT(_SYMBOLS, KC_BSPC),KC_SPACE,   KC_SPACE, LT(_FUNC, KC_BSPC)


    ),
    [_SYMBOLS] = LAYOUT(

        QK_GESC,     KC_1,          KC_2,         KC_3,         KC_4,        KC_5,                  KC_6,     KC_7,           KC_8,         KC_9,         KC_0,           _______,
        KC_TAB,      KC_Q,          KC_W,         KC_E,         KC_R,        KC_T,                  KC_Y,     KC_MINS,        KC_EQL,       KC_O,         KC_GRAVE,       KC_GRAVE,
        KC_ESC,      _______,       _______,      _______,      _______,     _______,               KC_H,     TD(TD_PAREN),   TD(TD_BRACK), TD(TD_BRACE), KC_QUOTE,       KC_ENT,
        _______,     _______,       _______,      _______,      _______,     _______,               KC_N,     KC_M,           KC_COMMA,     KC_DOT,       KC_SLSH,        _______,
                                                                _______,     _______,               _______,  _______
    ),

    [_FUNC] = LAYOUT(

        KC_F1,      KC_F2,         KC_F3,        KC_F4,        KC_F5,       KC_F6,                  KC_F7,      KC_F8,          KC_F9,        KC_F10,       KC_F11,        KC_F12,
        _______,    _______,       _______,      _______,      _______,     _______,                _______,    _______,        _______,      _______,      _______,       _______,
        _______,    _______,       _______,      _______,      _______,     _______,                KC_LEFT,    KC_DOWN,        KC_UP,        KC_RIGHT,     _______,       _______,
        _______,    _______,       _______,      _______,      _______,     _______,                _______,    _______,        _______,      _______,      _______,       _______,
                                                               _______,     _______,                _______,    _______
    )

};
// clang-format on
#ifdef RGBLIGHT_ENABLE
switch (get_highest_layer(layer_state)) {
    case _QWERTY:
        rgblight_setrgb_at(255, 0, 0, 0);
        break;

    case _FUNC:
        rgblight_setrgb_at(0, 255, 0, 0);
        break;

    case _SYMBOLS:
        rgblight_setrgb_at(0, 0, 255, 0);
        break;
}
#endif /* ifdef RGBLIGHT_ENABLE */
#ifdef OLED_ENABLE

static void render_logo(void) {
    static const char PROGMEM siva_logo[] = {// 'sivaicon(1)', 32x28px
                                             0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0xf0, 0xf8, 0xfc, 0xfe, 0x7f, 0x7f, 0xfe, 0xfc, 0xf8, 0xf0, 0xe0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x06, 0x87, 0xc7, 0xe7, 0xf7, 0xff, 0x03, 0x01, 0x00, 0x00, 0xc0, 0xe0, 0xf1, 0xfb, 0xff, 0xff, 0x7f, 0xbf, 0xdf, 0xee, 0xf4, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0x7f, 0x3f, 0x1f, 0x0f, 0x07, 0x03, 0x00, 0x00, 0x00, 0x00, 0xdf, 0xef, 0xf7, 0xfb, 0xfd, 0x7e, 0x3f, 0x1f, 0x0f, 0x07, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

    oled_write_raw_P(siva_logo, sizeof(siva_logo));
}

#endif

/*

                                                - -
                                              --- ---
                                            :---- ----:
                                           ------ ------
                                         -------- --------
                                       ---------- ----------
                                     ------------ ------------
                                   -------------- --------------
                                  --------------- ---------------
                                ----------------- -----------------
                              ------------------- -------------------
                            --------------------- ---------------------
                          ---------------------     ---------------------
                        :--------------------:       :--------------------:
                       ---------------------           ---------------------
                     ---------------------               ---------------------
                   ---------------------                   ---------------------
                 ---------------------                       ---------------------
               ---------------------                           ---------------------
                                                              ---------------------
                                  --                        ---------------------
                                ----                      ---------------------   --
                              ------                    ---------------------   ----
                            --------                  ---------------------   ------
                          :---------                :--------------------:  :-------
                         -----------               ---------------------   ---------
                       -------------              --------------------   -----------
                     ---------------              ------------------   -------------
                   -----------------              ----------------   ---------------
                 -------------------              --------------   -----------------
                --------------------              -------------   ------------------
               --------------------               -----------   ------------------
               ------------------                 ---------   ------------------
               ----------------                   -------   ------------------
               --------------                     -----   ------------------
               ------------:                      ---:  :-----------------:
               -----------                        --   ------------------
               ---------                             ------------------
               -------                             ------------------
               -----                              -----------------
               ---                                ---------------
               --                                 --------------
                                                  ------------
                                                  ----------
                                                  --------
                                                  ------
                                                  ----:
                                                  ---
                                                  -
consume.
enhance.
replicate.
                                                          */
