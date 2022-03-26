/*
 * EraseDeck.h
 *
 *  Created on: Feb 14, 2022
 *      Author: iban
 */

#ifndef VIEW_COMMANDS_DECKVIEW_ERASEDECK_H_
#define VIEW_COMMANDS_DECKVIEW_ERASEDECK_H_
#include <Common/Command.h>
#include <Controllers/DeckDesignController.h>

namespace view {
namespace commands
{

class Erase_deck : public Command
{
public:
	Erase_deck();
	virtual ~Erase_deck();
	Erase_deck(const Erase_deck &other) = default;
	Erase_deck(Erase_deck &&other) = default;
	Erase_deck& operator=(const Erase_deck &other) = default;
	Erase_deck& operator=(Erase_deck &&other) = default;

	void execute() override;
	std::string get_description() override;

private:
	controllers::Deck_design_controller design_controller_;
};

} /* namespace commands */
} /* namespace view */

#endif /* VIEW_COMMANDS_DECKVIEW_ERASEDECK_H_ */
