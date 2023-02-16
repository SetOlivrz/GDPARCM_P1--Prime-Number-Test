#include "PrimeChecker.h"

PrimeChecker::PrimeChecker(int id, int interval, int given)
{
	// initialize thread attributes
	this->id = id;
	this->interval = interval;
	this->givenNumber = given;
}

void PrimeChecker::run()
{
	int startingDivisor = 2 + id;
	int currentDivisor;

	
	for (int index = startingDivisor; index < givenNumber; index += interval)
	{
		currentDivisor = (interval * index) + (2 + id);
		if (givenNumber % currentDivisor == 0)
		{
			isPrime = false;
		}
	}

	isFinished = true;


}
