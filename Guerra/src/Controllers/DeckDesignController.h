/*
 * DeckCreationController.h
 *
 *  Created on: Feb 12, 2022
 *      Author: iban
 */

#ifndef CONTROLLERS_DECKDESIGNCONTROLLER_H_
#define CONTROLLERS_DECKDESIGNCONTROLLER_H_

#include "../Common/Types.h"
#include "../Deck/DeckModel.h"
#include <tuple>


namespace controllers {

class Deck_design_controller
{
public:
	Deck_design_controller();
	virtual ~Deck_design_controller();
	Deck_design_controller(const Deck_design_controller &other) = default;
	Deck_design_controller(Deck_design_controller &&other) = default;
	Deck_design_controller& operator=(const Deck_design_controller &other) = default;
	Deck_design_controller& operator=(Deck_design_controller &&other) = default;

	void create_deck(Deckname_values_colours deck_info);
	std::vector<std::string> get_deck_names();
private:
	deck::Deck_model deck_manager_;
};

} /* namespace controllers */

#endif /* CONTROLLERS_DECKDESIGNCONTROLLER_H_ */
