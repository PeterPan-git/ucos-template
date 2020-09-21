#include"os_includes.h"
#include"stm32f10x.h"

/****************************************************************************
* Function Name  : SYSYTICK_Init
* Description    : 初始化器件时钟为72MHz，开启系统滴答定时器
* Input          : None
* Output         : None
* Return         : 0：开启成功；1：开启失败
****************************************************************************/

void SYSTICK_Init(void)
{
	uint16_t ms = 0;
	uint32_t reloadValue;
	ms = 1000 / OS_TICKS_PER_SEC;     //计算一次延时多少毫秒
	reloadValue = 72000;              //延时1ms是的重置数
	reloadValue *= ms;                //计算实际的重置数
	if(reloadValue > 0x0FFFFFF)      //重置寄存器只有24位
	{
		reloadValue = 0x0FFFFFF;
	}

	SysTick_Config(reloadValue); //开启成功返回0		
}

/****************************************************************************
* Function Name  : SysTick_Handler
* Description    : 系统滴答定时器的中断，用来做任务切换
* Input          : None
* Output         : None
* Return         : None
****************************************************************************/

void SysTick_Handler(void)
{
	OSIntEnter();		//进入中断
    OSTimeTick();       //调用ucos的时钟服务程序               
    OSIntExit();        //触发任务切换软中断
}












