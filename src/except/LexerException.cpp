/*
 * LexerException.cpp
 * Implements an exception thrown when the SmileBASIC lexer 
 * encounters an unknown character
 * Created on 5/30/2020
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
#include "LexerException.h"
#include <sstream>

//constructor
LexerException::LexerException(unsigned int line, unsigned int column, char badChar)
	: errMsg() //init the error message
{
	//assemble the error message
	std::stringstream ss;
	ss << '[';
	ss << line;
	ss << ':';
	ss << column;
	ss << "] unknown character ";
	ss << badChar;
	this->errMsg = ss.str();
}

//destructor
LexerException::~LexerException() {
	//no code needed
}

//copy constructor
LexerException::LexerException(const LexerException& le)
	: errMsg(le.errMsg) //copy the error message
{
	//no code needed
}

//assignment operator
LexerException& LexerException::operator=(const LexerException& src) {
	this->errMsg = src.errMsg; //assign the error message
	return *this; //and return the instance
}

//overridden what method - called when the exception is thrown
const char* LexerException::what() const throw() {
	return this->errMsg.c_str(); //return the error message
}

//end of implementation
