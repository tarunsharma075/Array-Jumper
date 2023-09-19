#include "../header/UIHandler.h"
#include "../header/GameService.h"
#include "../header/SplashScreenUIController.h"
#include "../header/MainMenuUIController.h"

UIHandler::UIHandler()
{
    game_service = nullptr;
    game_window = nullptr;
    splash_screen_controller = nullptr;
    main_menu_controller = nullptr;

    instantiateControllers();
}

UIHandler::~UIHandler() 
{
    delete(splash_screen_controller);
    delete(main_menu_controller);
}

void UIHandler::initialize(GameService* game_service_instance, sf::RenderWindow* window_to_set)
{
    game_service = game_service_instance;
    game_window = window_to_set;

    initializeControllers();
}

void UIHandler::instantiateControllers()
{
    splash_screen_controller = new SplashScreenUIController();
    main_menu_controller = new MainMenuUIController();
}

void UIHandler::initializeControllers()
{
    main_menu_controller->initialize(game_window);
    splash_screen_controller->initialize(this, game_window);
}

void UIHandler::updateUI()
{
	switch (current_state)
	{
    case UIState::SPLASH_SCREEN:
        splash_screen_controller->update();
        break;
	case UIState::MAIN_MENU:
        main_menu_controller->update();
		break;
	default:
		break;
	}
}

void UIHandler::render() 
{ 
    switch (current_state)
    {
    case UIState::SPLASH_SCREEN:
        splash_screen_controller->render();
        break;
    case UIState::MAIN_MENU:
        main_menu_controller->render();
        break;
    default:
        break;
    }
}

void UIHandler::setUIState(UIState new_state)
{
    current_state = new_state;

    switch (current_state)
    {
    case UIState::SPLASH_SCREEN:
        splash_screen_controller->showSplashScreen();
        break;
    case UIState::MAIN_MENU:
        main_menu_controller->showMainMenuScreen();
        break;
    default:
        break;
    }
}