/*
 * SaveGameModel.h
 *
 *  Created on: Feb 19, 2022
 *      Author: iban
 */

#ifndef SAVEDGAMES_SAVEGAMEMODEL_H_
#define SAVEDGAMES_SAVEGAMEMODEL_H_

namespace saved_games {

class Save_game_model
{
public:
	Save_game_model();
	virtual ~Save_game_model();
	Save_game_model(const Save_game_model &other) = default;
	Save_game_model(Save_game_model &&other) = default;
	Save_game_model& operator=(const Save_game_model &other) = default;
	Save_game_model& operator=(Save_game_model &&other) = default;
};

} /* namespace saved_games */

#endif /* SAVEDGAMES_SAVEGAMEMODEL_H_ */
