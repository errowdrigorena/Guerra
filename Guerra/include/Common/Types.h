/*
 * Types.h
 *
 *  Created on: Feb 12, 2022
 *      Author: iban
 */

#ifndef COMMON_TYPES_H_
#define COMMON_TYPES_H_

#include <vector>
#include <utility>
#include <string>

using Possible_colours = std::vector<std::string>;
using Value_name = std::pair<unsigned int, std::string>;
using Possible_values = std::vector<Value_name>;
using Deckname_values_colours =
		std::tuple<std::string, Possible_values, Possible_colours>;
using Colour_value = std::pair<unsigned int, unsigned int>;
using Deck_players = std::vector<Colour_value>;
using Deck_table = std::vector<Colour_value>;
using Name_id_deck = std::tuple<std::string, unsigned short, Deck_players>;
using Table_snapshoot = std::pair<Deck_table, std::vector<Name_id_deck>>;

enum class Manage_deckname_values_colours
{
	DECKNAME = 0, VALUES = 1, COLOURS = 2
};

enum class Manage_playername_id_deck
{
	PLAYERNAME = 0, ID = 1, DECK = 2
};
#endif /* COMMON_TYPES_H_ */
