/*
 * JSONSavedGame.cc
 *
 *  Created on: Feb 20, 2022
 *      Author: iban
 */
#include "JSONSavedGame.h"

namespace json
{

bpt::ptree create_card_array_json(std::vector<Colour_value> cards)
{
	bpt::ptree card_array{};

	for(auto& colour_value : cards)
	{
		bpt::ptree colour_value_json{};
		colour_value_json.put("Color", colour_value.first);
		colour_value_json.put("Valor", colour_value.second);

		card_array.push_back({"", colour_value_json });
	}

	return card_array;
}

bpt::ptree create_players_json(std::vector<Name_id_deck> players_snapshoot)
{
	bpt::ptree players_json{};
	//bpt::ptree saved_game_child{};
	for(auto& player_info : players_snapshoot)
	{
		bpt::ptree player_json{};

		auto name = std::get<static_cast<int>(mpid::PLAYERNAME)>(player_info);
		auto id = std::get<static_cast<int>(mpid::ID)>(player_info);
		auto deck = std::get<static_cast<int>(mpid::DECK)>(player_info);

		auto deck_json = create_card_array_json(deck);

		std::string id_child_tag = "Id";
		std::string  deck_child_tag = "Deck";

		player_json.put(id_child_tag, id);
		player_json.put_child(deck_child_tag, deck_json);

		players_json.push_back({name, player_json});
	}

	return players_json;
}

bpt::ptree create_saved_json(std::string saved_name, Table_snapshoot snapshoot)
{
	bpt::ptree saved_game_json{};

	auto players_json = create_players_json(snapshoot.second);
	auto table_deck_json = create_card_array_json(snapshoot.first);

	std::string players_child_tag = saved_name +".Players";
	std::string table_child_tag = saved_name +".Table";

	saved_game_json.put_child(players_child_tag, players_json);
	saved_game_json.put_child(table_child_tag, table_deck_json);

	return saved_game_json;
}

}


