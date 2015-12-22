#ifndef _LED_H_
#define _LED_H_  

void gpio_init(void); //LED
void Get_Power(void); //������ʾ
void led_open(void); //����
void led_off(void); //�ػ�
void led_send(void); //����
void led_gps_failed(void); //δ���յ�GPS
void led_activate(void); //����
void led_charge(void);  //���ʱ����

extern INT16U adc_charge;//����ֵ

////////////////////
#define LED1_ON()   P13=1
#define LED1_OFF()  P13=0
#define LED2_ON()   P14=1
#define LED2_OFF()  P14=0
#define LED3_ON()   P07=1
#define LED3_OFF()  P07=0
#define LED4_ON()   P02=1
#define LED4_OFF()  P02=0
#define LED5_ON()   P16=1
#define LED5_OFF()  P16=0
#define LED6_ON()   P00=1
#define LED6_OFF()  P00=0
#define LED7_ON()   P15=1
#define LED7_OFF()  P15=0
#define LED8_ON()   P01=1
#define LED8_OFF()  P01=0

#define POWER_GRADE_1		   1
#define POWER_GRADE_2		   2
#define POWER_GRADE_3		   3
#define POWER_GRADE_4		   4
#define POWER_GRADE_5		   5
#define POWER_GRADE_6		   6
#define POWER_GRADE_7		   7
#define POWER_GRADE_8		   8
#define POWER_GRADE_9		   9
#define POWER_GRADE_10		 10
#define POWER_GRADE_FULL	   10

void delay_ms(INT16U dj) ;		//ms������ʱ
void delay_ms2(INT16U dj) ; 
void delay_ms3(INT16U dj) ; 
void delay_ms4(INT16U dj) ;
void ALL_LED_UP(void);			//����led����
void ALL_LED_DOWN(void);  		//����ledϨ��
void led_round(INT8U TIMES,INT16U speed);	 //led��ˮ�ƣ�Ȧ�����ٶȣ�
void all_led_flash(INT8U TIMES,INT16U up_time,INT16U down_time);	 //ȫ��led��˸����˸����������ʱ��ms��Ϩ��ʱ��ms��
char part_led_flash_open(INT8U xLED,INT8U TIMES,INT16U up_time,INT16U down_time); //������˸
void part_led_flash(INT8U xLED,INT8U TIMES,INT16U up_time,INT16U down_time);	  //�������led��˸����˸����������ʱ��ms��Ϩ��ʱ��ms��
void led_get_power(INT8U ENERGY);			   //���ʱled����Ϊ������1~9����ʹ��POWER_GRADE_1~8���POWER_GRADE_FULL�꣩
void led_startup(INT8U ENERGY);				   //����ʱled����Ϊ������1~8����ʹ��POWER_GRADE_1~8�꣩
void led_shutdown(INT8U ENERGY);			   //�ػ�ʱled����Ϊ������1~8����ʹ��POWER_GRADE_1~8�꣩
void led_write_finished(void);				   //д��ɹ�ʱled����Ϊ
INT8U get_led_charge (void);   //�������
INT8U get_led_charging (void);  //���ʱ����ֵ

void FOUR_LED_UP(void);
void FOUR_LED_DOWN(void);
char daynight_flash(void);
#endif

