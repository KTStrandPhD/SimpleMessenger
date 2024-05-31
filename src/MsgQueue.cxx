//MsgQueue.cxx
//Contains function definitions for custom send/receive functions

#include "MsgQueue.h"
#include "SimpleMessenger.h"

using namespace boost::interprocess;

void SendMessage() {

  //Utilizing boost try-catch for error control
	BOOST_TRY{
		message_queue::remove("message_queue");                                       //Clears "message_queue"
		MessengerDemo sendData(true);                                                 //Create and populate first data object

		message_queue mq(create_only, "message_queue", 100, sizeof(sendData));				//Create message_queue object, we choose create_only to only add to the message queue
		for (int i = 0; i < 10; i++) { 

			MessengerDemo sendData(true);																		            //Create MessengerDemo object
			std::stringstream outputString;																	            //Create serializable string

      boost::archive::text_oarchive outputArchive(outputString);                  //Create archive object using Boost
			outputArchive << sendData;																			            //Storing data in archive
			std::string serializedOutput(outputString.str());								            //Define serialized data
		
			mq.send(serializedOutput.data(), serializedOutput.size(), 0);		            //Send message to queue
			std::cout << "Message sent." << std::endl;                                  
		}
	}
	BOOST_CATCH(interprocess_exception &ex) {                                       //Call in case of exception
		std::cout << ex.what() << std::endl;
	} BOOST_CATCH_END
}

void ReceiveMessage() {

  //Utilizing boost try-catch for error control
	BOOST_TRY{
		message_queue mq(open_only, "message_queue");                                 //Create message_queue object. choosing open_only to read data
		unsigned int priority;                                                        //Required priority for message receiving
		message_queue::size_type recvSize;                                            //Size of message

		for (int i = 0; i < 10; i++) {
			MessengerDemo recvData;                                                     //Create empty data object to be filled with message
			std::stringstream inputString;                                              //Create message string
			std::string serializedInput;                                                //Create string to receive serialized data
			serializedInput.resize(sizeof(recvData));                                   //Resizing serializedInput string to match size of data object
			
			mq.receive(&serializedInput[0], sizeof(recvData), recvSize, priority);      //Receive message from queue
			inputString << serializedInput;                                             //Store serialized data into inputString

			boost::archive::text_iarchive inputArchive(inputString);                    //Create input archive object
			inputArchive >> recvData;                                                   //Transfer message to recvData object

			std::cout << "Message received." << std::endl;

 			std::cout << "int: {" << recvData.position;                                 //Output message to terminal
			std::cout << "}, float: {" << recvData.velocity;
			std::cout << "}, string: {" << recvData.name;
			std::cout << "}, enum: {" << recvData.enumMap[recvData.hgt];
			std::cout << "}" << std::endl;
		}
	} 
	BOOST_CATCH(interprocess_exception &ex) {                                       //Call in case of exception
		std::cout << ex.what() << std::endl;
	}	BOOST_CATCH_END

	message_queue::remove("message_queue");                                         //Clears message_queue
}
