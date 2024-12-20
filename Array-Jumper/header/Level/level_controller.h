#pragma once

namespace Level {

	class LevelModel;
	class LevelView;
	enum class BlocKType ;
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
			BlocKType getCurrentBoxValue(int currentValue);
	};
}
