/*
 * GameStarter.cpp
 *
 *  Created on: Feb 13, 2022
 *      Author: iban
 */

#include <View/Commands/StartView/GameStarter.h>

#include <View/LoopManagement.h>
#include <View/View.h>
#include <View/Commands/GameView/LoadGame.h>
#include <View/Commands/GameView/NewGame.h>

namespace view {
namespace commands {

Game_starter::Game_starter() {
	// TODO Auto-generated constructor stub

}

Game_starter::~Game_starter() {
	// TODO Auto-generated destructor stub
}

void Game_starter::execute()
{
	View game_console{std::make_shared<New_game>(), std::make_shared<Load_game>() };
	option_loop(std::move(game_console) );
}

std::string Game_starter::get_description()
{
	return "Jugar partida";
}

} /* namespace commands */
} /* namespace view */
