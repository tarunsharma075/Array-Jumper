#pragma once
#include <SFML/Graphics/RenderWindow.hpp>

#include "../../header/Graphics/GraphicHandler.h"
#include "../../header/UI/UIHandler.h"
#include "../../header/Sound/SoundHandler.h"


namespace Main
{
	/*class GraphicHandler;
	class UIHandler;
	class SoundHandler;*/

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
		Graphics::GraphicHandler* graphic_handler;
		UI::UIHandler* ui_handler;
		Sound::SoundHandler* sound_handler;

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
}