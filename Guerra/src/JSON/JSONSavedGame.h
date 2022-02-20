/*
 * JSONSavedGame.h
 *
 *  Created on: Feb 20, 2022
 *      Author: iban
 */

#ifndef JSON_JSONSAVEDGAME_H_
#define JSON_JSONSAVEDGAME_H_

#include "../Table/Table.h"
#include "JSONOperations.h"

namespace json
{

bpt::ptree create_saved_json(std::string saved_name, Table_snapshoot snapshoot);

bpt::ptree create_players_json(std::vector<Name_id_deck> players_snapshoot);

bpt::ptree create_card_array_json(std::vector<Colour_value> cards);

}

#endif /* JSON_JSONSAVEDGAME_H_ */
