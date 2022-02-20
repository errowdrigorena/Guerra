/*
 * XMLOperations.cc
 *
 *  Created on: Feb 13, 2022
 *      Author: iban
 */
#include "JSONOperations.h"
#include "../Card/Card.h"

#include <iostream>
#include <fstream>
#include <boost/property_tree/ptree_fwd.hpp>
#include <algorithm>

#include "../Common/Paths.h"
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

bpt::ptree combine_jsons(bpt::ptree main_part, bpt::ptree aditional_part)
{
	try
	{
		for (const auto &node : aditional_part.get_child(""))
		{
			auto tag = node.first.data();
			auto value = node.second;

			main_part.put_child(tag, value);
		}
	}
	catch(const bpt::ptree_error& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return main_part;
}

void add_json_to_file(bpt::ptree addable, const fs::path file_path)
{
	std::stringstream json_string;

	try
	{
		bpt::ptree all_jsons = create_json_from_file(file_path);
		all_jsons = combine_jsons(all_jsons, addable);
		bpt::write_json(json_string, all_jsons);
		std::ofstream file_ofstrem(file_path);
		file_ofstrem << json_string.rdbuf();
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
		common::create_file(file_path);
		std::ofstream file_ofstrem(file_path);
		file_ofstrem << "{}";
		file_ofstrem.close();
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

std::vector<std::string> get_main_nodes_in_json_file(const fs::path file_path)
{
	std::vector<std::string> deck_names{};
	auto json = create_json_from_file(file_path);

	for (const auto &node : json.get_child(""))
	{
		auto insertable = node.first.data();
		deck_names.push_back(insertable);
	}

	return deck_names;
}

bool erase_node_in_json_file(const fs::path file_path,
		const std::string node_name)
{
	auto json = create_json_from_file(file_path);
	bool correct{false };

	try
	{
		json.erase(node_name);
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
