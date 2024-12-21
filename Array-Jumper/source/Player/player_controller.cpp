#include "../../header/Player/player_controller.h"
#include "../../header/Player/player_view.h"
#include "../../header/Player/player_model.h"
#include"../../header/Global/ServiceLocator.h"
#include"../../header/Event/EventService.h"
#include<iostream>
namespace Player {
	
	Player::PlayerController::PlayerController()
	{
		m_playerModelForPlayerController = new PlayerModel();
		m_playerViewForPlayerController = new PlayerView(this);
	}

	PlayerController::~PlayerController()
	{
		Destroy();
	}

	void Player::PlayerController::Initialize()
	{
		m_playerModelForPlayerController->Initialize();
		m_playerViewForPlayerController->initialize();
		eventService = Global::ServiceLocator::getInstance()->getEventService();
		
	}

	void Player::PlayerController::Update()
	{
		
		m_playerViewForPlayerController->update();
		ReadInput();
	}

	void Player::PlayerController::Render()
	{
		m_playerViewForPlayerController->render();
	}

	PlayerState Player::PlayerController::GetPlayerState()
	{
		return m_playerModelForPlayerController->getPlayerState();
	}

	void PlayerController::SetPlayerState(PlayerState newPlayerState)
	{
		m_playerModelForPlayerController->SetPlayerState(newPlayerState);
	}
	int PlayerController::GetPlayerPosition()
	{
		return m_playerModelForPlayerController->GetCurrentPsoition();
	}
	void PlayerController::Move(MoveMentDirection direction)
	{
		int steps, targetPsoition;
		switch (direction) {

		case MoveMentDirection::Forward:
			steps = 1;
			break;
			case MoveMentDirection::Backward:
				steps = -1;
				break;
			default:
				steps = 0;
				break;
		}
		targetPsoition = m_playerModelForPlayerController->GetCurrentPsoition() + steps;
		if (!IsPositionValid(targetPsoition)) {
			return;

			m_playerModelForPlayerController->SetPlayerCurrentPosition(targetPsoition);
			Global::ServiceLocator::getInstance()->getSoundService()->playSound(Sound::SoundType::MOVE);
		}
	}
	bool PlayerController::IsPositionValid(int targetpsoition)
	{
		if (targetpsoition >= 0 && targetpsoition < Level::LevelData::NUMBER_OF_BOXES)
			
			return true;
		return false;
	}
	void PlayerController::ReadInput()
	{
		if (eventService->pressedDKey() || eventService->pressedLeftArrowKey())
		{
			Move(MoveMentDirection::Forward);
		}
		if (eventService->pressedAKey() || eventService->pressedRightArrowKey());
		{
			Move(MoveMentDirection::Backward);
		}
	}
	void PlayerController::Destroy()
	{
		delete(m_playerModelForPlayerController);
		delete(m_playerViewForPlayerController);
	}

}
