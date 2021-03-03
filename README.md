# acm_networking_project
This project is related to networking between server-client using UDP and TCP protocols.

## Introduction
Programs made using scoket programming to communicate between two sockets over a defind network using different protocols mainly TCP and UDP.

## How to run
There are two cpp programs, compile them using compiler, `g++` mainly and run provding the port numbers for server and hostname and port number for clients. 
`.\serverTCP 2000 2001` for server and `.\clientTCP localhost 2000`, `.\clientTCP localhost 2001`for the clients.

## Tech stack
Basics of Socket programmming in TCP and UDP are used, For `TCP`, it is creating a socket, binding it to the port,  waiting for the client to send a request and the accepting it, and tgen sending and receiving messages. For `UDP`, there is no need to accept the request for sending messages. 

## Logic
Creating an array of sockets of different port number and binding them respectively, and connecting them to their respective clients. This creates a one-to-many communication network

## Interesting addition
Apart from the basics taught in the lectures, This project is based on many-to-one network rather than one-to-one network, which was taught in the lectures. Many hosts are connected to a single server, sending message from a server send the message to all connected hosts.

## Screenshots 

![udp1](https://user-images.githubusercontent.com/62436345/109860321-00730f80-7c84-11eb-9053-94d3926151cc.png)
![udp2](https://user-images.githubusercontent.com/62436345/109860319-ffda7900-7c83-11eb-815e-ca9f17f5960d.png)
![udp3](https://user-images.githubusercontent.com/62436345/109860316-fd781f00-7c83-11eb-85da-4e7265a7675b.png)

