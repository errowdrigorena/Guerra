/*
 * EraseDeck.cpp
 *
 *  Created on: Feb 14, 2022
 *      Author: iban
 */

#include "EraseDeck.h"
#include "../../LoopManagement.h"

namespace view {
namespace commands {

Erase_deck::Erase_deck() : design_controller_{}
{
	; //do nothing
}

Erase_deck::~Erase_deck()
{
	; //do nothing
}

void Erase_deck::execute()
{
	auto decks_options = design_controller_.get_deck_names();
	decks_options.push_back("salir");

	auto eraseable = option_selector(decks_options);
	if( eraseable != "salir" )
	{
		design_controller_.erase_deck(eraseable);
	}
}

std::string Erase_deck::get_description()
{
	return "Eliminar baraja";
}

} /* namespace commands */
} /* namespace view */
