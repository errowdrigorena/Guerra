/*
 * DrawState.h
 *
 *  Created on: Feb 18, 2022
 *      Author: iban
 */

#ifndef STATES_DRAWSTATE_H_
#define STATES_DRAWSTATE_H_
#include "StateOfGame.h"

namespace states
{

class Draw_state : public State_of_game
{
public:
	Draw_state();
	virtual ~Draw_state();
	Draw_state(const Draw_state &other) = default;
	Draw_state(Draw_state &&other) = default;
	Draw_state& operator=(const Draw_state &other) = default;
	Draw_state& operator=(Draw_state &&other) = default;

	void execute(table::Table& table_model) override;
};

} /* namespace states */

#endif /* STATES_DRAWSTATE_H_ */
