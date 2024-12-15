#pragma once

namespace Level {

	class LevelModel;
	class LevelView;

	class LevelController {

	private:
		LevelModel* m_levlModelForLevelController;
		LevelView* m_levlViewForLevelController;

		public:
			LevelController();
			~LevelController();
			void Initialize();
			void Update();
			void Render();
	};
}
