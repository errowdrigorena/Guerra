/*
 * SaveGame.h
 *
 *  Created on: Feb 18, 2022
 *      Author: iban
 */

#ifndef VIEW_COMMANDS_GAMEVIEW_SAVEGAME_H_
#define VIEW_COMMANDS_GAMEVIEW_SAVEGAME_H_
#include <memory>

#include <Common/Command.h>
#include <Controllers/TableController.h>
#include <Controllers/SaveGamesController.h>

using Table_control_shared = std::shared_ptr<controllers::Table_controller>;

namespace view {
namespace commands {

class Save_game : public Command
{
public:
	Save_game(const Table_control_shared table_controller);
	virtual ~Save_game();
	Save_game(const Save_game &other) = default;
	Save_game(Save_game &&other) = default;
	Save_game& operator=(const Save_game &other) = default;
	Save_game& operator=(Save_game &&other) = default;

	void execute() override;
	std::string get_description() override;
private:
	Table_control_shared table_controller_;
	controllers::Save_games_controller save_games_controller_;
};

} /* namespace commands */
} /* namespace view */

#endif /* VIEW_COMMANDS_GAMEVIEW_SAVEGAME_H_ */
