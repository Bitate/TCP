include_directories(${CMAKE_SOURCE_DIR}/include)

set(allSourceFiles
	"TCPConnection.cpp"
	"TCPPacket.cpp"
	"TCPTCB.cpp"
	"TCPSocket.cpp"
)

set(allHeaderFiles
	"../include/TCPConnection.hpp"
	"../include/TCPPacket.hpp"
	"../include/TCPTCB.hpp"
	"../include/TCPSocket.hpp"
)

add_library(allTCPLibs STATIC
	${allSourceFiles}
	${allHeaderFiles}
)

add_library(TCPTCBLib STATIC
	../include/TCPTCB.hpp
	TCPTCB.cpp
)

add_library(TCPPacketLib STATIC
	../include/TCPPacket.hpp
	TCPPacket.cpp
)

add_library(TCPConnectionLib STATIC
	../include/TCPConnection.hpp
	TCPConnection.cpp
)

add_library(TCPSocketLib STATIC
	../include/TCPSocket.hpp
	TCPSocket.cpp
)

add_library(TCPTimerLib STATIC
	../include/TCPTimer.hpp
	TCPTimer.cpp
)