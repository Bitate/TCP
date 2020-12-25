#include "TCPConnection.hpp"
#include <gtest/gtest.h>

TEST(TCPConnectionTests, openConnectionTest)
{
	TCPConnection tcpConnection;

	
	EXPECT_TRUE(tcpConnection.openConnection());	

}
