//OneShotSndRcv.cxx

#include "SimpleMessenger.h"
#include "MsgQueue.h"

int main() {
	
	srand(time(NULL));            //Seeding RNG
	SendMessage();                //Populate data structures and send message
	ReceiveMessage();             //Receive and print message

	return 0;
}
