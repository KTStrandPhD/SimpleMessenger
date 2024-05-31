#Makefile used to compile on Ubuntu 22.04, x86

#This make file builds three executables. 
#OneShotSndRcv sends and receives a messages at once
#SendMessage and ReceiveMessage are separate process which can be called at anytime

all: OneShotSndRcv SendMessage ReceiveMessage

OneShotSndRcv:
	g++ -I/usr/include/ -L/usr/lib/x86_64-linux-gnu/ -std=c++11 -o OneShotSndRcv src/SimpleMessenger.cxx src/OneShotSndRcv.cxx src/MsgQueue.cxx -lboost_serialization 

SendMessage:
	g++ -I/usr/include/ -L/usr/lib/x86_64-linux-gnu/ -std=c++11 -o SendMessage src/SimpleMessenger.cxx src/SendMessage.cxx src/MsgQueue.cxx -lboost_serialization 

ReceiveMessage:
	g++ -I/usr/include/ -L/usr/lib/x86_64-linux-gnu/ -std=c++11 -o ReceiveMessage src/SimpleMessenger.cxx src/ReceiveMessage.cxx src/MsgQueue.cxx -lboost_serialization 

clean:
	rm OneShotSndRcv SendMessage ReceiveMessage
