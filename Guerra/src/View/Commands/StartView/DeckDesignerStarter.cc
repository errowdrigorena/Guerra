/*
 * DeckDesignerStarter.cc
 *
 *  Created on: Feb 13, 2022
 *      Author: iban
 */

#include <View/Commands/StartView/DeckDesignerStarter.h>
#include <View/LoopManagement.h>
#include <View/View.h>
#include <View/Commands/DeckView/CreateDeck.h>
#include <View/Commands/DeckView/EraseDeck.h>

namespace view {
namespace commands {

Deck_designer_starter::Deck_designer_starter()
{
	// TODO Auto-generated constructor stub
}

Deck_designer_starter::~Deck_designer_starter()
{
	// TODO Auto-generated destructor stub
}

void Deck_designer_starter::execute()
{
	View deck_designer_console{std::make_shared<Create_deck>(), std::make_shared<Erase_deck>()};
	option_loop(std::move(deck_designer_console) );
}

std::string Deck_designer_starter::get_description()
{
	return "Crear/eliminar barajas";
}

} /* namespace commands */
} /* namespace view */
