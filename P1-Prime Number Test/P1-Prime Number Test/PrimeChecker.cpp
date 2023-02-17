#include "PrimeChecker.h"
#include <iostream>
PrimeChecker::PrimeChecker(int id, int interval, int given)
{
	// initialize thread attributes
	this->id = id;
	this->interval = interval;
	this->givenNumber = given;

	std::cout << "created thread with id: " << id << ", interval: " << interval << ", given: " << given << std::endl;
}

void PrimeChecker::run()
{
	IETThread::sleep(500);

	int startingDivisor = 2 + id;
	//int currentDivisor = 1;

	//int i = 0;
	//std::cout << "Thread: " << id << "| Current Divisor" << startingDivisor << std::endl;
	for (int currentDivisor = startingDivisor; currentDivisor < givenNumber; currentDivisor += interval)
	{
		//currentDivisor = (interval * index) + (2 + id);
		//std::cout <<"Thread: " << id << "| Current Divisor" << currentDivisor << std::endl;
		//divisorList.push_back(currentDivisor);
		if (givenNumber % currentDivisor == 0 && currentDivisor != givenNumber)
		{
			isPrime = false;
		}
		//i++;

		if (currentDivisor + interval < currentDivisor)
			break;
	}
	/*if(isPrime)
	std::cout << "In Thread 1: Prime " << isPrime << std::endl;

	else
	std::cout << "In Thread 1: Not Prime " << isPrime << std::endl;*/

	isFinished = true;

	delete this;
	

}
