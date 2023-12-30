#include "../header/GameService.h"
#include "../header/GraphicHandler.h"
#include "../header/UIHandler.h"
#include "../header/SoundHandler.h"

GameState GameService::current_state = GameState::BOOT;

GameService::GameService()  
{ 
	graphic_handler = nullptr;
	ui_handler = nullptr;
	sound_handler = nullptr;
	game_window = nullptr;

	createHandlers();
}

GameService::~GameService() { onDestroy(); }

void GameService::ignite()
{
	initialize();
	showSplashScreen();
}

void GameService::createHandlers()
{
	graphic_handler = new GraphicHandler();
	ui_handler = new UIHandler();
	sound_handler = new SoundHandler();
}

void GameService::initialize()
{
	// Game Window will be created here.
	game_window = graphic_handler->createGameWindow();
	graphic_handler->setFrameRate(frame_rate);

	sound_handler->initialize();
	ui_handler->initialize(game_window, sound_handler);
}

// Main Game Loop.
void GameService::update()
{
	ui_handler->updateUI();
}

void GameService::render()
{
	game_window->clear();
	ui_handler->render();
	game_window->display();
}

bool GameService::isRunning() { return graphic_handler->isGameWindowOpen(); }

void GameService::showSplashScreen() { setGameState(GameState::SPLASH_SCREEN); }

void GameService::onDestroy()
{
	delete(ui_handler);
	delete(sound_handler);
	delete(graphic_handler);
}

void GameService::setGameState(GameState new_state) { current_state = new_state; }

GameState GameService::getGameState() { return current_state; }