/*
 * Loop_management.h
 *
 *  Created on: Feb 13, 2022
 *      Author: iban
 */

#ifndef COMMON_LOOP_MANAGEMENT_H_
#define COMMON_LOOP_MANAGEMENT_H_
#include "InterfaceOperations.h"

namespace operations = view::interface_operations;

template<typename View>
void option_loop(View option_view)
{
	auto option{0 };
	while( option_view.is_running() )
	{
		option_view.show_options();
		option = option_view.ask_for_option();
		option_view.execute_option(option);
	}
}

std::string option_selector(std::vector<std::string> options);

std::string option_management(std::vector<std::string> options, std::string tip);

#endif /* COMMON_LOOP_MANAGEMENT_H_ */
