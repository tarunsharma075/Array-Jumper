#include "../header/UIHandler.h"
#include "../header/GameService.h"

UIHandler::UIHandler(GameService* instance, sf::RenderWindow* window)
{
    game_service = instance;
    game_window = nullptr;
}

UIHandler::~UIHandler() { }

void UIHandler::initialize(sf::RenderWindow* window)
{
    initializeVariables(window);
    initializeOutscalLogo();
    initializeBackgroundImage();
    initializeButtons();
}

void UIHandler::initializeVariables(sf::RenderWindow* window)
{
    game_window = window;
    elapsedTime = 0.0f;
}

void UIHandler::initializeOutscalLogo()
{
    loadOutscalTexture();
    outscal_logo_sprite.setTexture(outscal_logo_texture);
    setPositionToCenter();
}

// Load the background texture and sprite
void UIHandler::initializeBackgroundImage()
{
    if (background_texture.loadFromFile("assets/textures/array_jumper_bg.png"))
    {
        background_sprite.setTexture(background_texture);
        scaleBackgroundImage();
    }
}

void UIHandler::initializeButtons()
{
    if (loadButtonTexturesFromFile())
    {
        setButtonSprites();
        scaleAllButttons();
        positionButtons();
    }
}

void UIHandler::updateUI()
{
	switch (current_state)
	{
    case UIState::SPLASH_SCREEN:
        updateSplashSceenUI();
        break;
	case UIState::MAIN_MENU:
        updateMainMenuUI();
		break;
	default:
		break;
	}
}

void UIHandler::updateSplashSceenUI()
{
    if(elapsedTime < splash_screen_time) 
    {
        float deltaTime = clock.restart().asSeconds();
        elapsedTime += deltaTime;
        updateLogo(deltaTime);
    }
    else
    {
        logoAnimationComplete();
    }
}

void UIHandler::updateMainMenuUI()
{
    if (pressedMouseButton()) handleButtonInteractions();
}

void UIHandler::render() 
{ 
    switch (current_state)
    {
    case UIState::SPLASH_SCREEN:
        renderSplashScreenUI();
        break;
    case UIState::MAIN_MENU:
        renderMainMenuUI();
        break;
    default:
        break;
    }
}

void UIHandler::renderSplashScreenUI()
{
    game_window->draw(outscal_logo_sprite);
}

void UIHandler::renderMainMenuUI()
{
    game_window->draw(background_sprite);
    game_window->draw(play_button_sprite);
    game_window->draw(instructions_button_sprite);
    game_window->draw(quit_button_sprite);
}

void UIHandler::loadOutscalTexture()
{
    if (!tryLoadingOutscalLogo())
        printf("ERROR :: UIService :: Unable to find Outscal Logo Texture");
}

bool UIHandler::tryLoadingOutscalLogo() { return outscal_logo_texture.loadFromFile("assets/textures/outscal_logo.png"); }

void UIHandler::setPositionToCenter()
{
    sf::Vector2u windowSize = game_window->getSize();
    sf::Vector2u logoSize = outscal_logo_texture.getSize();
    outscal_logo_sprite.setPosition((windowSize.x - logoSize.x) / 2.0f, (windowSize.y - logoSize.y) / 2.0f);
}

void UIHandler::scaleBackgroundImage()
{
    background_sprite.setScale(
        static_cast<float>(game_window->getSize().x) / background_sprite.getTexture()->getSize().x,
        static_cast<float>(game_window->getSize().y) / background_sprite.getTexture()->getSize().y
    );
}

bool UIHandler::loadButtonTexturesFromFile()
{
    return play_button_texture.loadFromFile("assets/textures/play_button.png") &&
        instructions_button_texture.loadFromFile("assets/textures/instructions_button.png") &&
        quit_button_texture.loadFromFile("assets/textures/quit_button.png");
}

void UIHandler::setButtonSprites()
{
    play_button_sprite.setTexture(play_button_texture);
    instructions_button_sprite.setTexture(instructions_button_texture);
    quit_button_sprite.setTexture(quit_button_texture);
}

void UIHandler::scaleAllButttons()
{
    scaleButton(&play_button_sprite);
    scaleButton(&instructions_button_sprite);
    scaleButton(&quit_button_sprite);
}

void UIHandler::scaleButton(sf::Sprite* buttonToScale)
{
    buttonToScale->setScale(
        button_width / buttonToScale->getTexture()->getSize().x,
        button_height / buttonToScale->getTexture()->getSize().y
    );
}

void UIHandler::positionButtons()
{
    float x_position = (static_cast<float>(game_window->getSize().x) / 2) - button_width / 2;

    play_button_sprite.setPosition({ x_position, 500.f });
    instructions_button_sprite.setPosition({ x_position, 700.f });
    quit_button_sprite.setPosition({ x_position, 900.f });
}

void UIHandler::setUIState(UIState new_state)
{
    current_state = new_state;

    switch (current_state)
    {
    case UIState::SPLASH_SCREEN:
        showSplashScreen();
        break;
    case UIState::MAIN_MENU:
        showMainMenuScreen();
        break;
    default:
        break;
    }
}

void UIHandler::showSplashScreen()
{
    // Reset the Clock:
    clock.restart();
    elapsedTime = 0.0f;
}

void UIHandler::showMainMenuScreen()
{
}

void UIHandler::updateLogo(float deltaTime)
{
    if (elapsedTime <= 4.0f)
    {
        showLogoWithFade();
    }
    else
    {
        hideLogoWithFade();
    }
}

// Calculate the alpha value based on elapsed time (e.g., linear interpolation)
void UIHandler::showLogoWithFade()
{
    float alpha = std::min(1.0f, elapsedTime / logo_animation_time); // Gradually becomes visible over 2 seconds
    outscal_logo_sprite.setColor(sf::Color(255, 255, 255, static_cast<sf::Uint8>(alpha * 255)));
}

// Once the logo is fully visible, start fading out after 2 seconds.
void UIHandler::hideLogoWithFade()
{
    float alpha = std::max(0.0f, 1.0f - ((elapsedTime - 4.0f) / logo_animation_time));
    outscal_logo_sprite.setColor(sf::Color(255, 255, 255, static_cast<sf::Uint8>(alpha * 255)));
}

void UIHandler::logoAnimationComplete() { setUIState(UIState::MAIN_MENU); }

bool UIHandler::pressedMouseButton() { return sf::Mouse::isButtonPressed(sf::Mouse::Left); }

void UIHandler::handleButtonInteractions()
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

bool UIHandler::clickedButton(sf::Sprite* button_sprite, sf::Vector2f mouse_position)
{
    return button_sprite->getGlobalBounds().contains(mouse_position);
}