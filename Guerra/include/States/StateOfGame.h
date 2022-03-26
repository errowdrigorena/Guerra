/*
 * StateOfGame.h
 *
 *  Created on: Feb 18, 2022
 *      Author: iban
 */

#ifndef STATES_STATEOFGAME_H_
#define STATES_STATEOFGAME_H_
#include <Table/Table.h>
#include <States/GameState.h>
#include <States/GameTrigger.h>

namespace states {

class State_of_game
{
public:
	State_of_game(Game_state state): state_{state}, trigger_{} {};
	virtual ~State_of_game() = default;
	State_of_game(const State_of_game &other) = default;
	State_of_game(State_of_game &&other) = default;
	State_of_game& operator=(const State_of_game &other) = default;
	State_of_game& operator=(State_of_game &&other) = default;

	Game_state get_state() const {return state_;}
	Game_trigger get_trigger() const {return trigger_;}
	void set_trigger(Game_trigger trigger){trigger_ = trigger;}

	virtual void execute(table::Table& table_model) = 0;

private:
	Game_state state_;
	Game_trigger trigger_;
};

} /* namespace states */

#endif /* STATES_STATEOFGAME_H_ */
