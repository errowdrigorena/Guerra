/*
 * DealState.h
 *
 *  Created on: Feb 18, 2022
 *      Author: iban
 */

#ifndef STATES_DEALSTATE_H_
#define STATES_DEALSTATE_H_
#include "StateOfGame.h"

namespace states {

class Deal_state : public State_of_game
{
public:
	Deal_state();
	virtual ~Deal_state();
	Deal_state(const Deal_state &other)=default;
	Deal_state(Deal_state &&other)=default;
	Deal_state& operator=(const Deal_state &other)=default;
	Deal_state& operator=(Deal_state &&other)=default;

	void execute(table::Table& table_model) override;
};

} /* namespace states */

#endif /* STATES_DEALSTATE_H_ */
