#pragma once

namespace Player {
	class PlayerModel {
	private:
		float m_currentPosition;

	public:

		void SetPlayerPosition(float _positionChange);
		float GetPlayer();

		enum class PlayerState {
			Alive,
			Dead,
		};
	};
}