//DynonProject.h

#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <boost/archive/text_oarchive.hpp>
#include <boost/interprocess/ipc/message_queue.hpp>
#include <boost/archive/text_iarchive.hpp>

#ifndef SIMPLEMESSENGER_H
#define SIMPLEMESSENGER_H

//Project class
class SimpleMessenger {
	public:

		//class attributes
		enum height {
			small,
			average,
			tall
		};
		int position;
		float velocity;
		std::string name;
		height hgt;

		std::map <int, std::string> enumMap;						//To be used to map to human readable enums
		std::string names[20] = {"Kyle", "Tucker", "Grace", "Gwendolyn", "Clare", "Scott", "Caroline", "Steve", "Bill", "Kurt", 
											"Alexandra", "John", "Erica", "Pim", "Bart", "Gerard", "Mohammed", "Murphy", "Joe", "Harriet"};

		int RandomizeInt();
		float RandomizeFloat();
		std::string RandomizeString();
		height RandomizeEnum();
		void GenerateData();
		void DefineEnumMap();	

	private:
		friend class boost::serialization::access;

		//Function to serialize the message due to std::string
		template <class Archive>                                      //Archive template to be used with boost serialization
		void serialize(Archive &ar, const unsigned int version) {     //Boost serialization
			ar & position;
			ar & velocity;
			ar & name;
			ar & hgt;
		}
};


/*Defining MessengerDemo subclass from SimpleMessenger*/
class MessengerDemo: public SimpleMessenger {

	//Subclass methods
	public:

		//Constructors
		//Empty object to be filled with received message. Generating enum map on creation
		MessengerDemo() {
			SimpleMessenger::DefineEnumMap();
		}

		//Constructor to populate the object before sending message
			//This isn't the safest way to do this, but it'll have to do due to time constraints
		MessengerDemo(bool constructFlag) {
			SimpleMessenger::DefineEnumMap();
			SimpleMessenger::GenerateData();
		}

		//Destructor
		~MessengerDemo() {}
};

#endif
