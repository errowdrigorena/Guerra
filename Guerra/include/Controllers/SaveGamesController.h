/*
 * SaveGamesController.h
 *
 *  Created on: Feb 19, 2022
 *      Author: iban
 */

#ifndef CONTROLLERS_SAVEGAMESCONTROLLER_H_
#define CONTROLLERS_SAVEGAMESCONTROLLER_H_
#include <Common/Types.h>
#include <SavedGames/SaveGamesModel.h>

namespace controllers {

class Save_games_controller
{
public:
	Save_games_controller();
	virtual ~Save_games_controller();
	Save_games_controller(const Save_games_controller &other) = default;
	Save_games_controller(Save_games_controller &&other) = default;
	Save_games_controller& operator=(const Save_games_controller &other) = default;
	Save_games_controller& operator=(Save_games_controller &&other) = default;

	std::vector<std::string> get_saved_games_names();

	void save_game(std::string game_name, Table_snapshoot snapshoot );

	table::Table load_game(std::string game_name, std::string deck_model);
private:
	saved_games::Save_games_model save_game_model_;
};

} /* namespace controllers */

#endif /* CONTROLLERS_SAVEGAMESCONTROLLER_H_ */
