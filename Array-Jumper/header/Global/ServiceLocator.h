#pragma once
#include "../../header/Graphics/GraphicService.h"
#include "../../header/Event/EventService.h"
#include "../../header/UI/UIService.h"
#include "../../header/Sound/SoundService.h"
#include"../../header/Player/player_service.h"
#include"../../header/Level/level_service.h"


namespace Global
{
    using namespace Graphics;
    using namespace Event;
    using namespace Sound;
    using namespace UI;
    using namespace Player;
    using namespace Level;
    

    class ServiceLocator
    {
    private:
     GraphicService* graphic_service;
     EventService* event_service;
      SoundService* sound_service;
        UI::UIService* ui_service;
       PlayerService* player_service;
        LevelService* level_service;

        ~ServiceLocator();

        void createServices();
        void clearAllServices();

    public:
        ServiceLocator();
        static ServiceLocator* getInstance();

        void initialize();
        void update();
        void render();

       GraphicService* getGraphicService();
        EventService* getEventService();
        SoundService* getSoundService();
      UIService* getUIService();
       PlayerService* getPlayerService();
       LevelService *getLevelService();
        
    };
}