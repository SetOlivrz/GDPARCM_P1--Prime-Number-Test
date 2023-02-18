#pragma once
#include "IETThread.h"
#include <vector>
class PrimeChecker : public IETThread
{
public:
	PrimeChecker(int id, int interval, int given);
	int id;
	int interval;
	int givenNumber;
	bool isPrime = true;
	bool isFinished = false;
	std::vector<int> divisorList;
	// Inherited via IETThread
	virtual void run() override;

};

