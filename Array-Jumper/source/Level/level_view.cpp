#include"../../header/Level/level_view.h"
#include"../../header/Global/ServiceLocator.h"
#include"../../header/Global/Config.h"
using namespace Global;
namespace Level {
	void LevelView::createImages()
	{
		m_backgroundImage = new UI::UIElement::ImageView();
	}
	void LevelView::initializeImages()
	{
		m_backgroundImage->initialize(Config::array_jumper_bg_texture_path,
			m_gameWindowForLevelView->getSize().x,
			m_gameWindowForLevelView->getSize().y,
			sf::Vector2f(0, 0));
		m_backgroundImage->setImageAlpha(m_backgroundAlphaValue);

	}
	void LevelView::updateImages()
	{
		m_backgroundImage->update();
	}
	void LevelView::drawLevel()
	{
		m_backgroundImage->render();
	}
	void LevelView::deleteImages()
	{
		delete(m_backgroundImage);
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