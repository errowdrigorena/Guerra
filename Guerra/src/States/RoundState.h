/*
 * RoundState.h
 *
 *  Created on: Feb 18, 2022
 *      Author: iban
 */

#ifndef STATES_ROUNDSTATE_H_
#define STATES_ROUNDSTATE_H_
#include "StateOfGame.h"

namespace states
{

class Round_state : public State_of_game
{
public:
	Round_state();
	virtual ~Round_state();
	Round_state(const Round_state &other) = default;
	Round_state(Round_state &&other) = default;
	Round_state& operator=(const Round_state &other) = default;
	Round_state& operator=(Round_state &&other) = default;

	void execute(table::Table& table_model) override;
};

} /* namespace states */

#endif /* STATES_ROUNDSTATE_H_ */
