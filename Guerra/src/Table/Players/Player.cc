/*
 * Player.cc
 *
 *  Created on: Feb 17, 2022
 *      Author: iban
 */

#include <Table/Players/Player.h>

#include <algorithm>
namespace table {

Player::Player(unsigned short id, std::string name) : id_{id }, name_{name }, deck_{}
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

std::size_t Player::get_number_cards() const
{
	return deck_.size();
}

void Player::provide_cards(const Table_deck& table_deck_chunk)
{
	std::for_each(table_deck_chunk.begin(), table_deck_chunk.end(),
			[&](card::Card card){ deck_.push_back(card); });
}

Name_id_deck Player::get_snapshoot() const
{
	Deck_players deck{};
	for(auto& card : deck_)
	{
		Colour_value colour_value{card.get_colour(), card.get_value() };
		deck.push_back(colour_value);
	}

	Name_id_deck snapshoot{name_, id_, deck};
	return snapshoot;
}
card::Card Player::play_card()
{
	auto card_to_play = deck_.front();
	deck_.pop_front();
	return card_to_play;
}

} /* namespace table */
