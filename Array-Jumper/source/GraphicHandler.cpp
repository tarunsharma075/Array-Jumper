#include "../header/GraphicHandler.h"

GraphicHandler::GraphicHandler() { game_window = nullptr; }

GraphicHandler::~GraphicHandler() { delete(game_window); }

sf::RenderWindow* GraphicHandler::createGameWindow()
{
	configureVideoMode();
	game_window = new sf::RenderWindow(video_mode, game_window_title, sf::Style::Fullscreen);
	return game_window;
}

void GraphicHandler::configureVideoMode()
{
	video_mode = *(new sf::VideoMode(game_window_width, game_window_height, sf::VideoMode::getDesktopMode().bitsPerPixel));
}

void GraphicHandler::setFrameRate(int frame_rate_to_set) { game_window->setFramerateLimit(frame_rate_to_set); }

void GraphicHandler::updateGraphics() { }

void GraphicHandler::render() { }

bool GraphicHandler::isGameWindowOpen() { return game_window->isOpen(); }

sf::RenderWindow* GraphicHandler::getWindow() { return game_window; }