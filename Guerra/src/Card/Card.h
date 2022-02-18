/*
 * Card.h
 *
 *  Created on: Feb 11, 2022
 *      Author: iban
 */

#ifndef CARD_CARD_H_
#define CARD_CARD_H_

namespace card
{

class Card {
public:
	Card(): colour_id_{}, value_{} {};
	Card(unsigned int colour, unsigned int value);
	virtual ~Card();
	Card(const Card &other)=default;
	Card(Card &&other)=default;
	Card& operator=(const Card &other)=default;
	Card& operator=(Card &&other)=default;

	friend bool operator > (const Card& lho, const Card& rho);
	friend bool operator < (const Card& lho, const Card& rho);
	friend bool operator == (const Card& lho, const Card& rho);
	friend bool operator != (const Card& lho, const Card& rho);

private:
	unsigned int colour_id_;
	unsigned int value_;
};

}
#endif /* CARD_CARD_H_ */
