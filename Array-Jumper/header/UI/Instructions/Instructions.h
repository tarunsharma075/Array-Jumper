#pragma once
#include <SFML/Graphics.hpp>

class GraphicHandler;

class Instructions
{
private:
	const int number_of_instructions = 4;
	const float top_offset = 250.f;
	const float text_spacing = 100.f;

	const sf::String instruction_string_one = "Move with 'Left' and 'Right' arrow keys";
	const sf::String instruction_string_two = "Hold 'Space' while moving to 'JUMP'";
	const sf::String instruction_string_three = "Your player will 'JUMP' forward or backward by the value of your current cell";
	const sf::String instruction_string_four = "Reach the target cell to 'Win' the game";

	GraphicHandler* graphic_handler;
	sf::String* instructions;

	void initializeInstructions();
	void drawInstructions();
	void onDestroy();

public:
	Instructions();
	~Instructions();

	void initialize(GraphicHandler* graphic_handler_instance);
	void update();
	void render();
};