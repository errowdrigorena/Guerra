/*
 * ViewFactory.cc
 *
 *  Created on: Feb 15, 2022
 *      Author: iban
 */

#include <View/Commands/CommandFactory.h>

namespace view
{
namespace commands
{
std::vector<std::string> Command_factory::get_command_options()
{
	std::vector<std::string> command_options{};

	for(auto& command : commands_of_view_)
	{
		auto insertable = command->get_description();
		command_options.push_back(insertable);
	}

	return command_options;
}

std::shared_ptr<Command> Command_factory::share_command(std::size_t index)
{
	std::shared_ptr<Command> command{};

	if(index <= commands_of_view_.size() )
	{
		command = commands_of_view_[index-1];
	}
	else
	{
		std::cout << "Opción fuera de rango." << std::endl;
	}

	return command;
}
}
}


