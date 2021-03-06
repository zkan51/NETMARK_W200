#ifndef __MAIN_H
#define	__MAIN_H

#include "stm32f10x.h"
#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "math.h"

#include "config.h"
#include "usart1.h"
#include "usart2.h"
#include "usart3.h"
#include "SKY72310.h"
#include "msg_slot.h"
#include "timer.h"
#include "gps.h"
#include "gps_algorithm.h"
#include "mkmsg.h"	
#include "exti.h"
#include "rtc.h"
#include "flashwr.h"
#include "charge.h"
#include "test.h"
#include "led.h"

void Delay(__IO u32 nCount);

// union dds_union
// {
// 	unsigned long dds_data32;  //高地址存放高位，低地址存放低位。
// 	u8 dds_data8[4];
// };

//////msg21/////
extern u8 dev_type;//助航设备类型 5bit
extern u8 dev_name[54];//助航设备名称 120bit+(0~84)bit
extern u8 dev_local[5]; //尺寸位置参考点 30bit
extern u8 dev_time; //时戳 6bit
extern u8 dev_state; //AtoN状态 8bit
extern u8 dev_etype; //电子定位装置类型 4bit

extern u16 boatlong; 
extern u8 boatwidth; 
extern u16 boatsize_a; 
extern u16 boatsize_b; 
extern u8 boatsize_c;	
extern u8 boatsize_d;	
////////////////

typedef enum
{ 
	off=0,
	on
}ais_status;

extern unsigned long MMSI;
extern u8 boatnum[16];
extern u8 CodeNum[6]; //密码
extern u8 Vender_ID[6];
extern u8 Call_sign[6];
extern unsigned long jingdu;
extern unsigned long weidu;
extern unsigned int sog;
extern unsigned int direction;
extern unsigned long gpstime;
extern u8 msg[45];
extern GPS_INFO   GPS;
extern u8 len; //输入消息的字节数
extern u16 slot_increacement; //随机时隙增量，由随机化程序产生
extern ais_status task_flag2;//发送任务完成标志 !!初值必须置为1,用来标识是否进入时隙号随机化函数； 
extern ais_status task_flag1;

extern ais_status freq_pn_flag;

//extern union dds_union dds_word_update[16][5];
//extern char  dds_word_real_num[8][5];
extern int  dds_word_real[9][5];
// extern u16 dds_w1[17][5];
// extern u16 dds_w2[17][5];
// extern u16 dds_w3[17][5];
// extern u16 dds_w4[17][5];
extern u16 fre_cnt;

extern u8 msg18_24AB_add[768];
extern u8 msg18_add[256];
extern u8 msg24A_add[256];
extern u8 msg24B_add[256];
extern u8 msg21_add[256*2];

// extern u8 valid_cnt_m18;
// extern u8 valid_cnt_m24A;
// extern u8 valid_cnt_m24B;

extern u16 TIM3_CAM1;
extern u16 TIM3_CAM2;
extern u16 TIM3_CAM3;
extern u16 TIM3_CAM4;
extern u16 TIM3_CAM5;

extern u16 interval_s;  //发射间隔计数，变化值
extern u16 interval_num; //发射间隔计数
extern u16 gps_invalid; //gps失效的次数标志
//extern u16 gps_invalid_num; //失效次数值
extern u16 time_o;//GPS前次时间存储
extern u16 intervalA;  //间隔计数次数 固定值
extern u16 intervalB;  //间隔计数次数 超时值
extern u8 cogsel;
extern u8 Openflag; // 开机

extern u16 var_m24;
extern ais_status flag_m24;
extern ais_status flag_fre_check;
extern u16 msequence_poly;	//上位机写入 与控制的接口。
extern u8 flag_channel;		 //信道选择标志位,初始化为信道1
extern ais_status flag_initial_slot;
extern ais_status flag_gps_valid; //初值一定为off,gps有效数据标志。上电初gps无效。
extern u8 code_cnt; //密码正确与否标志。code_flag1=6时密码正确
extern ais_status code_flag1; //判断密码是否正确，默认不正确
extern ais_status code_flag2; //是否写过密码标志，默认为未写过。
extern ais_status charging_flag;
extern ais_status gps_off_flag; //关闭gps标志
extern u8 gps_off_cnt;
extern ais_status key_off_flag; //钥匙关闭网位仪标志，默认为off
extern ais_status key_on_flag; //钥匙关闭网位仪标志，默认为off
//extern ais_status clk_convert_flag;//主频时钟切换标志
extern ais_status reset_flag;

extern u16 activation_flag;//激活标志
extern u32 ChipUniqueID_Flash[3];   //芯片96bit UID

extern u8 rxflag; //发送标志,防止发送时进入中断
extern u8 status;	//用于判断接收/发送状态
extern u8 txbuf[31]; 	   //串口3发送缓冲
extern u8 key_off_cnt;

extern u8 wireless_en;// 无线读写码使能，默认不能读写
extern u8 wireless_cnt;//无线使能计数
#define SEND_INTERVAL                        ((uint16_t)9000)


#endif /* __MAIN_H */
