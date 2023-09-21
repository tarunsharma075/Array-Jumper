#include "../header/GameService.h"
#include "../header/GraphicHandler.h"
#include "../header/UIHandler.h"

GameState GameService::current_state = GameState::BOOT;

GameService::GameService()  
{ 
	graphic_handler = nullptr;
	ui_handler = nullptr;
	game_window = nullptr;

	createHandlers();
}

GameService::~GameService()  
{
	onDestroy(); 
}

void GameService::ignite()
{
	initialize();
	showSplashScreen();
}

void GameService::createHandlers()
{
	graphic_handler = new GraphicHandler();
	ui_handler = new UIHandler();
}

void GameService::initialize()
{
	// Game Window will be created here.
	game_window = graphic_handler->createGameWindow();
	graphic_handler->setFrameRate(frame_rate);

	ui_handler->initialize(game_window);
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
}

GameState GameService::getGameState() { return current_state; }