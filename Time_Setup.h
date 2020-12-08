#ifndef Time_Setup_H
  #define Time_Setup_H

  #include <Arduino.h>
  #include <time.h>
  #include "main_Setup.h"

  extern char time_output[30]; //Time output
  extern char hour_output[12];
  extern char day_output[12];
  extern char month_output[12];
  extern char year_output[5];

  extern String Date_str;        //Strings to hold time
  extern String Time_str;
  extern String Month_str;
  extern String Year_str;

  extern int local_Unix_time;      //Local time variable must be a signed integer
  extern int n;
  extern long rssi;

  void Time_Update();
  void Run_Time();
  void Time_Setup();
  


#endif