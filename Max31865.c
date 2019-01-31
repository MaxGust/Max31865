#include "max31865.h"
         

void Max31865_Init(MAX31865_STR *base,
	void(*MAX31865_CS_L)(void),
	void(*MAX31865_CS_H)(void),
	uint8_t(*MAX31865_SPI_RW)(uint8_t))
{
	base->max31865_cs_l = MAX31865_CS_L;
	base->max31865_cs_h = MAX31865_CS_H;
	base->max31865_spi_rw = MAX31865_SPI_RW;

	base->max31865_cs_l;
	base->max31865_spi_rw(0x80)	;//配置寄存器地址
	base->max31865_spi_rw(0xd1)	;//写0xd1(1101_0001)到配置寄存器:3-wire RTD,50Hz filter select
	base->max31865_cs_h;	
}

float Get_Temperature(MAX31865_STR *base)
{
	float  temperature;                   //store the value of RTD MSB and RTD LSB register
	u16 RTD = 0;

	base->max31865_cs_l;
	base->max31865_spi_rw(0x01)	;//RTD MSBs地址
	RTD = base->max31865_spi_rw(0)	;//RTD H  这里的0未用到，接收数据只传进去SPI1SPI_I2S_ReceiveData(SPI1)
	RTD <<= 8;
	RTD |= base->max31865_spi_rw(0)	;//RTD L
	base->max31865_cs_h; 

	RTD = RTD>>1;//需要右移一位
	temperature = RTD/32.0 - 256;//根据说明书11页
	// temperature *= 10.0;

	return temperature;
}  