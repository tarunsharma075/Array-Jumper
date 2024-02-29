#pragma once
#include <SFML/Graphics.hpp>
#include "../../header/Sound/SoundService.h"

namespace UI
{
	namespace SplashScreen
	{
		/*class SoundService;*/

		class SplashScreenUIController
		{
		private:
			// Constants:
			const float logo_animation_time = 2.0f;
			const float splash_screen_time = 6.0f;

			Sound::SoundService* sound_service;
			sf::RenderWindow* game_window;
			sf::Texture outscal_logo_texture;
			sf::Sprite outscal_logo_sprite;
			sf::Clock clock;
			float elapsed_time;

			// Initialization:
			void initializeVariables();
			void initializeOutscalLogo();
			void loadOutscalTexture();
			bool tryLoadingOutscalLogo();
			void setPositionToCenter();

			void showLogoWithFade();
			void hideLogoWithFade();
			void logoAnimationComplete();
			void updateLogo(float deltaTime);

		public:
			SplashScreenUIController();

			void initialize(sf::RenderWindow* game_window_instance, Sound::SoundService* sound_service_instance);
			void update();
			void render();

			void showSplashScreen();
		};
	}
}

