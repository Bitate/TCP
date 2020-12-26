include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(testAllTCPLibs
	main.cpp
)
target_link_libraries(testAllTCPLibs
	allTCPLibs
	gtest_main
)

add_executable(testTCPPacket
	TCPPacketTest.cpp
)
target_link_libraries(testTCPPacket
	TCPPacketLib
	gtest_main
)

add_executable(testTCPConnection
	TCPConnectionTest.cpp
)
target_link_libraries(testTCPConnection
	TCPConnectionLib
	gtest_main
)

add_executable(testTCPTCB
	TCPTCBTest.cpp
)
target_link_libraries(testTCPTCB
	TCPTCBLib
	gtest_main
)

add_executable(testTCPSocket
	TCPSocketTest.cpp
)
target_link_libraries(testTCPTCB
	TCPSocketLib
	gtest_main
)

add_executable(testTCPTimer
	TCPTimerTest.cpp
)
target_link_libraries(testTCPTimer
	TCPTimerLib
	gtest_main
)