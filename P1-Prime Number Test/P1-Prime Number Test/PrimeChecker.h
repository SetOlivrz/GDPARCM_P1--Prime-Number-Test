#pragma once
#include "IETThread.h"
class PrimeChecker : public IETThread
{
public:
	PrimeChecker(int id, int interval, int given);
	int id;
	int interval;
	int givenNumber;
	bool isPrime = false;
	bool isFinished = false;
	// Inherited via IETThread
	virtual void run() override;

};

