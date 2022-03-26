/*
 * JSONSavedGame.h
 *
 *  Created on: Feb 20, 2022
 *      Author: iban
 */

#ifndef JSON_JSONSAVEDGAME_H_
#define JSON_JSONSAVEDGAME_H_

#include <Table/Table.h>
#include <JSON/JSONOperations.h>

namespace json
{

bpt::ptree create_saved_json(const std::string& saved_name,
		const Table_snapshoot& snapshoot);

bpt::ptree create_players_json(const std::vector<Name_id_deck>& players_snapshoot);

bpt::ptree create_card_array_json(const std::vector<Colour_value>& cards);

table::Table load_game_from_file(const fs::path& file_path,
		const std::string& loadable_game, const std::string& deck_model);

std::vector<card::Card> get_cards_from_array_json(bpt::ptree json_array);

}

#endif /* JSON_JSONSAVEDGAME_H_ */
