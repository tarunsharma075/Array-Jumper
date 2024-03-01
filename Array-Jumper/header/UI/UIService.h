#pragma once
#include <SFML/Graphics/RenderWindow.hpp>

#include "../../header/UI/SplashScreen/SplashScreenUIController.h"
#include "../../header/UI/MainMenu/MainMenuUIController.h"
#include "../../header/UI/Instructions/InstructionsUIController.h"
#include "../../header/UI/Credits/CreditsScreenUIController.h"

namespace UI
{

	class UIService
	{
	private:
		SplashScreen::SplashScreenUIController* splash_screen_ui_controller;
		MainMenu::MainMenuUIController* main_menu_ui_controller;
		Credits::CreditsScreenUIController* credits_screen_ui_controller;
		Instrcutions::InstrcutionsUIController* instructions_ui_controller;

		sf::RenderWindow* game_window;

		void createControllers();
		void initializeControllers();
		void onDestroy();

	public:
		UIService();
		~UIService();

		void initialize();
		void update();
		void render();
	};
}