/*
 * SaveGame.cc
 *
 *  Created on: Feb 18, 2022
 *      Author: iban
 */

#include <View/Commands/GameView/SaveGame.h>

#include <iostream>

namespace view {
namespace commands {

Save_game::Save_game(const Table_control_shared table_controller) :
		table_controller_{table_controller }, save_games_controller_{}
{
	;//do nothing
}

Save_game::~Save_game()
{
	// TODO Auto-generated destructor stub
}

void Save_game::execute()
{
	auto snapshoot = table_controller_->get_game_snapshot();
	std::string saved_game_name{};

	std::cout << "Introduzca un nombre para la partida actual" << std::endl;
	std::cin >> saved_game_name;

	save_games_controller_.save_game(saved_game_name, snapshoot);
}

std::string Save_game::get_description()
{
	return "Guardar partida";
}

} /* namespace commands */
} /* namespace view */
