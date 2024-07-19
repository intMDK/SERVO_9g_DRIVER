#include "servo_middle.h"
#include "servo_hardware.h"

void servo_config(void)
{
	tim_PWM_GPIO_config();
	tim_PWM_config();
}

void servo_setAngle(float degree)
{
	float duty_cycle =( 3+(0.052*degree));
	tim_TIM_PWM_setDutyCycle_CH1(duty_cycle);
}

