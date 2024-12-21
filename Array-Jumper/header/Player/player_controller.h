#pragma once
#include"../../header/Player/movement_direction.h"
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
		void Move(MoveMentDirection direction);
		bool IsPositionValid(int targetpsoition);
		Event::EventService* eventService;
		void ReadInput();
	};
}