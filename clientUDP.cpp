#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]){

	if(argc != 2){

		cout<< "Missing port number\n";
		exit(0);

	}


	int port = atoi(argv[1]);
	char msg[1500];


	//create socket structure
	sockaddr_in clientSocket;
	clientSocket.sin_family = AF_INET;
	clientSocket.sin_port = htons(port);
	clientSocket.sin_addr.s_addr = INADDR_ANY;

	//initialized socket
	int clientSocketID = socket(AF_INET, SOCK_DGRAM, 0);
	if(clientSocketID < 0){

		cout<< "socket not made successfully\n";
		exit(0);

	}
	cout<< "socket made successfully\n";

	socklen_t len = sizeof(clientSocket);

	while(1){

		string data;
		cout<<"client : ";
		getline(cin, data);
		strcpy(msg, data.c_str());
		if(data=="exit"){

			cout<< "Session terminated..\n";
			break;

		}
		//send to server
		sendto(clientSocketID, (char*)&msg, sizeof(msg), 0, (struct sockaddr*)&clientSocket, len);

		//recv from server
		recvfrom(clientSocketID, (char*)&msg, sizeof(msg), 0, (sockaddr*)&clientSocket, &len);

		if(!strcmp(msg, "exit")){

			cout<<"Session terminated\n";
			break;

		}
		cout<<"Server : "<<msg<<endl;

	}

	//close socket
	close(clientSocketID);

	return 0;
}