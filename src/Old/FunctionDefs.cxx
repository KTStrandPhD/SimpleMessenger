#include <iostream>
#include <string>
#include <map>					//for mapping enum to human readable data using key-value pairs
#include <boost/interprocess/ipc/message_queue.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/string.hpp>

//Make this OOP. I would like to set up an algorithm that just does this in one shot.

//I'm giving the variables all 'relevant' names

//Randomly populate 10 structs to pass through Boost

//ALL OF THIS CAN BE PUT INTO ITS OWN CLASS AND SHOULD BE SERIALIZED THERE

using namespace std;
//declaring enum parameters outside of struct
enum height {
	small,
	average,
	tall
};

//This probably shouldn't be global
map <int, string> enumMap;

//This array of names is only used for random selection of names
string names[20] = {"Kyle", "Tucker", "Grace", "Gwendolyn", "Scott", "Caroline", "Steve", "Clare", "Bill", "Kurt", 
											"Alexandra", "John", "Erica", "Pim", "Bart", "Gerard", "Mohammed", "Murphy", "Joe", "Harriet"};

//Define a map for human readable enum data
void defineEnumMap() {
	enumMap.insert(pair<int, string>(0, "small"));
	enumMap.insert(pair<int, string>(1, "average"));
	enumMap.insert(pair<int, string>(2, "tall"));
}

struct dataStruct {  // Do i want to add a constructor to automtically
	int position;
	float velocity;
	string name;
	height hgt;
};

//Serialize struct

//This is randomize enum on object construction. I can put all property randomization in 1 methods since we know exactly what we need
height RandomizeEnum() {
	return static_cast<height>(rand() % (tall + 1));  // (tall + 1) is used to guarantee that any of the three enum properties can be selected by RNG 
}

int RandomizeInt() {
	return rand() % 1000000;  												// Selects a random integer between 0 and 999999
}

float RandomizeFloat() {
	return (float)rand() / RAND_MAX;									// Selecting a random float between 0 and 1
 
}

string RandomizeString() {													// Selects name from pre-built name array
	int stringSelector = rand() % 20;
	return names[stringSelector];
}

//Boost sender function
void boostSender() {
	message_queue mqSender(create
}

//Boost receiver function
void boostReceiver() {

}

int main() {
	srand(time(NULL)); 			//For RNG seeding
	//dataStruct testData = {1, 0.5, "Kyle", tall};
	
	defineEnumMap();

	for (int i = 0; i < 10; i++) {
		dataStruct testData = {RandomizeInt(), RandomizeFloat(), RandomizeString(), RandomizeEnum()};
		cout << "int: {" << testData.position << "}, float: {" << testData.velocity << "}, string: {" << testData.name << "}, enum: {" << enumMap[testData.hgt] << "}" << endl;
	}

	return 0;
}
