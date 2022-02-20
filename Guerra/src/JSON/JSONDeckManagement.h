/*
 * JSONDeckManagement.h
 *
 *  Created on: Feb 20, 2022
 *      Author: iban
 */

#ifndef JSON_JSONDECKMANAGEMENT_H_
#define JSON_JSONDECKMANAGEMENT_H_

#include "../Card/Card.h"
#include "JSONOperations.h"

namespace json
{
bpt::ptree create_deck_json(Deckname_values_colours deck_info);

std::vector<card::Card> load_card_deck_from_file(const fs::path file_path,
		const std::string deck_name);

std::map<unsigned int, std::string> load_colour_dictionary_from_file
	(const fs::path file_path, const std::string deck_name);

std::map<unsigned int, std::string> load_values_dictionary_from_file
	(const fs::path file_path, const std::string deck_name);
}

#endif /* JSON_JSONDECKMANAGEMENT_H_ */
