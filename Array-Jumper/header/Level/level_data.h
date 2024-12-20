#pragma once
#include"../../header/Level/BlockType.h"

namespace Level {
 
    struct LevelData
    {
        static const int NUMBER_OF_BOXES = 10;

            BlocKType level_boxes[NUMBER_OF_BOXES] = {
            BlocKType::ONE,
            BlocKType::TWO,
            BlocKType::OBSTACLE_ONE,
            BlocKType::TWO,
            BlocKType::THREE,
            BlocKType::ONE,
            BlocKType::OBSTACLE_TWO,
            BlocKType::TWO,
            BlocKType::ONE,
            BlocKType::TARGET};
    };
    }