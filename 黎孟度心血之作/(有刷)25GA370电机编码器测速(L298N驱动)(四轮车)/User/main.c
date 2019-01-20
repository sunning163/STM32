/*******************************************************************************
模板制作：  华南理工大学广州学院野狼队
程序名：	25GA370四轮电机编码器测速程序
编写人：	黎孟度
编写时间：	2019年1月16日
硬件支持：	STM32F103ZET6及其驱动板　  

修改日志：　　
1-	

说明：
 # 本程序是在芯片为STM32F103ZET6的硬件基础上编写的，移植需了解硬件接口差异。
 # 本模板加载了霍尔编码器的测速模块，可实现电机测速。
 # 可根据自己的需要增加或删减。
*******************************************************************************/
/*
 *        因为调试串口使用到PA9和PA10两个引脚，而TIM1通道也刚好使用到
 *   这两个引脚，为正常使用调试串口，在初始化定时器时不使用这两个引脚。
 *
 */
/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"
#include "tim.h"
#include "encoder.h"
#include "usart.h"

extern __IO uint32_t CaptureNumber; // 定义全局变量，表示编码器的值

/*******************************************************************************
* 函 数 名         : delay
* 函数功能		   : 简单粗暴的延时函数
* 输    入         : 无
* 输    出         : 无
*                             黎孟度心血之作                                   *
*******************************************************************************/
static void delay(void)
{
	uint16_t i,j;
	for(i=0;i<1000;++i)
	{
		for(j=0;j<5000;++j)
		{
			
		}
	}
}


/*******************************************************************************
* 函 数 名         : main
* 函数功能		   : 初始化有关器件、赋予电机速度及用串口输出电机速度
* 输    入         : 无
* 输    出         : 无
*                             黎孟度心血之作                                   *
*******************************************************************************/
int main(void)
{ 
  
	DCMOTOR_BRUSH_TIMx_PWM_Init();//初始化定时器PWM输出
	TIMx_DCmotor_ENCODER_Init();  //初始化编码器捕获，编码器对应TIM3_CH3:PB0引脚
	DEBUG_USART_Init();           //usart串口初始化
	
	printf("编码器测试\n");

	DCMOTOR_25GA370_Contrl(1,1,500);
	/*电机控制，参数1：通道选择；参数2：正反转控制；
	            参数3：速度控制（数值越大速度越慢）*/

	while (1)
	{   
		delay();                            //小延时
		printf("freq:%d\n",CaptureNumber);  // 打印编码器捕获值
		CaptureNumber=0;                    // 清零，从零开始计数
	}
}

/****************** (C) COPYRIGHT 2019 黎孟度心血之作 **************************
******************************END OF FILE**************************************/
