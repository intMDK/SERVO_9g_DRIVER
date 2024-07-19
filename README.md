To use this driver, follow these steps:

First Add the provided files to your project.
Second Include the header in your main file:
#include "servo_middle.h"
Then Call the following functions in your main code: 
servo_config();
HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
servo_setAngle(degree);

These steps will enable you to control the servo motor with ease.

