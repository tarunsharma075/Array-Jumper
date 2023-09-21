#pragma once
#include <SFML/Graphics/RenderWindow.hpp>

class GameService;
class SplashScreenUIController;
class MainMenuUIController;
class SoundHandler;

class UIHandler
{
private:
	SplashScreenUIController* splash_screen_controller;
	MainMenuUIController* main_menu_controller;

	sf::RenderWindow* game_window;
	SoundHandler* sound_handler;

	void createControllers();
	void initializeControllers();

public:
	UIHandler();
	~UIHandler();

	void initialize(sf::RenderWindow* game_window_instance, SoundHandler* sound_handler_instance);
	void updateUI();
	void render();
};