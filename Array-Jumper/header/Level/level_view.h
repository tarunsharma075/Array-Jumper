#pragma once
#include"../../header/Graphics/GraphicService.h"
#include"../../header/UI/UIElement/ImageView.h"
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


		void createImages();
		void initializeImages();
		void updateImages();
		void drawLevel();
		void deleteImages();

	public:
		LevelView(LevelController* controller);
		~LevelView();
		void Initialize();
		void Update();
		void Render();
	};
}