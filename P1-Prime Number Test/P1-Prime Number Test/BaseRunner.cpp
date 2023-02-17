#include "BaseRunner.h"

/// <summary>
/// This demonstrates a running parallax background where after X seconds, a batch of assets will be streamed and loaded.
/// </summary>
const sf::Time BaseRunner::TIME_PER_FRAME = sf::seconds(1.f / 60.f);

BaseRunner::BaseRunner()
{
	// TEST VALUES
	// int = 2147483647 (max)
	// long = (max)
	this->nThreads = 256;

	// NOT PRIME
	//this->testNumber = 1000000;
	//this->testNumber = 100000000;
	//this->testNumber = 2000000000;

	// PRIME
	//this->testNumber = 1000003;
	//this->testNumber = 100000007;
	this->testNumber = 2147483647;
}

void BaseRunner::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	sf::Time startTime = sf::Time::Zero;
	sf::Time endTime = sf::Time::Zero;

	// elapsed time for the computation process
	sf::Time timeTaken = sf::Time::Zero;

	bool isAllFinished;


	for (int i = 0; i < nThreads; i++)
	{
		// instantiate Prime checker
		PrimeChecker* checkerInstance = new PrimeChecker(i, nThreads, testNumber);
		// add in thread list
		checkerThreadList.push_back(checkerInstance);
	}

	startTime = clock.getElapsedTime();
	for (int i = 0; i < nThreads; i++)
	{
		// run thread
		checkerThreadList[i]->start();

	}
	// start time
	
	do {
		isAllFinished = true;
		//cout << testNumber << " still computing\n";
		for (int i = 0; i < checkerThreadList.size(); i++)
		{
			// modify the value when not Finished
			if (!checkerThreadList[i]->isFinished)
			{
				isAllFinished = false;
				
				break;
			}
		}
	} while (!isAllFinished);

	// end time
	endTime = clock.getElapsedTime();

	// compute total time elapsed
	timeTaken = endTime - startTime;

	endTime = startTime;



	isAPrimeNumber = true;
	for (int i = 0; i < checkerThreadList.size(); i++)
	{
		// modify the value when false
		if (!checkerThreadList[i]->isPrime)
		{
			isAPrimeNumber = false;
		}
	}

	// display thread divisors (Debugging)
	//displayDivisorsPerThread();



	// display output
	if (isAPrimeNumber)
	{
		cout << testNumber << " is a Prime Number | "<< timeTaken.asMilliseconds()<<" ms| Threads: "<< nThreads<<"\n";
	}
	else
	{
		cout << testNumber << " is NOT a Prime Number | " << timeTaken.asMilliseconds() << " ms| Threads: " << nThreads << "\n";
	}
	
}
void BaseRunner::processEvents()
{

}

void BaseRunner::update(sf::Time elapsedTime) 
{

}

void BaseRunner::render() 
{

}

void BaseRunner::displayDivisorsPerThread()
{
	for (int i = 0; i < checkerThreadList.size(); i++)
	{
		for (int j = 0; j < checkerThreadList[i]->divisorList.size(); j++)
		{
			std::cout << "Thread: " << checkerThreadList[i]->id << " | Divisor: " << checkerThreadList[i]->divisorList[j] << std::endl;
		}
	}
}