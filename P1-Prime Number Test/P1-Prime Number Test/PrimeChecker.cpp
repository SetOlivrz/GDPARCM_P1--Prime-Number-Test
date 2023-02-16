#include "PrimeChecker.h"
#include <iostream>
PrimeChecker::PrimeChecker(int id, int interval, int given)
{
	// initialize thread attributes
	this->id = id;
	this->interval = interval;
	this->givenNumber = given;

	std::cout << "created thread with id: " << id << ", interval: " << interval << ", given: " << std::endl;
}

void PrimeChecker::run()
{
	//sleep(200);

	//int startingDivisor = 2 + id;
	int currentDivisor;

	
	for (int index = 0; index < givenNumber; index += interval)
	{
		currentDivisor = (interval * index) + (2 + id);
		//std::cout << "Current Divisor" << currentDivisor << std::endl;

		if (givenNumber % currentDivisor == 0 && currentDivisor != givenNumber)
		{
			isPrime = false;
		}
	}
	/*if(isPrime)
	std::cout << "In Thread 1: Prime " << isPrime << std::endl;

	else
	std::cout << "In Thread 1: Not Prime " << isPrime << std::endl;*/

	isFinished = true;


}
