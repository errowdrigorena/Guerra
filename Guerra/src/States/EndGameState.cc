/*
 * EndGameStatus.cc
 *
 *  Created on: Feb 18, 2022
 *      Author: iban
 */

#include <States/EndGameState.h>

namespace states {

End_game_state::End_game_state() : State_of_game{Game_state::Showing_result}
{
	; //do nothing
}

End_game_state::~End_game_state()
{
	; //do nothing
}

void End_game_state::execute(table::Table& table_model)
{
	set_trigger(Game_trigger::Game_over); //this state doesn't make nothing
}

} /* namespace states */
