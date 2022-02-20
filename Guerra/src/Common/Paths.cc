/*
 * Paths.cc
 *
 *  Created on: Feb 19, 2022
 *      Author: iban
 */
#include "Paths.h"

#include <fstream>

namespace common
{
void create_file(fs::path route)
{
	if(fs::exists(route) == false)
	{
		std::ofstream file_ofstrem(route);
		file_ofstrem.close();
	}
}

void create_directory(fs::path route)
{
	if(fs::is_directory(route) == false)
	{
		fs::create_directory(route);
	}
}

}
