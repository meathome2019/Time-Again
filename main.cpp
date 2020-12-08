#include <Arduino.h>
#include "main_Setup.h"
//#include "Wire.h"
#include "Time_Setup.h"
#include "WiFi_Setup.h"

//extern LiquidCrystal_I2C lcd;

Scheduler ts;                         //Task scheduler

Task Run_Time1(1000, TASK_FOREVER,&Run_Time,&ts,true);      //Main time routine action once per second
Task Time_Update1(60* TASK_MINUTE, TASK_FOREVER,&Time_Update,&ts,true); //Update time once an hour

//#######################################################################################
void setup(){
  Serial.begin(115200);
  LCD_Setup();
  WiFi_ON();

  Run_Time1.disable();  // Disable to maintain clock accuracy
  Time_Setup();
  Time_Update1.enableDelayed();
  Run_Time1.enableDelayed();
}

void loop(){
  ts.execute();
}
//###############################################################################################

