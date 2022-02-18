/*
 * Play_round.h
 *
 *  Created on: Feb 18, 2022
 *      Author: iban
 */

#ifndef VIEW_COMMANDS_GAMEVIEW_PLAYROUND_H_
#define VIEW_COMMANDS_GAMEVIEW_PLAYROUND_H_
#include <memory>

#include "../../../Common/Command.h"
#include "../../../Controllers/TableController.h"

using Table_control_shared = std::shared_ptr<controllers::Table_controller>;

namespace view {
namespace commands {

class Play_round : public Command
{
public:
	Play_round() = default;
	Play_round(const Table_control_shared table_controller);
	virtual ~Play_round();
	Play_round(const Play_round &other) = default;
	Play_round(Play_round &&other) = default;
	Play_round& operator=(const Play_round &other) = default;
	Play_round& operator=(Play_round &&other) = default;

	void execute() override;
	std::string get_description() override;
private:
	Table_control_shared table_controller_;
};

} /* namespace commands */
} /* namespace view */

#endif /* VIEW_COMMANDS_GAMEVIEW_PLAYROUND_H_ */
