#ifndef Display_Setup_H
  #define Display_Setup_H

  #include <Arduino.h>
  #include <LiquidCrystal_I2C.h>
  #include "main_Setup.h"

  extern LiquidCrystal_I2C lcd;

  void LCD_Setup();
  void Lcd_Print_Connecting_to_time_server();
  void Lcd_Print_Time();
  
  #endif