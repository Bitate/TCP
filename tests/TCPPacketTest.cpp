#include "TCPPacket.hpp"

#include <gtest/gtest.h>

TEST(TcpPacketTests, parseTcpPacketNoOptionsAndPaddingTest)
{
    TCPPacket tcp;

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
    std::string rawTCPPacketHexStream = "0cdd00508c3b7afeec4c8b6750180203e2240000";

    EXPECT_TRUE(tcp.parseRawPacket(rawTCPPacketHexStream));
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