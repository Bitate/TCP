#include "TCPPacket.hpp"

TCPPacket::TCPPacket()
{

}

TCPPacket::~TCPPacket()
{

}

void TCPPacket::setSourcePort(const uint16_t& newSourcePort)
{
    sourcePort = newSourcePort;
}

void TCPPacket::setDestinationPort(const uint16_t& newDestinationPort)
{
    destinationPort = newDestinationPort;
}

void TCPPacket::setSequenceNumber(const uint32_t& newSequenceNumber)
{
    sequenceNumber = newSequenceNumber;
}

void TCPPacket::setAcknowledgeNumber(const uint32_t& newAcknowledgeNumber)
{
    acknowledgeNumber = newAcknowledgeNumber;
}

void TCPPacket::setDataOffset(const uint16_t& newDataOffset)
{
    dataOffset = newDataOffset;
}

void TCPPacket::setReserved(const uint16_t& newReserved)
{
    reserved = newReserved;
}

void TCPPacket::setUGR(const uint16_t& newUGR)
{
    UGR = newUGR;
}

void TCPPacket::setACK(const uint16_t& newACK)
{
    ACK = newACK;
}

void TCPPacket::setPSH(const uint16_t& newPSH)
{
    PSH = newPSH;
}

void TCPPacket::setRST(const uint16_t& newRST)
{
    RST = newRST;
}
	
void TCPPacket::setSYN(const uint16_t& newSYN)
{
    SYN = newSYN;
}

void TCPPacket::setFIN(const uint16_t& newFIN)
{
    FIN = newFIN;
}

void TCPPacket::setWindowSize(const uint16_t& newWindowSize)
{
    windowSize = newWindowSize;
}

void TCPPacket::setChecksum(const uint16_t& newChecksum)
{   
    checksum = newChecksum;
}

void TCPPacket::setUrgentPointer(const uint16_t& newUrgentPointer)
{
    urgentPointer = newUrgentPointer;
}

void TCPPacket::setData(const std::vector<uint8_t>& newData)
{
    data = newData;
}