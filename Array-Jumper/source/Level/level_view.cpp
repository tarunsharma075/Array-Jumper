#include"../../header/Level/level_view.h"
#include"../../header/Global/ServiceLocator.h"
#include"../../header/Global/Config.h"
#include"../../header/Level/level_controller.h"
#include"../../header/Level/level_data.h"
#include<iostream>
using namespace Global;
namespace Level {
	void LevelView::createImages()
	{
		m_backgroundImage = new UI::UIElement::ImageView();
		m_boxImage = new UI::UIElement::ImageView();
		target_overlay_image = new UI::UIElement::ImageView();
		letter_one_overlay_image = new UI::UIElement::ImageView();
		letter_two_overlay_image = new UI::UIElement::ImageView();
		letter_three_overlay_image = new UI::UIElement::ImageView();
		obstacle_one_overlay_image = new UI::UIElement::ImageView();
		obstacle_two_overlay_image = new UI::UIElement::ImageView();
	}
	void LevelView::initializeImages()
	{
		m_backgroundImage->initialize(Config::array_jumper_bg_texture_path,
			m_gameWindowForLevelView->getSize().x,
			m_gameWindowForLevelView->getSize().y,
			sf::Vector2f(0, 0));
		m_backgroundImage->setImageAlpha(m_backgroundAlphaValue);

		m_boxImage->initialize(Config::box_texture_path,
			box_dimension.box_width,
			box_dimension.box_height,
			sf::Vector2f(0, 0));


		//target_overlay_image->initialize(Config::target_texture_path, box_dimension.box_width, box_dimension.box_height, sf::Vector2f(0, 0));
		std::cout << "The initialize function for targt is caleed";
		letter_one_overlay_image->initialize(Config::letter_one_texture_path, box_dimension.box_width, box_dimension.box_height, sf::Vector2f(0, 0));
		letter_two_overlay_image->initialize(Config::letter_two_texture_path, box_dimension.box_width, box_dimension.box_height, sf::Vector2f(0, 0));
		letter_three_overlay_image->initialize(Config::letter_three_texture_path, box_dimension.box_width, box_dimension.box_height, sf::Vector2f(0, 0));
		obstacle_one_overlay_image->initialize(Config::obstacle_01_texture_path, box_dimension.box_width, box_dimension.box_height, sf::Vector2f(0, 0));
		obstacle_two_overlay_image->initialize(Config::obstacle_02_texture_path, box_dimension.box_width, box_dimension.box_height, sf::Vector2f(0, 0));

	}
	void LevelView::updateImages()
	{
		m_backgroundImage->update();
		m_boxImage->update();
		//target_overlay_image->update();
		letter_one_overlay_image->update();
		letter_two_overlay_image->update();
		letter_three_overlay_image->update();
		obstacle_one_overlay_image->update();
		obstacle_two_overlay_image->update();
	}
	void LevelView::drawLevel()
	{
		m_backgroundImage->render();
		for (int i = 0; i < LevelData::NUMBER_OF_BOXES; i++) {
			sf::Vector2f position = CalculateBoxPosition(i);
			BlocKType blockToDraw = m_levelController->getCurrentBoxValue(i);
			DrawBox(position);
			DrawboxValue(position, blockToDraw);
	   }
	}
	void LevelView::deleteImages()
	{
		delete(m_backgroundImage);
		delete(m_boxImage);
		delete(target_overlay_image);
		delete(letter_one_overlay_image);
		delete(letter_two_overlay_image);
		delete(letter_three_overlay_image);
		delete(obstacle_one_overlay_image);
		delete(obstacle_two_overlay_image);

	}
	void LevelView::CalculateBoxDimensions()
	{
		if (m_gameWindowForLevelView==NULL) {

			std::cout << "No We cant Calculate the size of boxed";
		}
		else {
			
			CalculateBoxWidthHeight();
			CalculateBoxSpacing();
		}
	}
	UI::UIElement::ImageView* LevelView::GetBoxOverLayImage(BlocKType overlayImage)
	{
		switch (overlayImage) {
		case BlocKType::OBSTACLE_ONE:
			return obstacle_one_overlay_image;
		case BlocKType::OBSTACLE_TWO:
			return obstacle_two_overlay_image;
		case BlocKType::TARGET:
				return target_overlay_image;
		case BlocKType::ONE:
			return letter_one_overlay_image;
		case BlocKType::TWO:
			return letter_two_overlay_image;
		case BlocKType::THREE:
			return letter_three_overlay_image;

		}
		return nullptr;
	}
	void LevelView::DrawBox(sf::Vector2f position)
	{
		m_boxImage->setPosition(position);
		m_boxImage->render();
	}
	void LevelView::DrawboxValue(sf::Vector2f position, BlocKType box_value)
	{
		UI::UIElement::ImageView*  image = GetBoxOverLayImage(box_value);
		image->setPosition(position);
		image->render();
	}
	void LevelView::CalculateBoxWidthHeight()
	{
		float scrrenWidth = static_cast<float>(m_gameWindowForLevelView->getSize().x);

		int numOfBox = LevelData::NUMBER_OF_BOXES;
		int numOfGaps = numOfBox + 1;
		float totalSpaceByGaps = box_dimension.box_width * static_cast<float>(numOfGaps);

		float totalSpace = numOfBox + totalSpaceByGaps;

		box_dimension.box_width = scrrenWidth / (totalSpace);
		box_dimension.box_height = box_dimension.box_width;
	}
	void LevelView::CalculateBoxSpacing()
	{
		box_dimension.box_spacing = box_dimension.box_spacing_percentage * box_dimension.box_width;
	}
	sf::Vector2f LevelView::CalculateBoxPosition(int index)
	{
		float xPosition = box_dimension.box_spacing + static_cast<float>(index) * (box_dimension.box_width + box_dimension.box_spacing);
		float yposition = static_cast<float>(m_gameWindowForLevelView->getSize().y) - box_dimension.box_height - box_dimension.bottom_offset;
		return sf::Vector2f(xPosition, yposition);
	}
	LevelView::LevelView(LevelController* controller)
	{
		m_gameWindowForLevelView = nullptr;
		m_levelController = controller;
		createImages();
	

	}
	LevelView::~LevelView()
	{
		deleteImages();
	}
	void LevelView::Initialize()
	{
		m_gameWindowForLevelView = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
		CalculateBoxDimensions();
		initializeImages();
	}
	void LevelView::Update()
	{
		updateImages();
	}
	void LevelView::Render()
	{
		drawLevel();
	}
}