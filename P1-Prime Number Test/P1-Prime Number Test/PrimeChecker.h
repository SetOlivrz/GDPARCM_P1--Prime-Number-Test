#pragma once
#include "IETThread.h"
class PrimeChecker : public IETThread
{
public:
	PrimeChecker(int id, int interval, int given);
	int id;
	// Inherited via IETThread
	virtual void run() override;

private:
	
	int in
};

