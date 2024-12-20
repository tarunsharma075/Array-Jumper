#include"../../header/Level/level_controller.h"
#include"../../header/Level/level_service.h"
namespace Level {
	LevelService::LevelService()
	{
		m_playerControllerForPlayerService = new LevelController();
	}
	LevelService::~LevelService()
	{
		delete(m_playerControllerForPlayerService);
	}
	void LevelService::Initialize()
	{
		m_playerControllerForPlayerService->Initialize();
	}
	void LevelService::Update()
	{
		m_playerControllerForPlayerService->Update();
	}
	void LevelService::Render()
	{
		m_playerControllerForPlayerService->Render();
	}
	BoxDimensions LevelService::GetBoxDimesnion()
	{
		return m_playerControllerForPlayerService->GetBoxDimension();
	}
}