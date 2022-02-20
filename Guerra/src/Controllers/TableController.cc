/*
 * TableController.cc
 *
 *  Created on: Feb 17, 2022
 *      Author: iban
 */

#include "TableController.h"

namespace controllers {

Table_controller::Table_controller(std::vector<std::string> player_names,
		std::string deck_name) : state_machine_{ table::Table{player_names, deck_name} }
{
	;//do nothing
}

Table_controller::Table_controller(table::Table table) : state_machine_{table }
{
	;//do nothing
}

Table_controller::~Table_controller()
{
	;//do nothing
}

void Table_controller::perform_game_state()
{
	state_machine_.interact_with_table();
}

std::string Table_controller::get_round_info()
{
	return state_machine_.get_round_info();
}

Table_snapshoot Table_controller::get_game_snapshot()
{
	return state_machine_.get_game_snapshot();
}

} /* namespace controllers */
