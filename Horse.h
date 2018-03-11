#ifndef HORSE_H
#define HORSE_H
#include <string>
#include <iostream>

class Horse
{
private:
	std::string name;
	std::string rider;
	int maxRunningDistPerSecond; //random int between 1-100
	int distanceTraveled;
	int racesWon = 0;
	int totalRaces = 0;

public:
	Horse(); //overloaded constructors to make it easier to dynamically allocate memory for an array of Horse objects without having to pass parameters until later in the main function
	Horse(std::string, std::string);
	int runASecond(); //returns int in the range of 0-maxRunningDistPerSecond; the distance the horse covers in a second
	int horsePos(); //returns distanceTraveled
	void sendToGate(); //sets distanceTraveled to 0
	void displayHorse(int); //draws track and horse
	void stats(); //displays stats of races won and ran
	void ranRace(); //increments totalRaces
	void wonRace(); //increments racesWon

	~Horse();
};
#endif /* HORSE_H */
