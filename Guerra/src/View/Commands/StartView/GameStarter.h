/*
 * GameStarter.h
 *
 *  Created on: Feb 13, 2022
 *      Author: iban
 */

#ifndef VIEW_COMMANDS_STARTVIEW_GAMESTARTER_H_
#define VIEW_COMMANDS_STARTVIEW_GAMESTARTER_H_
#include "../../../Common/Command.h"

namespace view {
namespace commands {

class Game_starter : public Command
{
public:
	Game_starter();
	virtual ~Game_starter();

	void execute() override;
	std::string get_description() override;
};

} /* namespace commands */
} /* namespace view */

#endif /* VIEW_COMMANDS_STARTVIEW_GAMESTARTER_H_ */
