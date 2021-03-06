/*
 * EraseDeck.cpp
 *
 *  Created on: Feb 14, 2022
 *      Author: iban
 */

#include <View/Commands/DeckView/EraseDeck.h>
#include <View/LoopManagement.h>

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
	auto eraseable = option_management(decks_options, "Elija baraja para borrar \n");

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
