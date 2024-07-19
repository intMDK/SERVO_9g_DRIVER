#ifndef INC_SERVO_HARDWARE_H_
#define INC_SERVO_HARDWARE_H_
#include "main.h"

void tim_PWM_GPIO_config(void);

bool tim_PWM_config(void);

void tim_TIM_PWM_setDutyCycle_CH1(float duty);

#endif /* INC_SERVO_HARDWARE_H_ */
