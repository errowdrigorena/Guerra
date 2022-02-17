/*
 * Card.h
 *
 *  Created on: Feb 11, 2022
 *      Author: iban
 */

#ifndef CARD_CARD_H_
#define CARD_CARD_H_
#include <map>
#include <string>

using Id_colour = std::map<unsigned int, std::string>;

class Card {
public:
	Card();
	virtual ~Card();
	Card(const Card &other)=default;
	Card(Card &&other)=default;
	Card& operator=(const Card &other)=default;
	Card& operator=(Card &&other)=default;
private:
	Id_colour colours_;

};

#endif /* CARD_CARD_H_ */
