#include "../header/UIHandler.h"
#include "../header/GameService.h"
#include "../header/SplashScreenUIController.h"
#include "../header/MainMenuUIController.h"

UIHandler::UIHandler()
{
    game_service = nullptr;
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
    splash_screen_controller = nullptr;
    main_menu_controller = nullptr;

    splash_screen_controller = new SplashScreenUIController();
    main_menu_controller = new MainMenuUIController();
}

void UIHandler::initialize(GameService* game_service_instance, sf::RenderWindow* window_to_set)
{
    game_service = game_service_instance;
    game_window = window_to_set;

    initializeControllers();
}

void UIHandler::initializeControllers()
{
    main_menu_controller->initialize(game_window);
    splash_screen_controller->initialize(game_window, game_service, this);
}

void UIHandler::updateUI()
{
	switch (game_service->getGameState())
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
    switch (game_service->getGameState())
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