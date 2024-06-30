#include "stm32f10x.h"                  // Device header
#include "OLED.h"						//OLEDͷ�ļ�����			
#include "USART.h"						//����ͷ�ļ�����	
#include "Modbus.h"						//ModebusЭ��ͷ�ļ�����	
#include "Encoder.h"					//������ͷ�ļ�����	
#include "PID.h"						//PIDͷ�ļ�����	
#include <string.h>						//�ַ���ͷ�ļ�����	
#include "PWM.h"						//PWMͷ�ļ�����	
#include "TIM.h"						//��ʱ��ͷ�ļ�����	
#include "SWITCH.h"						//��λ����ͷ�ļ�����	
#include "Delay.h"						//�ӳٺ���ͷ�ļ�����	
 
 //�������
extern int16_t KP;						//ȫ�ֺ�������ȡModbus��KP
extern int16_t KI;						//ȫ�ֺ�������ȡModbus��KI
extern int16_t KD;						//ȫ�ֺ�������ȡModbus��KD
extern int16_t Dx;						//ȫ�ֺ�������ȡModbus�о���Dx
extern int16_t Dy;						//ȫ�ֺ�������ȡModbus�о���Dy
float xcurrent_location;					//���嵱ǰλ�õı���
float ycurrent_location;					//���嵱ǰλ�õı���
int32_t Numx;							//�������������ֵ�ۼӣ���xcurrent_location�ʱ���
int32_t Numy;							//�������������ֵ�ۼӣ���ycurrent_location�ʱ���
unsigned char rcbuf[100];    			//MODBUS���ջ�����
uint8_t i;								//ѭ�����������iֵ

int main(void)
{
	// * 1.���豸�ĳ�ʼ��
	OLED_Init();
	USART1_Init();
	PWM_Init();
	Tim_Init();
	xEncoder_Init();
	yEncoder_Init();
	Switch_Init();
	
	// * 2.�ϵ縴λ�����ƶ���̨�ص���λ���ش�
	while(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_13)==1){xMotor_SetSpeed(20);}//�ϵ��Զ���λ�����￪������ѭ��
	Delay_ms(1000);					//�ṩһ������ǰ����ʱ�䣬���⿪�ض�����ԭ����û��λ
	xMotor_SetSpeed(0);				//��ͣ
	Delay_ms(2000);					//�ӳ�
	
	// * 3.��ʼִ��
	 while(1)
	 {
		Numx += xEncoder_Get();					//��ȡ���ϴ˵��ô˺�������ת������������ֵ����������ֵ�ӵ�Num��
		Numy += yEncoder_Get();					//��ȡ���ϴ˵��ô˺�������ת������������ֵ����������ֵ�ӵ�Num��
		xcurrent_location = Numx*0.0348/100;
		ycurrent_location = Numy*0.0348/100;		//�ҵ��豸���Գ����������ֵ����ȷ��mm���������ƶ�����/�������õ�һ������ƶ�����
												//���磺ǰ��0.5cm�õ���������39200����ô5/39200�õ��ľ���һ�����ƶ��ľ��룬�ٰ�
												//		������϶�ȡ�������������õ��ľ���Ŀǰ���ƶ�����
		OLED_ShowSignedNum(1,1,KP,5);
		OLED_ShowSignedNum(2,1,KD,5);
		OLED_ShowSignedNum(3,1,Numx,5);
		OLED_ShowSignedNum(4,1,xcurrent_location,5);
		int16_t speedx = xLocation_PID(xcurrent_location,Dx);//��ǰλ�ã�Ŀ��λ��

		xMotor_SetSpeed(-speedx);
		int16_t speedy = yLocation_PID(ycurrent_location,Dy);//��ǰλ�ã�Ŀ��λ��
		yMotor_SetSpeed(-speedy);
	 }
 }

 
 // * 4.���մ��ڷ��͡�ʹ�ô����ж�
void USART1_IRQHandler(void) 
{
    if (USART_GetITStatus(USART1, USART_IT_RXNE) != RESET) 
	{   
		uint8_t receivedData = USART_ReceiveData(USART1); 	// ��ȡ���յ�������
		i%=8;												// ʵ��ÿ��λ�����·���
		rcbuf[i++]=receivedData;							// ��λ����
		uint16_t len = strlen((char*)rcbuf);				// ��ȡ���鳤�ȣ�����CRC����ʱ����ʹ��
		// �����յ������ݴ��ݸ� Modbus ������
		ProcessModbusRTUFrame(rcbuf, len);					//ִ��modbusЭ��Ķ�ȡ
		USART_ClearITPendingBit(USART1, USART_IT_RXNE);    	// ��������жϱ�־λ
    }
}

// * 5.��ʱ���жϣ�ʵ�ֵ�Ƭ�������򴮿ڷ���KP��KI��KD��D������
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
            while (USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET); // �ȴ��������
        }
        TIM_ClearITPendingBit(TIM4, TIM_IT_Update);
    }
}
