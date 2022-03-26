/*
 * DeckModel.cc
 *
 *  Created on: Feb 13, 2022
 *      Author: iban
 */

#include <Deck/DeckModel.h>
#include <JSON/JSONOperations.h>
#include <JSON/JSONDeckManagement.h>
#include <Common/Paths.h>

namespace deck {

Deck_model::Deck_model()
{
	common::create_directory(common::decks_info_path.parent_path());
	common::create_file(common::decks_info_path);
}

Deck_model::~Deck_model()
{
	// TODO Auto-generated destructor stub
}

void Deck_model::save_deck(Deckname_values_colours deck_info) const
{
	auto deck_insertable = json::create_deck_json(deck_info);
	json::add_json_to_file(deck_insertable, common::decks_info_path);
}

std::vector<std::string>  Deck_model::get_deck_names() const
{
	auto deck_names = json::get_main_nodes_in_json_file(common::decks_info_path);
	return deck_names;
}

void Deck_model::erase_deck(std::string deck_name) const
{
	json::erase_node_in_json_file(common::decks_info_path, deck_name);
}

} /* namespace deck */
