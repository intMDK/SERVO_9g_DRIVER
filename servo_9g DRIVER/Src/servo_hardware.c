#include "servo_hardware.h"
//
// note:
uint16_t TIM_PRESCALER = 40;// You may need to change this value according to your needs
uint16_t TIM_PERIOD = 36000;// You may need to change this value according to your needs

//
TIM_HandleTypeDef htim1;

void tim_PWM_GPIO_config(void)
{
	GPIO_InitTypeDef gpioInitStruct = {0};
	__HAL_RCC_GPIOA_CLK_ENABLE();
	//
	gpioInitStruct.Pin = GPIO_PIN_8;
	gpioInitStruct.Mode = GPIO_MODE_AF_PP;
	gpioInitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOA, &gpioInitStruct);
}
void tim_TIM_PWM_setDutyCycle_CH1(float duty)
{

	//
	uint16_t ccrvalue = (uint16_t)((__HAL_TIM_GET_AUTORELOAD(&htim1)+0.0f)*(duty/100.0f));
	//
	__HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_1,ccrvalue);


}
bool tim_PWM_config(void)
{

	//
	__HAL_RCC_TIM1_CLK_ENABLE();
	//
	htim1.Instance = TIM1;
	htim1.Init.Prescaler = TIM_PRESCALER-1;
	htim1.Init.Period = TIM_PERIOD-1;
	htim1.Init.AutoReloadPreload = TIM_AUTOMATICOUTPUT_DISABLE;
	htim1.Init.CounterMode = TIM_COUNTERMODE_UP;
	htim1.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	//
	if(HAL_TIM_Base_Init(&htim1) != HAL_OK)
	{
		return false;
	}

	TIM_ClockConfigTypeDef timClockConfig = {0};
	timClockConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
	//
	if(HAL_TIM_ConfigClockSource(&htim1,&timClockConfig) != HAL_OK)
		{
			return false;
		}
	//
	HAL_TIM_PWM_Init(&htim1);

	TIM_OC_InitTypeDef ocConfig = {0};
	ocConfig.OCMode = TIM_OCMODE_PWM1;
	ocConfig.OCFastMode = TIM_OCFAST_DISABLE;
	ocConfig.OCPolarity = TIM_OCPOLARITY_HIGH;
	ocConfig.Pulse = 0;
	//
	if(HAL_TIM_OC_ConfigChannel(&htim1, &ocConfig, TIM_CHANNEL_1)!= HAL_OK)
	{
		return false;
	}
	return true;
}

