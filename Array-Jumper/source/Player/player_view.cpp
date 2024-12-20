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

	void PlayerView::CalculatePlayerDimensions()
	{
		m_playerHeight = 1000.f;
		m_playerWidth = 1000.f;
	}

	void PlayerView::updatePlayerPosition()
	{
		m_playerImage->setPosition(calulcatePlayerPosition());
	}

	sf::Vector2f PlayerView::calulcatePlayerPosition()
	{
		return sf::Vector2f(0,0);
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