#include "../../header/Player/PlayerView.h"
#include"../../header/Global/Config.h"
#include"../../header/Global/ServiceLocator.h"
using namespace UI::UIElement;
using namespace Global;

Player::PlayerView::PlayerView()
{
}

Player::PlayerView::~PlayerView()
{
	m_game_Window = NULL;
	m_player_Image = new ImageView();
}



void Player::PlayerView::CalculatePlayerDimensions()
{
	m_playerHeight = 1000.f;
	m_playerHeight = 1000.f;
}


void Player::PlayerView::InitializePlayerImage()
{
	m_player_Image->initialize(Config::character_texture_path, m_playerWidth, m_playerHeight, sf::Vector2f(0,0));
}

void Player::PlayerView::LoadPlayer()
{
	CalculatePlayerDimensions();
	InitializePlayerImage();

}
void Player::PlayerView::initialize()
{
	ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
	LoadPlayer();
}

sf::Vector2f Player::PlayerView::calculatePlayerPosition()
{
	return sf::Vector2f();
}

void Player::PlayerView::updatePlayerPosition()
{
	m_player_Image->setPosition(calculatePlayerPosition());
}

void Player::PlayerView::drawPlayer()
{
	m_player_Image->render();
}


