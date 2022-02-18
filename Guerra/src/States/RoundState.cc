/*
 * RoundState.cc
 *
 *  Created on: Feb 18, 2022
 *      Author: iban
 */

#include "RoundState.h"

namespace states {

Round_state::Round_state() : State_of_game{Game_state::Dealing}
{
	; //do nothing
}

Round_state::~Round_state()
{
	; //do nothing
}

void Round_state::execute(table::Table& table_model)
{
	; //in implementation
}

} /* namespace states */
