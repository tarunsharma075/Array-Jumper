#pragma once

namespace Player
{
	enum class PlayerState
	{
		ALIVE,
		DEAD
	};

	class PlayerModel
	{
	private:

		PlayerState m_PlayerState= PlayerState::ALIVE;
		int m_current_position;

	public:
		PlayerState getPlayerState();
		void SetPlayerState(PlayerState new_player_state);

		int GetPosition();
		void SetPlayerCurrentPosition(int new_position);
		void Initialize();
		void Update();
		void Render();
	};
}