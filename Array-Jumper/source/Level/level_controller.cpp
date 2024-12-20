#include"../../header/Level/level_controller.h"
#include"../../header/Level/level_model.h"
#include"../../header/Level/level_view.h"
#include"../../header/Level/BlockType.h"
#include<iostream>
namespace Level {
	LevelController::LevelController()
	{
		m_levlModelForLevelController = new LevelModel();
		m_levlViewForLevelController = new LevelView(this);
	}
	LevelController::~LevelController()
	{
	}
	void LevelController::Initialize()
	{

		m_levlViewForLevelController->initilaize();
	}
	void LevelController::Update()
	{
		m_levlViewForLevelController->update();
	
	}
	void LevelController::Render()
	{
		m_levlViewForLevelController->render();
	}
	BlocKType LevelController::getCurrentBoxValue(int currentValue)
	{
		return m_levlModelForLevelController->getCurrentBoxValue(currentValue);
	}
	BoxDimensions LevelController::GetBoxDimension()
	{
		
		return m_levlViewForLevelController->getBoxDimension();
	}
}