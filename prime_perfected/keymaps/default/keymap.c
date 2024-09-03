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
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) {
        return OLED_ROTATION_180    ;  // flips the display 180 degrees if offhand
    }

    return rotation;
}

static void render_img(void) {
    static const char PROGMEM siva_logo[] = {
// 'prime_perfected', 32x128px
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0xf0, 0xf8, 0xfc, 
0xfc, 0xf8, 0xf0, 0xe0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x18, 0x1c, 0x1e, 0x9f, 0xdf, 0xff, 0x0f, 0x07, 0x03, 0x01, 
0x01, 0x83, 0xc7, 0xef, 0xff, 0xff, 0xff, 0xfe, 0x7c, 0xb8, 0xd0, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0xfc, 0xfe, 0x7f, 0x3f, 0x1f, 0x0f, 0x00, 0x00, 0x00, 0x00, 
0x7f, 0xbf, 0xdf, 0xef, 0xf7, 0xfb, 0xfd, 0x7e, 0x3f, 0x1f, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x3f, 0x1f, 0x0f, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
      };
    oled_write_raw_P(siva_logo,sizeof(siva_logo));
}



bool oled_task_user(void) {
    if (is_keyboard_master()) {
      render_img();
    } else {
      oled_set_cursor(0,1);
      switch (get_highest_layer(layer_state))
      {
      case _QWERTY_DEFAULT :
      oled_write("BASE", false);
        break;
      case _QWERTY_CODE :
      oled_write("CODE", false);
        break;
      case _QWERTY_FUNC :
      oled_write("FUNC", false);
        break;
      case _GAMING :
      oled_write("GAME", false);
        break;
      }
        //oled_scroll_left();  // Turns on scrolling
    }
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