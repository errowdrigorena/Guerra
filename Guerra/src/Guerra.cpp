#include "JSON/JSONOperations.h"
#include "View/Commands/StartView/DeckDesignerStarter.h"
#include "View/Commands/StartView/GameStarter.h"
#include "View/LoopManagement.h"
#include "View/View.h"

using view::commands::Deck_designer_starter;
using view::commands::Game_starter;
using namespace std;

int main(int argc, char **argv) {

	/*std::string q{"introduce número " };

	auto b = view::interface_operations::ask_value<short>(q);
	auto a = view::interface_operations::ask_number(q);

	std::function<short(std::string)> ask_for_shorts{
			view::interface_operations::ask_value<short> };
	auto z = view::interface_operations::ask_multiple_values<short>(q, 5,
			view::interface_operations::ask_value<short> );*/
	//auto b = ask_value2<short>(q);

	//view::deck_design::create_design();
	auto path_navigator = fs::current_path()/"Decks"/"Decks_info.json";
	auto options = json::get_decks_in_json_file(path_navigator);
	std::string deck_name{"New Deck"};
	json::load_card_deck_from_file(path_navigator, deck_name);

	auto dic = json::load_colour_dictionary_from_file(path_navigator, deck_name);

	for( auto colour : dic)
	{
		cout << colour.second << "-->" << colour.first << endl;
	}

	auto vals = json::load_values_dictionary_from_file(path_navigator, deck_name);

	for( auto val : vals)
	{
		cout << val.second << "-->" << val.first << endl;
	}
	view::View main_view{std::make_shared<Deck_designer_starter>(),
		std::make_shared<Game_starter>()};
	//view::Start_view main_view{};
	option_loop(std::move(main_view) );

	return 0;
}
