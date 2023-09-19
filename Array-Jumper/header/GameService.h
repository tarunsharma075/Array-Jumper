#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
class UIHandler;
class GraphicHandler;

enum class GameState
{
	SPLASH_SCREEN,
	MAIN_MENU,
};

class GameService
{
private:
	const int frame_rate = 60;

	sf::RenderWindow* game_window;
	GraphicHandler* graphic_handler;
	UIHandler* ui_handler;
	GameState current_state;

	void instantiateHandlers();

	void ignite();
	void update();
	void render();

	bool isRunning();
	void initialize();
	void showSplashScreen();
	void onDestroy();

public:
	friend int main();

	GameService();
	virtual ~GameService();

	void setGameState(GameState new_state);

	GraphicHandler* getGraphicHandler();
	UIHandler* getUIHandler();
	GameState getGameState();
};