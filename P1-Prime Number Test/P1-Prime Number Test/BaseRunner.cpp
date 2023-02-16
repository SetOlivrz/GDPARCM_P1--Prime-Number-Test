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

	sf::Time startTime;
	sf::Time endTime;

	sf::Time timeTaken;

	bool isAllFinished;


	for (int i = 0; i < nThreads; i++)
	{
		// instantiate Prime checker
		PrimeChecker* checkerInstance = new PrimeChecker(i, nThreads, testNumber);
		// added check in list
		checkerThreadList.push_back(checkerInstance);

		// run thread
		checkerThreadList[i]->start();

	}


	startTime = clock.getElapsedTime();
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
	endTime = clock.getElapsedTime();

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

	/*for (int i = 0; i < checkerThreadList.size(); i++)
	{
		for (int j = 0; j < checkerThreadList[i]->divisorList.size(); j++)
		{
			std::cout << "Thread: " << checkerThreadList[i]->id << " | Divisor: " << checkerThreadList[i]->divisorList[j] << std::endl;
		}
	}*/
	

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