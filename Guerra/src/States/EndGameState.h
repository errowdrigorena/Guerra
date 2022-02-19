/*
 * EndGameStatus.h
 *
 *  Created on: Feb 18, 2022
 *      Author: iban
 */

#ifndef STATES_ENDGAMESTATE_H_
#define STATES_ENDGAMESTATE_H_
#include "StateOfGame.h"

namespace states
{

class End_game_state : public State_of_game
{
public:
	End_game_state();
	virtual ~End_game_state();
	End_game_state(const End_game_state &other) = default;
	End_game_state(End_game_state &&other) = default;
	End_game_state& operator=(const End_game_state &other) = default;
	End_game_state& operator=(End_game_state &&other) = default;

	void execute(table::Table& table_model) override;
};

} /* namespace states */

#endif /* STATES_ENDGAMESTATE_H_ */
