/*
 * Player.h
 *
 *  Created on: Feb 17, 2022
 *      Author: iban
 */

#ifndef TABLE_PLAYERS_PLAYER_H_
#define TABLE_PLAYERS_PLAYER_H_
#include <string>

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

private:
	unsigned short id_ = 0;
	std::string name_;
	//su mazo
};

} /* namespace table */

#endif /* TABLE_PLAYERS_PLAYER_H_ */
