/*
 * NewGame.cc
 *
 *  Created on: Feb 17, 2022
 *      Author: iban
 */

#include "NewGame.h"

#include <iostream>
#include <vector>

#include "../../../JSON/JSONOperations.h"
#include "../../../Common/Paths.h"
#include "../../LoopManagement.h"

namespace
{

std::vector<std::string> name_players(unsigned short number_players)
{
	std::vector<std::string> player_names{};

	for(unsigned short i = 0; i < number_players; i++)
	{
		std::string insertable{};
		std::cout << "Introduzca nombre del jugador " << i+1 << std::endl;
		std::cin >> insertable;
		player_names.push_back(insertable);
	}

	return player_names;
}

std::string chose_deck()
{
	std::cout << "Elija modelo de baraja " << i+1 << std::endl;
	auto decks_options = json::get_decks_in_json_file(decks_info_path);
	decks_options.push_back("salir");

	auto selected_deck = option_selector(decks_options);

	return selected_deck;
}

}

namespace view {
namespace commands {

New_game::New_game() : table_controller_{}
{

}

New_game::~New_game()
{
	// TODO Auto-generated destructor stub
}

void New_game::execute()
{
	constexpr unsigned short number_of_players{2 };
	auto player_names = name_players( number_of_players );

	auto chosen_deck = chose_deck();

	controllers::Table_controller movable{player_names, chosen_deck};
	table_controller_ = std::move(movable);
}

std::string New_game::get_description()
{
	return "Iniciar nueva partida";
}

} /* namespace commands */
} /* namespace view */
