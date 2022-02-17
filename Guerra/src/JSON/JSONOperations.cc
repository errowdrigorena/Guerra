/*
 * XMLOperations.cc
 *
 *  Created on: Feb 13, 2022
 *      Author: iban
 */
#include "JSONOperations.h"

#include <iostream>
#include <fstream>
#include <boost/property_tree/ptree_fwd.hpp>
#include <algorithm>

using mdvc = Manage_deckname_values_colours;
Tag_value from_name_value_to_tag_value(Value_name transformable);

namespace json
{

std::stringstream read_file(const fs::path file_path)
{
	std::ifstream file_ifstream(file_path);
	std::stringstream file_readed{};

	if( file_ifstream.is_open() )
	{
		std::string line { };

		while (getline(file_ifstream, line))
		{
			file_readed << line;
		}
		file_ifstream.close();
	}

	return file_readed;
}

void add_json_to_file(bpt::ptree addable, const fs::path file_path)
{
	std::stringstream jsonString{};

	try
	{
		bpt::write_json(jsonString, addable);
		std::ofstream file_ofstrem(file_path);
		file_ofstrem << jsonString.rdbuf();
		file_ofstrem.close();
	}
	catch(const bpt::ptree_error& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void create_file_from_json(bpt::ptree addable, const fs::path file_path)
{
	if( fs::exists(file_path) )
	{
		fs::remove(file_path);
	}

	add_json_to_file(addable, file_path);
}

bpt::ptree create_json_from_file(const fs::path file_path)
{
	auto is = read_file(file_path);
	bpt::ptree json_from_file{};

	try
	{
		read_json(is, json_from_file);
	}
	catch(const bpt::ptree_error& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return json_from_file;
}

bpt::ptree create_json_enumeration(const std::vector<std::string> tags )
{
	bpt::ptree json_enumeration{};

	for(std::size_t i = 0 ; i < tags.size(); i++)
	{
		json_enumeration.put(tags[i], (i) );
	}

	return json_enumeration;
}

bpt::ptree create_json_flat_level(const std::vector<Tag_value> tags_values )
{
	bpt::ptree json_tag_values{};

	auto insert_on_ptree = [&](const Tag_value& insertable)
			{json_tag_values.put(insertable.first, insertable.second);};

	std::for_each(tags_values.begin(), tags_values.end(), insert_on_ptree);

	return json_tag_values;
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
	std::string  values_child_tag = title_deck + ".Colours";

	deck_json.put_child(colour_child_tag, colour_enum_json);
	deck_json.put_child(values_child_tag, names_values_json);

	return deck_json;
}

std::vector<std::string> get_decks_in_json_file(const fs::path file_path)
{
	std::vector<std::string> deck_names{};
	auto json = create_json_from_file(file_path);

	for (const auto &book : json.get_child(""))
	{
		auto insertable = book.first.data();
		deck_names.push_back(insertable);
	}

	return deck_names;
}

bool erase_deck_in_json_file(const fs::path file_path,
		const std::string deck_name)
{
	auto json = create_json_from_file(file_path);
	bool correct{false };

	try
	{
		json.erase(deck_name);
		correct = true;
		create_file_from_json(json, file_path);
	}
	catch(const bpt::ptree_error& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return correct;
}

} //namespace json ends

Tag_value from_name_value_to_tag_value(Value_name transformable)
{

	return{transformable.second, transformable.first};
}
