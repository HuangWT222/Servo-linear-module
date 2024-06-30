#include "stm32f10x.h"                

//����ȫ�ֱ�������Modbus�ж�ȡ
extern int16_t KP;
extern int16_t KI;
extern int16_t KD;

 /*
  * ��    ����x��λ��pid
  * ��    ����Ŀǰ���룬Ŀ�����
  * �� �� ֵ������ٶ�
  */
int16_t xLocation_PID(float distance,float Td)
{
	static float xL_error,xL_error_last,xv_L;			// ������̬��������PIddle����Ч
	xL_error = distance-Td;  						// �õ���Ŀǰλ�� - Ŀ��λ�õõ�
	xv_L = KP*xL_error + KD*(xL_error_last-xL_error);	// PID����
	xL_error_last = xL_error;							// ������Ͻ������Ϊ��һ�����
	return xv_L;										// �������ٶ�ֵ����
}

int16_t yLocation_PID(float distance,float Td)
{
	static float yL_error,yL_error_last,yv_L;			// ������̬��������PIddle����Ч
	yL_error = distance-Td;  						// �õ���Ŀǰλ�� - Ŀ��λ�õõ�
	yv_L = KP*yL_error + KD*(yL_error_last-yL_error);	// PID����
	yL_error_last = yL_error;							// ������Ͻ������Ϊ��һ�����
	return yv_L;										// �������ٶ�ֵ����
}
