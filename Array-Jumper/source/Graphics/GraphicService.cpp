#include "../../header/Graphics/GraphicService.h"
#include "../../header/Global/Config.h"


namespace Graphics
{
	using namespace Global;
	
	GraphicService::GraphicService() { game_window = nullptr; }

	GraphicService::~GraphicService() { onDestroy(); }

	void GraphicService::initialize()
	{
		createGameWindow();
		setFrameRate(frame_rate);
		initializeText();
	}

	void GraphicService::update(){}
	void GraphicService::render(){}

	sf::RenderWindow* GraphicService::createGameWindow()
	{
		configureVideoMode();
		game_window = new sf::RenderWindow(video_mode, game_window_title, sf::Style::Fullscreen);
		return game_window;
	}

	void GraphicService::configureVideoMode()
	{
		video_mode = *(new sf::VideoMode(game_window_width, game_window_height, sf::VideoMode::getDesktopMode().bitsPerPixel));
	}

	void GraphicService::setFrameRate(int frame_rate_to_set) { game_window->setFramerateLimit(frame_rate_to_set); }

	void GraphicService::initializeText()
	{
		loadFont();
		setupText();
	}

	bool GraphicService::loadFont() { return font.loadFromFile(Config::bubble_bobble_font_path); }

	void GraphicService::setupText()
	{
		text.setFont(font);
		text.setCharacterSize(default_font_size);
		text.setFillColor(sf::Color::White);
	}

	bool GraphicService::isGameWindowOpen() { return game_window->isOpen(); }

	sf::RenderWindow* GraphicService::getGameWindow() { return game_window; }

	void GraphicService::drawText(sf::String text_value, sf::Vector2f text_position)
	{
		text.setString(text_value);
		text.setPosition(text_position);
		game_window->draw(text);
	}

	void GraphicService::drawText(sf::String text_value, float text_y_position, int font_size_to_set)
	{
		text.setCharacterSize(font_size_to_set);
		drawText(text_value, text_y_position);
		text.setCharacterSize(default_font_size);
	}

	void GraphicService::drawText(sf::String text_value, float text_y_position)
	{
		text.setString(text_value);
		center_align_text(text_y_position);
		game_window->draw(text);
	}

	void GraphicService::center_align_text(float y_position)
	{
		sf::FloatRect textBounds = text.getLocalBounds();

		float x_position = (game_window->getSize().x - textBounds.width) / 2;
		text.setPosition(x_position, y_position);
	}

	void GraphicService::onDestroy()
	{
		delete(game_window);
	}

}