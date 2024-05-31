//MsgQueue.h
//This header conatins the declarations for the custom message send/receive functions

#include "SimpleMessenger.h"

#ifndef MSGQUEUE_H
#define MSGQUEUE_H

void SendMessage();               //Populates data object and sends message to queue
void ReceiveMessage();            //Receives and prints message

#endif
