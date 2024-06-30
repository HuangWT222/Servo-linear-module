#include "stm32f10x.h"                  // Device header
#include <string.h>

#define RX_BUFFER_SIZE 128

//���崮�ڷ��ͽ��յı�ʶ���ͱ���������
uint8_t Serial_RxData = 0;
uint8_t Serial_RxFlag = 0;
char Serial_RxBuffer[RX_BUFFER_SIZE];
uint8_t Serial_RxBufferIndex = 0;

//���ڳ�ʼ��
void USART1_Init(void)
{
    
	/*����ʱ��*/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1 | RCC_APB2Periph_GPIOA, ENABLE);	//ʹ��USART1��GPIOAʱ��
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
    GPIO_PinRemapConfig(GPIO_Remap_USART1, ENABLE);

	
	/*GPIO��ʼ��*/
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);					//��PB6���ų�ʼ��Ϊ�����������
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);					//��PB7���ų�ʼ��Ϊ��������
	
	/*USART��ʼ��*/
	USART_InitTypeDef USART_InitStructure;					//����ṹ�����
	USART_InitStructure.USART_BaudRate = 9600;				//������
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;	//Ӳ�������ƣ�����Ҫ
	USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;	//ģʽ������ģʽ�ͽ���ģʽ��ѡ��
	USART_InitStructure.USART_Parity = USART_Parity_No;		//��żУ�飬����Ҫ
	USART_InitStructure.USART_StopBits = USART_StopBits_1;	//ֹͣλ��ѡ��1λ
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;		//�ֳ���ѡ��8λ
	USART_Init(USART1, &USART_InitStructure);				//���ṹ���������USART_Init������USART1
	
	/*�ж��������*/
	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);			//�������ڽ������ݵ��ж�
	
	/*NVIC�жϷ���*/
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);			//����NVICΪ����2
	
	/*NVIC����*/
	NVIC_InitTypeDef NVIC_InitStructure;					//����ṹ�����
	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;		//ѡ������NVIC��USART1��
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//ָ��NVIC��·ʹ��
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;		//ָ��NVIC��·����ռ���ȼ�Ϊ1
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;		//ָ��NVIC��·����Ӧ���ȼ�Ϊ1
	NVIC_Init(&NVIC_InitStructure);							//���ṹ���������NVIC_Init������NVIC����
	
	/*USARTʹ��*/
	USART_Cmd(USART1, ENABLE);								//ʹ��USART1�����ڿ�ʼ����
}

void USART_SendChar(uint8_t data) {
    while (USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET);    // �ȴ����ͻ�����Ϊ��
    USART_SendData(USART1, data);    // ��������
    while (USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET);    // �ȴ��������
}

void USART_SendString(const char* str) {
    while (*str) {
        USART_SendChar(*str++);    // ����ַ�����
    }
}

void USART_ReceiveDataHandler(uint8_t data) {
    // ������յ�������...
    if (Serial_RxBufferIndex < RX_BUFFER_SIZE - 1) {    // �������
        Serial_RxBuffer[Serial_RxBufferIndex++] = data;    // �洢���յ�������
    }
    
    if (data == '\n') {    // �ж��Ƿ���յ����з�
        Serial_RxBuffer[Serial_RxBufferIndex] = '\0';    // �ڽ��ջ�����ĩβ����ַ���������
        Serial_RxFlag = 1;    // ���ý��ձ�־λΪ1
        Serial_RxBufferIndex = 0;    // ���ý��ջ���������
    }
}

uint8_t USART_GetRxData(void) {
    return Serial_RxData;    // ���ؽ��յ����ݱ���
}

uint8_t USART_GetRxFlag(void) {
    if (Serial_RxFlag == 1) {    // �����־λΪ1
        Serial_RxFlag = 0;
        return 1;    // ����1�����Զ������־λ
    }
    return 0;    // �����־λΪ0���򷵻�0
}


/*
//�ж�
void USART1_IRQHandler(void) {
    if (USART_GetITStatus(USART1, USART_IT_RXNE) != RESET) {    // ���յ�����
        uint8_t data = USART_ReceiveData(USART1);    // ��ȡ���յ�������
        
        // ��������н��յ����ݺ�Ĳ���
		
		USART_ClearITPendingBit(USART1, USART_IT_RXNE);    // ��������жϱ�־λ
    }
}
*/



