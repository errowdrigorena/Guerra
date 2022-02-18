/*
 * View.cpp
 *
 *  Created on: Feb 15, 2022
 *      Author: iban
 */
#include"View.h"

namespace view
{

View::View(Init_list commands) : options_{}, exit_{}, factory_{commands}
{
	auto options = factory_.get_command_options();
	std::copy(options.begin(), options.end(), std::back_inserter(options_));
	options_.push_back("Salir"); //it must be the last one*/
}

void View::show_options()
{
	auto i = 1;
	for(auto option : options_)
	{
		std::cout << i << ". " << option << std::endl;
		i++;
	}
}

void View::execute_option(int option)
{
	if(option == options_.size())
	{
		std::cout << "Esta pantalla procede a cerrarse" << std::endl;
		exit_ = true;
	}
	else
	{
		auto next_interface = factory_.share_command(option);
		if( next_interface )
		{
			next_interface->execute();
		}

	}
}

int View::ask_for_option()
{
	int option = operations::ask_value<int>("Introduzca una opción");

	std::string check_question
		{"Introduzca un número de opción superior a 0 (numérico)" };
	operations::check_number(check_question, option);

	return option;
}

};
