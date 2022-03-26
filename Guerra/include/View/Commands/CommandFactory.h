/*
 * ViewFactory.h
 *
 *  Created on: Feb 15, 2022
 *      Author: iban
 */

#ifndef VIEW_VIEWFACTORY_H_
#define VIEW_VIEWFACTORY_H_
#include <memory>
#include <string>
#include <vector>
#include <iostream>

#include <Common/Command.h>

using Init_list = std::initializer_list<std::shared_ptr<Command>>;

namespace view
{
namespace commands
{

class Command_factory
{
public:
	Command_factory(Init_list commands) : commands_of_view_{commands}{}
	virtual ~Command_factory() = default;

	std::vector<std::string> get_command_options();

	std::shared_ptr<Command> share_command(std::size_t);

protected:
	std::vector<std::shared_ptr<Command>> commands_of_view_;
};

}
}
#endif /* VIEW_VIEWFACTORY_H_ */
