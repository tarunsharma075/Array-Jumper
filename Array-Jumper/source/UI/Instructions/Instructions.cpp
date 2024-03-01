#include "../../header/UI/Instructions/Instructions.h"
#include "../../header/Graphics/GraphicService.h"

Instructions::Instructions()
{
    graphic_handler = nullptr;
    instructions = nullptr;
}

Instructions::~Instructions()
{
    onDestroy();
}

void Instructions::initialize(GraphicHandler* graphic_handler_instance)
{
    graphic_handler = graphic_handler_instance;
    initializeInstructions();
}

void Instructions::update()
{
}

void Instructions::render()
{
    drawInstructions();
}

void Instructions::initializeInstructions()
{
    instructions = new sf::String[number_of_instructions]();

    instructions[0] = instruction_string_one;
    instructions[1] = instruction_string_two;
    instructions[2] = instruction_string_three;
    instructions[3] = instruction_string_four;
}

void Instructions::drawInstructions()
{
    for (int i = 0; i < number_of_instructions; i++)
    {
        graphic_handler->drawText(instructions[i], top_offset + (text_spacing * i));
    }
}

void Instructions::onDestroy()
{
    delete[] instructions;
}
