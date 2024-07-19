# SERVO_9g_DRIVER
Easily control a 9g servo motor by integrating these files into your project. Simply add the provided code to your project, configure the necessary parameters, and start driving your servo with precise PWM signals.

To use this driver, follow these steps:

First Add the provided files to your project.
Second Include the header in your main file:
#include "servo_middle.h"
Then Call the following functions in your main code: 
servo_config();
HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
servo_setAngle(degree);

These steps will enable you to control the servo motor with ease.

