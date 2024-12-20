#include "../../header/Level/level_view.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Global/Config.h"
#include "../../header/Level/level_controller.h"
#include "../../header/Level/level_model.h"
#include<iostream>
using namespace Global;
using namespace UI::UIElement;
using namespace std;

namespace Level {

    LevelView::LevelView(LevelController* controller)
    {
        level_controller = controller;
        game_window = nullptr;
        createImage();
    }

    LevelView::~LevelView()
    {
        deleteImage();
    }

    void LevelView::initilaize()
    {
        game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
        calcuateBoxDimension();
        initilizeImage();
    }

    void LevelView::update()
    {
        updateImage();
    }

    void LevelView::render()
    {
        drawImage();
    }

    void LevelView::calculateBoxWidthHeightDimension()
    {
        float screenWidth = static_cast<float>(game_window->getSize().x);
        int numBoxes = LevelData::NUMBER_OF_BOXES;

        // Each Box has a Gap on its left, 1 extra gap for the last block's right side
        int numGaps = numBoxes + 1;

        // Total space consumed by all gaps
        float totalSpaceByGaps = box_dimension.box_spacing_percentage * static_cast<float>(numGaps);

        // Total space consumed by boxes and gaps
        float totalSpace = numBoxes + totalSpaceByGaps;

        box_dimension.box_width = screenWidth / totalSpace;
        box_dimension.box_height = box_dimension.box_width;

       
        
    }

    void LevelView::calculateBoxSpacing()
    {
        box_dimension.box_spacing = box_dimension.box_spacing_percentage * box_dimension.box_width;
    }

    void LevelView::calcuateBoxDimension()
    {
        if (!game_window) return;
        calculateBoxWidthHeightDimension();
        calculateBoxSpacing();
    }

    sf::Vector2f LevelView::calculateBoxPosition(int index)
    {
        float xPosition = box_dimension.box_spacing + static_cast<float>(index) * (box_dimension.box_width + box_dimension.box_spacing);
        float yPosition = static_cast<float>(game_window->getSize().y) - box_dimension.box_height - box_dimension.bottom_offset;
        return sf::Vector2f(xPosition, yPosition);
    }

    UI::UIElement::ImageView* LevelView::getBoxImage(BlocKType type)
    {
        switch(type)
        {
		case BlocKType::OBSTACLE_ONE:
            return obstacle_one_overlay_image;
            break;
        case BlocKType::OBSTACLE_TWO:
            return obstacle_two_overlay_image;
            break;
        case BlocKType::TARGET:
            return target_overlay_image;
            break;
        case BlocKType::ONE:
            return letter_one_overlay_image;
            break;
        case BlocKType::TWO:
            return letter_two_overlay_image;
            break;
        case BlocKType::THREE:
            return letter_three_overlay_image;
            break;
        }
        return nullptr;
    }


    void LevelView::drawBox(sf::Vector2f position)
    {

        box_image->setPosition(position);
        box_image->render();
    }

    void LevelView::drawBoxValue(sf::Vector2f position, BlocKType type)
    {


        ImageView* image = getBoxImage(type);
        image->setPosition(position);
        image->render();
    }

    BoxDimensions LevelView::getBoxDimension()
    {
        cout << "height" << box_dimension.box_height;
        cout << "width" << box_dimension.box_width;

        return box_dimension;
    }

    void LevelView::createImage()
    {
        background_image = new ImageView();
        box_image = new ImageView();
        target_overlay_image = new ImageView();
        letter_one_overlay_image = new ImageView();
        letter_two_overlay_image = new ImageView();
        letter_three_overlay_image = new ImageView();
        obstacle_one_overlay_image = new ImageView();
        obstacle_two_overlay_image = new ImageView();
    }

    void LevelView::initilizeImage()
    {
        background_image->initialize(Config::array_jumper_bg_texture_path, game_window->getSize().x, game_window->getSize().y, sf::Vector2f(0, 0));
        background_image->setImageAlpha(background_alpha);

        box_image->initialize(Config::box_texture_path, box_dimension.box_width, box_dimension.box_height, sf::Vector2f(0, 0));
        //target_overlay_image->initialize(Config::target_texture_path, box_dimension.box_width, box_dimension.box_height, sf::Vector2f(0, 0));
        letter_one_overlay_image->initialize(Config::letter_one_texture_path, box_dimension.box_width, box_dimension.box_height, sf::Vector2f(0, 0));
        letter_two_overlay_image->initialize(Config::letter_two_texture_path, box_dimension.box_width, box_dimension.box_height, sf::Vector2f(0, 0));
        letter_three_overlay_image->initialize(Config::letter_three_texture_path, box_dimension.box_width, box_dimension.box_height, sf::Vector2f(0, 0));
        obstacle_one_overlay_image->initialize(Config::obstacle_01_texture_path, box_dimension.box_width, box_dimension.box_height, sf::Vector2f(0, 0));
        obstacle_two_overlay_image->initialize(Config::obstacle_02_texture_path, box_dimension.box_width, box_dimension.box_height, sf::Vector2f(0, 0));
    }

    void LevelView::updateImage()
    {
        background_image->update();
        box_image->update();
        target_overlay_image->update();
        letter_one_overlay_image->update();
        letter_two_overlay_image->update();
        letter_three_overlay_image->update();
        obstacle_one_overlay_image->update();
        obstacle_two_overlay_image->update();
    }

    void LevelView::drawImage()
    {
        background_image->render();

        for (int i = 0; i < LevelData::NUMBER_OF_BOXES; i++)
        {
            sf::Vector2f positon = calculateBoxPosition(i);
           BlocKType blockTypeToDraw = level_controller->getCurrentBoxValue(i);
            drawBox(positon);
            drawBoxValue(positon, blockTypeToDraw);
        }
    }

    void LevelView::deleteImage()
    {
        delete(background_image);
        delete(box_image);
        delete(target_overlay_image);
        delete(letter_one_overlay_image);
        delete(letter_two_overlay_image);
        delete(letter_three_overlay_image);
        delete(obstacle_one_overlay_image);
        delete(obstacle_two_overlay_image);
    }
    
    

} 
