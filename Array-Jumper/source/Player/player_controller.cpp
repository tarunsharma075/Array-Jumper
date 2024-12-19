#include "../../header/Player/player_controller.h"
#include "../../header/Player/player_view.h"
#include "../../header/Player/player_model.h"
#include"../../header/Global/ServiceLocator.h"
using namespace Event;
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
		event = Global::ServiceLocator::getInstance()->getEventService();
	}

	void Player::PlayerController::Update()
	{
		ReadInput();
		m_playerViewForPlayerController->update();
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
	int PlayerController::GetPlayerPosistion()
	{
		return m_playerModelForPlayerController->GetPosition();
	}
	void PlayerController::move(MovementDirection direction)
	{
		int steps, targetPosition;
		switch (direction)
		{
		case Player::Forward:
			steps = 1;
			break;
		case Player::BacKward:
			steps = -1;
			break;
		default:
			steps = 0;
			break;
		}
		targetPosition = m_playerModelForPlayerController->GetPosition() + steps;
		if (!IsPlayerInBounds(targetPosition))

			return;
		m_playerModelForPlayerController->SetPlayerCurrentPosition(targetPosition);
		Global::ServiceLocator::getInstance()->getSoundService()->playSound(Sound::SoundType::MOVE);
		
	}
	bool PlayerController::IsPlayerInBounds(int targetPosition)
	{
		
			if (targetPosition >= 0 && targetPosition <=Level::LevelData::NUMBER_OF_BOXES) {
				return true;
			}
			else {
				return false;
			}

		
	}
	void PlayerController::ReadInput()
	{
		if (event->pressedAKey() || event->pressedLeftArrowKey()) {

			move(MovementDirection::BacKward);

			if (event->heldSpaceKey()) {
				Jump(MovementDirection::BacKward);
			}
			else {
				Jump(MovementDirection::BacKward);
			}
		}
		else if (event->pressedDKey() || event->pressedRightArrowKey()) {
			move(MovementDirection::Forward);


			if (event->heldSpaceKey()) {
				Jump(MovementDirection::Forward);
			}
			else {
				Jump(MovementDirection::Forward);
			}
		}
	}

	Level::BlocKType PlayerController::GetCurrentBoxValue(int currentPosition)
	{
		return Level::BlocKType();
	}

	void PlayerController::Jump(MovementDirection direction)
	{
		int currentPosition = m_playerModelForPlayerController->GetPosition();
		Level::BlocKType currentBoxValue = Global::ServiceLocator::getInstance()->getLevelService()->GetBoxValue(currentPosition);
		int steps, target=0;
		switch (direction)
		{
		case Player::Forward:
			steps = static_cast<int>(currentBoxValue);
			break;
		case Player::BacKward:
			steps = static_cast<int>(currentBoxValue)*-1;
			break;
		default:
			steps = 0;
			break;
		}
		m_playerModelForPlayerController->SetPlayerCurrentPosition(target);
		Global::ServiceLocator::getInstance()->getSoundService()->playSound(Sound::SoundType::JUMP);
	}
	
	void PlayerController::Destroy()
	{
		delete(m_playerModelForPlayerController);
		delete(m_playerViewForPlayerController);
	}

}

