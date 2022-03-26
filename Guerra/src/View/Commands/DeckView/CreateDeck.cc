/*
 * CreateDeck.cc
 *
 *  Created on: Feb 14, 2022
 *      Author: iban
 */

#include <View/Commands/DeckView/CreateDeck.h>

#include <Common/Types.h>
#include <Common/Paths.h>
#include <View/InterfaceOperations.h>

namespace operations = view::interface_operations;

namespace
{
Possible_colours create_colours()
{
	std::string ask_number_colours{"¿Cuántos palos va a tener esta baraja?" };
	auto number_of_colours = operations::ask_value<short>(ask_number_colours);

	std::string check_question
		{"Introduzca un número de palos superior a 0 (numérico)" };
	operations::check_number(check_question, number_of_colours);

	std::string create_color_question{"Introduzca el nombre del palo" };
	auto colors = operations::ask_multiple_values<std::string>
					(create_color_question, number_of_colours,
							operations::ask_value<std::string>);

	return colors;
}

Possible_values create_values()
{
	std::string ask_number_of_values{"¿Cuántas cartas va a tener cada palo?" };
	auto number_of_values = operations::ask_value<int>(ask_number_of_values);

	std::string check_question
		{"Introduzca un número de cartas superior a 0 (numérico)" };
	operations::check_number(check_question, number_of_values);

	std::string create_values_question{"Introduzca valor numérico y nombre de"
			" la carta" };

	auto introduce_value_name = [](std::string question)
			-> std::pair<std::size_t, std::string>
		{
			auto value_name =
					operations::ask_pair<std::size_t, std::string>(question);
			return value_name;
		};

	auto introduce_check_value_name = [&](std::string question)
			-> std::pair<std::size_t, std::string>
		{
			auto value_name = introduce_value_name(question);

			while ( std::cin.good() == false || value_name.first < 1 )
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Introduzca un valor de carta superior a 0 (numérico)" << std::endl;
				value_name = introduce_value_name(question);
			}

			return value_name;
		};

	auto card_values_and_names =
			operations::ask_multiple_values<Value_name>(create_values_question,
					number_of_values,
					introduce_check_value_name );

	return card_values_and_names;
}

std::string give_deck_name()
{
	std::string ask_deck_name{"Proporcione un nombre a la baraja"};
	return operations::ask_value<std::string>(ask_deck_name);
}

}

namespace view {
namespace commands {

Create_deck::Create_deck() : design_controller_{}
{
	// TODO Auto-generated constructor stub

}

Create_deck::~Create_deck() {
	// TODO Auto-generated destructor stub
}

void Create_deck::execute()
{
	auto deck_name = give_deck_name();
	auto deck_colours = create_colours();
	auto deck_values_names = create_values();

	Deckname_values_colours deck_info{deck_name, deck_values_names, deck_colours };

	design_controller_.create_deck(deck_info);
}

std::string Create_deck::get_description()
{
	return "Crear baraja";
}

} /* namespace commands */
} /* namespace view */
