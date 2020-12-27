#pragma once

#include "TCPSocket.hpp"
#include "TCPTimer.hpp"

#include <vector>
#include <cstdint>

enum class TCPConnectionStatus
{
	// connection established
	ESTABLISHED,

	// connection closed
	CLOSED,

	// SYNed on send side
	SYNED_ON_SEND_SIDE,

	// SYNed on receive side
	SYNED_ON_RECEIVE_SIDE
};

enum class TCPMajorStates
{

};

class TCPConnection 
{
public:
	TCPConnection();
	~TCPConnection();

public:
	/**
	 * @brief  OPEN(local_port, foreign socket [,timer])
	 * @param  port  TCP port.
	 * @param  foreignSocket  TCP peer socket.
	 * @param  timeout  TCP timer.
     * @return  A TCB(Transmission Control Block) if succeeds, otherwise an error.
	 * @remarks  If the foreignSocket is not specified, then this forms a LISTENING socket.
	 *			 If the specified connection is already OPEN, an error is returned.
	 *			 On success, a full-duplex transmission control block [TCP] is returned and 
	 *		     partially filled in with data from the parameters passed by caller.
	 *			 
     *			 No network traffic is generated after calling this function. 
     */
	void openConnection(const int port, const TCPSocket& foreignSocket, TCPTimer& timerout);
	
	/**
	 * @brief  CLOSE(established connection)
	 * @param  
	 */
	void closeConnection(const TCPConnection& openedConnection);
	
	/**
	 * @brief  INTERRUPT(established connection)
	 * @param  openedConnection  TCP opened connection.
	 * @remarks  There are three cases in closing a TCP connection:
	 *				1. Local side closes;
	 *				2. Remote side closes by sending a FIN control signal;
	 *              3. Both sides close simultaneously.
	 */
	void interruptConnection(const TCPConnection& openedConnection);

	/**
	 * @brief  STATUS(given connection)
	 * @param  
	 */
	TCPConnectionStatus getConnectionStatus(const TCPConnection& givenConnection);

	/**
	 * @brief  SEND(established connection, data [,timer])
	 * @param  
	 */
	void send(
			const TCPConnection& openedConnection, 
			std::vector<uint8_t>& data,
			bool isLastLetter, 
			TCPTimer& timeout
	);

	/**
	 * @brief  RECEIVE(established connection, buffer)
   	 * @param
     * @param  
	 */
	void receive(
			const TCPConnection& openedConnection,
			std::vector<uint8_t>& buffer
	);

	/**
	 * @brief  Generate TCP's Initial Sequence Number
	 * @return  ISN number in 32-bit.
	 * @remarks  The generation of ISN must prevent from gussing attacks.
	 */
	uint32_t generateInitialSequenceNumber();


private:
	bool isConnectionEstablished;
	
	TCPConnectionStatus connectionStatus;

	/**
	 * Each TCP connection actually is a four-tuple of (local_ip, local_port, remote_ip, remote_port).
	 */
	uint32_t localIp;
	uint16_t localPort;
	uint32_t remoteIp;
	uint16_t remotePort;


}; 


