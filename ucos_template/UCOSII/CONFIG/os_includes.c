#include"os_includes.h"
#include"stm32f10x.h"

/****************************************************************************
* Function Name  : SYSYTICK_Init
* Description    : ��ʼ������ʱ��Ϊ72MHz������ϵͳ�δ�ʱ��
* Input          : None
* Output         : None
* Return         : 0�������ɹ���1������ʧ��
****************************************************************************/

void SYSTICK_Init(void)
{
	uint16_t ms = 0;
	uint32_t reloadValue;
	ms = 1000 / OS_TICKS_PER_SEC;     //����һ����ʱ���ٺ���
	reloadValue = 72000;              //��ʱ1ms�ǵ�������
	reloadValue *= ms;                //����ʵ�ʵ�������
	if(reloadValue > 0x0FFFFFF)      //���üĴ���ֻ��24λ
	{
		reloadValue = 0x0FFFFFF;
	}

	SysTick_Config(reloadValue); //�����ɹ�����0		
}

/****************************************************************************
* Function Name  : SysTick_Handler
* Description    : ϵͳ�δ�ʱ�����жϣ������������л�
* Input          : None
* Output         : None
* Return         : None
****************************************************************************/

void SysTick_Handler(void)
{
	OSIntEnter();		//�����ж�
    OSTimeTick();       //����ucos��ʱ�ӷ������               
    OSIntExit();        //���������л����ж�
}












