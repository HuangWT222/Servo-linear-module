#ifndef __USART_H__
#define __USART_H__

// ��ʼ��USART1
void USART1_Init(void);
// ���͵����ַ�
void USART_SendChar(uint8_t data);
// �����ַ���
void USART_SendString(const char* str);
// �������ݴ�����
void USART_ReceiveDataHandler(uint8_t data);
// ��ȡ���յ�����������
uint8_t USART_GetRxData(void);
// ��ȡ���ձ�־λ
uint8_t USART_GetRxFlag(void);

#endif /* __USART_H__ */
