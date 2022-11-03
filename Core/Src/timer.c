/*
 * timer.c
 *
 *  Created on: Oct 29, 2022
 *      Author: PC
 */

#include "timer.h"
#include "main.h"
#include "input_processing.h"
#include "input_reading.h"
int timer1_flag = 0;
int timer1_counter = 0;

void setTimer1(int duration)
{
	timer1_counter = duration;
	timer1_flag = 0;
}

void timerRun()
{
	if(timer1_counter > 0)
	{
		timer1_counter--;
		if(timer1_counter <= 0)
		{
			timer1_flag = 1;
		}
	}
}

void HAL_TIM_PeriodElapsedCallback ( TIM_HandleTypeDef * htim )
{
	if(htim->Instance == TIM2)
	{
		button_reading();
	}
}
