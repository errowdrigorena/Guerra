/*
 * Player.h
 *
 *  Created on: Feb 17, 2022
 *      Author: iban
 */

#ifndef TABLE_PLAYERS_PLAYER_H_
#define TABLE_PLAYERS_PLAYER_H_
#include <deque>
#include <string>
#include <vector>

#include "../../Card/Card.h"

using Table_deck = std::vector<card::Card>;
using Player_deck = std::deque<card::Card>;

namespace table {

class Player {
public:
	Player() = default;
	Player(unsigned short id, std::string name);
	virtual ~Player();
	Player(const Player &other) = default;
	Player(Player &&other) = default;
	Player& operator=(const Player &other) = default;
	Player& operator=(Player &&other) = default;

	unsigned short get_id() const;
	std::string get_name() const;
	std::size_t get_number_cards() const;

	void provide_cards(const Table_deck& table_deck_chunk);

	card::Card play_card();
private:
	unsigned short id_ = 0;
	std::string name_;
	Player_deck deck_;
};

} /* namespace table */

#endif /* TABLE_PLAYERS_PLAYER_H_ */
