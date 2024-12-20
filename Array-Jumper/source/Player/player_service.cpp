#include"../../header/Player/player_controller.h"
#include"../../header/Player/player_service.h"
#include<iostream>
namespace Player
{
	PlayerService::PlayerService() { playercontroller = new PlayerController(); }

	PlayerService::~PlayerService() { destroy(); }

	void PlayerService::Initialize()
	{
		playercontroller->Initialize();
	}

	void PlayerService::Update()
	{
		playercontroller->Update();
	}

	void PlayerService::Render()
	{
		
		playercontroller->Render();
	}

	int PlayerService::GetPlayerPosition()
	{
		return playercontroller->GetPlayerPosition();
	}

	

	void PlayerService::destroy() { delete(playercontroller); }
}
