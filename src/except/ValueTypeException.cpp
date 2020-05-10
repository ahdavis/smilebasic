/*
 * ValueTypeException.cpp
 * Implements an exception thrown when a value of the wrong type
 * is requested from a Value
 * Created on 3/19/2020
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
#include "ValueTypeException.h"
#include <sstream>

//constructor
ValueTypeException::ValueTypeException(ValueType expected, ValueType actual)
	: errMsg() //init the error message
{
	//assemble the error message
	std::stringstream ss;
	ss << "Wrong value type requested (expected ";
	ss << nameForValueType(expected);
	ss << ", found ";
	ss << nameForValueType(actual);
	ss << ")";
	this->errMsg = ss.str();
}

//destructor
ValueTypeException::~ValueTypeException() {
	//no code needed	
}

//copy constructor
ValueTypeException::ValueTypeException(const ValueTypeException& vte)
	: errMsg(vte.errMsg) //copy the error message
{
	//no code needed 
}

//assignment operator
ValueTypeException& ValueTypeException::operator=(const ValueTypeException& src) {
	std::exception::operator=(src); //assign the superclass
	this->errMsg = src.errMsg; //assign the error message
	return *this; //and return the instance
}

//overridden what() method - called when the exception is thrown
const char* ValueTypeException::what() const throw() {
	return this->errMsg.c_str(); //return the error message 
}

//end of implementation
