/*
 * SaveGameModel.cc
 *
 *  Created on: Feb 19, 2022
 *      Author: iban
 */

#include "SaveGameModel.h"
#include "../JSON/JSONOperations.h"
#include "../Common/Paths.h"

namespace saved_games
{

Save_game_model::Save_game_model()
{
	common::create_directory(common::saves_info_path.parent_path());
	common::create_file(common::saves_info_path);
}

Save_game_model::~Save_game_model()
{
	; //do nothing
}

} /* namespace saved_games */
