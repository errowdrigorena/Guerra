/*
 * Table.cc
 *
 *  Created on: Feb 11, 2022
 *      Author: iban
 */

#include "Table.h"
#include "../Common/Paths.h"
#include "../JSON/JSONOperations.h"

namespace table
{

Table::Table(std::vector<std::string> player_names, std::string deck_model) :
		players_{Player{1, player_names[0]}, Player{2, player_names[1]} },
		deck_{json::load_card_deck_from_file(decks_info_path, deck_model) },
		id_color_{json::load_colour_dictionary_from_file(decks_info_path, deck_model) },
		value_name_{json::load_values_dictionary_from_file(decks_info_path, deck_model) }
{
	; //do nothing
}

Table::~Table()
{
	// TODO Auto-generated destructor stub
}

}
