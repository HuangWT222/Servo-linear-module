#include "stm32f10x.h"                  // Device header

/**
  * ��    ����PWM��ʼ��
  * ��    ������
  * �� �� ֵ����
  * ��    ע��ʹ�õ���DRV8833�������������IN����PWM�����������Ҫ��������ͨ��
  */
void PWM_Init(void)
{
	/*����ʱ��*/
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);			//����TIM3��ʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);			//����GPIOA��ʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);			//����GPIOB��ʱ��
	/*GPIO��ʼ��*/
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);							//��PA6��PA7���ų�ʼ��Ϊ�����������	
																	//��������Ƶ����ţ�����Ҫ����Ϊ����ģʽ
	/*GPIO��ʼ��*/
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);							//��PB0��PB1���ų�ʼ��Ϊ�����������	
																	//��������Ƶ����ţ�����Ҫ����Ϊ����ģʽ
	/*����ʱ��Դ*/
	TIM_InternalClockConfig(TIM3);		//ѡ��TIM3Ϊ�ڲ�ʱ�ӣ��������ô˺�����TIMĬ��ҲΪ�ڲ�ʱ��
	
	/*ʱ����Ԫ��ʼ��*/
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;				//����ṹ�����
	TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;     //ʱ�ӷ�Ƶ��ѡ�񲻷�Ƶ���˲������������˲���ʱ�ӣ���Ӱ��ʱ����Ԫ����
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up; //������ģʽ��ѡ�����ϼ���
	TIM_TimeBaseInitStructure.TIM_Period = 100-1;                 //�������ڣ���ARR��ֵ
	TIM_TimeBaseInitStructure.TIM_Prescaler = 36-1;               //Ԥ��Ƶ������PSC��ֵ
	TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;            //�ظ����������߼���ʱ���Ż��õ�
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseInitStructure);             //���ṹ���������TIM_TimeBaseInit������TIM3��ʱ����Ԫ
	
	/*����Ƚϳ�ʼ��*/ 
	TIM_OCInitTypeDef TIM_OCInitStructure;							//����ṹ�����
	TIM_OCStructInit(&TIM_OCInitStructure);                         //�ṹ���ʼ�������ṹ��û��������ֵ
	                                                                //�����ִ�д˺��������ṹ�����г�Ա����һ��Ĭ��ֵ
	                                                                //����ṹ���ֵ��ȷ��������
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;               //����Ƚ�ģʽ��ѡ��PWMģʽ1
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;       //������ԣ�ѡ��Ϊ�ߣ���ѡ����Ϊ�ͣ�������ߵ͵�ƽȡ��
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;   //���ʹ��
	TIM_OCInitStructure.TIM_Pulse = 0;								//��ʼ��CCRֵ
	TIM_OC1Init(TIM3, &TIM_OCInitStructure);                        //���ṹ���������TIM_OC1Init������TIM3������Ƚ�ͨ��1
	TIM_OC2Init(TIM3, &TIM_OCInitStructure);                        //���ṹ���������TIM_OC2Init������TIM3������Ƚ�ͨ��2
	TIM_OC3Init(TIM3, &TIM_OCInitStructure);                        //���ṹ���������TIM_OC1Init������TIM3������Ƚ�ͨ��3
	TIM_OC4Init(TIM3, &TIM_OCInitStructure);                        //���ṹ���������TIM_OC2Init������TIM3������Ƚ�ͨ��4
	/*TIMʹ��*/
	TIM_Cmd(TIM3, ENABLE);			//ʹ��TIM3����ʱ����ʼ����
}

/**
  * ��    ����PWM����CCR
  * ��    ����Compare Ҫд���CCR��ֵ����Χ��0~100
  * �� �� ֵ����
  * ע�����CCR��ARR��ͬ����ռ�ձȣ��˺���������CCR��ֵ������ֱ����ռ�ձ�
  *           ռ�ձ�Duty = CCR / (ARR + 1)
  */
void PWM_SetCompare1(uint16_t Compare)
{
	TIM_SetCompare1(TIM3, Compare);		//����CCR1��ֵ
}

void PWM_SetCompare2(uint16_t Compare)
{
	TIM_SetCompare2(TIM3, Compare);		//����CCR2��ֵ
}

void PWM_SetCompare3(uint16_t Compare)
{
	TIM_SetCompare3(TIM3, Compare);		//����CCR3��ֵ
}

void PWM_SetCompare4(uint16_t Compare)
{
	TIM_SetCompare4(TIM3, Compare);		//����CCR4��ֵ
}

/**
  * ��    ����������ṩ������ѹ������Ϊ����ռ�ձ�
  * ��    ����mian.c��ִ����pid�еõ����ٶ�ֵ
  * �� �� ֵ����
  * ע��������ڵ������������ѹ����Ҫ���в�����������֪CRR��Χ��0~100��
  *          ��������д����һ���޷�
  */
void xMotor_SetSpeed(int16_t MotorSpeed)
{
	if(MotorSpeed==0)									//�����ֹʱ������
	{
		TIM_SetCompare1(TIM3, 0);
		TIM_SetCompare2(TIM3, 0);
	}
	else if(MotorSpeed>0)
	{
		if(MotorSpeed>70){MotorSpeed=70;}				//�޷�
		TIM_SetCompare1(TIM3, 0);
		TIM_SetCompare2(TIM3, MotorSpeed+30);			//������������ת
	}
	else												
	{
		if(MotorSpeed<-70){MotorSpeed=-70;}				//�޷�
		TIM_SetCompare1(TIM3, -MotorSpeed+30);			//������������ת
		TIM_SetCompare2(TIM3, 0);
	}
}

void yMotor_SetSpeed(int16_t MotorSpeed)
{
	if(MotorSpeed==0)									//�����ֹʱ������
	{
		TIM_SetCompare3(TIM3, 0);
		TIM_SetCompare4(TIM3, 0);
	}
	else if(MotorSpeed>0)
	{
		if(MotorSpeed>70){MotorSpeed=70;}				//�޷�
		TIM_SetCompare3(TIM3, 0);
		TIM_SetCompare4(TIM3, MotorSpeed+30);			//������������ת
	}
	else												
	{
		if(MotorSpeed<-70){MotorSpeed=-70;}				//�޷�
		TIM_SetCompare3(TIM3, -MotorSpeed+30);			//������������ת
		TIM_SetCompare4(TIM3, 0);
	}
}
