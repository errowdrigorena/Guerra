#include "JSON/JSONOperations.h"
#include "View/Commands/StartView/DeckDesignerStarter.h"
#include "View/Commands/StartView/GameStarter.h"
#include "View/LoopManagement.h"
#include "View/View.h"

using view::commands::Deck_designer_starter;
using view::commands::Game_starter;
using namespace std;

int main(int argc, char **argv) {

	view::View main_view{std::make_shared<Deck_designer_starter>(),
		std::make_shared<Game_starter>()};
	option_loop(std::move(main_view) );

	return 0;
}
