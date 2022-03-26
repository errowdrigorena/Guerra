/*
 * Play_round.cc
 *
 *  Created on: Feb 18, 2022
 *      Author: iban
 */

#include <View/Commands/GameView/PlayRound.h>

#include <iostream>

namespace view {
namespace commands {

Play_round::Play_round(const Table_control_shared table_controller) :
				table_controller_{table_controller }
{
	; //do nothing
}

Play_round::~Play_round()
{
	; //do nothing
}

void Play_round::execute()
{
	table_controller_->perform_game_state();
	std::cout << table_controller_->get_round_info() << std::endl;
}

std::string Play_round::get_description()
{
	return "Jugar ronda";
}

} /* namespace commands */
} /* namespace view */
