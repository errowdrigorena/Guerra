/*
 * TableController.cc
 *
 *  Created on: Feb 17, 2022
 *      Author: iban
 */

#include "TableController.h"

namespace controllers {

Table_controller::Table_controller(std::vector<std::string> player_names,
		std::string deck_name) : table_model_{player_names, deck_name}
{
	// TODO Auto-generated constructor stub
}

Table_controller::~Table_controller() {
	// TODO Auto-generated destructor stub
}

} /* namespace controllers */
