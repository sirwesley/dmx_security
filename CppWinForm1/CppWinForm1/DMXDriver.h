#pragma once

#include "pro_driver.h"


ref class DMXDriver
{
public:
	DMXDriver();
	void FTDI_ClosePort();
	int FTDI_ListDevices();
	int FTDI_SendData(int label, unsigned char *data, int length);
	int FTDI_ReceiveData(int label, unsigned char *data, unsigned int expected_length);
	void FTDI_PurgeBuffer();
	uint16_t FTDI_OpenDevice(int device_num);
	uint8_t FTDI_RxDMX(uint8_t label, unsigned char *data, uint32_t* expected_length);
	int FTDI_connect();
	int getDeviceConnected();
	void setPurple();
	void setBlue();
	void setRed();
private: 
		WORD wVID;
		WORD wPID;
		uint16_t device_connected;
		uint8_t Num_Devices;
};





