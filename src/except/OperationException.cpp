/*
 * OperationException.cpp
 * Implements an exception thrown when a symbolic operation is attempted
 * between incompatible values
 * Created on 5/11/2020
 * Created by Andrew Davis
 *
 * Copyright (C) 2020  Andrew Davis
 *
 * This program is free software: you can redistribute it and/or modify   
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

//includes
#include "OperationException.h"
#include "../var/ValueType.h"
#include <sstream>

//constructor
OperationException::OperationException(const Value& lhs, const Value& rhs, char opSym)
	: errMsg() //init the error message
{
	//assemble the error message
	std::stringstream ss;
	ss << "Bad operation (the operator '";
	ss << opSym;
	ss << "' is not defined for types ";
	ss << nameForValueType(lhs.getType());
	ss << " and ";
	ss << nameForValueType(rhs.getType());
	ss << ")";
	this->errMsg = ss.str();
}

//destructor
OperationException::~OperationException() {
	//no code needed
}

//copy constructor
OperationException::OperationException(const OperationException& ce)
	: errMsg(ce.errMsg) //copy the error message
{
	//no code needed 
}

//assignment operator
OperationException& OperationException::operator=(const OperationException& src) {
	this->errMsg = src.errMsg; //assign the error message
	return *this; //and return the instance
}

//overridden what method - called when the exception is thrown
const char* OperationException::what() const throw() {
	return this->errMsg.c_str(); //return the error message
}

//end of implementation
