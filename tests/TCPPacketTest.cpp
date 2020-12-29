#include "TCPPacket.hpp"

#include <gtest/gtest.h>

TEST(TcpPacketTests, parseTcpPacketByteStreamWithoutOptionsAndPaddingTest)
{
    // Transmission Control Protocol
    // Source Port: 3293
    // Destination Port: 80
    // Sequence number: 2352708350
    // Acknowledgment number: 3964439399
    // 0101    ....   = Header Length: 20 bytes (5)
    // Flags: 0x018 (PSH, ACK)
    // 000. .... .... = Reserved: Not set
    // ...0 .... .... = Nonce: Not set
    // .... 0... .... = Congestion Window Reduced (CWR): Not set
    // .... .0.. .... = ECN-Echo: Not set
    // .... ..0. .... = Urgent: Not set
    // .... ...1 .... = Acknowledgment: Set
    // .... .... 1... = Push: Set
    // .... .... .0.. = Reset: Not set
    // .... .... ..0. = Syn: Not set
    // .... .... ...0 = Fin: Not set
    // Window size value: 515
    // Checksum: 57892 
    // Urgent pointer: 0
    std::vector< uint8_t > rawTcpPacket = {
        0x0Cu, 0xDDu, 0x00u, 0x50u, 
        0x8Cu, 0x3Bu, 0x7Au, 0xFEu, 
        0xECu, 0x4Cu, 0x8Bu, 0x67u, 
        0x50u, 0x18u, 0x02u, 0x03u, 
        0xE2u, 0x24u, 0x00u, 0x00u
    };

    TCPPacket tcp;
    EXPECT_TRUE(tcp.parseRawPacket(rawTcpPacket));
    EXPECT_EQ(tcp.getSourcePort(), 3293);
    EXPECT_EQ(tcp.getDestinationPort(), 80);
    EXPECT_EQ(tcp.getSequenceNumber(), 2352708350);
    EXPECT_EQ(tcp.getAcknowledgementNumber(), 3964439399);
    EXPECT_EQ(tcp.getDataOffset(), 5);
    EXPECT_EQ(tcp.getReserved(), 0);
    EXPECT_EQ(tcp.getURG(), 0);
    EXPECT_EQ(tcp.getACK(), 1);
    EXPECT_EQ(tcp.getPSH(), 1);
    EXPECT_EQ(tcp.getRST(), 0);
    EXPECT_EQ(tcp.getSYN(), 0);
    EXPECT_EQ(tcp.getFIN(), 0);
    EXPECT_EQ(tcp.getWindowSize(), 515);
    EXPECT_EQ(tcp.getChecksum(), 57892);
    EXPECT_EQ(tcp.getUrgentPointer(), 0);
}

TEST(TcpPacketTests, parseTcpPacketHexStringWithoutOptionsAndPaddingTest)
{
    // Transmission Control Protocol
    // Source Port: 3293
    // Destination Port: 80
    // Sequence number: 2352708350
    // Acknowledgment number: 3964439399
    // 0101    ....   = Header Length: 20 bytes (5)
    // Flags: 0x018 (PSH, ACK)
    // 000. .... .... = Reserved: Not set
    // ...0 .... .... = Nonce: Not set
    // .... 0... .... = Congestion Window Reduced (CWR): Not set
    // .... .0.. .... = ECN-Echo: Not set
    // .... ..0. .... = Urgent: Not set
    // .... ...1 .... = Acknowledgment: Set
    // .... .... 1... = Push: Set
    // .... .... .0.. = Reset: Not set
    // .... .... ..0. = Syn: Not set
    // .... .... ...0 = Fin: Not set
    // Window size value: 515
    // Checksum: 57892 
    // Urgent pointer: 0
    std::string rawTcpPacketHexString = "0cdd00508c3b7afeec4c8b6750180203e2240000";

    TCPPacket tcp;
    EXPECT_TRUE(tcp.parseRawPacket(rawTcpPacketHexString));
    EXPECT_EQ(tcp.getSourcePort(), 3293);
    EXPECT_EQ(tcp.getDestinationPort(), 80);
    EXPECT_EQ(tcp.getSequenceNumber(), 2352708350);
    EXPECT_EQ(tcp.getAcknowledgementNumber(), 3964439399);
    EXPECT_EQ(tcp.getDataOffset(), 5);
    EXPECT_EQ(tcp.getReserved(), 0);
    EXPECT_EQ(tcp.getURG(), 0);
    EXPECT_EQ(tcp.getACK(), 1);
    EXPECT_EQ(tcp.getPSH(), 1);
    EXPECT_EQ(tcp.getRST(), 0);
    EXPECT_EQ(tcp.getSYN(), 0);
    EXPECT_EQ(tcp.getFIN(), 0);
    EXPECT_EQ(tcp.getWindowSize(), 515);
    EXPECT_EQ(tcp.getChecksum(), 57892);
    EXPECT_EQ(tcp.getUrgentPointer(), 0);
}

TEST(TcpPacketTests, generateTcpPacketWithoutOptionsAndPaddingTest)
{
    TCPPacket tcp;

    tcp.setSourcePort(3293);
    tcp.setDestinationPort(80);
    tcp.setSequenceNumber(2352708350);
    tcp.setAcknowledgmentNumber(3964439399);
    tcp.setDataOffset(5);
    tcp.setReserved(0);
    tcp.setUGR(0);
    tcp.setACK(1);
    tcp.setPSH(1);
    tcp.setRST(0);
    tcp.setSYN(0);
    tcp.setFIN(0);
    tcp.setWindowSize(515);
    tcp.setChecksum(57892);
    tcp.setUrgentPointer(0);

    std::vector< uint8_t > rawPacket = {
        0x0Cu, 0xDDu, 0x00u, 0x50u, 
        0x8Cu, 0x3Bu, 0x7Au, 0xFEu, 
        0xECu, 0x4Cu, 0x8Bu, 0x67u, 
        0x50u, 0x18u, 0x02u, 0x03u, 
        0xE2u, 0x24u, 0x00u, 0x00u
    };
    
    EXPECT_EQ(tcp.generateRawPacket(), rawPacket);
}