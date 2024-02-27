#pragma once
#include <SFML/Graphics/RenderWindow.hpp>

#include "../../header/UI/SplashScreen/SplashScreenUIController.h"
#include "../../header/UI/MainMenu/MainMenuUIController.h"
#include "../../header/Sound/SoundHandler.h"

namespace UI
{
	/*class GameService;
	class SplashScreenUIController;
	class MainMenuUIController;
	class SoundHandler;*/

	class UIHandler
	{
	private:
		SplashScreen::SplashScreenUIController* splash_screen_controller;
		MainMenu::MainMenuUIController* main_menu_controller;

		sf::RenderWindow* game_window;
		Sound::SoundHandler* sound_handler;

		void createControllers();
		void initializeControllers();

	public:
		UIHandler();
		~UIHandler();

		void initialize(sf::RenderWindow* game_window_instance, Sound::SoundHandler* sound_handler_instance);
		void updateUI();
		void render();
	};
}