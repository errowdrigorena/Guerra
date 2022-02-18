/*
 * EndGameStatus.cc
 *
 *  Created on: Feb 18, 2022
 *      Author: iban
 */

#include "EndGameState.h"

namespace states {

End_game_status::End_game_status() : State_of_game{Game_state::Showing_result}
{
	; //do nothing
}

End_game_status::~End_game_status()
{
	; //do nothing
}

void End_game_status::execute(table::Table& table_model)
{
	; //in implementatios
}

} /* namespace states */
