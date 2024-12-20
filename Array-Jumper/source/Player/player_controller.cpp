#include "../../header/Player/player_controller.h"
#include "../../header/Player/player_view.h"
#include "../../header/Player/player_model.h"
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
	}

	void Player::PlayerController::Update()
	{
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
	int PlayerController::GetPlayerPosition()
	{
		return m_playerModelForPlayerController->GetPosition();
	}
	void PlayerController::Destroy()
	{
		delete(m_playerModelForPlayerController);
		delete(m_playerViewForPlayerController);
	}

}
