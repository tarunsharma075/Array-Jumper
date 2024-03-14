#include "../../header/UI/Instructions/InstructionsUIController.h"
#include "../../header/Main/GameService.h"
#include "../../header/Graphics/GraphicService.h"
#include "../../header/Sound/SoundService.h"
#include "../../header/Event/EventService.h"
#include "../../header/Global/Config.h"
#include "../../header/Global/ServiceLocator.h"

namespace UI
{
    namespace Instrcutions
    {
        using namespace Global;
        using namespace UIElement;
        using namespace Main;
        using namespace Graphics;
        using namespace Sound;

        InstrcutionsUIController::InstrcutionsUIController()
        {
            createButtons();
            createImage();
            createText();
        }

        InstrcutionsUIController::~InstrcutionsUIController()
        {
            destroy();
        }

        void InstrcutionsUIController::createImage()
        {
            background_image = new ImageView();
        }

        void InstrcutionsUIController::createButtons()
        {
            menu_button = new ButtonView();
        }

        void InstrcutionsUIController::createText()
        {
            for (int i = 0; i < number_of_instructions; i++)
            {
                instructions_text_list.push_back(new TextView());
            }
        }

        void InstrcutionsUIController::initialize()
        {
            initializeTexts();
            initializeBackgroundImage();
            initializeButtons();
            registerButtonCallback();
        }

        void InstrcutionsUIController::initializeBackgroundImage()
        {
            sf::RenderWindow* game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();

            background_image->initialize(Config::array_jumper_bg_texture_path, game_window->getSize().x, game_window->getSize().y, sf::Vector2f(0, 0));
            background_image->setImageAlpha(background_alpha);
        }

        void InstrcutionsUIController::initializeButtons()
        {
            menu_button->initialize("Menu Button", Config::menu_button_texture_path, button_width, button_height, sf::Vector2f(0, menu_button_y_position));
            menu_button->setCentreAlinged();
        }

        void InstrcutionsUIController::initializeTexts()
        {
            for (int i = 0; i < instructions_text_list.size(); i++)
            {
                instructions_text_list[i]->initialize(instructions[i], sf::Vector2f(0, top_offset + (text_spacing * i)), FontType::BUBBLE_BOBBLE, font_size, text_color);
                instructions_text_list[i]->setTextCentreAligned();
            }
        }

        void InstrcutionsUIController::registerButtonCallback()
        {
            menu_button->registerCallbackFuntion(std::bind(&InstrcutionsUIController::menuButtonCallback, this));
        }

        void InstrcutionsUIController::menuButtonCallback()
        {
            ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK);
            GameService::setGameState(GameState::MAIN_MENU);
        }

        void InstrcutionsUIController::update()
        {
            background_image->update();
            menu_button->update();

            for (int i = 0; i < instructions_text_list.size(); i++)
            {
                instructions_text_list[i]->update();
            }
        }

        void InstrcutionsUIController::render()
        {
            background_image->render();
            menu_button->render();

            for (int i = 0; i < instructions_text_list.size(); i++)
            {
                instructions_text_list[i]->render();
            }
        }

        void InstrcutionsUIController::show()
        {
            background_image->show();
            menu_button->show();

            for (int i = 0; i < instructions_text_list.size(); i++)
            {
                instructions_text_list[i]->show();
            }
        }

        void InstrcutionsUIController::destroy()
        {
            delete (background_image);
            delete (menu_button);

            for (int i = 0; i < instructions_text_list.size(); i++)
            {
                delete (instructions_text_list[i]);
            }
        }
    }
}