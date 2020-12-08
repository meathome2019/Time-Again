#include <Arduino.h>
  #include "main_Setup.h"

  //char time_output[30]; //Time output
  //char hour_output[12];
  //char day_output[12];
  //char month_output[12];
  //char year_output[5];

  String Date_str;        //Strings to hold time
  String Time_str;
  String Month_str;
  String Year_str;
  int n;
  int local_Unix_time = 0;
//######################################################################################################
  void Time_Setup(){
  configTime(0, 0, "pool.ntp.org", "time.nist.gov");
  // See https://github.com/nayarsystems/posix_tz_db/blob/master/zones.csv for Timezone codes for your region
  setenv("TZ", "GMT0BST,M3.5.0/01,M10.5.0/02", 1);
  delay(1000); // Wait for time services
  time_t now;
  time(&now);
  delay(1000);
  while (now<=1607372135){
    now = time(nullptr);
    Lcd_Print_Connecting_to_time_server();
    n++;
    delay(2000);
  }  
  local_Unix_time = now + 2; // The addition of 1 counters the NTP setup time delay
  }
//####################################################################################################
  void Run_Time(){
  time_t now;
  local_Unix_time++;
  now = local_Unix_time;
  //See http://www.cplusplus.com/reference/ctime/strftime/
  strftime(day_output, 12, "%A   ", localtime(&now)); // Formats date as: Sat 24-Jun-17
  strftime(hour_output, 12, "%r", localtime(&now));    // Formats time as: 14:05:49
  strftime(month_output, 12, "%B", localtime(&now));
  strftime(year_output, 12, "%Y", localtime(&now));
  Date_str = day_output;
  Time_str = hour_output;
  Month_str = month_output;
  Year_str = year_output;
  Lcd_Print_Time();
}
//######################################################################################################
void Time_Update(){
  time_t now;
  time(&now);
  Serial.println("Synchronising local time, time error was: "+String(now-local_Unix_time));
  local_Unix_time = now;
}