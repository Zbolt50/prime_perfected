#pragma once


#define SERIAL_USART_FULL_DUPLEX
#define SERIAL_USART_TX_PIN GP8
#define SERIAL_USART_RX_PIN GP9
#define SERIAL_PIO_USE_PIO1  //Force the usage of PIO1 peripheral, by default the Serial implementation uses the PIO0 peripheral
#define SERIAL_DEBUG

#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_OLED_ENABLE

#define MASTER_LEFT

#define BOOTMAGIC_LITE_ROW_RIGHT 0    
#define BOOTMAGIC_LITE_COLUMN_RIGHT 5

