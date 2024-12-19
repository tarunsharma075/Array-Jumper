#pragma once
#include"../../header/Player/MovementDirection.h"
#include"../../header/Level/level_model.h"
#include"../../header/Event/EventService.h"
namespace Player {
	class PlayerModel;
	class PlayerView;
	enum class PlayerState;
	class PlayerController {
	private:
		PlayerModel* m_playerModelForPlayerController;
		PlayerView* m_playerViewForPlayerController;
		PlayerState m_plyaerState;
		Event::EventService* event;
		
		void Destroy();

	public:
		PlayerController();
		~PlayerController();
		void Initialize();
		void Update();
		void Render();

		PlayerState GetPlayerState();
		void SetPlayerState(PlayerState newPlayerState);
		int GetPlayerPosistion();
		void move(MovementDirection direction);
		bool IsPlayerInBounds(int targetPosition);
		void ReadInput();
		Level::BlocKType GetCurrentBoxValue(int currentPosition);
		void Jump(MovementDirection direction);
	};
}