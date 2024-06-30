#include "stm32f10x.h"                  // Device header
#include "OLED.h"						//OLED头文件声明			
#include "USART.h"						//串口头文件声明	
#include "Modbus.h"						//Modebus协议头文件声明	
#include "Encoder.h"					//编码器头文件声明	
#include "PID.h"						//PID头文件声明	
#include <string.h>						//字符串头文件声明	
#include "PWM.h"						//PWM头文件声明	
#include "TIM.h"						//定时器头文件声明	
#include "SWITCH.h"						//限位开关头文件声明	
#include "Delay.h"						//延迟函数头文件声明	
 
 //定义变量
extern int16_t KP;						//全局函数，获取Modbus中KP
extern int16_t KI;						//全局函数，获取Modbus中KI
extern int16_t KD;						//全局函数，获取Modbus中KD
extern int16_t Dx;						//全局函数，获取Modbus中距离Dx
extern int16_t Dy;						//全局函数，获取Modbus中距离Dy
float xcurrent_location;					//定义当前位置的变量
float ycurrent_location;					//定义当前位置的变量
int32_t Numx;							//定义编码器的数值累加，与xcurrent_location呈比例
int32_t Numy;							//定义编码器的数值累加，与ycurrent_location呈比例
unsigned char rcbuf[100];    			//MODBUS接收缓冲区
uint8_t i;								//循环发送数组的i值

int main(void)
{
	// * 1.各设备的初始化
	OLED_Init();
	USART1_Init();
	PWM_Init();
	Tim_Init();
	xEncoder_Init();
	yEncoder_Init();
	Switch_Init();
	
	// * 2.上电复位，让移动滑台回到限位开关处
	while(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_13)==1){xMotor_SetSpeed(20);}//上电自动复位，到达开关跳出循环
	Delay_ms(1000);					//提供一个继续前进的时间，避免开关抖动等原因导致没复位
	xMotor_SetSpeed(0);				//暂停
	Delay_ms(2000);					//延迟
	
	// * 3.开始执行
	 while(1)
	 {
		Numx += xEncoder_Get();					//获取自上此调用此函数后，旋转编码器的增量值，并将增量值加到Num上
		Numy += yEncoder_Get();					//获取自上此调用此函数后，旋转编码器的增量值，并将增量值加到Num上
		xcurrent_location = Numx*0.0348/100;
		ycurrent_location = Numy*0.0348/100;		//我的设备调试出来是这个数值，精确到mm，就是用移动距离/脉冲数得到一脉冲的移动距离
												//比如：前进0.5cm得到的脉冲是39200，那么5/39200得到的就是一脉冲移动的距离，再把
												//		这个乘上读取到的脉冲数，得到的就是目前的移动距离
		OLED_ShowSignedNum(1,1,KP,5);
		OLED_ShowSignedNum(2,1,KD,5);
		OLED_ShowSignedNum(3,1,Numx,5);
		OLED_ShowSignedNum(4,1,xcurrent_location,5);
		int16_t speedx = xLocation_PID(xcurrent_location,Dx);//当前位置，目标位置

		xMotor_SetSpeed(-speedx);
		int16_t speedy = yLocation_PID(ycurrent_location,Dy);//当前位置，目标位置
		yMotor_SetSpeed(-speedy);
	 }
 }

 
 // * 4.接收串口发送。使用串口中断
void USART1_IRQHandler(void) 
{
    if (USART_GetITStatus(USART1, USART_IT_RXNE) != RESET) 
	{   
		uint8_t receivedData = USART_ReceiveData(USART1); 	// 读取接收到的数据
		i%=8;												// 实现每八位就重新发送
		rcbuf[i++]=receivedData;							// 逐位发送
		uint16_t len = strlen((char*)rcbuf);				// 读取数组长度，当有CRC检验时可以使用
		// 将接收到的数据传递给 Modbus 处理函数
		ProcessModbusRTUFrame(rcbuf, len);					//执行modbus协议的读取
		USART_ClearITPendingBit(USART1, USART_IT_RXNE);    	// 清除接收中断标志位
    }
}

// * 5.定时器中断，实现单片机不断向串口发送KP，KI，KD，D的数据
void TIM4_IRQHandler(void)
{
    if (TIM_GetITStatus(TIM4, TIM_IT_Update) == SET)
    {
        uint16_t i;
        uint16_t length = 8;
        char Array[8];
        Array[0] = KP / 256; Array[1] = KP % 256; Array[2] = KI / 256; Array[3] = KI % 256;
        Array[4] = KD / 256; Array[5] = KD % 256; Array[6] = 256 / 256; Array[7] = 257 % 256;

        for (i = 0; i < length; i++)
        {
            USART_SendData(USART1, Array[i]);
            while (USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET); // 等待发送完成
        }
        TIM_ClearITPendingBit(TIM4, TIM_IT_Update);
    }
}
