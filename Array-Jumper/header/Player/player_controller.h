#pragma once
namespace Player {
	class PlayerModel;
	class PlayerView;
	enum class PlayerState;
	class PlayerController {
	private:
		PlayerModel* m_playerModelForPlayerController;
		PlayerView* m_playerViewForPlayerController;
		PlayerState m_plyaerState;
		
		void Destroy();

	public:
		PlayerController();
		~PlayerController();
		void Initialize();
		void Update();
		void Render();

		PlayerState GetPlayerState();
		void SetPlayerState(PlayerState newPlayerState);
		int GetPlayerPosition();
	};
}