/*
 * DeckModel.h
 *
 *  Created on: Feb 13, 2022
 *      Author: iban
 */

#ifndef DECK_DECKMODEL_H_
#define DECK_DECKMODEL_H_

#include "../Common/Types.h"

namespace deck {

class Deck_model {
public:
	Deck_model();
	virtual ~Deck_model();
	Deck_model(const Deck_model &other) = default;
	Deck_model(Deck_model &&other) = default;
	Deck_model& operator=(const Deck_model &other) = default;
	Deck_model& operator=(Deck_model &&other) = default;

	void save_deck(Deckname_values_colours deck_info) const;
	std::vector<std::string>  get_deck_names() const;
	void erase_deck(std::string deck_name) const;
};

} /* namespace deck */

#endif /* DECK_DECKMODEL_H_ */
