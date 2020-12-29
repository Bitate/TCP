#include "TCPPacket.hpp"

TCPPacket::TCPPacket()
    : sourcePort(0), 
      destinationPort(0),
      sequenceNumber(0),
      acknowledgeNumber(0),
      dataOffset(0),
      reserved(0),
      UGR(0),
      ACK(0),
      PSH(0),
      RST(0),
      SYN(0),
      FIN(0),
      windowSize(0),
      checksum(0),
      urgentPointer(0)
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

void TCPPacket::setAcknowledgmentNumber(const uint32_t& newAcknowledgeNumber)
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

uint16_t TCPPacket::getSourcePort() const
{
    return sourcePort;
}

uint16_t TCPPacket::getDestinationPort() const
{
    return destinationPort;
}

uint32_t TCPPacket::getSequenceNumber() const
{
    return sequenceNumber;
}

uint32_t TCPPacket::getAcknowledgementNumber() const
{
    return acknowledgeNumber;
}

uint16_t TCPPacket::getDataOffset() const
{
    return dataOffset;
}

uint16_t TCPPacket::getReserved() const
{
    return reserved;
}

uint16_t TCPPacket::getURG() const
{
    return UGR;
}

uint16_t TCPPacket::getACK() const
{
    return ACK;
}

uint16_t TCPPacket::getPSH() const
{
    return PSH;
}

uint16_t TCPPacket::getRST() const
{
    return RST;
}

uint16_t TCPPacket::getSYN() const
{
    return SYN;
}

uint16_t TCPPacket::getFIN() const
{
    return FIN;
}

uint16_t TCPPacket::getWindowSize() const
{
    return windowSize;
}

uint16_t TCPPacket::getChecksum() const
{
    return checksum;
}

uint16_t TCPPacket::getUrgentPointer() const
{
    return urgentPointer;
}

bool TCPPacket::parseRawPacket(const std::string& rawPacket)
{
    std::istringstream sourcePortString(rawPacket.substr(0, 4));
    sourcePortString >> std::hex >> sourcePort;
    
    std::istringstream destinationPortString(rawPacket.substr(4, 4));
    destinationPortString >> std::hex >> destinationPort;

    std::istringstream sequenceNumberString(rawPacket.substr(8, 8));
    sequenceNumberString >> std::hex >> sequenceNumber;

    std::istringstream acknowledgementNumberString(rawPacket.substr(16, 8));
    acknowledgementNumberString >> std::hex >> acknowledgeNumber;

    // wordString contains: dataOffset(4-bit), reserved(6-bit), and flags(6-bit)
    // altogether is a word(16-bit)
    std::istringstream wordString(rawPacket.substr(24, 4));
    uint16_t wordBuffer;
    wordString >> std::hex >> wordBuffer;
    dataOffset = (wordBuffer & 0xF000u) >> 12; 
    reserved   = (wordBuffer & 0x0FC0u) >> 6;
    UGR        = (wordBuffer & 0x0020u) >> 5;
    ACK        = (wordBuffer & 0x0010u) >> 4;
    PSH        = (wordBuffer & 0x0008u) >> 3;
    RST        = (wordBuffer & 0x0004u) >> 2;
    SYN        = (wordBuffer & 0x0002u) >> 1;
    FIN        =  wordBuffer & 0x0001u;

    std::istringstream windowSizeString(rawPacket.substr(28, 4));
    windowSizeString >> std::hex >> windowSize;

    std::istringstream checksumString(rawPacket.substr(32, 4));
    checksumString >> std::hex >> checksum;

    std::istringstream urgentPointerString(rawPacket.substr(36, 4));
    urgentPointerString >> std::hex >> urgentPointer;
    
    // TODO: check whether given raw data is valid
    return true;
}

bool TCPPacket::parseRawPacket(const std::vector<uint8_t>& rawPacket)
{
    char hexMapper[] = "0123456789ABCDEF";
    std::string rawPacketHexString;
    for(const uint8_t& byte : rawPacket)
    {
        rawPacketHexString += hexMapper[ (byte >> 4) ];
        rawPacketHexString += hexMapper[ (byte & 0xFu)];
    }

    return parseRawPacket(rawPacketHexString);
}

std::vector<uint8_t> TCPPacket::generateRawPacket()
{
    std::vector<uint8_t> rawPacket;
    
    rawPacket.push_back(sourcePort >> 8);
    rawPacket.push_back(sourcePort);
    
    rawPacket.push_back(destinationPort >> 8);
    rawPacket.push_back(destinationPort);
    
    rawPacket.push_back(sequenceNumber >> 24);
    rawPacket.push_back(sequenceNumber >> 16);
    rawPacket.push_back(sequenceNumber >> 8);
    rawPacket.push_back(sequenceNumber);

    rawPacket.push_back(acknowledgeNumber >> 24);
    rawPacket.push_back(acknowledgeNumber >> 16);
    rawPacket.push_back(acknowledgeNumber >> 8);
    rawPacket.push_back(acknowledgeNumber);

    uint16_t buffer = (dataOffset << 12) | (reserved<<6) | (UGR<<5) | (ACK<<4) | (PSH<<3) | (RST<<2) | (SYN<<1) | FIN;
    rawPacket.push_back(buffer >> 8);
    rawPacket.push_back(buffer);
    
    rawPacket.push_back(windowSize >> 8);
    rawPacket.push_back(windowSize);

    rawPacket.push_back(checksum >> 8);
    rawPacket.push_back(checksum);

    rawPacket.push_back(urgentPointer >> 8);
    rawPacket.push_back(urgentPointer >> 0);

    // TODO: add options, padding and data
    return rawPacket;
}