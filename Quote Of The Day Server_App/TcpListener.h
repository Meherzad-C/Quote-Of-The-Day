#pragma once

#include <ws2tcpip.h>						// Header file for WinSock functions
#include <string>

#pragma comment (lib, "ws2_32.lib")			// WinSock library file

#define MAX_BUFFER_SIZE (49152)

// Forward declaration of class
class CTcpListener;

// Callback to data received
typedef void (*MessageReceivedHandler)(CTcpListener* listener, int socketId, std::string msg);


class CTcpListener
{
public:

	CTcpListener(std::string ipAddress, int port, MessageReceivedHandler handler);

	~CTcpListener();

	// Sending message to the specified client
	void Send(int clientSocket, std::string msg);

	// Initializing WinSock
	bool Init();


	// Receiving loop
	void Run();

	void Cleanup();
	// Sending back message
	// Cleanup

private:

	// Creating a Socket
	SOCKET CreateSocket();

	// Waiting for a connection
	SOCKET WaitForConnection(SOCKET listening);

	std::string	m_ipAddress;
	int m_port;
	MessageReceivedHandler MessageReceived;
};

