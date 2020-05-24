/*
 * VarNotRegisteredException.cpp
 * Implements an exception thrown when a non-registered Variable
 * is requested from the variable registry
 * Created on 5/23/2020
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
#include "VarNotRegisteredException.h"
#include <sstream>

//constructor
VarNotRegisteredException::VarNotRegisteredException(const std::string& varName)
	: errMsg() //init the error message
{
	//assemble the error message
	std::stringstream ss;
	ss << "Error: The variable ";
	ss << varName;
	ss << " was not found in the registry.";
	this->errMsg = ss.str();
}

//destructor
VarNotRegisteredException::~VarNotRegisteredException() {
	//no code needed
}

//copy constructor
VarNotRegisteredException::VarNotRegisteredException(const VarNotRegisteredException& vnre)
	: errMsg(vnre.errMsg) //copy the error message
{
	//no code needed
}	

//assignment operator
VarNotRegisteredException& VarNotRegisteredException::operator=(const VarNotRegisteredException& src) {
	this->errMsg = src.errMsg; //assign the error message
	return *this; //and return the instance
}

//overridden what method - called when the exception is thrown
const char* VarNotRegisteredException::what() const throw() {
	return this->errMsg.c_str(); //return the error message
}

//end of implementation
