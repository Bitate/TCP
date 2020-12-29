#pragma once

#include <vector>
#include <string>
#include <cmath>
#include <cstdint>
#include <sstream>
#include <iomanip>

/**
 * TODO: In my view, TCP Packet = TCP Segment. Is this equation true?
 */

class TCPPacket
{
public:
	TCPPacket();
	~TCPPacket();

	// setters
public:
	void setSourcePort(const uint16_t& newSourcePort);
	void setDestinationPort(const uint16_t& newDestinationPort);
	void setSequenceNumber(const uint32_t& newSequenceNumber);
	void setAcknowledgmentNumber(const uint32_t& newAcknowledgeNumber);
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

	// getters
public:
	uint16_t getSourcePort() const;
	uint16_t getDestinationPort() const;
	uint32_t getSequenceNumber() const;
	uint32_t getAcknowledgementNumber() const;
	uint16_t getDataOffset() const;
	uint16_t getReserved() const;
	uint16_t getURG() const;
	uint16_t getACK() const;
	uint16_t getPSH() const;
	uint16_t getRST() const;
	uint16_t getSYN() const;
	uint16_t getFIN() const;
	uint16_t getWindowSize() const;
	uint16_t getChecksum() const;
	uint16_t getUrgentPointer() const;
	// TODO: add getOptions and getPadding
	std::vector<uint8_t>& getData() const;

public:
	/**
	 * @brief  Parse raw TCP packet byte stream.
	 * @param  rawPacket  Given raw TCP packet byte stream in @b big-endian.
	 * @return  True if succeeds.
	 */
	bool parseRawPacket(const std::vector<uint8_t>& rawPacket);

	/**
	 * @brief  Parse raw TCP packet byte stream.
	 * @param  rawPacket  Given raw TCP packet byte stream in @b big-endian.
	 * @return  True if succeeds.
	 */
	bool parseRawPacket(const std::string& rawPacket);

	/**
	 * @brief  Generate/Assemble TCP packet byte stream.
	 * @return  Raw TCP packet byte stream.
	 */
	std::vector<uint8_t> generateRawPacket();

private:
	uint16_t sourcePort;
	uint16_t destinationPort;
	
	uint32_t sequenceNumber;
 	uint32_t acknowledgeNumber;
	
	uint16_t dataOffset : 4;	// also known as header length
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
