/*
 * SaveGamesController.cc
 *
 *  Created on: Feb 19, 2022
 *      Author: iban
 */

#include "SaveGamesController.h"
#include "../Common/Paths.h"

namespace controllers {

Save_games_controller::Save_games_controller() : save_game_model_{}
{
	; //do nothing
}

Save_games_controller::~Save_games_controller()
{
	; //do nothing
}

std::vector<std::string> Save_games_controller::get_saved_games_names()
{
	return save_game_model_.get_saved_games_names();
}

void Save_games_controller::save_game(std::string game_name,
		Table_snapshoot snapshoot)
{
	save_game_model_.save_game(game_name, snapshoot);
}

table::Table Save_games_controller::load_game(std::string game_name,
		std::string deck_model)
{
	return save_game_model_.load_game(game_name, deck_model);
}

} /* namespace controllers */
