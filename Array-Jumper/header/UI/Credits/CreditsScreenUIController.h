#pragma once
#include <SFML/Graphics.hpp>


namespace UI
{
	namespace Credits
	{

		class CreditsScreenUIController
		{
		private:
			sf::RenderWindow* game_window;
			const sf::String game_window_title = "Outscal Presents - Array Jumper";
			
			const float button_width = 400.f;
			const float button_height = 140.f;
			const float background_alpha = 110.f;

			// Textures:
			sf::Texture background_texture;
			sf::Sprite background_sprite;

			sf::Texture quit_button_texture;
			sf::Sprite quit_button_sprite;

			sf::Texture menu_button_texture;
			sf::Sprite menu_button_sprite;

			const float top_offset = 300.f;
			const int font_size = 100;

			void initializeBackgroundImage();
			void setBackgroundAlpha();
			void scaleBackgroundImage();

			void initializeButtons();
			bool loadButtonTexturesFromFile();
			void setButtonSprites();

			void scaleAllButttons();
			void scaleButton(sf::Sprite* button_to_scale);
			void positionButtons();

			bool pressedMouseButton();
			void handleButtonInteractions();
			bool clickedButton(sf::Sprite*, sf::Vector2f);

			void onClickQuitButton();
			void onClickMenuButton();

			void drawGameTitle();

		public:
			CreditsScreenUIController();
			~CreditsScreenUIController();

			void initialize();
			void update();
			void render();
		};
	}
}
