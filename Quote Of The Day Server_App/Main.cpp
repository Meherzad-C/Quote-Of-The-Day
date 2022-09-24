#include <iostream>
#include <string>

#include "TcpListener.h"
#include "Qotd.h"

using namespace std;


void Listener_MessageReceived(CTcpListener* listener, int client, string msg);

// Class function callback for quotes txt file
CQotd quotes("Wisdom.txt");

void main()
{
	CTcpListener server("127.0.0.1", 54000, Listener_MessageReceived);

	if (server.Init())
	{
		cout << "------------------------SERVER UP------------------------" << "\n\n" << endl;
		server.Run();
	}
}

void Listener_MessageReceived(CTcpListener* listener, int client, string msg)
{
	if (msg == "Hi")
	{
		listener->Send(client, "Greetings human! Welcome to the Quote of the day Server! Would you like a Quote for today?\n");
	}
	
	
		if (msg == "yes" || msg == "another")
		{
			listener->Send(client, quotes.GetRandomQuote());
		}

	

	if (msg == "quit")
	{
		listener->Send(client, "'Quitting, have a great day!\n");
		exit(0);
	}
}