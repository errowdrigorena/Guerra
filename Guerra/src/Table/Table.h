/*
 * Table.h
 *
 *  Created on: Feb 11, 2022
 *      Author: iban
 */

#ifndef TABLE_TABLE_H_
#define TABLE_TABLE_H_

#include <deque>

using deck = std::deque<int>;

namespace table
{

class Table
{
public:
	Table();
	virtual ~Table();
	Table(const Table &other) = default;
	Table(Table &&other) = default;
	Table& operator=(const Table &other) = default;
	Table& operator=(Table &&other) = default;
private:

};

}
#endif /* TABLE_TABLE_H_ */
