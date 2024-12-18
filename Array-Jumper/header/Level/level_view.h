#pragma once
#include"../../header/Graphics/GraphicService.h"
#include"../../header/UI/UIElement/ImageView.h"
#include"../../header/Level/level_model.h"

using namespace sf;
using namespace UI;
namespace Level {

	class LevelController;
	class LevelView{
	private:
		RenderWindow* m_gameWindowForLevelView;
		LevelController* m_levelController;
		UIElement::ImageView* m_backgroundImage;
		float m_backgroundAlphaValue = 110.f;
		BoxDimensions box_dimension;
		UIElement::ImageView* m_boxImage;
		UI::UIElement::ImageView* target_overlay_image;
		UI::UIElement::ImageView* letter_one_overlay_image;
		UI::UIElement::ImageView* letter_two_overlay_image;
		UI::UIElement::ImageView* letter_three_overlay_image;
		UI::UIElement::ImageView* obstacle_one_overlay_image;
	    UI::UIElement::ImageView* obstacle_two_overlay_image;
		void createImages();
		void initializeImages();
		void updateImages();
		void drawLevel();
		void deleteImages();
		void CalculateBoxDimensions();
		UI::UIElement::ImageView* GetBoxOverLayImage(BlocKType overlayImage);
		void DrawBox(sf::Vector2f position);
		void DrawboxValue(sf::Vector2f position, BlocKType box_value);
		void CalculateBoxWidthHeight();
		void CalculateBoxSpacing();
		sf::Vector2f CalculateBoxPosition(int index);
	public:
		LevelView(LevelController* controller);
		~LevelView();
		void Initialize();
		void Update();
		void Render();
		BoxDimensions getBoxDimensions();
	};
}