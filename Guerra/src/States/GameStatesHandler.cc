/*
 * GameStatesHandler.cc
 *
 *  Created on: Feb 19, 2022
 *      Author: iban
 */

#include "GameStatesHandler.h"

#include "DealState.h"
#include "DrawState.h"
#include "EndGameState.h"
#include "RoundState.h"

namespace states {

using State = Game_state;
using Trigger = Game_trigger;
Game_states_handler::Game_states_handler(table::Table table_model) :
		transition_rules_{}, actual_state_{std::make_shared<Deal_state>() },
		table_model_{table_model }
{
	auto round_state = std::make_shared<Round_state>();
	auto draw_state = std::make_shared<Draw_state>();
	auto last_state = std::make_shared<End_game_state>();

	transition_rules_[State::Dealing][Trigger::Cards_dealed] = round_state;
	transition_rules_[State::Playing_round][Trigger::Someone_wins_round] = round_state;
	transition_rules_[State::Playing_round][Trigger::Draw_happened] = draw_state;
	transition_rules_[State::Playing_round][Trigger::Game_over] = last_state;
	transition_rules_[State::Performing_draw_round][Trigger::Draw_happened] = round_state;
	transition_rules_[State::Showing_result][Trigger::Game_over] = last_state;
}

Game_states_handler::~Game_states_handler()
{
	; //do nothing
}

void Game_states_handler::interact_with_table()
{
	actual_state_->execute(table_model_);
	actual_state_ = transition_rules_[actual_state_->get_state()][actual_state_->get_trigger()];
}

std::string Game_states_handler::get_round_info()
{
	return table_model_.get_last_round_result();
}

} /* namespace states */
