#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
class UIHandler;
class GraphicHandler;

class GameService
{
private:
	const int frame_rate = 60;

	sf::RenderWindow* game_window;
	GraphicHandler* graphic_handler;
	UIHandler* ui_handler;

	void initialize();

	void ignite();
	void update();
	void render();

	bool isRunning();
	void initializeGameWindow();
	void showSplashScreen();
	void onDestroy();

public:
	friend int main();

	GameService();
	virtual ~GameService();

	GraphicHandler* getGraphicHandler();
	UIHandler* getUIHandler();
};