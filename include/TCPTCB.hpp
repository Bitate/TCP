#include <cstdint>

#include "TCPConnection"
#include "TCPSocket"

class TCPTCB
{
public:

private:
	TCPConnection* localConnection;
	TCPSocket* localSocket;
	TCPSocket* foreignSocket;
	
	uint16_t receiveWindowSize;
	uint32_t receiveLeftWindowEdge;
	uint16_t receivePacketBufferSize;
	uint16_t sendWindowSize;
	uint32_t sendLeftWindowEdge;
	uint16_t sendPakcetBufferSize;	

	uint32_t nextPacketSequenceNumber;

	TCPConnectionState* connectionState;
	
	// 16 bits special flags
	
	uint16_t retransmissionTimeout;
	

};
