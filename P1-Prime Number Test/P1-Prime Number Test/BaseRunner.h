#include <SFML/Graphics.hpp>
#include <vector>
#include "PrimeChecker.h"

using namespace std;
class BaseRunner : private sf::NonCopyable
{
public:
	static const sf::Time	TIME_PER_FRAME;
	static const int WINDOW_WIDTH = 1920;
	static const int WINDOW_HEIGHT = 1080;

	BaseRunner();
	void run();

private:
	
	sf::RenderWindow window;

	void render();
	void processEvents();
	void update(sf::Time elapsedTime);

	vector<PrimeChecker*>checkerThreadList;

	int nThreads = 4;
	int testNumber = 547483647;
	bool isAPrimeNumber = false;
};


