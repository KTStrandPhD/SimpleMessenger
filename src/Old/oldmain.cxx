#include "SimpleMessenger.h"

int main() {

	srand(time(NULL)); 							//For RNG seeding
	//MessengerDemo testData[10](true);
	MessengerDemo *testData = new MessengerDemo[10];
  //testData.DefineEnumMap();		//Setting up human readable enum map
	for (int i = 0; i < 10; i++) {
		testData[i] = MessengerDemo(true);
		//MessengerDemo testData(true);				//The true is to flag the constructor to populate the object with data
		std::cout << "int: {" << testData[i].position << "}, float: {" << testData[i].velocity << "}, string: {" << testData[i].name << "}, enum: {" << testData[i].enumMap[testData[i].hgt] << "}" << std::endl;	
	}

	return 0;
}
