/*
 * DeckModel.cc
 *
 *  Created on: Feb 13, 2022
 *      Author: iban
 */

#include "DeckModel.h"
#include "../JSON/JSONOperations.h"

void create_decks_directory();
void create_decks_file();

namespace deck {

Deck_model::Deck_model()
{
	create_decks_directory();
	create_decks_file();
}

Deck_model::~Deck_model()
{
	// TODO Auto-generated destructor stub
}

void save_deck(Deckname_values_colours deck_info)
{
	auto path_navigator = fs::current_path()/"Decks"/"Decks_info.info";
	auto deck = json::create_deck_json(deck_info);


}

} /* namespace deck */

void create_decks_file()
{
	auto path_navigator = fs::current_path()/"Decks"/"Decks_info.info";
	if(fs::exists(path_navigator) == false)
	{
		std::ofstream file_ofstrem(path_navigator);
		file_ofstrem.close();
	}
}

void create_decks_directory()
{
	auto path_navigator = fs::current_path()/"Decks";
	if(fs::is_directory(path_navigator) == false)
	{
		fs::create_directory(path_navigator);
	}
}
