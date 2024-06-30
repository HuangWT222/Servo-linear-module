#include "stm32f10x.h"                  // Device header
#include "Modbus.h"
#include "string.h"


//����KP��KI��KDֵ������λ��ͨ�����ڷ�����ֵ
int16_t KP;
int16_t KI;
int16_t KD;
int16_t Dx;
int16_t Dy;

void ProcessModbusRTUFrame(uint8_t* frame, uint16_t length) 
{
    // ȷ��֡���Ⱥ�CRCУ����ȷ
	//............����Ŀ��Ϊ�򵥣��˴���д��
	
    uint8_t slaveId = frame[0];							//��ȡ�ӻ�id
    uint8_t functionCode = frame[1];					//��ȡ������
	uint16_t Address = frame[2]*256+frame[3];			//��ȡ��ַ
    int16_t Value = frame[4]*256+frame[5];				//��ȡ����
	if(slaveId == 1)									//�ж��Ƿ��Ǹôӻ�λ��
	{
		switch (functionCode) 							//���ݹ�����ʵ�ֲ�ͬ����
		{
			case 0x06: 									//0x06Ϊд�빦��
			{ // д�����Ĵ���							//������ģ���˼Ĵ�����ַ
				if (Address == 0) {						//��ַ0ʱд��KPֵ
					KP = Value;
				} else if (Address == 1) {				//��ַ1ʱд��KIֵ
					KI = Value;
				} else if (Address == 2) {				//��ַ2ʱд��KDֵ
					KD = Value;
				}else if (Address == 3) {				//��ַ3ʱд��Dxֵ
					Dx = Value;
				}else if (Address == 4) {				//��ַ4ʱд��Dyֵ
					Dy = Value;
				}
				break;
			}
			default:
				break;
		}
	}
}

