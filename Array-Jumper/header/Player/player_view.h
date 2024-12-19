#pragma once
#include"../../header/UI/UIElement/ImageView.h"
#include"../../header/Level/level_model.h"

namespace Player {
	class PlayerController;
	enum class PlayerState;
	class PlayerView {

	private:
		UI::UIElement::ImageView* m_playerImage;
		sf::RenderWindow* m_gameWindow;
		float m_playerHeight;
		float m_playerWidth;
		int currrentPosition;

		void InitializePlayerImage(); //Initialize player_image 
		void drawPlayer(); //Called every frame to render the sprite on the screen
		void LoadPlayer(); //Loads the information needed to render the player
		void CalculatePlayerDimensions(); //Calculate the size of image
		void updatePlayerPosition(); //Updates the Player Sprite's position on each frame
		sf::Vector2f calulcatePlayerPosition();
		PlayerController* m_playerController;
		Level::BoxDimensions currentBoxDimensions;

	public:
		PlayerView(PlayerController* controller);
		~PlayerView();

		void initialize();
		void update();
		void render();
		int  GetPlayerPosition();
		void SetPlayerPosition(int newPosition);
;
	};
}