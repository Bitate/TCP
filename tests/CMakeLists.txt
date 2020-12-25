include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(testAllTCPLibs
	main.cpp
)
target_link_libraries(testAllTCPLibs
	allTCPLibs
	gtest-main
)

add_executable(testTCPPacket
	TCPPacketTest.cpp
)
target_link_libraries(testTCPPacket
	TCPPacketLib
	gtest-main
)

add_executable(testTCPConnection
	TCPConnectionTest.cpp
)
target_link_libraries(testTCPConnection
	TCPConectionLib
	gtest-main
)

add_executable(testTCPTCB
	TCPTCBTest.cpp
)
target_link_libraries(testTCPTCB
	TCPTCBLib
	gtest-main
)
