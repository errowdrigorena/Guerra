/*
 * DeckCreationController.cc
 *
 *  Created on: Feb 12, 2022
 *      Author: iban
 */
#include "DeckDesignController.h"

namespace controllers {


Deck_design_controller::Deck_design_controller() : deck_manager_{}
{
	; //do nothing
}

Deck_design_controller::~Deck_design_controller()
{
	; //do nothing
}

void Deck_design_controller::create_deck(Deckname_values_colours deck_info) const
{
	deck_manager_.save_deck(deck_info);
}

std::vector<std::string> Deck_design_controller::get_deck_names() const
{
	return deck_manager_.get_deck_names();
}

void Deck_design_controller::erase_deck(std::string deck_name) const
{
	deck_manager_.erase_deck(deck_name);
}

} /* namespace controllers */
