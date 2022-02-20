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

#include "../Common/Types.h"

namespace fs = std::filesystem;
namespace bpt = boost::property_tree;

using Tag_value = std::pair<std::string, int>;
using mdvc = Manage_deckname_values_colours;
using mpid = Manage_playername_id_deck;

namespace json
{

std::stringstream read_file(const fs::path file_path);

void add_json_to_file(bpt::ptree addable, const fs::path file_path);

//if a the file already exist it will be replaced
void create_file_from_json(bpt::ptree addable, const fs::path file_path);

bpt::ptree create_json_from_file(const fs::path file_path);

bpt::ptree create_json_enumeration(const std::vector<std::string> tags );

bpt::ptree create_json_flat_level(const std::vector<Tag_value> tags_values );

bpt::ptree create_saved_json(std::string saved_name, Table_snapshoot snapshoot);

bpt::ptree create_players_json(std::vector<Name_id_deck> players_snapshoot);

std::vector<std::string> get_main_nodes_in_json_file(const fs::path file_path);

bpt::ptree combine_jsons(bpt::ptree main_part, bpt::ptree aditional_part);

//returns true if successful
bool erase_node_in_json_file(const fs::path file_path,
		const std::string node_name);

}

#endif /* JSON_JSONOPERATIONS_H_ */
