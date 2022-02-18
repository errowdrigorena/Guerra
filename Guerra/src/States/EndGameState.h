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

class End_game_status : public State_of_game
{
public:
	End_game_status();
	virtual ~End_game_status();
	End_game_status(const End_game_status &other) = default;
	End_game_status(End_game_status &&other) = default;
	End_game_status& operator=(const End_game_status &other) = default;
	End_game_status& operator=(End_game_status &&other) = default;

	void execute(table::Table& table_model) override;
};

} /* namespace states */

#endif /* STATES_ENDGAMESTATE_H_ */
