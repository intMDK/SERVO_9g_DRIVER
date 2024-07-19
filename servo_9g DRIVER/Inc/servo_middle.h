
#ifndef INC_SERVO_MIDDLE_H_
#define INC_SERVO_MIDDLE_H_
#include "main.h"

extern TIM_HandleTypeDef htim1;

void servo_config(void);
void servo_setAngle(float degree);


#endif /* INC_SERVO_MIDDLE_H_ */
