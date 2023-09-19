#pragma once
#include <SFML/Graphics.hpp>

class GameService;
class UIHandler;

class SplashScreenUIController
{
private:
	// Constants:
	const float logo_animation_time = 2.0f;
	const float splash_screen_time = 6.0f;

	GameService* game_service;
	UIHandler* ui_handler;

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

	void initialize(sf::RenderWindow* window_to_set, GameService* game_service_instance, UIHandler* ui_handler_instance);
	void update();
	void render();

	void showSplashScreen();
};

