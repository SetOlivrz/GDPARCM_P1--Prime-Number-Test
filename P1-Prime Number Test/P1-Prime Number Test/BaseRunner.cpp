#include "BaseRunner.h"

/// <summary>
/// This demonstrates a running parallax background where after X seconds, a batch of assets will be streamed and loaded.
/// </summary>
const sf::Time BaseRunner::TIME_PER_FRAME = sf::seconds(1.f / 60.f);

BaseRunner::BaseRunner()
{
	//load initial textures
}

void BaseRunner::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;


	for (int i = 0; i < nThreads; i++)
	{
		// instantiate Prime checker
		PrimeChecker* checkerInstance = new PrimeChecker(i, nThreads, testNumber);
		// added check in list
		checkerThreadList.push_back(checkerInstance);

		// run thread
		checkerThreadList[i]->start();

	}

	bool isAllFinished;

	do {
		isAllFinished = true;
		cout << testNumber << " still computing\n";
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

	isAPrimeNumber = true;
	for (int i = 0; i < checkerThreadList.size(); i++)
	{
		// modify the value when false
		if (!checkerThreadList[i]->isPrime)
		{
			isAPrimeNumber = false;
		}
	}


	if (isAPrimeNumber)
	{
		cout << testNumber << " is a Prime Number\n";
	}
	else
	{
		cout << testNumber << " is NOT a Prime Number\n";
	}
}
void BaseRunner::processEvents()
{
//	for (int i = 0; i < nThreads; i++)
//	{
//		// create thread
//		// instantiate thread (number range)
//		// add thread to list
//		// thread start
//
//
//	}

	//display output + processing time
}

void BaseRunner::update(sf::Time elapsedTime) 
{
	/*GameObjectManager::getInstance()->update(elapsedTime);*/
}

void BaseRunner::render() 
{
	/*this->window.clear();
	GameObjectManager::getInstance()->draw(&this->window);
	this->window.display();*/
}