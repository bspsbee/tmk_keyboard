/*
Copyright 2012 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef CONFIG_H
#define CONFIG_H


/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x0A0C
#define DEVICE_VER      0x0009
#define MANUFACTURER    di0ib
#define PRODUCT         The GNAP! Keyboard
#define DESCRIPTION     A compact keyboard

/* key matrix size */
#define MATRIX_ROWS 4
#define MATRIX_COLS 12

/* define if matrix has ghost */
//#define MATRIX_HAS_GHOST

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE    5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* key combination for command */
#define IS_COMMAND() ( \
    keyboard_report->mods == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)) \
)

/* Enable GNAP matrix serial output */
#define GNAP_ENABLE

/* USART configuration */
#ifdef __AVR_ATmega32U4__
#      define SERIAL_UART_BAUD 9600
#      define SERIAL_UART_DATA UDR1	
#      define SERIAL_UART_UBRR (F_CPU / (16UL * SERIAL_UART_BAUD) - 1)
#      define SERIAL_UART_RXD_VECT USART1_RX_vect
#      define SERIAL_UART_TXD_READY (UCSR1A & _BV(UDRE1))
#      define SERIAL_UART_INIT() do { \
            /* baud rate */ \
            UBRR1L = SERIAL_UART_UBRR; \
            /* baud rate */ \
            UBRR1H = SERIAL_UART_UBRR >> 8; \
            /* enable TX */ \
            UCSR1B = _BV(TXEN1); \
            /* 8-bit data */ \
            UCSR1C = _BV(UCSZ11) | _BV(UCSZ10); \
            sei(); \
        } while(0)
#   else
#       error "USART configuration is needed."
#endif

/* ws2812 RGB LED */
#define ws2812_PORTREG  PORTD
#define ws2812_DDRREG   DDRD
#define ws2812_pin PD5
#define RGBLED_NUM 7     // Number of LEDs
#ifndef RGBLIGHT_HUE_STEP
#define RGBLIGHT_HUE_STEP 10
#endif
#ifndef RGBLIGHT_SAT_STEP
#define RGBLIGHT_SAT_STEP 17
#endif
#ifndef RGBLIGHT_VAL_STEP
#define RGBLIGHT_VAL_STEP 17
#endif

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
//#define NO_ACTION_MACRO
//#define NO_ACTION_FUNCTION

#endif
