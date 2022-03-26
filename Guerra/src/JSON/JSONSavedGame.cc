/*
 * JSONSavedGame.cc
 *
 *  Created on: Feb 20, 2022
 *      Author: iban
 */
#include <JSON/JSONSavedGame.h>

#include <iostream>
namespace json
{

bpt::ptree create_card_array_json(const std::vector<Colour_value>& cards)
{
	bpt::ptree card_array{};

	for(auto& colour_value : cards)
	{
		bpt::ptree colour_value_json{};
		colour_value_json.put("Colour", colour_value.first);
		colour_value_json.put("Value", colour_value.second);

		card_array.push_back({"", colour_value_json });
	}

	return card_array;
}

bpt::ptree create_players_json(const std::vector<Name_id_deck>& players_snapshoot)
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

bpt::ptree create_saved_json(const std::string& saved_name, const Table_snapshoot& snapshoot)
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

std::vector<card::Card> get_cards_from_array_json(bpt::ptree json_array)
{
	std::vector<card::Card> card_chunk{};

	for (const auto& card_json : json_array)
	{
		unsigned int card_data =
				std::stoul( card_json.second.get_child("Colour").data() );
		unsigned int value_data =
				std::stoul( card_json.second.get_child("Value").data() );

		card_chunk.push_back({card_data, value_data});
	}

	return card_chunk;
}

std::array<table::Player, number_players> get_players_from_json(bpt::ptree json_players)
{
	std::array<table::Player, number_players> players{};

	for (const auto& player : json_players)
	{
		std::string name = player.first.data();
		unsigned short id = std::stoul( player.second.get_child("Id").data() );
		std::vector<card::Card> deck =
				get_cards_from_array_json(player.second.get_child("Deck") );

		table::Player insertable{id, name};
		insertable.provide_cards(deck);

		players[id-1] = insertable;
	}

	return players;
}

table::Table load_game_from_file(const fs::path& file_path,
		const std::string& loadable_game, const std::string& deck_model )
{
	auto json_file = create_json_from_file(file_path);
	auto json_loaded_game = json_file.get_child(loadable_game);

	std::string table_tag = loadable_game + ".Table";
	std::string players_tag = loadable_game + ".Players";

	auto table_deck = get_cards_from_array_json(json_file.get_child(table_tag) );
	auto players = get_players_from_json(json_file.get_child(players_tag) );

	table::Table game_snapshoot{players, table_deck, deck_model};
	return game_snapshoot;
}

}


