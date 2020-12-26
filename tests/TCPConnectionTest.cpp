#include "TCPConnection.hpp"

#include <gtest/gtest.h>

TEST(TCPConnectionTests, generateISNTest)
{
	TCPConnection tcpConnection;

	tcpConnection.generateInitialSequenceNumber();
}
