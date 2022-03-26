/*
 * NewGame.h
 *
 *  Created on: Feb 17, 2022
 *      Author: iban
 */

#ifndef VIEW_COMMANDS_GAMEVIEW_NEWGAME_H_
#define VIEW_COMMANDS_GAMEVIEW_NEWGAME_H_
#include <Common/Command.h>
#include <Controllers/TableController.h>

namespace view {
namespace commands {

class New_game : public Command
{
public:
	New_game();
	virtual ~New_game();
	New_game& operator=(New_game &&other);
	New_game& operator=(const New_game &other);
	New_game(New_game &&other);
	New_game(const New_game &other);

	void execute() override;
	std::string get_description() override;
};

} /* namespace commands */
} /* namespace view */

#endif /* VIEW_COMMANDS_GAMEVIEW_NEWGAME_H_ */
