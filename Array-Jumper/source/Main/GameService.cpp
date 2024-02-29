#include "../../header/Main/GameService.h"

namespace Main
{
	using namespace Graphics;
	using namespace UI;
	using namespace Sound;

	GameState GameService::current_state = GameState::BOOT;

	GameService::GameService()
	{
		graphic_service = nullptr;
		ui_service = nullptr;
		sound_service = nullptr;
		game_window = nullptr;

		createServices();
	}

	GameService::~GameService() { onDestroy(); }

	void GameService::ignite()
	{
		initialize();
		showSplashScreen();
	}

	void GameService::createServices()
	{
		graphic_service = new GraphicService();
		ui_service = new UIService();
		sound_service = new SoundService();
	}

	void GameService::initialize()
	{
		// Game Window will be created here.
		game_window = graphic_service->createGameWindow();
		graphic_service->setFrameRate(frame_rate);

		sound_service->initialize();
		ui_service->initialize(game_window, sound_service);
	}

	// Main Game Loop.
	void GameService::update()
	{
		ui_service->updateUI();
	}

	void GameService::render()
	{
		game_window->clear();
		ui_service->render();
		game_window->display();
	}

	bool GameService::isRunning() { return graphic_service->isGameWindowOpen(); }

	void GameService::showSplashScreen() { setGameState(GameState::SPLASH_SCREEN); }

	void GameService::onDestroy()
	{
		delete(ui_service);
		delete(sound_service);
		delete(graphic_service);
	}

	void GameService::setGameState(GameState new_state) { current_state = new_state; }

	GameState GameService::getGameState() { return current_state; }
}