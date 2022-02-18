/*
 * XMLOperations.h
 *
 *  Created on: Feb 13, 2022
 *      Author: iban
 */

#ifndef JSON_JSONOPERATIONS_H_
#define JSON_JSONOPERATIONS_H_

#include <filesystem>
#include <vector>
#include <string>
#include <boost/property_tree/json_parser.hpp>
#include <map>

#include "../Card/Card.h"
#include "../Common/Types.h"

namespace fs = std::filesystem;
namespace bpt = boost::property_tree;

using Tag_value = std::pair<std::string, int>;

namespace json
{

std::stringstream read_file(const fs::path file_path);

void add_json_to_file(bpt::ptree addable, const fs::path file_path);

//if a the file already exist it will be replaced
void create_file_from_json(bpt::ptree addable, const fs::path file_path);

bpt::ptree create_json_from_file(const fs::path file_path);

bpt::ptree create_json_enumeration(const std::vector<std::string> tags );

bpt::ptree create_json_flat_level(const std::vector<Tag_value> tags_values );

bpt::ptree create_deck_json(Deckname_values_colours deck_info);

std::vector<std::string> get_decks_in_json_file(const fs::path file_path);

//returns true if successful
bool erase_deck_in_json_file(const fs::path file_path,
		const std::string deck_name);

std::vector<card::Card> load_card_deck_from_file(const fs::path file_path,
		const std::string deck_name);

std::map<unsigned int, std::string> load_colour_dictionary_from_file
	(const fs::path file_path, const std::string deck_name);

std::map<unsigned int, std::string> load_values_dictionary_from_file
	(const fs::path file_path, const std::string deck_name);
}

#endif /* JSON_JSONOPERATIONS_H_ */
