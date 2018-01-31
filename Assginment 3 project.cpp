// Assginment 3 project.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <ctime>
using std::cout;
using std::endl;

int main()
{
	//generate random dog at park location on 8X8 grid.
	cout << "Prisoners are assigned a park # on a an 8X8 grid. All Dogs have been assigned tracking chips as well " << endl;
	srand(time(0)); //random number seeding 
					//randomizing the number between 1-64
					//random number sequence
	int searchGridHighNumber = 64;
	int searchGridLownumber = 1;
	int dogLocation = rand() % searchGridHighNumber + searchGridLownumber;
	cout << "The dog is located at Park # " << dogLocation
		<< " on 8X8 grid with 1-64 sectors." << endl;
	cout << "Dog tracking system online....." << endl;
	int dogLocationPredictionCounter = 0;
	//is dog has been found 
	bool targetfound = false;

	while (targetfound == false)
	{
		// software selecting park prediction in tracking dog with chip data.
		int targetLocationPrediction = ((searchGridHighNumber - searchGridLownumber) / 2) + searchGridLownumber;
		dogLocationPredictionCounter++; //dogLocationPredictionCounter = targetLocationPredictionCounter +1;
											 //Radar ping of dog location
		cout << "==============================================================" << endl;
		cout << "Dtrack sending out ping # " << dogLocationPredictionCounter << endl;
		//Ping tells us 
		//If the dog park is higer or lower or right on the park location 
		//Is the dog park prediction higher then dog location 
		if (targetLocationPrediction > dogLocation)
		{
			//was higher than the park number  
			//does not need to search at or above park number
			searchGridHighNumber = targetLocationPrediction - 1;
			//subtract one dont need to search same number
			cout << "The Dtracks cell prediciton of " << targetLocationPrediction << " was higher than the actual park location " << dogLocation << endl;
			cout << "The new searchGirdNumber = " << searchGridHighNumber << endl;
		}
		else if (targetLocationPrediction < dogLocation)
		{
			//the dog location prediction was lower then park location
			//does not need to serach at or below cell number
			searchGridLownumber = dogLocationPredictionCounter++;
			//add one because we dont need to search same number 
			cout << "The Dtracks cell prediciton of " << targetLocationPrediction << " was lower than the actual park location " << dogLocation << endl;
			cout << "The new searchGridLownumber = " << searchGridLownumber << endl;
		}
		else if (targetLocationPrediction == dogLocation)
		{
			//Dog was found!!!
			cout << "Doggo was hiding at park # " << dogLocation << endl;
			cout << "Doggo was found at park # " << targetLocationPrediction << endl;
			cout << "Dtrack took " << dogLocationPredictionCounter << " predicitons to find the dog location on park grid of  8x8 (64)" << endl;
			targetfound = true;
		}
		else
		{
			//keeps Dtrack from running forever
			cout << "Software malfunction!!!!" << endl;
			cout << "Send dog chip to vet for SoftWare diagnostics!!!" << endl;
			targetfound = true;
		}
	}
	//pause then exit ....
	system("pause");
	return 0;
}
