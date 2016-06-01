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
	void send();
	void setPurple();
	void setBlue();
	void setRed();
	void setUV();
	void setChannels(int offset, int ch1, int ch2, int ch3, int ch4, int ch5, int ch6, int ch7, int ch8);
private: 
		WORD wVID;
		WORD wPID;
		uint16_t device_connected;
		uint8_t Num_Devices;
		//enum { maxLimit = 513 };
		array<unsigned char> ^myDmx;
};





