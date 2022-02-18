/*
 * SaveGame.cc
 *
 *  Created on: Feb 18, 2022
 *      Author: iban
 */

#include "SaveGame.h"

namespace view {
namespace commands {

Save_game::Save_game(const Table_control_shared table_controller) :
		table_controller_{table_controller }
{
	;//do nothing
}

Save_game::~Save_game()
{
	// TODO Auto-generated destructor stub
}

void Save_game::execute()
{
	; //sin implementar
}

std::string Save_game::get_description()
{
	return "Guardar partida";
}

} /* namespace commands */
} /* namespace view */
