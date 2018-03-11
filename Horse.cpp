#include "Horse.h"

Horse::Horse() {};
Horse::Horse(std::string name, std::string rider)
{
	this->name = name;
	this->rider = rider;
	this->maxRunningDistPerSecond = rand() % 100 + 1;
	this->distanceTraveled = 0;
}

int Horse::runASecond() {
	distanceTraveled += rand() % (maxRunningDistPerSecond + 1);
	return distanceTraveled;
}

int Horse::horsePos() {
	return distanceTraveled;
}

void Horse::sendToGate() {
	distanceTraveled = 0;
}

void Horse::stats() {
	std::cout << name << " has won " << racesWon << "/" << totalRaces << std::endl;
}

void Horse::ranRace() {
	totalRaces++;
}

void Horse::wonRace() {
	racesWon++;
}

void Horse::displayHorse(int goalLength) { //draws track and horse
	const double TRACK_CHAR_WIDTH = 75;
	double trackScale = (TRACK_CHAR_WIDTH - 2) / goalLength;
	std::cout << "|";
	if (distanceTraveled >= goalLength) { //draws track and horse if the horse is passed the finish line (|---...---|>)
		int count = 0;
		for (int i = 0; i < (TRACK_CHAR_WIDTH - 2); i++) {
			std::cout << "-";
			count++;
		}
		std::cout << "|> " << name << ", ridden by " << rider << std::endl;
	}
	else { //draws track and horse if the horse is still running the race (|---...--->   ...    |)
		int count = 0;
		for (int i = 0; i <= (floor(trackScale * distanceTraveled) - 1); i++) {
			std::cout << "-";
			count++;
		}
		std::cout << ">";
		while (count < TRACK_CHAR_WIDTH - 3) {
			std::cout << " ";
			count++;
		}
		std::cout << "| " << name << ", ridden by " << rider << std::endl;
	}
}


Horse::~Horse()
{
}
