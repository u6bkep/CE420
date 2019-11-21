/******************************************************************************
* @file    sh1106.h
* @author Driver obtained from the OLED manufacturer (Waveshare Team)
* @Adapted for PIC32 by  Erick Moreno and Girma Tewolde
* @Last Modified: 11/10/2019 @ 3:30 PM
* @brief   This file includes the OLED driver for SH1106 display module
******************************************************************************
*/

#include <p32xxxx.h>
#include <stdint.h>

#define OLED_RST            _RF6        //PORTFbits.RF6
#define OLED_RST_DIR        _TRISF6
#define OLED_DC             _RD7        //PORTDbits.RD7
#define OLED_DC_DIR         _TRISD7
#define OLED_CS             _RD6        //PORTDbits.RD6
#define OLED_CS_DIR         _TRISD6
#define SPI_MOSI            _RG8        //PORTGbits.RG8
#define SPI_MOSI_DIR        _TRISG8
#define SPI_SCK             _RG6        //PORTGbits.RG6
#define SPI_SCK_DIR         _TRISG6

#define VCCSTATE SH1106_SWITCHCAPVCC
#define WIDTH   128
#define HEIGHT   64
#define NUM_PAGE  8

uint8_t oled_buf[WIDTH * HEIGHT / 8];

void SH1106_begin();
void SH1106_display(uint8_t* buffer);
void SH1106_clear(uint8_t* buffer);
void SH1106_pixel(uint16_t x, uint16_t y, uint8_t color, uint8_t* buffer);
void SH1106_bitmap(uint8_t x, uint8_t y, const uint8_t *pBmp, uint8_t chWidth, uint8_t chHeight, uint8_t* buffer);
void SH1106_char1616(uint8_t x, uint8_t y, uint8_t chChar, uint8_t* buffer);
void SH1106_char3216(uint8_t x, uint8_t y, uint8_t chChar, uint8_t* buffer);
void SH1106_string(uint8_t x, uint8_t y, const uint8_t *pString, uint8_t Size, uint8_t Mode, uint8_t* buffer);
void initSPI2(void);
void writeSPI2Buff(uint8_t *buffer, uint16_t bufferLength);
void command(uint8_t cmd);
void usDelay(uint32_t us);
int writeSPI2(uint16_t data);

const uint8_t Font1612[11][32];
const uint8_t Font3216[11][64];


