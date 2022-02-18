/*
 * DrawState.cc
 *
 *  Created on: Feb 18, 2022
 *      Author: iban
 */

#include "DrawState.h"

namespace states {

Draw_state::Draw_state() : State_of_game{Game_state::Performing_draw_round}
{
	; //do nothing
}

Draw_state::~Draw_state()
{
	; //do nothing
}

void Draw_state::execute(table::Table& table_model)
{
	; //in implementatios
}

} /* namespace states */
