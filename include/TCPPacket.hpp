#pragma once

#include <vector>

#include <cmath>
#include <cstdint>

/**
 * TODO: In my view, TCP Packet = TCP Segment. Is this equation true?
 */

class TCPPacket
{
public:
	TCPPacket();
	~TCPPacket();

public:
	void setSourcePort(const uint16_t& newSourcePort);
	void setDestinationPort(const uint16_t& newDestinationPort);
	void setSequenceNumber(const uint32_t& newSequenceNumber);
	void setAcknowledgeNumber(const uint32_t& newAcknowledgeNumber);
	void setDataOffset(const uint16_t& newDataOffset);
	void setReserved(const uint16_t& newReserved);
	void setUGR(const uint16_t& newUGR);
	void setACK(const uint16_t& newACK);
	void setPSH(const uint16_t& newPSH);
	void setRST(const uint16_t& newRST);
	void setSYN(const uint16_t& newSYN);
	void setFIN(const uint16_t& newFIN);
	void setWindowSize(const uint16_t& newWindowSize);
	void setChecksum(const uint16_t& newChecksum);
	void setUrgentPointer(const uint16_t& newUrgentPointer);
	void setData(const std::vector<uint8_t>& newData);

private:
	uint16_t sourcePort;
	uint16_t destinationPort;
	
	uint32_t sequenceNumber;
 	uint32_t acknowledgeNumber;
	
	uint16_t dataOffset : 4;
	uint16_t reserved   : 6;
	uint16_t UGR        : 1;
	uint16_t ACK		: 1;
	uint16_t PSH        : 1;
	uint16_t RST        : 1;
	uint16_t SYN        : 1;
	uint16_t FIN        : 1;

	uint16_t windowSize;	
	uint16_t checksum;
	uint16_t urgentPointer;
	
	// TODO: how to represent options and padding ???

	std::vector<uint8_t> data;
};
