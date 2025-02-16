#pragma once

// Establishes Split Keyboard Serial Communications
#define SERIAL_USART_FULL_DUPLEX
#define SERIAL_USART_TX_PIN GP8
#define SERIAL_USART_RX_PIN GP9

#define I2C_DRIVER I2CD0
#define I2C1_SCL_PIN GP13
#define I2C1_SDA_PIN GP12

#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_OLED_ENABLE
#define SPLIT_LED_STATE_ENABLE
#define EE_HANDS
// #define MASTER_LEFT

#define BOOTMAGIC_LITE_ROW_RIGHT 2
#define BOOTMAGIC_LITE_COLUMN_RIGHT 6

#define BOOTMAGIC_LITE_ROW_LEFT 3
#define BOOTMAGIC_LITE_COLUMN_LEFT 3
// Tap Dance Config
#define TAPPING_TERM 175
#define TAPPING_TERM_PER_KEY
