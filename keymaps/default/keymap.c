// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H


enum layer_names {
    _QWERTY_DEFAULT,
    _QWERTY_CODE,
    _QWERTY_FUNC,
    _GAMING,
};
enum combos {
    GAME
};

const uint16_t PROGMEM game_combo[] = {KC_F1,KC_F2,KC_F3, COMBO_END};
combo_t key_combos[] = {
    COMBO(game_combo, TO(3))
};

// Tap Dance Declaration
enum tap_dance {
    TD_PARENTHESIS,
    TD_GAMING_BUTTON
};

tap_dance_action_t tap_dance_actions[] = {
    // Tap once for (, twice for )
    [TD_PARENTHESIS] = ACTION_TAP_DANCE_DOUBLE(KC_LPRN, KC_RPRN),
    [TD_GAMING_BUTTON] = ACTION_TAP_DANCE_DOUBLE(KC_V, KC_B),
};
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY_DEFAULT] = LAYOUT(
      
        QK_GESC, KC_1, KC_2,   KC_3,   KC_4,   KC_5,                  KC_6,   KC_7,   KC_8,     KC_9,   KC_0,    KC_BSPC,
        KC_TAB,  KC_Q, KC_W,   KC_E,   KC_R,   KC_T,                  KC_Y,   KC_U,   KC_I,     KC_O,   KC_P,    KC_BSLS,
        LCTL_T(KC_LGUI), KC_A, KC_S,   KC_D,   KC_F, KC_G,            KC_H,   KC_J,   KC_K,     KC_L,   KC_SCLN, KC_ENTER,
        KC_LSFT, KC_Z, KC_X,   KC_C,   KC_V,   KC_B,          KC_N,   KC_M,   KC_COMMA, KC_DOT, KC_SLSH, KC_RSFT,  
                                       LT(1,KC_BSPC), KC_SPACE,       KC_SPACE, LT(1,KC_BSPC)  
    ),

    [_QWERTY_CODE] = LAYOUT(
        QK_GESC, _______,_______,_______,_______,_______,             _______, _______, _______, _______, _______, KC_DEL,
        KC_TAB,  _______,_______,_______,_______,_______,             KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, TD(TD_PARENTHESIS), KC_QUOTE,
        MO(_QWERTY_FUNC),_______,_______,_______,_______,_______,     _______, _______, _______, _______, KC_SCLN, MO(_QWERTY_FUNC),
        KC_LCTL, _______,_______,_______,_______,_______,             _______, _______, _______, _______, _______, KC_RCTL,  
                                       KC_LSFT, KC_SPACE,             KC_SPACE,KC_RSFT  
    ),

    [_QWERTY_FUNC] = LAYOUT( 
        KC_F1,    KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,              KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11, KC_F12,
        KC_ENTER, _______,_______,_______,_______,_______,            _______,   KC_PGUP,   KC_UP,   KC_PGDN, _______, KC_PSCR,
        KC_LALT,  _______,_______,_______,_______,_______,            _______,   KC_LEFT,   KC_DOWN, KC_RIGHT, _______, _______,
        KC_LGUI,  _______,_______,_______,_______,_______,            _______,   _______,   _______,   _______, _______, TT(1),  
                                              KC_LSFT, KC_SPACE,      KC_SPACE, KC_RSFT  
    ),
    [_GAMING] = LAYOUT( 
        KC_ESC,   KC_F1,   KC_1,   KC_2,   KC_3,   KC_4,               XXXXXXX,   XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_ENTER, KC_TAB,  KC_Q,   KC_W,   KC_E,   KC_R,               XXXXXXX,   XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_LALT,  KC_G,    KC_A,   KC_S,   KC_D,   KC_F,               XXXXXXX,   XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_LCTL,  KC_LSFT, KC_Z,   KC_X,   KC_C,   KC_V,               XXXXXXX,   XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  
                             TD(TD_GAMING_BUTTON), KC_SPACE,           XXXXXXX,   XXXXXXX  
    )  
};



#ifdef OLED_ENABLE

static void render_logo(void) {
    static const char PROGMEM siva_logo[] = {// 'sivaicon(1)', 32x28px
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0xf0, 0xf8, 0xfc, 0xfe, 0x7f, 
0x7f, 0xfe, 0xfc, 0xf8, 0xf0, 0xe0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x06, 0x87, 0xc7, 0xe7, 0xf7, 0xff, 0x03, 0x01, 0x00, 0x00, 
0xc0, 0xe0, 0xf1, 0xfb, 0xff, 0xff, 0x7f, 0xbf, 0xdf, 0xee, 0xf4, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0x7f, 0x3f, 0x1f, 0x0f, 0x07, 0x03, 0x00, 0x00, 0x00, 0x00, 
0xdf, 0xef, 0xf7, 0xfb, 0xfd, 0x7e, 0x3f, 0x1f, 0x0f, 0x07, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x0f, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

    oled_write_raw_P(siva_logo, sizeof(siva_logo));
}

/* 32 * 32 os logos */
static const char PROGMEM windows_logo[] = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0xf8, 0xf8, 0xf8, 0xfc, 0xfc, 0xfc, 0x00, 0xfc, 0xfc, 
0xfc, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfb, 0xfb, 0xfb, 0xfb, 0xfb, 0xfb, 0xfb, 0x00, 0xfb, 0xfb, 
0xfb, 0xfb, 0xfb, 0xfb, 0xfb, 0xfb, 0xfb, 0xfb, 0xfb, 0xfb, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x07, 0x07, 0x07, 0x0f, 0x0f, 0x0f, 0x00, 0x0f, 0x0f, 
0x0f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x3f, 0x3f, 0x3f, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

static const char PROGMEM mac_logo[] = {};

static void print_status(void) {
    /* Print current mode */
    oled_set_cursor(0, 0);
    
    render_logo();

    oled_set_cursor(0, 5);

    /* Print current layer */
    oled_write("LAYER", false);

    oled_set_cursor(0, 6);

    switch (get_highest_layer(layer_state)) {
        case _QWERTY_DEFAULT:
            oled_write("BASE", false);
            break;
        case _QWERTY_CODE:
            oled_write("CODE", false);
            break;
        case _QWERTY_FUNC:
            oled_write("FUNC", false);
            break;
        case _GAMING:
            oled_write("GAME", false);
            break;
        default:
            oled_write("Undef", false);
    }
    oled_set_cursor(0,9);
    oled_write_raw_P(windows_logo, sizeof(windows_logo));
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_270; }
bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status();
    } else {
      oled_set_cursor(0,5);
      render_logo();
    }
    return false;
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
