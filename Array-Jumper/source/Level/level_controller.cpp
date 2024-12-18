#include"../../header/Level/level_controller.h"
#include"../../header/Level/level_model.h"
#include"../../header/Level/level_view.h"
#include"../../header/Level/BlockType.h"
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
		m_levlViewForLevelController->Initialize();
	}
	void LevelController::Update()
	{
		m_levlViewForLevelController->Update();
	}
	void LevelController::Render()
	{
		m_levlViewForLevelController->Render();
	}
	BlocKType LevelController::getCurrentBoxValue(int currentValue)
	{
		return m_levlModelForLevelController->getCurrentBoxValue(currentValue);
	}
	BoxDimensions LevelController::GetBoxDimensions()
	{
		return m_levlViewForLevelController->getBoxDimensions();
	}
}