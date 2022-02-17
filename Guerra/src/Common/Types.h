/*
 * Types.h
 *
 *  Created on: Feb 12, 2022
 *      Author: iban
 */

#ifndef COMMON_TYPES_H_
#define COMMON_TYPES_H_

#include <vector>
#include <utility>
#include <string>

using Possible_colours = std::vector<std::string>;
using Value_name = std::pair<unsigned int, std::string>;
using Possible_values = std::vector<Value_name>;
using Deckname_values_colours =
		std::tuple<std::string, Possible_values, Possible_colours>;

enum class Manage_deckname_values_colours
{
	DECKNAME = 0, VALUES = 1, COLOURS = 2
};

#endif /* COMMON_TYPES_H_ */
