/*
 * DeckDesignerStarter.h
 *
 *  Created on: Feb 13, 2022
 *      Author: iban
 */

#ifndef VIEW_COMMANDS_STARTVIEW_DECKDESIGNERSTARTER_H_
#define VIEW_COMMANDS_STARTVIEW_DECKDESIGNERSTARTER_H_
#include <Common/Command.h>

namespace view {
namespace commands {

class Deck_designer_starter : public Command
{
public:
	Deck_designer_starter();
	virtual ~Deck_designer_starter();

	void execute() override;
	std::string get_description() override;

};

} /* namespace commands */
} /* namespace view */

#endif /* VIEW_COMMANDS_STARTVIEW_DECKDESIGNERSTARTER_H_ */
