#pragma once
#include <SFML/Graphics/RenderWindow.hpp>

class GameService;
class SplashScreenUIController;
class MainMenuUIController;

class UIHandler
{
private:
	SplashScreenUIController* splash_screen_controller;
	MainMenuUIController* main_menu_controller;

	sf::RenderWindow* game_window;

	void createControllers();
	void initializeControllers();

public:
	UIHandler();
	~UIHandler();

	void initialize(sf::RenderWindow* window_to_set);
	void updateUI();
	void render();
};