#include "../header/MainMenuUIController.h"

MainMenuUIController::MainMenuUIController()
{
    game_window = nullptr;
}

void MainMenuUIController::initialize(sf::RenderWindow* window_to_set)
{
    game_window = window_to_set;
    initializeBackgroundImage();
    initializeButtons();
}

void MainMenuUIController::update()
{
    if (pressedMouseButton()) handleButtonInteractions();
}

void MainMenuUIController::render()
{
    game_window->draw(background_sprite);
    game_window->draw(play_button_sprite);
    game_window->draw(instructions_button_sprite);
    game_window->draw(quit_button_sprite);
}

// Load the background texture and sprite
void MainMenuUIController::initializeBackgroundImage()
{
    if (background_texture.loadFromFile("assets/textures/array_jumper_bg.png"))
    {
        background_sprite.setTexture(background_texture);
        scaleBackgroundImage();
    }
}

void MainMenuUIController::scaleBackgroundImage()
{
    background_sprite.setScale(
        static_cast<float>(game_window->getSize().x) / background_sprite.getTexture()->getSize().x,
        static_cast<float>(game_window->getSize().y) / background_sprite.getTexture()->getSize().y
    );
}

void MainMenuUIController::initializeButtons()
{
    if (loadButtonTexturesFromFile())
    {
        setButtonSprites();
        scaleAllButttons();
        positionButtons();
    }
}

bool MainMenuUIController::loadButtonTexturesFromFile()
{
    return play_button_texture.loadFromFile("assets/textures/play_button.png") &&
        instructions_button_texture.loadFromFile("assets/textures/instructions_button.png") &&
        quit_button_texture.loadFromFile("assets/textures/quit_button.png");
}

void MainMenuUIController::setButtonSprites()
{
    play_button_sprite.setTexture(play_button_texture);
    instructions_button_sprite.setTexture(instructions_button_texture);
    quit_button_sprite.setTexture(quit_button_texture);
}

void MainMenuUIController::scaleAllButttons()
{
    scaleButton(&play_button_sprite);
    scaleButton(&instructions_button_sprite);
    scaleButton(&quit_button_sprite);
}

void MainMenuUIController::scaleButton(sf::Sprite* button_to_scale)
{
    button_to_scale->setScale(
        button_width / button_to_scale->getTexture()->getSize().x,
        button_height / button_to_scale->getTexture()->getSize().y
    );
}

void MainMenuUIController::positionButtons()
{
    float x_position = (static_cast<float>(game_window->getSize().x) / 2) - button_width / 2;

    play_button_sprite.setPosition({ x_position, 500.f });
    instructions_button_sprite.setPosition({ x_position, 700.f });
    quit_button_sprite.setPosition({ x_position, 900.f });
}

bool MainMenuUIController::pressedMouseButton() { return sf::Mouse::isButtonPressed(sf::Mouse::Left); }

void MainMenuUIController::handleButtonInteractions()
{
    sf::Vector2f mouse_position = sf::Vector2f(sf::Mouse::getPosition(*game_window));

    if (clickedButton(&play_button_sprite, mouse_position))
    {
        printf("Clicked Play Button \n");
    }

    if (clickedButton(&instructions_button_sprite, mouse_position))
    {
        printf("Clicked Instruction Button \n");
    }

    if (clickedButton(&quit_button_sprite, mouse_position))
    {
        game_window->close();
    }
}

bool MainMenuUIController::clickedButton(sf::Sprite* button_sprite, sf::Vector2f mouse_position)
{
    return button_sprite->getGlobalBounds().contains(mouse_position);
}

void MainMenuUIController::showMainMenuScreen()
{
}