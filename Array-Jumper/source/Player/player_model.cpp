#include "../../header/Player/player_model.h"
namespace Player {


	PlayerState PlayerModel::getPlayerState()
	{
		return m_PlayerState;
	}

	

	void Player::PlayerModel::SetPlayerState(PlayerState newPlayerState)
	{
		m_PlayerState = newPlayerState;
	}
	int PlayerModel::GetPosition()
	{
		return m_current_position;
	}
	void PlayerModel::SetPlayerCurrentPosition(int newPosition)
	{
		m_current_position = newPosition;
	}
	void PlayerModel::Initialize()
	{
	}
	void PlayerModel::Update()
	{
	}
	void PlayerModel::Render()
	{
	}
}