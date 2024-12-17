#include "../../header/Global/ServiceLocator.h"
#include "../../header/Main/GameService.h"
#include "../../header/Event/EventService.h"
#include"../../header/Player/player_service.h"
#include"../../header/Level/level_service.h"

namespace Global
{
	
	

	ServiceLocator::ServiceLocator()
	{
		graphic_service = nullptr;
		event_service = nullptr;
		sound_service = nullptr;
		ui_service = nullptr;
		player_service = nullptr;
		level_service = nullptr;

		createServices();
	}

	ServiceLocator::~ServiceLocator() { clearAllServices(); }

	void ServiceLocator::createServices()
	{
		graphic_service = new GraphicService();
		event_service = new EventService();
		sound_service = new SoundService();
		ui_service = new UIService();
		player_service = new PlayerService();
		level_service = new LevelService();
	}

	void ServiceLocator::initialize()
	{
		graphic_service->initialize();
		event_service->initialize();
		sound_service->initialize();
		ui_service->initialize();
		player_service->Initialize();
		level_service->Initialize();
	}

	void ServiceLocator::update()
	{
		graphic_service->update();
		event_service->update();
		ui_service->update();
		if (Main::GameService::getGameState() == Main::GameState::GAMEPLAY)
		{
			player_service->Update();
			level_service->Update();
		}
	}
	

	void ServiceLocator::render()
	{
		graphic_service->render();
		ui_service->render();
		if (Main::GameService::getGameState() == Main::GameState::GAMEPLAY)
		{
			level_service->Render();
			//player_service->Render();
		
		}
	

	}

	void ServiceLocator::clearAllServices()
	{
		delete(graphic_service);
		delete(event_service);
		delete(sound_service);
		delete(ui_service);
	}

	ServiceLocator* ServiceLocator::getInstance()
	{
		static ServiceLocator instance;
		return &instance;
	}

	GraphicService* ServiceLocator::getGraphicService() { return graphic_service; }

	EventService* ServiceLocator::getEventService() { return event_service; }

	SoundService* ServiceLocator::getSoundService() { return sound_service; }

	UIService* ServiceLocator::getUIService() { return ui_service; }
	Player::PlayerService* ServiceLocator::getPlayerService() { return player_service; }

	LevelService *ServiceLocator::getLevelService()
	{
		return level_service;
	}
	
}