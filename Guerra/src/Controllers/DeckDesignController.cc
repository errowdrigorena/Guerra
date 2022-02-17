/*
 * DeckCreationController.cc
 *
 *  Created on: Feb 12, 2022
 *      Author: iban
 */
#include "../JSON/JSONOperations.h"
#include "../Common/Paths.h"
#include "DeckDesignController.h"

namespace controllers {


Deck_design_controller::Deck_design_controller() : deck_manager_{}
{
	auto path_navigator = decks_info_path;
}

Deck_design_controller::~Deck_design_controller() {
	// TODO Auto-generated destructor stub
}

void Deck_design_controller::create_deck(Deckname_values_colours deck_info)
{
	auto deck_insertable = json::create_deck_json(deck_info);
	json::add_json_to_file(deck_insertable, decks_info_path);
}

std::vector<std::string> Deck_design_controller::get_deck_names()
{
	auto deck_names = json::get_decks_in_json_file(decks_info_path);
	return deck_names;
}

} /* namespace controllers */
