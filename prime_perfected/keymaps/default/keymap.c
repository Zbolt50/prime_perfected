// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum combos {
    GAME
};

const uint16_t PROGMEM game_combo[] = {KC_F1,KC_F2,KC_F3,KC_F4, COMBO_END};
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

enum layer_names {
    _QWERTY_DEFAULT,
    _QWERTY_CODE,
    _QWERTY_FUNC,
    _GAMING,
};

#ifdef OLED_ENABLE
static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };

    oled_write_P(qmk_logo, false);
}

bool oled_task_user(void) {
    render_logo();
    return false;
}
#endif


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT(
        QK_GESC, KC_1, KC_2,   KC_3,   KC_4,   KC_5,                  KC_6,   KC_7,   KC_8,   KC_9,   KC_0,    KC_BSPC,
        KC_TAB,  KC_Q, KC_W,   KC_E,   KC_R,   KC_T,                  KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,    KC_BSLS,
        KC_LSFT, KC_A, KC_S,   KC_D,   KC_F,   KC_G,                  KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN, KC_ENTER,
        KC_LCTL, KC_Z, KC_X,   KC_C,   KC_V,   KC_B,                  KC_N,   KC_M,   KC_COMMA, KC_DOT, KC_SLSH, KC_RCTL,  
                                       LT(2,KC_BSPC), KC_SPACE,       KC_SPACE, LT(1,KC_BSPC)  
    ),

    [1] = LAYOUT(
        QK_GESC, _______,_______,_______,_______,_______,             _______, _______, _______, _______, _______, KC_DEL,
        KC_TAB,  _______,_______,_______,_______,_______,             KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, TD(TD_PARENTHESIS), KC_QUOTE,
        _______, _______,_______,_______,_______,_______,             KC_LEFT, KC_RIGHT,KC_UP,   KC_DOWN, KC_SCLN, KC_TILD,
        _______, _______,_______,_______,_______,_______,             _______, _______, _______, _______, _______, _______,  
                                       KC_LSFT, KC_SPACE,             KC_SPACE,_______  
    ),
    [2] = LAYOUT( 
        KC_F1,    KC_F2,    KC_F3,   KC_F4,   KC_F5,  KC_F6,          KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11, KC_F12,
        KC_ENTER, _______,_______,_______,_______,_______,            _______,   _______,   _______,   _______, _______, _______,
        KC_LALT,  _______,_______,_______,_______,_______,            _______,   _______,   _______,   _______, _______, _______,
        KC_LGUI,  _______,_______,_______,_______,_______,            _______,   _______,   _______,   _______, _______, _______,  
                                              _______, KC_SPACE,      KC_SPACE, KC_RSFT  
    ),
    [3] = LAYOUT( 
        KC_ESC,   KC_F1,   KC_1,   KC_2,   KC_3,   KC_4,               XXXXXXX,   XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_ENTER, KC_TAB,  KC_Q,   KC_W,   KC_E,   KC_R,               XXXXXXX,   XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_LALT,  KC_G,    KC_A,   KC_S,   KC_D,   KC_F,               XXXXXXX,   XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_LGUI,  KC_LSFT, KC_Z,   KC_X,   KC_C,   KC_V,               XXXXXXX,   XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  
                             TD(TD_GAMING_BUTTON), KC_SPACE,           XXXXXXX,   XXXXXXX  
    )  
};

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