#include <string>
#include <ctime>
#include <iostream>
#include "horse.h"
using namespace std;

Horse * furthestHorse(int, int, Horse*); //finds the horse object with the largest distance value
void input(int&, int); //functions for input error checking for race distance, number of horses, and y/n inputs
void input(char&);

int main() {
	int numOfHorses = 0, distance;
	char nextSecond, cont;
	srand(time(NULL));
	cout << "How many horses are in the race? (>=1): ";

	input(numOfHorses, 1);

	Horse * horses = new Horse[numOfHorses]; //pointer to an array of Horse objects

	for (int i = 0; i < numOfHorses; i++) {
		string horse, rider;
		cout << "Please give me the name of horse " << i + 1 << ": ";
		cin >> horse;
		cout << "Please give me the name of rider " << i + 1 << ": ";
		cin >> rider;
		horses[i] = Horse(horse, rider);
	}

	cout << "Please enter the distance of the race (>=100): ";

	input(distance, 100);

	do { //main loop for displaying the horses' progress
		cout << "\nThe start!\n";
		for (int i = 0; i < numOfHorses; i++) horses[i].displayHorse(distance);
		cout << "Are you ready for the next second? (y/n): ";
		input(nextSecond);

		while (nextSecond == 'y') {
			for (int i = 0; i < numOfHorses; i++) horses[i].runASecond();
			for (int i = 0; i < numOfHorses; i++) horses[i].displayHorse(distance);
			if (furthestHorse(numOfHorses, distance, horses)->horsePos() >= distance) break; //breaks out of loop if a horse is passed the finish line
			cout << "Are you ready for the next second? (y/n): ";
			input(nextSecond);
			if (nextSecond == 'n') break;
		}

		if (furthestHorse(numOfHorses, distance, horses)->horsePos() >= distance && nextSecond == 'y') furthestHorse(numOfHorses, distance, horses)->wonRace(); //chooses a winner

		if (nextSecond == 'y') { //increments ranRace member variable for each horse
			for (int i = 0; i < numOfHorses; i++) {
				horses[i].ranRace();
			}
		}	

		cout << endl;
		for (int i = 0; i < numOfHorses; i++) { //resets horses and displays races won and participation
			horses[i].stats();
			horses[i].sendToGate();
		}

		cout << "Do you wish to continue? (y/n): ";

		input(cont);

	} while (cont == 'y');
	delete[] horses;
	return 0;
	}

Horse * furthestHorse(int n, int distance, Horse * horses) { //takes number of horses, race length, and the Horse array pointer and returns a pointer to the furthest horse from the start
	int maxPos = 0;
	int j = 0;
	for (int i = 0; i < n; i++) {
		if (horses[i].horsePos() > maxPos) {
			maxPos = horses[i].horsePos();
			j = i;
		} else if (horses[i].horsePos() == maxPos) {
			if (rand() % 2 == 0) j = i; //picks randomly between two horses if two horses have the same distance traveled
		}
	}
	return &horses[j];
}

void input(int &a, int minValue) { //error checks int inputs; only allows positive numbers >= minValue
	cin >> a;
	while (a < minValue || !a) {
		cout << "Please enter a valid number: ";
		cin.clear();
		cin.ignore(100, '\n');
		cin >> a;
	}
}

void input(char &a) { //error checks char inputs; only allows 'y' or 'n'.
	cin >> a;
	a = tolower(a);
	while (a != 'y' && a != 'n') {
		cout << "Please enter a valid letter: ";
		cin.clear();
		cin.ignore(100, '\n');
		cin >> a;
		a = tolower(a);
	}
}