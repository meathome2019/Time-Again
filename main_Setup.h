#ifndef main_H
  #define main_Setup_H

  #include <Arduino.h>
  #include <TaskScheduler.h>
  #include <LiquidCrystal_I2C.h>
  #include "Time_Setup.h"
  #include "WiFi_Setup.h"
  #include "Display_Setup.h"

  void Run_Time();
  void Time_Update();


  #endif