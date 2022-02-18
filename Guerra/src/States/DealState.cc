/*
 * DealState.cc
 *
 *  Created on: Feb 18, 2022
 *      Author: iban
 */

#include "DealState.h"

namespace states {

Deal_state::Deal_state() : State_of_game{Game_state::Dealing}
{
	;//do nothing
}

Deal_state::~Deal_state()
{
	;//do nothing
}

void Deal_state::execute(table::Table& table_model)
{
	table_model.shuffle_deck();
	table_model.deal_cards();
	set_trigger(Game_trigger::Cards_dealed);
}

} /* namespace states */
