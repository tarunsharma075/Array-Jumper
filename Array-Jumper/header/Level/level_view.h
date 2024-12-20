#pragma once
#include"../../header/Graphics/GraphicService.h"
#include"../../header/UI/UIElement/ImageView.h"
#include"../../header/Level/level_model.h"
#include"../../header/Level/BlockType.h"
namespace Level
{
	class LevelController;
	class LevelView
	{
	public:
		LevelView(LevelController* controller);
		~LevelView();

		void initilaize();
		void update();
		void render();

		void calculateBoxWidthHeightDimension();
		void calculateBoxSpacing();
		void calcuateBoxDimension();
		sf::Vector2f calculateBoxPosition(int index);
		UI::UIElement::ImageView* getBoxImage(BlocKType type);

		void drawBox(sf::Vector2f position);
		void drawBoxValue(sf::Vector2f position, BlocKType type);

		BoxDimensions getBoxDimension();



	private:
		LevelController* level_controller;
		UI::UIElement::ImageView* background_image;
		UI::UIElement::ImageView* box_image;
		sf::RenderWindow* game_window;

		const float background_alpha = 110.f;

		BoxDimensions box_dimension;

		UI::UIElement::ImageView* target_overlay_image;
		UI::UIElement::ImageView* letter_one_overlay_image;
		UI::UIElement::ImageView* letter_two_overlay_image;
		UI::UIElement::ImageView* letter_three_overlay_image;
		UI::UIElement::ImageView* obstacle_one_overlay_image;
		UI::UIElement::ImageView* obstacle_two_overlay_image;

		void  createImage();
		void initilizeImage();
		void updateImage();
		void drawImage();
		void deleteImage();
	};

}

