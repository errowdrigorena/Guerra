/*
 * CreateDeck.h
 *
 *  Created on: Feb 14, 2022
 *      Author: iban
 */

#ifndef VIEW_COMMANDS_DECKVIEW_CREATEDECK_H_
#define VIEW_COMMANDS_DECKVIEW_CREATEDECK_H_
#include "../../../Common/Command.h"
#include "../../../Controllers/DeckDesignController.h"

namespace view {
namespace commands {

class Create_deck : public Command
{
public:
	Create_deck();
	virtual ~Create_deck();
	Create_deck(const Create_deck &other)=default;
	Create_deck(Create_deck &&other)=default;
	Create_deck& operator=(const Create_deck &other)=default;
	Create_deck& operator=(Create_deck &&other)=default;

	void execute() override;
	std::string get_description() override;

private:
	controllers::Deck_design_controller design_controller_;
};

} /* namespace commands */
} /* namespace view */

#endif /* VIEW_COMMANDS_DECKVIEW_CREATEDECK_H_ */
