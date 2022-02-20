/*
 * JSONDeckManagement.cc
 *
 *  Created on: Feb 20, 2022
 *      Author: iban
 */
#include "JSONDeckManagement.h"

Tag_value from_name_value_to_tag_value(Value_name transformable);
std::map<unsigned int, std::string> load_dictionary_from_file
	(const fs::path file_path, const std::string deck_name,
	 const std::string of_what);

namespace json
{

std::map<unsigned int, std::string> load_colour_dictionary_from_file
	(const fs::path file_path, const std::string deck_name)
{
	auto dictionary = load_dictionary_from_file(file_path, deck_name, "Colours");
	return dictionary;
}

std::map<unsigned int, std::string> load_values_dictionary_from_file
	(const fs::path file_path, const std::string deck_name)
{
	auto dictionary = load_dictionary_from_file(file_path, deck_name, "Values");
	return dictionary;
}


bpt::ptree create_deck_json(Deckname_values_colours deck_info)
{
	auto title_deck = std::get<static_cast<int>(mdvc::DECKNAME)>(deck_info);
	auto colours_deck = std::get<static_cast<int>(mdvc::COLOURS)>(deck_info);
	auto values_names_deck = std::get<static_cast<int>(mdvc::VALUES)>(deck_info);

	std::vector<Tag_value> tag_values_deck{};
	std::transform(values_names_deck.begin(), values_names_deck.end(),
			std::back_inserter(tag_values_deck), from_name_value_to_tag_value);

	auto names_values_json = create_json_flat_level(tag_values_deck);
	auto colour_enum_json = create_json_enumeration(colours_deck);
	bpt::ptree deck_json{};

	std::string colour_child_tag = title_deck + ".Colours";
	std::string  values_child_tag = title_deck + ".Values";

	deck_json.put_child(colour_child_tag, colour_enum_json);
	deck_json.put_child(values_child_tag, names_values_json);

	return deck_json;
}


std::vector<card::Card> load_card_deck_from_file(const fs::path file_path,
		const std::string deck_name)
{
	auto json_file = create_json_from_file(file_path);
	auto json_deck = json_file.get_child(deck_name);

	std::vector<card::Card> card_deck{};
	for (const auto &value : json_deck.get_child("Values"))
	{
		for (const auto &colour : json_deck.get_child("Colours"))
		{
			unsigned int colour_id  = std::stoul( colour.second.data() );
			unsigned int value_id = std::stoul( value.second.data() );

			card::Card insertable{colour_id, value_id};
			card_deck.push_back(insertable);
		}
	}

	return card_deck;
}

}


Tag_value from_name_value_to_tag_value(Value_name transformable)
{

	return{transformable.second, transformable.first};
}

std::map<unsigned int, std::string> load_dictionary_from_file
	(const fs::path file_path, const std::string deck_name,
	 const std::string of_what)
{
	auto json_file = json::create_json_from_file(file_path);
	auto json_deck = json_file.get_child(deck_name);

	std::map<unsigned int, std::string> dictionary;

	for (const auto &colour : json_deck.get_child(of_what) )
	{
		unsigned int key = std::stoul( colour.second.data() );
		dictionary[key] = colour.first.data();
	}

	return dictionary;
}
