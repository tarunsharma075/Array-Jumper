#include "../header/GameService.h"
#include "../header/GraphicHandler.h"
#include "../header/UIHandler.h"

GameService::GameService()  { instantiateHandlers(); }

GameService::~GameService()  { onDestroy(); }

void GameService::instantiateHandlers()
{
	graphic_handler = nullptr;
	ui_handler = nullptr;

	graphic_handler = new GraphicHandler();
	ui_handler = new UIHandler();
}

void GameService::ignite()
{
	initialize();
	showSplashScreen();
}

void GameService::initialize()
{
	// Game Window will be created here.
	game_window = graphic_handler->createGameWindow();
	graphic_handler->setFrameRate(frame_rate);

	ui_handler->initialize(this, game_window);
}

// Main Game Loop.
void GameService::update()
{
	graphic_handler->updateGraphics();
	ui_handler->updateUI();
}

void GameService::render()
{
	game_window->clear();

	graphic_handler->render();
	ui_handler->render();

	game_window->display();
}

bool GameService::isRunning() { return graphic_handler->isGameWindowOpen(); }

void GameService::showSplashScreen() { setGameState(GameState::SPLASH_SCREEN); }

void GameService::onDestroy()
{
	delete(graphic_handler);
	delete(ui_handler);
}

void GameService::setGameState(GameState new_state)
{
	current_state = new_state;

	switch (current_state)
	{
	case GameState::SPLASH_SCREEN:
		break;
	case GameState::MAIN_MENU:
		break;
	default:
		break;
	}
}

GraphicHandler* GameService::getGraphicHandler() { return graphic_handler; }

UIHandler* GameService::getUIHandler() { return ui_handler; }

GameState GameService::getGameState() { return current_state; }
