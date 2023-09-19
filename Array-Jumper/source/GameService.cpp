#include "../header/GameService.h"
#include "../header/GraphicHandler.h"
#include "../header/UIHandler.h"

GameService::GameService() { initialize(); }

GameService::~GameService() { onDestroy(); }

void GameService::initialize()
{
	graphic_handler = new GraphicHandler();
	ui_handler = new UIHandler();
}

void GameService::ignite()
{
	initializeGameWindow();
	showSplashScreen();
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

void GameService::initializeGameWindow()
{
	// Game Window will be created here.
	game_window = graphic_handler->createGameWindow();
	graphic_handler->setFrameRate(frame_rate);

	ui_handler->initialize(this, game_window);
}

void GameService::showSplashScreen() { ui_handler->setUIState(UIState::SPLASH_SCREEN); }

void GameService::onDestroy()
{
	delete(graphic_handler);
	delete(ui_handler);
}

GraphicHandler* GameService::getGraphicHandler() { return graphic_handler; }

UIHandler* GameService::getUIHandler() { return ui_handler; }