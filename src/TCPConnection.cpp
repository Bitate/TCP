#include "TCPConnection.hpp"

TCPConnection::TCPConnection()
	: isConnectionEstablished(false),
	  connectionStatus(TCPConnectionStatus::CLOSED)
{
	
}

TCPConnection::~TCPConnection()
{

}

TCPConnectionStatus TCPConnection::getConnectionStatus(const TCPConnection& givenConnection)
{
	return TCPConnectionStatus::CLOSED;
}

uint32_t TCPConnection::generateInitialSequenceNumber()
{
	return 0;
}