/*
 * SaveGameModel.cc
 *
 *  Created on: Feb 19, 2022
 *      Author: iban
 */

#include "../JSON/JSONSavedGame.h"
#include "../Common/Paths.h"
#include "SaveGamesModel.h"

namespace saved_games
{

Save_games_model::Save_games_model()
{
	common::create_directory(common::saves_info_path.parent_path());
	common::create_file(common::saves_info_path);
}

Save_games_model::~Save_games_model()
{
	; //do nothing
}

void Save_games_model::save_game(std::string game_name,
		Table_snapshoot snapshoot)
{
	auto saved_game = json::create_saved_json(game_name, snapshoot);
	json::add_json_to_file(saved_game, common::saves_info_path);
}

std::vector<std::string> Save_games_model::get_saved_games_names()
{

}

} /* namespace saved_games */
