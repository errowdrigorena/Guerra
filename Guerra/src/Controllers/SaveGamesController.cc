/*
 * SaveGamesController.cc
 *
 *  Created on: Feb 19, 2022
 *      Author: iban
 */

#include "SaveGamesController.h"
#include "../Common/Paths.h"
#include "../JSON/JSONOperations.h"

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

}

void Save_games_controller::save_game(std::string game_name,
		Table_snapshoot snapshoot)
{
	// save_game_model_ must be called
	auto saved_game = json::create_saved_json(game_name, snapshoot);
	json::add_json_to_file(saved_game, common::saves_info_path);

}

} /* namespace controllers */
