/*
 * Player.cc
 *
 *  Created on: Feb 17, 2022
 *      Author: iban
 */

#include "Player.h"

#include <algorithm>
namespace table {

Player::Player(unsigned short id, std::string name) : id_{id }, name_{name }
{
	; //do nothing
}

Player::~Player() {
	// TODO Auto-generated destructor stub
}

unsigned short Player::get_id() const
{
	return id_;
}
std::string Player::get_name() const
{
	return name_;
}

void Player::provide_cards(const Table_deck& table_deck_chunk)
{
	std::for_each(table_deck_chunk.begin(), table_deck_chunk.end(),
			[&](card::Card card){ deck_.push_back(card); });
}

card::Card Player::play_card()
{
	auto card_to_play = deck_.front();
	deck_.pop_front();
	return card_to_play;
}

} /* namespace table */
