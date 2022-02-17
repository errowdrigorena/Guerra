/*
 * TableController.h
 *
 *  Created on: Feb 17, 2022
 *      Author: iban
 */

#ifndef CONTROLLERS_TABLECONTROLLER_H_
#define CONTROLLERS_TABLECONTROLLER_H_

namespace controllers {

class Table_controller
{
public:
	Table_controller();
	virtual ~Table_controller();
	Table_controller(const Table_controller &other) = default;
	Table_controller(Table_controller &&other) = default;
	Table_controller& operator=(const Table_controller &other) = default;
	Table_controller& operator=(Table_controller &&other) = default;
private:

};

} /* namespace controllers */

#endif /* CONTROLLERS_TABLECONTROLLER_H_ */
