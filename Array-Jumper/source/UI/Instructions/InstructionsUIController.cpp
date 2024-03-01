#include "../../header/UI/Instructions/InstructionsUIController.h"
#include "../../header/Global/ServiceLocator.h"



namespace UI
{
    namespace Instrcutions
    {
        using namespace Global;

        InstrcutionsUIController::InstrcutionsUIController()
        {
            instructions = nullptr;
        }

        InstrcutionsUIController::~InstrcutionsUIController()
        {
            onDestroy();
        }

        void InstrcutionsUIController::initialize()
        {
            initializeInstructions();
        }

        void InstrcutionsUIController::update()
        {
        }

        void InstrcutionsUIController::render()
        {
            drawInstructions();
        }

        void InstrcutionsUIController::initializeInstructions()
        {
            instructions = new sf::String[number_of_instructions]();

            instructions[0] = instruction_string_one;
            instructions[1] = instruction_string_two;
            instructions[2] = instruction_string_three;
            instructions[3] = instruction_string_four;
        }

        void InstrcutionsUIController::drawInstructions()
        {
            for (int i = 0; i < number_of_instructions; i++)
            {
                ServiceLocator::getInstance()->getGraphicService()->drawText(instructions[i], top_offset + (text_spacing * i));
            }
        }

        void InstrcutionsUIController::onDestroy()
        {
            delete[] instructions;
        }
    }
}