include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(mainExe
	main.cpp
)
target_link_libraries(mainExe
	allTCPLibs
	gtest_main
)

add_executable(TCPPacketTest
	TCPPacketTest.cpp
)
target_link_libraries(TCPPacketTest
	TCPPacketLib
	gtest_main
)

add_executable(TCPConnectionTest
	TCPConnectionTest.cpp
)
target_link_libraries(TCPConnectionTest
	TCPConnectionLib
	gtest_main
)

add_executable(TCPTCBTest
	TCPTCBTest.cpp
)
target_link_libraries(TCPTCBTest
	TCPTCBLib
	gtest_main
)

add_executable(TCPSocketTest
	TCPSocketTest.cpp
)
target_link_libraries(TCPSocketTest
	TCPSocketLib
	gtest_main
)

add_executable(TCPTimerTest
	TCPTimerTest.cpp
)
target_link_libraries(TCPTimerTest
	TCPTimerLib
	gtest_main
)

add_executable(getRawSockets
	rawSocket.cpp
)