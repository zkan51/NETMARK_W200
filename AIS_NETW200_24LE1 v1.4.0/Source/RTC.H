#ifndef __RTC_H__
#define __RTC_H__

#include "reg24le1.h" 
#include "string.h"

void rtc2_init(void);
void sendmsg18(void);  //RF���ͶϿ�������
void Is_Charge(void);  //�ж��Ƿ��ڳ��
void adc_square(void);  //adc�������� ��������
void abc(void);

#endif