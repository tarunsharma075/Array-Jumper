#pragma once
#include <SFML/Graphics/RenderWindow.hpp>

class GraphicHandler;
class UIHandler;
class SoundHandler;

enum class GameState
{
	BOOT,
	SPLASH_SCREEN,
	MAIN_MENU,
};

class GameService
{
private:
	const int frame_rate = 60;

	static GameState current_state;

	sf::RenderWindow* game_window;
	GraphicHandler* graphic_handler;
	UIHandler* ui_handler;
	SoundHandler* sound_handler;

	void createHandlers();
	void initialize();
	void showSplashScreen();
	void onDestroy();

public:
	GameService();
	virtual ~GameService();

	void ignite();
	void update();
	void render();
	bool isRunning();

	static void setGameState(GameState new_state);
	static GameState getGameState();
};