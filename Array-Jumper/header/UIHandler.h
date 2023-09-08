#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics.hpp>

class GameService;

enum class UIState
{
	SPLASH_SCREEN,
	MAIN_MENU,
};

class UIHandler
{
private:
	GameService* game_service;
	UIState current_state;

	// Constants:
	const float logo_animation_time = 2.0f;
	const float splash_screen_time = 6.0f;
	const float button_width = 400.f;
	const float button_height = 140.f;

	sf::Clock clock;
	float elapsedTime;

	sf::RenderWindow* game_window;

	// Textures:
	sf::Texture background_texture;
	sf::Sprite background_sprite;

	sf::Texture play_button_texture;
	sf::Sprite play_button_sprite;

	sf::Texture instructions_button_texture;
	sf::Sprite instructions_button_sprite;

	sf::Texture quit_button_texture;
	sf::Sprite quit_button_sprite;

	sf::Texture outscal_logo_texture;
	sf::Sprite outscal_logo_sprite;

	void initializeVariables(sf::RenderWindow* window);
	void initializeOutscalLogo();
	void initializeBackgroundImage();
	void initializeButtons();
	
	void updateSplashSceenUI();
	void updateMainMenuUI();

	void renderSplashScreenUI();
	void renderMainMenuUI();

	void loadOutscalTexture();
	bool tryLoadingOutscalLogo();
	void setPositionToCenter();

	void scaleBackgroundImage();
	bool loadButtonTexturesFromFile();
	void setButtonSprites();
	void scaleAllButttons();
	void scaleButton(sf::Sprite* buttonToScale);
	void positionButtons();
	
	void updateLogo(float deltaTime);
	void showLogoWithFade();
	void hideLogoWithFade();
	void logoAnimationComplete();

	bool pressedMouseButton();
	void handleButtonInteractions();
	bool clickedButton(sf::Sprite*, sf::Vector2f);

public:
	UIHandler(GameService* instance, sf::RenderWindow* window);
	~UIHandler();

	void initialize(sf::RenderWindow* window_to_set);
	void updateUI();
	void render();

	void setUIState(UIState new_state);
	
	void showSplashScreen();
	void showMainMenuScreen();
};