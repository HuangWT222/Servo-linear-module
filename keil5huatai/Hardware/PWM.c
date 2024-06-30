#include "stm32f10x.h"                  // Device header

/**
  * 函    数：PWM初始化
  * 参    数：无
  * 返 回 值：无
  * 备    注：使用的是DRV8833电机驱动，两个IN脚用PWM输出，所以需要定义两个通道
  */
void PWM_Init(void)
{
	/*开启时钟*/
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);			//开启TIM3的时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);			//开启GPIOA的时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);			//开启GPIOB的时钟
	/*GPIO初始化*/
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);							//将PA6和PA7引脚初始化为复用推挽输出	
																	//受外设控制的引脚，均需要配置为复用模式
	/*GPIO初始化*/
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);							//将PB0和PB1引脚初始化为复用推挽输出	
																	//受外设控制的引脚，均需要配置为复用模式
	/*配置时钟源*/
	TIM_InternalClockConfig(TIM3);		//选择TIM3为内部时钟，若不调用此函数，TIM默认也为内部时钟
	
	/*时基单元初始化*/
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;				//定义结构体变量
	TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;     //时钟分频，选择不分频，此参数用于配置滤波器时钟，不影响时基单元功能
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up; //计数器模式，选择向上计数
	TIM_TimeBaseInitStructure.TIM_Period = 100-1;                 //计数周期，即ARR的值
	TIM_TimeBaseInitStructure.TIM_Prescaler = 36-1;               //预分频器，即PSC的值
	TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;            //重复计数器，高级定时器才会用到
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseInitStructure);             //将结构体变量交给TIM_TimeBaseInit，配置TIM3的时基单元
	
	/*输出比较初始化*/ 
	TIM_OCInitTypeDef TIM_OCInitStructure;							//定义结构体变量
	TIM_OCStructInit(&TIM_OCInitStructure);                         //结构体初始化，若结构体没有完整赋值
	                                                                //则最好执行此函数，给结构体所有成员都赋一个默认值
	                                                                //避免结构体初值不确定的问题
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;               //输出比较模式，选择PWM模式1
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;       //输出极性，选择为高，若选择极性为低，则输出高低电平取反
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;   //输出使能
	TIM_OCInitStructure.TIM_Pulse = 0;								//初始的CCR值
	TIM_OC1Init(TIM3, &TIM_OCInitStructure);                        //将结构体变量交给TIM_OC1Init，配置TIM3的输出比较通道1
	TIM_OC2Init(TIM3, &TIM_OCInitStructure);                        //将结构体变量交给TIM_OC2Init，配置TIM3的输出比较通道2
	TIM_OC3Init(TIM3, &TIM_OCInitStructure);                        //将结构体变量交给TIM_OC1Init，配置TIM3的输出比较通道3
	TIM_OC4Init(TIM3, &TIM_OCInitStructure);                        //将结构体变量交给TIM_OC2Init，配置TIM3的输出比较通道4
	/*TIM使能*/
	TIM_Cmd(TIM3, ENABLE);			//使能TIM3，定时器开始运行
}

/**
  * 函    数：PWM设置CCR
  * 参    数：Compare 要写入的CCR的值，范围：0~100
  * 返 回 值：无
  * 注意事项：CCR和ARR共同决定占空比，此函数仅设置CCR的值，并不直接是占空比
  *           占空比Duty = CCR / (ARR + 1)
  */
void PWM_SetCompare1(uint16_t Compare)
{
	TIM_SetCompare1(TIM3, Compare);		//设置CCR1的值
}

void PWM_SetCompare2(uint16_t Compare)
{
	TIM_SetCompare2(TIM3, Compare);		//设置CCR2的值
}

void PWM_SetCompare3(uint16_t Compare)
{
	TIM_SetCompare3(TIM3, Compare);		//设置CCR3的值
}

void PWM_SetCompare4(uint16_t Compare)
{
	TIM_SetCompare4(TIM3, Compare);		//设置CCR4的值
}

/**
  * 函    数：给电机提供驱动电压，本质为调节占空比
  * 参    数：mian.c中执行在pid中得到的速度值
  * 返 回 值：无
  * 注意事项：由于电机存在死区电压，需要进行补偿，但是已知CRR范围：0~100，
  *          所以我们写入了一个限幅
  */
void xMotor_SetSpeed(int16_t MotorSpeed)
{
	if(MotorSpeed==0)									//电机静止时的设置
	{
		TIM_SetCompare1(TIM3, 0);
		TIM_SetCompare2(TIM3, 0);
	}
	else if(MotorSpeed>0)
	{
		if(MotorSpeed>70){MotorSpeed=70;}				//限幅
		TIM_SetCompare1(TIM3, 0);
		TIM_SetCompare2(TIM3, MotorSpeed+30);			//死区补偿，正转
	}
	else												
	{
		if(MotorSpeed<-70){MotorSpeed=-70;}				//限幅
		TIM_SetCompare1(TIM3, -MotorSpeed+30);			//死区补偿，反转
		TIM_SetCompare2(TIM3, 0);
	}
}

void yMotor_SetSpeed(int16_t MotorSpeed)
{
	if(MotorSpeed==0)									//电机静止时的设置
	{
		TIM_SetCompare3(TIM3, 0);
		TIM_SetCompare4(TIM3, 0);
	}
	else if(MotorSpeed>0)
	{
		if(MotorSpeed>70){MotorSpeed=70;}				//限幅
		TIM_SetCompare3(TIM3, 0);
		TIM_SetCompare4(TIM3, MotorSpeed+30);			//死区补偿，正转
	}
	else												
	{
		if(MotorSpeed<-70){MotorSpeed=-70;}				//限幅
		TIM_SetCompare3(TIM3, -MotorSpeed+30);			//死区补偿，反转
		TIM_SetCompare4(TIM3, 0);
	}
}
