#include "../header/UIHandler.h"
#include "../header/GameService.h"
#include "../header/SplashScreenUIController.h"
#include "../header/MainMenuUIController.h"

UIHandler::UIHandler()
{
    splash_screen_controller = nullptr;
    main_menu_controller = nullptr;
    game_window = nullptr;

    createControllers();
}

UIHandler::~UIHandler() 
{
    delete(splash_screen_controller);
    delete(main_menu_controller);
}

void UIHandler::createControllers()
{
    splash_screen_controller = new SplashScreenUIController();
    main_menu_controller = new MainMenuUIController();
}

void UIHandler::initialize(sf::RenderWindow* game_window_instance, SoundHandler* sound_handler_instance)
{
    game_window = game_window_instance;
    sound_handler = sound_handler_instance;

    initializeControllers();
}

void UIHandler::initializeControllers()
{
    main_menu_controller->initialize(game_window, sound_handler);
    splash_screen_controller->initialize(game_window, sound_handler);
}

void UIHandler::updateUI()
{
	switch (GameService::getGameState())
	{
    case GameState::SPLASH_SCREEN:
        splash_screen_controller->update();
        break;
	case GameState::MAIN_MENU:
        main_menu_controller->update();
		break;
	default:
		break;
	}
}

void UIHandler::render() 
{ 
    switch (GameService::getGameState())
    {
    case GameState::SPLASH_SCREEN:
        splash_screen_controller->render();
        break;
    case GameState::MAIN_MENU:
        main_menu_controller->render();
        break;
    default:
        break;
    }
}