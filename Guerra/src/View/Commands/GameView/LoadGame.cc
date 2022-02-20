/*
 * LoadGame.cc
 *
 *  Created on: Feb 17, 2022
 *      Author: iban
 */

#include "LoadGame.h"
#include "../../LoopManagement.h"
#include "../../../Controllers/TableController.h"
#include "../../View.h"
#include "PlayRound.h"
#include "SaveGame.h"

#include <memory>

namespace view {
namespace commands {

Load_game::Load_game() : saved_games_controller_{}, design_controller_{}
{
	; //do nothing
}

Load_game::~Load_game()
{
	;//do nothing
}

void Load_game::execute()
{
	auto deck_models = design_controller_.get_deck_names();
	auto model = option_management(deck_models, "Elija tipo de baraja \n");

	if( model == "salir" )
	{
		return;
	}

	auto saved_games = saved_games_controller_.get_saved_games_names();
	auto loadable = option_management(saved_games,
			"Elija partida a retomar \n");

	if( loadable != "salir" )
	{
		auto game_status = saved_games_controller_.load_game(loadable, model);
		auto table_controller_shared =
				std::make_shared<controllers::Table_controller>(game_status);

		View game_console{std::make_shared<Play_round>(table_controller_shared),
			std::make_shared<Save_game>(table_controller_shared) };

		option_loop(std::move(game_console) );
	}
}

std::string Load_game::get_description()
{
	return "Cargar partida";
}

} /* namespace commands */
} /* namespace view */
