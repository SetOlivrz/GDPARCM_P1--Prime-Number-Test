#include "BaseRunner.h"

/// <summary>
/// This demonstrates a running parallax background where after X seconds, a batch of assets will be streamed and loaded.
/// </summary>
const sf::Time BaseRunner::TIME_PER_FRAME = sf::seconds(1.f / 60.f);

BaseRunner::BaseRunner()
{
	//load initial textures

}

void BaseRunner::run() {
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	while (this->window.isOpen())
	{
		sf::Time elapsedTime = clock.restart();
		timeSinceLastUpdate += elapsedTime;
		while (timeSinceLastUpdate > TIME_PER_FRAME)
		{
			timeSinceLastUpdate -= TIME_PER_FRAME;

			processEvents();
			//update(TIME_PER_FRAME);
			update(elapsedTime);
		}

		render();
	}
}

void BaseRunner::processEvents()
{
	//sf::Event event;
	//if (this->window.pollEvent(event)) {
	//	switch (event.type) {
	//	
	//	default: GameObjectManager::getInstance()->processInput(event); break;
	//	case sf::Event::Closed:
	//		this->window.close();
	//		break;

	//	}
	//}
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