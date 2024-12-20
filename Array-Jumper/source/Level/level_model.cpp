#include"../../header/Level/level_model.h"
namespace Level {
    LevelModel::LevelModel()
    {
    }
    LevelModel::~LevelModel()
    {
    }
    BlocKType LevelModel::getCurrentBoxValue(int currentPosition)
    {
        return current_level_data.level_boxes[currentPosition];
    }
}