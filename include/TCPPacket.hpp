#pragma once

#include <cstdint>

class TCPPacket
{
public:

private:
	uint16_t sourcePort;
	uint16_t destinationPort;
	uint32_t sequenceNumber;
 	uint32_t acknowledgeNumber;
	uint16_t window;
		
			

};
