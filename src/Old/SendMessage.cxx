//SendMessage.cxx
//Program to send message using boost::interprocess

#include "SimpleMessenger.h"

using namespace boost::interprocess;

int main() {

	srand(time(NULL));

	BOOST_TRY{
		message_queue::remove("message_queue");
		MessengerDemo sendData(true);

		message_queue mq(create_only, "message_queue", 100, sizeof(sendData));							//Create message_queue object, we choose create_only to only add to the message queue
		for (int i = 0; i < 10; i++) { //Change to a do while

			MessengerDemo sendData(true);																		//Create MessengerDemo object
			std::stringstream outputString;																	//Create serializable string

			//Save object to an archive
			boost::archive::text_oarchive outputArchive(outputString);			//Create archive object using Boost
			outputArchive << sendData;																			//Storing data in archive
			std::string serializedOutput(outputString.str());								//Define serialized data
		
			mq.send(serializedOutput.data(), serializedOutput.size(), 0);		//Send message to queue
			std::cout << "Message sent." << std::endl;
		}
	}
	BOOST_CATCH(interprocess_exception &ex) {
		std::cout << ex.what() << std::endl;
		return 1;
	} BOOST_CATCH_END



	//Now to receive the message
	BOOST_TRY{

		message_queue mq(open_only, "message_queue");
		unsigned int priority;
		message_queue::size_type recvSize;

		for (int i = 0; i < 10; i++) {
			MessengerDemo recvData;
			std::stringstream inputString;
			std::string serializedInput;
			serializedInput.resize(sizeof(recvData));
			
			mq.receive(&serializedInput[0], sizeof(recvData), recvSize, priority);
			inputString << serializedInput;

			boost::archive::text_iarchive inputArchive(inputString);
			inputArchive >> recvData;

			std::cout << "Message received." << std::endl;

			std::cout << "int: {" << recvData.position;
			std::cout << "}, float: {" << recvData.velocity;
			std::cout << "}, string: {" << recvData.name;
			std::cout << "}, enum: {" << recvData.enumMap[recvData.hgt];
			std::cout << "}" << std::endl;
		}
	} 
	BOOST_CATCH(interprocess_exception &ex) {
		std::cout << ex.what() << std::endl;
		return 1;
	}	BOOST_CATCH_END

	message_queue::remove("message_queue");

	return 0;
}
