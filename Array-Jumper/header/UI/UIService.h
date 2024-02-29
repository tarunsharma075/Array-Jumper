#pragma once
#include <SFML/Graphics/RenderWindow.hpp>

#include "../../header/UI/SplashScreen/SplashScreenUIController.h"
#include "../../header/UI/MainMenu/MainMenuUIController.h"
#include "../../header/Sound/SoundService.h"

namespace UI
{
	/*class GameService;
	class SplashScreenUIController;
	class MainMenuUIController;
	class SoundService;*/

	class UIService
	{
	private:
		SplashScreen::SplashScreenUIController* splash_screen_controller;
		MainMenu::MainMenuUIController* main_menu_controller;

		sf::RenderWindow* game_window;
		Sound::SoundService* sound_service;

		void createControllers();
		void initializeControllers();

	public:
		UIService();
		~UIService();

		void initialize(sf::RenderWindow* game_window_instance, Sound::SoundService* sound_service_instance);
		void updateUI();
		void render();
	};
}