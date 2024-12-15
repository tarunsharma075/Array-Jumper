#pragma once
namespace Level {
	class LevelController;
	class LevelService {
	private:
		LevelController*m_playerControllerForPlayerService;

	public:

		LevelService();
		~LevelService();
		void Initialize();
		void Update();
		void Render();
	};
 }