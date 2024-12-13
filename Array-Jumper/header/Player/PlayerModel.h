#pragma once

namespace Player {

	enum class PlayerState {

		Alive,
		Dead,
	};
	class PlayerModel {
		
	private:
		float m_currentPosition;
		PlayerState m_currentState;

	public:
		
		void SetPlayerPosition(float _positionChange);
		float GetPlayerPosition();
		void SetPlayerState(PlayerState _playerCurrentState);
		
	
		
	};
}