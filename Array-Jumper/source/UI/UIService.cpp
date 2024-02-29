#include "../../header/UI/UIService.h"
#include "../../header/Main/GameService.h"



namespace UI
{
    using namespace Main;
    using namespace SplashScreen;
    using namespace MainMenu;
    using namespace Sound;

    UIService::UIService()
    {
        splash_screen_controller = nullptr;
        main_menu_controller = nullptr;
        game_window = nullptr;

        createControllers();
    }

    UIService::~UIService()
    {
        delete(splash_screen_controller);
        delete(main_menu_controller);
    }

    void UIService::createControllers()
    {
        splash_screen_controller = new SplashScreenUIController();
        main_menu_controller = new MainMenuUIController();
    }

    void UIService::initialize(sf::RenderWindow* game_window_instance, SoundService* sound_service_instance)
    {
        game_window = game_window_instance;
        sound_service = sound_service_instance;

        initializeControllers();
    }

    void UIService::initializeControllers()
    {
        main_menu_controller->initialize(game_window, sound_service);
        splash_screen_controller->initialize(game_window, sound_service);
    }

    void UIService::updateUI()
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

    void UIService::render()
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
}