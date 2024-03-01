#pragma once
#include <SFML/Graphics.hpp>
#include "../../header/Graphics/GraphicService.h"


namespace UI
{
	namespace Instrcutions
	{
		class GraphicService;

		class InstrcutionsUIController
		{
		private:
			const int number_of_instructions = 4;
			const float top_offset = 250.f;
			const float text_spacing = 100.f;

			const sf::String instruction_string_one = "Move with 'Left' and 'Right' arrow keys";
			const sf::String instruction_string_two = "Hold 'Space' while moving to 'JUMP'";
			const sf::String instruction_string_three = "Your player will 'JUMP' forward or backward by the value of your current cell";
			const sf::String instruction_string_four = "Reach the target cell to 'Win' the game";

			sf::String* instructions;

			// Textures:
			sf::Texture background_texture;
			sf::Sprite background_sprite;

			sf::Texture menu_button_texture;
			sf::Sprite menu_button_sprite;

			void initializeInstructions();
			void drawInstructions();
			void onDestroy();

		public:
			InstrcutionsUIController();
			~InstrcutionsUIController();

			void initialize();
			void update();
			void render();
		};
	}
}