#include"../../header/Level/level_view.h"
#include"../../header/Global/ServiceLocator.h"
#include"../../header/Global/Config.h"
#include"../../header/Level/level_controller.h"
#include<iostream>
using namespace UI::UIElement;
using namespace Global;
namespace Level {
	void LevelView::createImages()
	{
		m_backgroundImage = new UI::UIElement::ImageView();
		m_boxImage = new UI::UIElement::ImageView();
		target_overlay_image = new ImageView();
		letter_one_overlay_image = new ImageView();
		letter_two_overlay_image = new ImageView();
		letter_three_overlay_image = new ImageView();
		obstacle_one_overlay_image = new ImageView();
		obstacle_two_overlay_image = new ImageView();
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

		target_overlay_image->initialize(Config::target_texture_path, box_dimension.box_width, box_dimension.box_height, sf::Vector2f(0, 0));
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
		target_overlay_image->update();
		letter_one_overlay_image->update();
		letter_two_overlay_image->update();
		letter_three_overlay_image->update();
		obstacle_one_overlay_image->update();
		obstacle_two_overlay_image->update();
	}
	void LevelView::drawLevel()
	{
		m_backgroundImage->render();
		DrawBox(Vector2f(0, 0));
		
		BlocKType blockToDraw = m_levelController->getCurrentBoxValue(0);
		DrawboxValue(Vector2f(0, 0), blockToDraw);
		
		
	}
	void LevelView::deleteImages()
	{
		delete(m_backgroundImage);
		delete(m_boxImage);
		target_overlay_image->update();
		letter_one_overlay_image->update();
		letter_two_overlay_image->update();
		letter_three_overlay_image->update();
		obstacle_one_overlay_image->update();
		obstacle_two_overlay_image->update();
	}
	void LevelView::CalculateBoxDimensions()
	{
		if (m_gameWindowForLevelView==NULL) {

			std::cout << "No We cant Calculate the size of boxed";
		}
		else {
			box_dimension.box_width = 300.f;
			box_dimension.box_height = 300.f;
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
		ImageView* image = GetBoxOverLayImage(box_value);
		image->setPosition(position);
		image->render();
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