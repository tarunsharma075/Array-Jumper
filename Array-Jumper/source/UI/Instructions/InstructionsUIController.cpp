#include "../../header/UI/Instructions/InstructionsUIController.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Global/Config.h"
#include "../../header/Main/GameService.h"
#include "../../header/Sound/SoundService.h"


namespace UI
{
    namespace Instrcutions
    {
        using namespace Global;
        using namespace Main;
        using namespace Sound;

        InstrcutionsUIController::InstrcutionsUIController()
        {
            instructions = nullptr;
        }

        InstrcutionsUIController::~InstrcutionsUIController()
        {
            onDestroy();
        }

        void InstrcutionsUIController::initialize()
        {
            game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
            initializeInstructions();
            initializeBackgroundImage();
            initializeMainMenuButton();
        }

        void InstrcutionsUIController::onDestroy()
        {
            delete[] instructions;
        }

        void InstrcutionsUIController::update()
        {
            if (pressedMouseButton())
            {
                handleButtonInteractions();
                mouse_button_pressed = true;
            }
            else
            {
                mouse_button_pressed = false;
            }
        }

        void InstrcutionsUIController::render()
        {
            game_window->draw(background_sprite);
            game_window->draw(menu_button_sprite);
            drawInstructions();
        }

        void InstrcutionsUIController::initializeInstructions()
        {
            instructions = new sf::String[number_of_instructions]();

            instructions[0] = instruction_string_one;
            instructions[1] = instruction_string_two;
            instructions[2] = instruction_string_three;
            instructions[3] = instruction_string_four;
        }

        void InstrcutionsUIController::drawInstructions()
        {
            for (int i = 0; i < number_of_instructions; i++)
            {
                ServiceLocator::getInstance()->getGraphicService()->drawText(instructions[i], top_offset + (text_spacing * i));
            }
        }

        void InstrcutionsUIController::initializeBackgroundImage()
        {
            if (background_texture.loadFromFile(Config::array_jumper_bg_texture_path))
            {
                background_sprite.setTexture(background_texture);
                scaleBackgroundImage();
            }
        }

        void InstrcutionsUIController::scaleBackgroundImage()
        {
            background_sprite.setScale(
                static_cast<float>(game_window->getSize().x) / background_sprite.getTexture()->getSize().x,
                static_cast<float>(game_window->getSize().y) / background_sprite.getTexture()->getSize().y
            );
        }

        void InstrcutionsUIController::initializeMainMenuButton()
        {
            if (!menu_button_texture.loadFromFile(Config::menu_button_texture_path))
            {
                printf("Button Texture Not Found");
                return;
            }

            menu_button_sprite.setTexture(menu_button_texture);
            scaleButton(&menu_button_sprite);

            float x_position = (static_cast<float>(game_window->getSize().x) / 2) - button_width / 2;
            menu_button_sprite.setPosition({ x_position, 800.f });
        }

        void InstrcutionsUIController::scaleButton(sf::Sprite* button_to_scale)
        {
            button_to_scale->setScale(
                button_width / button_to_scale->getTexture()->getSize().x,
                button_height / button_to_scale->getTexture()->getSize().y
            );
        }


        void InstrcutionsUIController::handleButtonInteractions()
        {
            if (mouse_button_pressed) return;

            sf::Vector2f mouse_position = sf::Vector2f(sf::Mouse::getPosition(*game_window));

            if (clickedButton(&menu_button_sprite, mouse_position))
            {
                GameService::setGameState(GameState::MAIN_MENU);
                ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK);
            }
        }

        bool InstrcutionsUIController::clickedButton(sf::Sprite* button_sprite, sf::Vector2f mouse_position)
        {
            return button_sprite->getGlobalBounds().contains(mouse_position);
        }

        bool InstrcutionsUIController::pressedMouseButton()
        {
            return ServiceLocator::getInstance()->getEventService()->pressedLeftMouseButton();
        }
    }
}