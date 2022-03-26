/*
 * Command.h
 *
 *  Created on: Feb 13, 2022
 *      Author: iban
 */

#ifndef COMMON_COMMAND_H_
#define COMMON_COMMAND_H_
#include <string>

class Command
{
public:
	Command(){};
	virtual ~Command(){};

	virtual void execute() = 0;
	virtual std::string get_description() = 0;
};

#endif /* COMMON_COMMAND_H_ */
