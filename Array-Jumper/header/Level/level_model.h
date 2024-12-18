#pragma once
#include"../../header/Level/level_data.h"
namespace Level {


	struct BoxDimensions {
		float box_width;
		float box_height;
		float box_spacing;

		float box_spacing_percentage = 0.1f;
		float bottom_offset = 150.f;
	};
	
	class LevelModel {

	private :

		LevelData current_level_data;

	public:
		LevelModel();
		~LevelModel();

		BlocKType getCurrentBoxValue(int currentPosition);
	};
}