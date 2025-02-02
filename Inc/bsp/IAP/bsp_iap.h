#ifndef __BSP_IAP_H__
#define	__BSP_IAP_H__

/* 包含头文件 ----------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* 类型定义 ------------------------------------------------------------------*/
/************************** IAP 数据类型定义********************************/
typedef  void ( * pIapFun_TypeDef ) ( void ); //定义一个函数类型的参数.

/* 宏定义 --------------------------------------------------------------------*/
/************************** IAP 宏参数定义********************************/
 //是否更新 APP 到 FLASH，否则更新到 RAM

#define APP_START_ADDR       0x08010000  	//应用程序起始地址(存放在FLASH)
	
/************************** IAP 外部变量********************************/
#define APP_FLASH_LEN  			   56320u       //定义 APP 固件最大容量，55kB=55*1024=56320

/* 扩展变量 ------------------------------------------------------------------*/
extern struct  STRUCT_IAP_RECIEVE      //串口数据帧的处理结构体
{
	uint8_t   ucDataBuf[APP_FLASH_LEN];
	uint16_t  usLength;
} strAppBin;

/* 函数声明 ------------------------------------------------------------------*/
void IAP_Write_App_Bin( uint32_t appxaddr, uint8_t * appbuf, uint32_t applen);	//在指定地址开始,写入bin
void IAP_ExecuteApp( uint32_t appxaddr );			                              //执行flash里面的app程序

#endif /* __BSP_IAP_H__ */

/******************* (C) COPYRIGHT 2015-2020 硬石嵌入式开发团队 *****END OF FILE****/
