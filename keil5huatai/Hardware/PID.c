#include "stm32f10x.h"                

//定义全局变量，从Modbus中读取
extern int16_t KP;
extern int16_t KI;
extern int16_t KD;

 /*
  * 函    数：x轴位置pid
  * 参    数：目前距离，目标距离
  * 返 回 值：电机速度
  */
int16_t xLocation_PID(float distance,float Td)
{
	static float xL_error,xL_error_last,xv_L;			// 声明静态变量，在PIddle中有效
	xL_error = distance-Td;  						// 得到误差，目前位置 - 目标位置得到
	xv_L = KP*xL_error + KD*(xL_error_last-xL_error);	// PID函数
	xL_error_last = xL_error;							// 计算完毕将误差置为上一次误差
	return xv_L;										// 将最终速度值返回
}

int16_t yLocation_PID(float distance,float Td)
{
	static float yL_error,yL_error_last,yv_L;			// 声明静态变量，在PIddle中有效
	yL_error = distance-Td;  						// 得到误差，目前位置 - 目标位置得到
	yv_L = KP*yL_error + KD*(yL_error_last-yL_error);	// PID函数
	yL_error_last = yL_error;							// 计算完毕将误差置为上一次误差
	return yv_L;										// 将最终速度值返回
}
