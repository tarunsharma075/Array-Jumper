#include"../../header/Player/player_view.h"
#include"../../header/Global/Config.h"
#include"../../header/Global/ServiceLocator.h"
#include"../../header/Player/player_controller.h"
#include"../../header/Player/player_model.h"
#include<iostream>
namespace Player {
	using namespace UI::UIElement;
	using namespace Global;
	
	PlayerView::PlayerView(PlayerController* controller)
	{
		m_playerController = controller;
		m_gameWindow = nullptr;
	    m_playerImage = new ImageView();
	}
	PlayerView::~PlayerView()
	{
	}
	void PlayerView::initialize()
	{
		std::cout << "image is set";
		m_gameWindow = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
		LoadPlayer();
	}
	void PlayerView::update()
	{
		updatePlayerPosition();
	}
	void PlayerView::render()
	{
		switch (m_playerController->GetPlayerState()) {
			
		case PlayerState::ALIVE:
			drawPlayer();
			break;
			
		}
	}

	int  PlayerView::GetPlayerPosition()
	{
		return currrentPosition;
	}

	void PlayerView::SetPlayerPosition(int newPosition)
	{
		currrentPosition = newPosition;
	}

	void PlayerView::CalculatePlayerDimensions()
	{
		currentBoxDimensions = ServiceLocator::getInstance()->getLevelService()->GetBoxDimension();
		m_playerWidth = currentBoxDimensions.box_width;
		m_playerHeight = currentBoxDimensions.box_height;
	}

	void PlayerView::updatePlayerPosition()
	{
		m_playerImage->setPosition(calulcatePlayerPosition());
	}

	sf::Vector2f PlayerView::calulcatePlayerPosition()
	{
		float xPosition = currentBoxDimensions.box_spacing + static_cast<float>(m_playerController->GetPlayerPosistion());
		float yPosition = static_cast<float>(m_gameWindow->getSize().y) - currentBoxDimensions.box_height - currentBoxDimensions.bottom_offset - m_playerHeight;
		return sf::Vector2f(xPosition, yPosition);
	}

	void PlayerView::InitializePlayerImage()
	{
		
		 m_playerImage->initialize(Config::character_texture_path,
			m_playerWidth,
			m_playerHeight,
			sf::Vector2f(100,200));
	}
	void PlayerView::drawPlayer()
	{
		m_playerImage->render();
	}
	void PlayerView::LoadPlayer()
	{
		CalculatePlayerDimensions();
		InitializePlayerImage();
	}
}