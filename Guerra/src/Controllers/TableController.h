/*
 * TableController.h
 *
 *  Created on: Feb 17, 2022
 *      Author: iban
 */

#ifndef CONTROLLERS_TABLECONTROLLER_H_
#define CONTROLLERS_TABLECONTROLLER_H_
#include "../Common/Types.h"
#include "../States/GameStatesHandler.h"
#include "../Table/Table.h"

namespace controllers {

class Table_controller
{
public:
	Table_controller(std::vector<std::string> player_names,
			std::string deck_name);
	virtual ~Table_controller();
	Table_controller(const Table_controller &other) = default;
	Table_controller(Table_controller &&other) = default;
	Table_controller& operator=(const Table_controller &other) = default;
	Table_controller& operator=(Table_controller &&other) = default;

	void perform_game_state();

	std::string get_round_info();

	Table_snapshoot get_game_snapshot();
private:
	states::Game_states_handler state_machine_;
};

} /* namespace controllers */

#endif /* CONTROLLERS_TABLECONTROLLER_H_ */
