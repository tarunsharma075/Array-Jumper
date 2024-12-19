#pragma once
#include"../../header/Level/level_model.h"
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
		BoxDimensions GetBoxDimension();
		Level::BlocKType GetBoxValue(int currrentPosition);
	};
 }