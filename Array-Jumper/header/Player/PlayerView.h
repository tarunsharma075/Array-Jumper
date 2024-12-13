#pragma once

#include "../../header/UI/UIElement/ImageView.h"
#include "SFML/Graphics.hpp" 

namespace Player {

    class PlayerView {
       
    private:
        UI::UIElement::ImageView* m_player_Image;
        sf::RenderWindow* m_game_Window;
        float m_playerHeight;
        float m_playerWidth;

        void InitializePlayerImage(); // Initialize player
        void LoadPlayer(); // Loads the information needed to render the player
        void calculatePlayerDimensions(); // Calculate the size of image
        void updatePlayerPosition(); // Updates the Player Sprite's position on each frame
        sf::Vector2f calculatePlayerPosition(); // Fixed typo in function name

    public:
        PlayerView();
        ~PlayerView();

        void initialize();
        void update();
        void render();
    };

} 
