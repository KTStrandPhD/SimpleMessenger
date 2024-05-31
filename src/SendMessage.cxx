//SendMessage.cxx
//Sends data to message queue

#include "SimpleMessenger.h"
#include "MsgQueue.h"

int main() {

	srand(time(NULL));					//Seeding RNG
	SendMessage();						//Send message to queue

	return 0;
}
