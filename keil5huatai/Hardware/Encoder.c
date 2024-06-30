#include "stm32f10x.h"                  // Device header

int16_t xEncoder_Count;					//ȫ�ֱ��������ڼ�����ת������������ֵ
int16_t yEncoder_Count;					//ȫ�ֱ��������ڼ�����ת������������ֵ

/**
  * ��    ������ת��������ʼ��
  * ��    ������
  * �� �� ֵ����
  */
void xEncoder_Init(void)
{
	/*����ʱ��*/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);		//����GPIOA��ʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);		//����AFIO��ʱ�ӣ��ⲿ�жϱ��뿪��AFIO��ʱ��
	
	/*GPIO��ʼ��*/
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);						//��PA8��PA9���ų�ʼ��Ϊ��������
	
	/*AFIOѡ���ж�����*/
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource8);//���ⲿ�жϵ�8����ӳ�䵽GPIOA����ѡ��PA8Ϊ�ⲿ�ж�����
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource9);//���ⲿ�жϵ�9����ӳ�䵽GPIOA����ѡ��PA9Ϊ�ⲿ�ж�����

	/*EXTI��ʼ��*/
	EXTI_InitTypeDef EXTI_InitStructure;						//����ṹ�����
	EXTI_InitStructure.EXTI_Line = EXTI_Line8 | EXTI_Line9 ;	//ѡ�������ⲿ�жϵ�8���ߺ�9����
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;					//ָ���ⲿ�ж���ʹ��
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;			//ָ���ⲿ�ж���Ϊ�ж�ģʽ
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;		//ָ���ⲿ�ж���Ϊ�½��ش���
	EXTI_Init(&EXTI_InitStructure);								//���ṹ���������EXTI_Init������EXTI����
	
	/*NVIC�жϷ���*/
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);				//����NVICΪ����2
	
	/*NVIC����*/
	NVIC_InitTypeDef NVIC_InitStructure;						//����ṹ�����
	NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn ;			//ѡ������NVIC��EXTI9_5_IRQn��
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;				//ָ��NVIC��·ʹ��
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;	//ָ��NVIC��·����ռ���ȼ�Ϊ0
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;			//ָ��NVIC��·����Ӧ���ȼ�Ϊ0
	NVIC_Init(&NVIC_InitStructure);								//���ṹ���������NVIC_Init������NVIC����
}

/**
  * ��    ������ת��������ȡ����ֵ
  * ��    ������
  * �� �� ֵ�����ϴ˵��ô˺�������ת������������ֵ
  */
int16_t xEncoder_Get(void)
{
	/*ʹ��Temp������Ϊ�м̣�Ŀ���Ƿ���Encoder_Count��������*/
	/*�����Ҳ����ֱ�ӷ���Encoder_Count
	  �������Ͳ��ǻ�ȡ����ֵ�Ĳ���������
	  Ҳ����ʵ�ֹ��ܣ�ֻ��˼·��һ��*/
	int16_t xTemp;
	xTemp = xEncoder_Count;
	xEncoder_Count = 0;
	return xTemp;
}

/**
  * ��    ����EXTI9_5�ⲿ�жϺ���
  * ��    ������
  * �� �� ֵ����
  * ע������˺���Ϊ�жϺ�����������ã��жϴ������Զ�ִ��
  *           ������ΪԤ����ָ�����ƣ����Դ������ļ�����
  *           ��ȷ����������ȷ���������κβ��죬�����жϺ��������ܽ���
  */
void EXTI9_5_IRQHandler(void)
{
	if (EXTI_GetITStatus(EXTI_Line8) == SET)		//�ж��Ƿ����ⲿ�ж�8���ߴ������ж�
	{
		/*��������������������󣬿��ٴ��ж����ŵ�ƽ���Ա��ⶶ��*/
		if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_8) == 0)
		{
			if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_9) == 0)		//PA8���½��ش����жϣ���ʱ�����һ��PA9�ĵ�ƽ��Ŀ�����ж���ת����
			{
				xEncoder_Count --;					//�˷�����Ϊ��ת�����������Լ�
			}
		}
		EXTI_ClearITPendingBit(EXTI_Line8);			//����ⲿ�ж�8���ߵ��жϱ�־λ
													//�жϱ�־λ�������
													//�����жϽ��������ϵش�����������������
	}
	else if (EXTI_GetITStatus(EXTI_Line9) == SET)		//�ж��Ƿ����ⲿ�ж�9���ߴ������ж�
	{
		/*��������������������󣬿��ٴ��ж����ŵ�ƽ���Ա��ⶶ��*/
		if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_9) == 0)
		{
			if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_8) == 0)		//PA9���½��ش����жϣ���ʱ�����һ��PA8�ĵ�ƽ��Ŀ�����ж���ת����
			{
				xEncoder_Count ++;					//�˷�����Ϊ��ת��������������
			}
		}
		EXTI_ClearITPendingBit(EXTI_Line9);			//����ⲿ�ж�9���ߵ��жϱ�־λ
													//�жϱ�־λ�������
													//�����жϽ��������ϵش�����������������
	}
}

/**
  * ��    ������ת��������ʼ��
  * ��    ������
  * �� �� ֵ����
  */
void yEncoder_Init(void)
{
	/*����ʱ��*/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);		//����GPIOA��ʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);		//����AFIO��ʱ�ӣ��ⲿ�жϱ��뿪��AFIO��ʱ��
	
	/*GPIO��ʼ��*/
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);						//��PA0��PA1���ų�ʼ��Ϊ��������
	
	/*AFIOѡ���ж�����*/
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource0);//���ⲿ�жϵ�0����ӳ�䵽GPIOA����ѡ��PA0Ϊ�ⲿ�ж�����
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource1);//���ⲿ�жϵ�1����ӳ�䵽GPIOA����ѡ��PA1Ϊ�ⲿ�ж�����

	/*EXTI��ʼ��*/
	EXTI_InitTypeDef EXTI_InitStructure;						//����ṹ�����
	EXTI_InitStructure.EXTI_Line = EXTI_Line0 | EXTI_Line1 ;	//ѡ�������ⲿ�жϵ�0���ߺ�1����
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;					//ָ���ⲿ�ж���ʹ��
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;			//ָ���ⲿ�ж���Ϊ�ж�ģʽ
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;		//ָ���ⲿ�ж���Ϊ�½��ش���
	EXTI_Init(&EXTI_InitStructure);								//���ṹ���������EXTI_Init������EXTI����
	
	/*NVIC�жϷ���*/
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);				//����NVICΪ����2
	
	/*NVIC����*/
	NVIC_InitTypeDef NVIC_InitStructure;						//����ṹ�����
	NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn;			//ѡ������NVIC��EXTI0��
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;				//ָ��NVIC��·ʹ��
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;	//ָ��NVIC��·����ռ���ȼ�Ϊ1
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;			//ָ��NVIC��·����Ӧ���ȼ�Ϊ1
	NVIC_Init(&NVIC_InitStructure);								//���ṹ���������NVIC_Init������NVIC����

	NVIC_InitStructure.NVIC_IRQChannel = EXTI1_IRQn;			//ѡ������NVIC��EXTI1��
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;				//ָ��NVIC��·ʹ��
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;	//ָ��NVIC��·����ռ���ȼ�Ϊ1
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;			//ָ��NVIC��·����Ӧ���ȼ�Ϊ2
	NVIC_Init(&NVIC_InitStructure);							//���ṹ���������NVIC_Init������NVIC����
}

/**
  * ��    ������ת��������ȡ����ֵ
  * ��    ������
  * �� �� ֵ�����ϴ˵��ô˺�������ת������������ֵ
  */
int16_t yEncoder_Get(void)
{
	/*ʹ��Temp������Ϊ�м̣�Ŀ���Ƿ���Encoder_Count��������*/
	/*�����Ҳ����ֱ�ӷ���Encoder_Count
	  �������Ͳ��ǻ�ȡ����ֵ�Ĳ���������
	  Ҳ����ʵ�ֹ��ܣ�ֻ��˼·��һ��*/
	int16_t yTemp;
	yTemp = yEncoder_Count;
	yEncoder_Count = 0;
	return yTemp;
}

/**
  * ��    ����EXTI0�ⲿ�жϺ���
  * ��    ������
  * �� �� ֵ����
  * ע������˺���Ϊ�жϺ�����������ã��жϴ������Զ�ִ��
  *           ������ΪԤ����ָ�����ƣ����Դ������ļ�����
  *           ��ȷ����������ȷ���������κβ��죬�����жϺ��������ܽ���
  */
void EXTI0_IRQHandler(void)
{
	if (EXTI_GetITStatus(EXTI_Line0) == SET)		//�ж��Ƿ����ⲿ�ж�0���ߴ������ж�
	{
		/*��������������������󣬿��ٴ��ж����ŵ�ƽ���Ա��ⶶ��*/
		if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0) == 0)
		{
			if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_1) == 0)		//PA0���½��ش����жϣ���ʱ�����һ��PA1�ĵ�ƽ��Ŀ�����ж���ת����
			{
				yEncoder_Count --;					//�˷�����Ϊ��ת�����������Լ�
			}
		}
		EXTI_ClearITPendingBit(EXTI_Line0);			//����ⲿ�ж�0���ߵ��жϱ�־λ
													//�жϱ�־λ�������
													//�����жϽ��������ϵش�����������������
	}
}

/**
  * ��    ����EXTI1�ⲿ�жϺ���
  * ��    ������
  * �� �� ֵ����
  * ע������˺���Ϊ�жϺ�����������ã��жϴ������Զ�ִ��
  *           ������ΪԤ����ָ�����ƣ����Դ������ļ�����
  *           ��ȷ����������ȷ���������κβ��죬�����жϺ��������ܽ���
  */
void EXTI1_IRQHandler(void)
{
	if (EXTI_GetITStatus(EXTI_Line1) == SET)		//�ж��Ƿ����ⲿ�ж�1���ߴ������ж�
	{
		/*��������������������󣬿��ٴ��ж����ŵ�ƽ���Ա��ⶶ��*/
		if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_1) == 0)
		{
			if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0) == 0)		//PA1���½��ش����жϣ���ʱ�����һ��PA0�ĵ�ƽ��Ŀ�����ж���ת����
			{
				yEncoder_Count ++;					//�˷�����Ϊ��ת��������������
			}
		}
		EXTI_ClearITPendingBit(EXTI_Line1);			//����ⲿ�ж�1���ߵ��жϱ�־λ
													//�жϱ�־λ�������
													//�����жϽ��������ϵش�����������������
	}
}
