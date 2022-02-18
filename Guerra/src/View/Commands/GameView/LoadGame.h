/*
 * LoadGame.h
 *
 *  Created on: Feb 17, 2022
 *      Author: iban
 */

#ifndef VIEW_COMMANDS_GAMEVIEW_LOADGAME_H_
#define VIEW_COMMANDS_GAMEVIEW_LOADGAME_H_
#include "../../../Common/Command.h"
#include "../../../Controllers/TableController.h"

namespace view {
namespace commands {

class Load_game : public Command
{
public:
	Load_game();
	virtual ~Load_game();
	Load_game(const Load_game &other);
	Load_game(Load_game &&other);
	Load_game& operator=(const Load_game &other);
	Load_game& operator=(Load_game &&other);

	void execute() override;
	std::string get_description() override;
};

} /* namespace commands */
} /* namespace view */

#endif /* VIEW_COMMANDS_GAMEVIEW_LOADGAME_H_ */
