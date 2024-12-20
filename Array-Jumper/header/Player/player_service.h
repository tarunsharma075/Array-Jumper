#pragma once

namespace Player
{
	class PlayerController;
	class PlayerService
	{
	private:
		PlayerController* playercontroller;

		void destroy();

	public:
		PlayerService();
		~PlayerService();

		void Initialize();
		void Update();
		void Render();
		int GetPlayerPosition();
	};
}