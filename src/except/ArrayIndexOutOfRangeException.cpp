/*
 * ArrayIndexOutOfRangeException.cpp
 * Implements an exception thrown when an array index is out of range
 * Created on 5/24/2020
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
#include "ArrayIndexOutOfRangeException.h"
#include <sstream>

//constructor
ArrayIndexOutOfRangeException::ArrayIndexOutOfRangeException(std::size_t badIdx, std::size_t arraySize)
	: errMsg() //init the error message
{
	//assemble the error message
	std::stringstream ss;
	ss << "Array index ";
	ss << badIdx;
	ss << " is out of range (maximum index is ";
	ss << arraySize - 1;
	ss << ")";
	this->errMsg = ss.str();
}

//destructor
ArrayIndexOutOfRangeException::~ArrayIndexOutOfRangeException() {
	//no code needed
}

//copy constructor
ArrayIndexOutOfRangeException::ArrayIndexOutOfRangeException(const ArrayIndexOutOfRangeException& exc)
	: errMsg(exc.errMsg) //copy the error message
{
	//no code needed
}

//assignment operator
ArrayIndexOutOfRangeException& ArrayIndexOutOfRangeException::operator=(const ArrayIndexOutOfRangeException& src) {
	this->errMsg = src.errMsg; //assign the error message
	return *this; //and return the instance
}

//overridden what method - called when the exception is thrown
const char* ArrayIndexOutOfRangeException::what() const throw() {
	return this->errMsg.c_str(); //return the error message
}

//end of implementation
