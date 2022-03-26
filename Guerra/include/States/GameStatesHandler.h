/*
 * GameStatesHandler.h
 *
 *  Created on: Feb 19, 2022
 *      Author: iban
 */

#ifndef STATES_GAMESTATESHANDLER_H_
#define STATES_GAMESTATESHANDLER_H_
#include <memory>

#include <Table/Table.h>
#include <States/StateOfGame.h>

using Status_ptr = std::shared_ptr<states::State_of_game>;

namespace states {

using Transition_map = std::map<Game_state, std::map<Game_trigger, Status_ptr>>;

class Game_states_handler {
public:
	Game_states_handler(table::Table table_model);
	virtual ~Game_states_handler();
	Game_states_handler(const Game_states_handler &other) = default;
	Game_states_handler(Game_states_handler &&other) = default;
	Game_states_handler& operator=(const Game_states_handler &other) = default;
	Game_states_handler& operator=(Game_states_handler &&other) = default;

	void interact_with_table();

	std::string get_round_info() const;

	Table_snapshoot get_game_snapshot() const;

private:
	Transition_map transition_rules_;
	Status_ptr actual_state_;
	table::Table table_model_;
};

} /* namespace states */

#endif /* STATES_GAMESTATESHANDLER_H_ */
