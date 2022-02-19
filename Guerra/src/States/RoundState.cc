/*
 * RoundState.cc
 *
 *  Created on: Feb 18, 2022
 *      Author: iban
 */

#include "RoundState.h"

namespace states {

Round_state::Round_state() : State_of_game{Game_state::Playing_round}
{
	; //do nothing
}

Round_state::~Round_state()
{
	; //do nothing
}

void Round_state::execute(table::Table& table_model)
{
	auto result = table_model.perform_round();
	static std::map<table::Round_result, Game_trigger> diccionary{
		{table::Round_result::Winner, Game_trigger::Someone_wins_round},
		{table::Round_result::Draw, Game_trigger::Draw_happened},
		{table::Round_result::Game_over, Game_trigger::Game_over} };

	set_trigger(diccionary[result]);
}

} /* namespace states */
