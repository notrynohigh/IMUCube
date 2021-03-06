/*====================================================================================================*/
/*====================================================================================================*/
#include "drivers\nrf5x_system.h"
#include "modules\module_serial.h"

#include "imuCube.h"
/*====================================================================================================*/
/*====================================================================================================*/
void IMUCube_Init( void )
{
  IMUCube_CKOCK_Config();
  IMUCube_GPIO_Config();
  IMUCube_UART_Config();
}
/*====================================================================================================*/
/*====================================================================================================*/
void IMUCube_Loop( void )
{
  uint8_t recvByte = 0;

  while(1) {
    recvByte = Serial_RecvByte();
    if(recvByte == 0x0D)
      Serial_SendByte(0x0A);
    Serial_SendByte(recvByte);
  }
}
/*====================================================================================================*/
/*====================================================================================================*/
