#include"../../header/Player/PlayerModel.h"

namespace Player {
	void PlayerModel::SetPlayerPosition(float _positionChange)
	{
		m_currentPosition = _positionChange;
	}
	float PlayerModel::GetPlayerPosition()
	{
		return m_currentPosition;
	}
	void PlayerModel::SetPlayerState(PlayerState _playerCurrentState) {
		m_currentState = _playerCurrentState;
	}
    
	
	
	

}