#ifndef __USART_H__
#define __USART_H__

// 初始化USART1
void USART1_Init(void);
// 发送单个字符
void USART_SendChar(uint8_t data);
// 发送字符串
void USART_SendString(const char* str);
// 接收数据处理函数
void USART_ReceiveDataHandler(uint8_t data);
// 获取接收到的最新数据
uint8_t USART_GetRxData(void);
// 获取接收标志位
uint8_t USART_GetRxFlag(void);

#endif /* __USART_H__ */
