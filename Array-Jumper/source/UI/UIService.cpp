#include "../../header/UI/UIService.h"
#include "../../header/Main/GameService.h"
#include "../../header/Global/ServiceLocator.h"



namespace UI
{
    using namespace Main;
    using namespace SplashScreen;
    using namespace MainMenu;
    using namespace Credits;
    using namespace Instrcutions;
    using namespace Global;

    UIService::UIService()
    {
        splash_screen_ui_controller = nullptr;
        main_menu_ui_controller = nullptr;
        credits_screen_ui_controller = nullptr;
        instructions_ui_controller = nullptr;
        game_window = nullptr;

        createControllers();
    }

    UIService::~UIService()
    {
        onDestroy();
    }

    void UIService::createControllers()
    {
        splash_screen_ui_controller = new SplashScreenUIController();
        main_menu_ui_controller = new MainMenuUIController();
        credits_screen_ui_controller = new CreditsScreenUIController();
        instructions_ui_controller = new InstrcutionsUIController();
    }

    void UIService::initialize()
    {
        game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();

        initializeControllers();
    }

    void UIService::initializeControllers()
    {
        splash_screen_ui_controller->initialize(game_window);
        main_menu_ui_controller->initialize(game_window);
        credits_screen_ui_controller->initialize();
        instructions_ui_controller->initialize();
    }

    void UIService::onDestroy()
    {
        delete(splash_screen_ui_controller);
        delete(main_menu_ui_controller);
        delete(credits_screen_ui_controller);
        delete(instructions_ui_controller);
    }

    void UIService::update()
    {
        switch (GameService::getGameState())
        {
        case GameState::SPLASH_SCREEN:
            splash_screen_ui_controller->update();
            break;
        case GameState::MAIN_MENU:
            main_menu_ui_controller->update();
            break;
        case GameState::INSTRUCTIONS:
            instructions_ui_controller->update();
            break;
        case GameState::CREDITS:
            credits_screen_ui_controller->update();
            break;
        }
    }

    void UIService::render()
    {
        switch (GameService::getGameState())
        {
        case GameState::SPLASH_SCREEN:
            splash_screen_ui_controller->render();
            break;
        case GameState::MAIN_MENU:
            main_menu_ui_controller->render();
            break;
        case GameState::INSTRUCTIONS:
            instructions_ui_controller->render();
            break;
        case GameState::CREDITS:
            credits_screen_ui_controller->render();
            break;
        }
    }
}