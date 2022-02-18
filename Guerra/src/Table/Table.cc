/*
 * Table.cc
 *
 *  Created on: Feb 11, 2022
 *      Author: iban
 */

#include "Table.h"
#include "../Common/Paths.h"
#include "../JSON/JSONOperations.h"

#include <random>
#include <chrono>
#include <algorithm>

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
	; //do nothing
}

void Table::shuffle_deck()
{
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	shuffle (deck_.begin(), deck_.end(), std::default_random_engine(seed));
}

void Table::deal_cards()
{
	auto player_number = players_.size();
	auto card_number = deck_.size();

	auto extra_card_number = card_number % player_number;
	for (auto& player : players_)
	{
		auto cards_in_players_deck = ( card_number / player_number );
		auto start_it = deck_.begin() +(player.get_id() * cards_in_players_deck);

		Deck player_deck{start_it, (start_it + cards_in_players_deck) };

		if( player.get_id() <= extra_card_number )
		{
			auto card_position = (cards_in_players_deck * player_number)
					+ player.get_id();
			player_deck.push_back( deck_.at(card_position) );
		}

		player.provide_cards(player_deck);
	}
}

std::string Table::get_last_round_result() const
{
	return last_round_result_;
}
}
