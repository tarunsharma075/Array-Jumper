#include "../../header/UI/Credits/CreditsScreenUIController.h"
#include "../../header/Main/GameService.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Global/Config.h"

namespace UI
{
    namespace Credits
    {
        using namespace Main;
        using namespace Global;
        using namespace Sound;

        CreditsScreenUIController::CreditsScreenUIController() { game_window = nullptr; }

        CreditsScreenUIController::~CreditsScreenUIController() = default;

        void CreditsScreenUIController::initialize()
        {
            game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
            initializeBackgroundImage();
            initializeButtons();
        }

        void CreditsScreenUIController::initializeBackgroundImage()
        {
            if (background_texture.loadFromFile(Config::array_jumper_bg_texture_path))
            {
                background_sprite.setTexture(background_texture);
                setBackgroundAlpha();
                scaleBackgroundImage();
            }
        }

        void CreditsScreenUIController::setBackgroundAlpha()
        {
            sf::Color color = background_sprite.getColor();
            color.a = background_alpha;
            background_sprite.setColor(color);
        }


        void CreditsScreenUIController::scaleBackgroundImage()
        {
            background_sprite.setScale(
                static_cast<float>(game_window->getSize().x) / background_sprite.getTexture()->getSize().x,
                static_cast<float>(game_window->getSize().y) / background_sprite.getTexture()->getSize().y
            );
        }

        void CreditsScreenUIController::initializeButtons()
        {
            if (loadButtonTexturesFromFile())
            {
                setButtonSprites();
                scaleAllButttons();
                positionButtons();
            }
        }

        bool CreditsScreenUIController::loadButtonTexturesFromFile()
        {
            return quit_button_texture.loadFromFile(Config::quit_button_texture_path) &&
                menu_button_texture.loadFromFile(Config::menu_button_texture_path);
        }

        void CreditsScreenUIController::setButtonSprites()
        {
            quit_button_sprite.setTexture(quit_button_texture);
            menu_button_sprite.setTexture(menu_button_texture);
        }

        void CreditsScreenUIController::scaleAllButttons()
        {
            scaleButton(&quit_button_sprite);
            scaleButton(&menu_button_sprite);
        }

        void CreditsScreenUIController::scaleButton(sf::Sprite* button_to_scale)
        {
            button_to_scale->setScale(
                button_width / button_to_scale->getTexture()->getSize().x,
                button_height / button_to_scale->getTexture()->getSize().y
            );
        }

        void CreditsScreenUIController::positionButtons()
        {
            float x_position = (static_cast<float>(game_window->getSize().x) / 2) - button_width / 2;

            menu_button_sprite.setPosition({ x_position, 600.f });
            quit_button_sprite.setPosition({ x_position, 800.f });
        }

        void CreditsScreenUIController::update()
        {
            if (pressedMouseButton())
                handleButtonInteractions();
        }

        void CreditsScreenUIController::render()
        {
            game_window->draw(background_sprite);
            game_window->draw(menu_button_sprite);
            game_window->draw(quit_button_sprite);
            drawGameTitle();
        }

        bool CreditsScreenUIController::pressedMouseButton() { return ServiceLocator::getInstance()->getEventService()->pressedLeftMouseButton(); }

        void CreditsScreenUIController::handleButtonInteractions()
        {
            sf::Vector2f mouse_position = sf::Vector2f(sf::Mouse::getPosition(*game_window));

            if (clickedButton(&quit_button_sprite, mouse_position))
                onClickQuitButton();

            if (clickedButton(&menu_button_sprite, mouse_position))
                onClickMenuButton();
        }

        bool CreditsScreenUIController::clickedButton(sf::Sprite* button_sprite, sf::Vector2f mouse_position)
        {
            return button_sprite->getGlobalBounds().contains(mouse_position);
        }

        void CreditsScreenUIController::onClickQuitButton() { game_window->close(); }

        void CreditsScreenUIController::onClickMenuButton()
        {
            ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK);
            GameService::setGameState(GameState::MAIN_MENU);
        }

        void CreditsScreenUIController::drawGameTitle()
        {
            ServiceLocator::getInstance()->getGraphicService()->drawText(game_window_title, top_offset, font_size);
        }
    }
}
