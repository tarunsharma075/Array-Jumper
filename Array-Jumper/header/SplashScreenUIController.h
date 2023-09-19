#pragma once
#include <SFML/Graphics.hpp>

class UIHandler;

class SplashScreenUIController
{
private:
	// Constants:
	const float logo_animation_time = 2.0f;
	const float splash_screen_time = 6.0f;

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

	void initialize(UIHandler* ui_handler_instance, sf::RenderWindow* window_to_set);
	void update();
	void render();

	void showSplashScreen();
};

