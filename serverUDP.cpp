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
vector<sockaddr_in> clientsocket;
vector<socklen_t> len_socket;
vector<int> serversocket;

int main(int argc, char *argv[]){

	if(argc < 2){

		cout<< "Missing port number "<<argc<<endl;
		exit(0);

	}

	char msg[1500];

	for(int i=1; i<argc; i++){
		int port = atoi(argv[i]);

		//create sockaddr_in structure
		sockaddr_in serverSocket;
		serverSocket.sin_family = AF_INET;
		serverSocket.sin_port = htons(port);
		serverSocket.sin_addr.s_addr = htonl(INADDR_ANY);

	    //initalize socket
	    int serverSocketID = socket(AF_INET, SOCK_DGRAM, 0);
	    if(serverSocketID < 0){

		    cout<<"error initalizing socket\n";
		    exit(0);

	    }

	    serversocket.push_back(serverSocketID);
	    //bind the socket to server
	    int bindport = bind(serverSocketID, (struct sockaddr*)&serverSocket, sizeof(serverSocket));
	    if(bindport < 0){

		    cout<<"error binding\n";
		    exit(0);

	    }

	    sockaddr_in clientSocket;
	    socklen_t len = sizeof(clientSocket);
	    clientsocket.push_back(clientSocket);
	    len_socket.push_back(len);

	}

	cout<<"waiting for message from client...\n";

	while(1){

        for(int i=0; i<serversocket.size(); i++){
		    recvfrom(serversocket[i], (char*)&msg, sizeof(msg), 0, (struct sockaddr*)&clientsocket[i], &len_socket[i]);
		    if(!strcmp(msg, "exit")){

        	    cout<<"Session terminated...\n";
        	    break;
            }
            cout<<"client "<<i<<": ";
            cout<<msg<<endl;
        }

        string data;
        cout<<"Server : ";
        getline(cin, data);
        strcpy(msg, data.c_str());
        if(data == "exit"){

        	cout<<"Session terminated...\n";
        	break;
        }
        for(int i=0; i<serversocket.size(); i++){
            sendto(serversocket[i], (char*)&msg, sizeof(msg), 0, (sockaddr*)&clientsocket[i], len_socket[i]);
        }

	}

	//close the socket
	for(int i=0; i<serversocket.size(); i++){
	    close(serversocket[i]);
    }

	return 0;
}