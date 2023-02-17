#include "PrimeChecker.h"
#include <iostream>
PrimeChecker::PrimeChecker(int id, int interval, int given)
{
	// initialize thread attributes
	this->id = id;
	this->interval = interval;
	this->givenNumber = given;

	//std::cout << "created thread with id: " << id << ", interval: " << interval << ", given: " << given << std::endl;
}

void PrimeChecker::run()
{
	// delay
	IETThread::sleep(500);

	int startingDivisor = 2 + id;

	for (int currentDivisor = startingDivisor; currentDivisor < givenNumber; currentDivisor += interval)
	{
		// add divisor to list (use only in small test numbers to avoid longer runtime [n < 1000])
		//divisorList.push_back(currentDivisor);

		// prime checker
		if (givenNumber % currentDivisor == 0 && currentDivisor != givenNumber)
		{
			isPrime = false;
		}

		// break for loop when the next divisor + interval > givenNumber
		if (currentDivisor + interval < currentDivisor)
		{
			//std::cout << "value exceeded its datatype value limit\n";
			break;
		}
			
	}

	isFinished = true;
}
