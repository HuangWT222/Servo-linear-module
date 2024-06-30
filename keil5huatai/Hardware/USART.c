#include "stm32f10x.h"                  // Device header
#include <string.h>

#define RX_BUFFER_SIZE 128

//定义串口发送接收的标识符和变量，数组
uint8_t Serial_RxData = 0;
uint8_t Serial_RxFlag = 0;
char Serial_RxBuffer[RX_BUFFER_SIZE];
uint8_t Serial_RxBufferIndex = 0;

//串口初始化
void USART1_Init(void)
{
    
	/*开启时钟*/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1 | RCC_APB2Periph_GPIOA, ENABLE);	//使能USART1，GPIOA时钟
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
    GPIO_PinRemapConfig(GPIO_Remap_USART1, ENABLE);

	
	/*GPIO初始化*/
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);					//将PB6引脚初始化为复用推挽输出
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);					//将PB7引脚初始化为上拉输入
	
	/*USART初始化*/
	USART_InitTypeDef USART_InitStructure;					//定义结构体变量
	USART_InitStructure.USART_BaudRate = 9600;				//波特率
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;	//硬件流控制，不需要
	USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;	//模式，发送模式和接收模式均选择
	USART_InitStructure.USART_Parity = USART_Parity_No;		//奇偶校验，不需要
	USART_InitStructure.USART_StopBits = USART_StopBits_1;	//停止位，选择1位
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;		//字长，选择8位
	USART_Init(USART1, &USART_InitStructure);				//将结构体变量交给USART_Init，配置USART1
	
	/*中断输出配置*/
	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);			//开启串口接收数据的中断
	
	/*NVIC中断分组*/
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);			//配置NVIC为分组2
	
	/*NVIC配置*/
	NVIC_InitTypeDef NVIC_InitStructure;					//定义结构体变量
	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;		//选择配置NVIC的USART1线
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//指定NVIC线路使能
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;		//指定NVIC线路的抢占优先级为1
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;		//指定NVIC线路的响应优先级为1
	NVIC_Init(&NVIC_InitStructure);							//将结构体变量交给NVIC_Init，配置NVIC外设
	
	/*USART使能*/
	USART_Cmd(USART1, ENABLE);								//使能USART1，串口开始运行
}

void USART_SendChar(uint8_t data) {
    while (USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET);    // 等待发送缓冲区为空
    USART_SendData(USART1, data);    // 发送数据
    while (USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET);    // 等待发送完成
}

void USART_SendString(const char* str) {
    while (*str) {
        USART_SendChar(*str++);    // 逐个字符发送
    }
}

void USART_ReceiveDataHandler(uint8_t data) {
    // 处理接收到的数据...
    if (Serial_RxBufferIndex < RX_BUFFER_SIZE - 1) {    // 避免溢出
        Serial_RxBuffer[Serial_RxBufferIndex++] = data;    // 存储接收到的数据
    }
    
    if (data == '\n') {    // 判断是否接收到换行符
        Serial_RxBuffer[Serial_RxBufferIndex] = '\0';    // 在接收缓冲区末尾添加字符串结束符
        Serial_RxFlag = 1;    // 设置接收标志位为1
        Serial_RxBufferIndex = 0;    // 重置接收缓冲区索引
    }
}

uint8_t USART_GetRxData(void) {
    return Serial_RxData;    // 返回接收的数据变量
}

uint8_t USART_GetRxFlag(void) {
    if (Serial_RxFlag == 1) {    // 如果标志位为1
        Serial_RxFlag = 0;
        return 1;    // 返回1，并自动清零标志位
    }
    return 0;    // 如果标志位为0，则返回0
}


/*
//中断
void USART1_IRQHandler(void) {
    if (USART_GetITStatus(USART1, USART_IT_RXNE) != RESET) {    // 接收到数据
        uint8_t data = USART_ReceiveData(USART1);    // 读取接收到的数据
        
        // 在这里进行接收到数据后的操作
		
		USART_ClearITPendingBit(USART1, USART_IT_RXNE);    // 清除接收中断标志位
    }
}
*/



