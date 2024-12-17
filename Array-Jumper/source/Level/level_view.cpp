#include"../../header/Level/level_view.h"
#include"../../header/Global/ServiceLocator.h"
#include"../../header/Global/Config.h"
#include<iostream>
using namespace Global;
namespace Level {
	void LevelView::createImages()
	{
		m_backgroundImage = new UI::UIElement::ImageView();
		m_boxImage = new UI::UIElement::ImageView();
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

	}
	void LevelView::updateImages()
	{
		m_backgroundImage->update();
		m_boxImage->update();
	}
	void LevelView::drawLevel()
	{
		m_backgroundImage->render();
		m_boxImage->render();
	}
	void LevelView::deleteImages()
	{
		delete(m_backgroundImage);
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