/*
 * EraseDeck.cpp
 *
 *  Created on: Feb 14, 2022
 *      Author: iban
 */

#include "EraseDeck.h"
#include "../../../JSON/JSONOperations.h"
#include "../../../Common/Paths.h"
#include "../../LoopManagement.h"

namespace view {
namespace commands {

Erase_deck::Erase_deck() {
	// TODO Auto-generated constructor stub

}

Erase_deck::~Erase_deck() {
	// TODO Auto-generated destructor stub
}

void Erase_deck::execute()
{
	auto decks_options = json::get_decks_in_json_file(decks_info_path);
	decks_options.push_back("salir");

	auto eraseable = option_selector(decks_options);
	if( eraseable != "salir" )
	{
		json::erase_deck_in_json_file(decks_info_path, eraseable);
	}
}

std::string Erase_deck::get_description()
{
	return "Eliminar baraja";
}

} /* namespace commands */
} /* namespace view */
