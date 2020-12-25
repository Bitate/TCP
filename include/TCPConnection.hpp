#pragma once

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
	 * @param  
	 */
	void interruptConnection(const TCPConnection& openedConnection);

	/**
	 * @brief  STATUS(given connection)
	 * @param  
	 */
	TCPStatus getConnectionStatus(const TCPConnection& givenConnection);

	/**
	 * @brief  SEND(established connection, data [,timer])
	 * @param  
	 */
	void send(
			const TCPConnection& openedConnection, 
			std::vector<u_int8>& data,
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
			std::vector<u_int8>& buffer
	);


	

private:
	bool isConnectionEstablished;
	

}; 

enum class TCPConnectionState
{
	// connection established
	ESTABLISHED,

	// connection closed
	CLOSED,

	// SYNed on send side
	SYNED_ON_SEND_SIDE,

	// SYNed on receive side
	SYNED_ON_RECEIVE_SIDE
}

