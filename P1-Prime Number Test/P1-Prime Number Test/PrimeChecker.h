#pragma once
#include "IETThread.h"
class PrimeChecker : public IETThread
{
	// Inherited via IETThread
	virtual void run() override;
};

