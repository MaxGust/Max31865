#ifndef __MAX31865_H
#define __MAX31865_H	 


typedef struct MAX31865_STR
{
	void(*max31865_cs_l)(void);
	void(*max31865_cs_h)(void);
	uint8_t(*max31865_spi_rw)(uint8_t);
}MAX31865_STR;
void Max31865_Init(MAX31865_STR *base,
	void(*MAX31865_CS_L)(void),
	void(*MAX31865_CS_H)(void),
	uint8_t(*MAX31865_SPI_RW)(uint8_t));
/**********************************************************************************************************
*	函 数 名: 得到温度
*	功能说明: 单位摄氏度
*	传    参: 
*	返 回 值: 
*   说    明: 
*********************************************************************************************************/
float Get_Temperature(MAX31865_STR *base);

#endif
