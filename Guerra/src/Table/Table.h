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
#include "../Common/Types.h"
#include "Players/Player.h"

constexpr std::size_t number_players{2 }; //it is fixed to reduce complexity

using Deck = std::vector<card::Card>;
using Id_colour = std::map<unsigned int, std::string>; //translator
using Value_cardname = std::map<unsigned int, std::string>; //translator

namespace table
{
enum class Round_result{Draw, Winner, Game_over};
enum class Who_can_play{Everyone, None, Someone};

class Table
{
public:
	Table(std::vector<std::string> player_names, std::string deck_name);
	virtual ~Table();
	Table(const Table &other) = default;
	Table(Table &&other) = default;
	Table& operator=(const Table &other) = default;
	Table& operator=(Table &&other) = default;

	void shuffle_deck();

	void deal_cards();

	Round_result perform_round(); //play game

	void perform_draw();

	std::string get_last_round_result() const;

	Table_snapshoot get_game_snapshot() const;

private:
	std::string notate_round(const std::map<std::string, card::Card> &round,
			const std::pair<std::string, card::Card> &winner,
			const Round_result &result);
	void give_regard_to_winner(const std::string& winner);
	bool check_if_someone_wins();
	Who_can_play arrange_someone_cant_play();

	std::array<Player, number_players> players_;
	Deck deck_;
	Id_colour id_colour_;
	Value_cardname value_name_;
	std::string last_round_result_;
	const std::size_t total_card_number_;
};

}
#endif /* TABLE_TABLE_H_ */
