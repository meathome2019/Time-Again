  #include <Arduino.h>
  #include "main_Setup.h"

  LiquidCrystal_I2C lcd(0x3f,20,4);
  long rssi;

//##################################################################################################
  void LCD_Setup(){
    lcd.init();
    lcd.backlight();
    lcd.home();
  }
  //#################################################################################################
  void Lcd_Print_Connecting_to_time_server(){  
    lcd.home();
    lcd.setCursor(0,0);
    lcd.print(" Connecting to Time");
    lcd.setCursor(7,1);
    lcd.print("Try:");
    lcd.print(n);
  }
  void Lcd_Print_Time(){
    lcd.home();  
    lcd.print(Time_str );
    lcd.setCursor(12,0);
    lcd.print(Month_str);
    lcd.setCursor(0,1);
    lcd.print(Date_str);
    lcd.setCursor(9,1);
    lcd.print(Year_str);
    lcd.setCursor(17,3);
    rssi = WiFi.RSSI();
  lcd.print(rssi);
  }
