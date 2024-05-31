#include "SimpleMessenger.h"

/* SimpleMessenger Class Definitions */

//Define a map for human readable enum data
void SimpleMessenger::DefineEnumMap() {
	this->enumMap.insert(std::pair<int, std::string>(0, "small"));
	this->enumMap.insert(std::pair<int, std::string>(1, "average"));
	this->enumMap.insert(std::pair<int, std::string>(2, "tall"));
}

SimpleMessenger::height SimpleMessenger::RandomizeEnum() {
	return static_cast<height>(rand() % (tall + 1));                  // (tall + 1) is used to guarantee that any of the three enum properties can be selected by RNG 
}

int SimpleMessenger::RandomizeInt() {
	return rand() % 1000000;  												                // Selects a random integer between 0 and 999999
}

float SimpleMessenger::RandomizeFloat() {
	return (float)rand() / RAND_MAX;									                // Selecting a random float between 0 and 1
 
}

std::string SimpleMessenger::RandomizeString() {										// Selects name from pre-built name array
	int nameSelector = rand() % 20;
	return names[nameSelector];
}

/* MessengerDemo Subclass Definitions */
void SimpleMessenger::GenerateData() {                              //Randomizes and populates data object
	this->position = this->RandomizeInt();
	this->velocity = this->RandomizeFloat();
	this->name = this->RandomizeString();
	this->hgt = this->RandomizeEnum();
}
