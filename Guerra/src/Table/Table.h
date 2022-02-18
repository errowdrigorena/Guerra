/*
 * Table.h
 *
 *  Created on: Feb 11, 2022
 *      Author: iban
 */

#ifndef TABLE_TABLE_H_
#define TABLE_TABLE_H_

#include <array>
#include <deque>
#include <map>
#include <vector>

#include "../Card/Card.h"
#include "Players/Player.h"

constexpr std::size_t number_players{2 }; //it is fixed to reduce complexity

using Deck = std::vector<card::Card>;
using Id_colour = std::map<unsigned int, std::string>; //translator
using Value_cardname = std::map<unsigned int, std::string>; //translator

namespace table
{

class Table
{
public:
	Table() = default;
	Table(std::vector<std::string> player_names, std::string deck_name);
	virtual ~Table();
	Table(const Table &other) = default;
	Table(Table &&other) = default;
	Table& operator=(const Table &other) = default;
	Table& operator=(Table &&other) = default;

private:
	std::array<Player, number_players> players_;
	Deck deck_;
	Id_colour id_color_;
	Value_cardname value_name_;
};

}
#endif /* TABLE_TABLE_H_ */
