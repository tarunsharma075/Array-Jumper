#pragma once
#include <SFML/Graphics/RenderWindow.hpp>

#include "../../header/Graphics/GraphicService.h"
#include "../../header/UI/UIService.h"
#include "../../header/Sound/SoundService.h"


namespace Main
{
	/*class GraphicService;
	class UIService;
	class SoundService;*/

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
		Graphics::GraphicService* graphic_service;
		UI::UIService* ui_service;
		Sound::SoundService* sound_service;

		void createServices();
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
}