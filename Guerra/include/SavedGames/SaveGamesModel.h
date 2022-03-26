/*
 * SaveGameModel.h
 *
 *  Created on: Feb 19, 2022
 *      Author: iban
 */

#ifndef SAVEDGAMES_SAVEGAMESMODEL_H_
#define SAVEDGAMES_SAVEGAMESMODEL_H_
#include <string>
#include <vector>

#include <Common/Types.h>
#include <Table/Table.h>

namespace saved_games {

class Save_games_model
{
public:
	Save_games_model();
	virtual ~Save_games_model();
	Save_games_model(const Save_games_model &other) = default;
	Save_games_model(Save_games_model &&other) = default;
	Save_games_model& operator=(const Save_games_model &other) = default;
	Save_games_model& operator=(Save_games_model &&other) = default;

	void save_game(std::string game_name, Table_snapshoot snapshoot);

	std::vector<std::string> get_saved_games_names();

	table::Table load_game(std::string game_name, std::string deck_model);

};

} /* namespace saved_games */

#endif /* SAVEDGAMES_SAVEGAMESMODEL_H_ */
