#include "stm32f10x.h"                  // Device header
#include "Modbus.h"
#include "string.h"


//定义KP，KI，KD值，由上位机通过串口发送数值
int16_t KP;
int16_t KI;
int16_t KD;
int16_t Dx;
int16_t Dy;

void ProcessModbusRTUFrame(uint8_t* frame, uint16_t length) 
{
    // 确保帧长度和CRC校验正确
	//............本项目较为简单，此处不写了
	
    uint8_t slaveId = frame[0];							//读取从机id
    uint8_t functionCode = frame[1];					//读取功能码
	uint16_t Address = frame[2]*256+frame[3];			//读取地址
    int16_t Value = frame[4]*256+frame[5];				//读取数据
	if(slaveId == 1)									//判断是否是该从机位置
	{
		switch (functionCode) 							//根据功能码实现不同功能
		{
			case 0x06: 									//0x06为写入功能
			{ // 写单个寄存器							//这里我模拟了寄存器地址
				if (Address == 0) {						//地址0时写入KP值
					KP = Value;
				} else if (Address == 1) {				//地址1时写入KI值
					KI = Value;
				} else if (Address == 2) {				//地址2时写入KD值
					KD = Value;
				}else if (Address == 3) {				//地址3时写入Dx值
					Dx = Value;
				}else if (Address == 4) {				//地址4时写入Dy值
					Dy = Value;
				}
				break;
			}
			default:
				break;
		}
	}
}

