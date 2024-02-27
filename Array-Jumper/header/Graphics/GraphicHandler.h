#pragma once
#include <SFML/Graphics/RenderWindow.hpp>

namespace Graphics
{
	class GraphicHandler
	{
	private:
		// Constants
		const std::string game_window_title = "Outscal Presents - Array Jumper";
		const int game_window_width = 1920;
		const int game_window_height = 1080;
		const sf::Color window_color = sf::Color(200, 200, 0, 255);

		sf::VideoMode video_mode;
		sf::RenderWindow* game_window;

		void configureVideoMode();

	public:
		GraphicHandler();
		~GraphicHandler();

		sf::RenderWindow* createGameWindow();
		bool isGameWindowOpen();
		void setFrameRate(int);
	};
}