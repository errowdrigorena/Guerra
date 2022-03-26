/*
 * Card.cc
 *
 *  Created on: Feb 11, 2022
 *      Author: iban
 */

#include <Card/Card.h>

namespace card
{

Card::Card(unsigned int colour, unsigned int value) : colour_id_{colour },
		value_{value }
{
	; //do nothing
}

Card::~Card()
{
	// TODO Auto-generated destructor stub
}

bool operator > (const Card& lho, const Card& rho)
{
	return lho.value_ > rho.value_;
}

bool operator < (const Card& lho, const Card& rho)
{
	return lho.value_ < rho.value_;
}

bool operator == (const Card& lho, const Card& rho)
{
	return lho.value_ == rho.value_;
}

bool operator != (const Card& lho, const Card& rho)
{
	return !( lho == rho );
}

}
