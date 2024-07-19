# SERVO_9g_DRIVER
Easily control a 9g servo motor by integrating these files into your project. Simply add the provided code to your project, configure the necessary parameters, and start driving your servo with precise PWM signals.

To use this driver, follow these steps:

1. Add the provided files to your project.
2. Include the header in your main file:
#include "servo_middle.h"
3. Call the following functions in your main code:
// Configure the servo
servo_config();

// Start the PWM signal on TIM1, Channel 1
HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);

// Set the servo angle
servo_setAngle(degree);
These steps will enable you to control the servo motor with ease.
