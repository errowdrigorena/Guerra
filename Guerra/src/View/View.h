/*
 * View.h
 *
 *  Created on: Feb 13, 2022
 *      Author: iban
 */

#ifndef VIEW_VIEW_H_
#define VIEW_VIEW_H_

#include <vector>
#include <string>
#include <iostream>
#include <memory>

#include "Commands/CommandFactory.h"
#include "InterfaceOperations.h"

namespace operations = view::interface_operations;

namespace view
{

using View_factory = commands::Command_factory;

class View
{
public:
	View(Init_list commands);
	virtual ~View() = default;
	View(const View &other) = delete;
	View(View &&other) = default;
	View& operator=(const View &other) = default;
	View& operator=(View &&other) = default;


	void show_options();

	void execute_option(int option);

	bool is_running(){return !exit_;}

	int ask_for_option();

private:
	std::vector<std::string> options_;
	bool exit_;
	View_factory factory_;
};

}
#endif /* VIEW_VIEW_H_ */
