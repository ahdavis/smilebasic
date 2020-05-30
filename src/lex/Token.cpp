/*
 * Token.cpp
 * Implements a class that represents a parser token
 * Created on 5/29/2020
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

//include
#include "Token.h"

//constant initialization
const Token Token::EOLToken = Token(TokenType::EOL, "");

//constructor
Token::Token(TokenType newType, const Value& newValue)
	: type(newType), value(newValue) //init the fields
{
	//no code needed
}

//destructor
Token::~Token() {
	//no code needed
}

//copy constructor
Token::Token(const Token& t)
	: type(t.type), value(t.value) //copy the fields
{
	//no code needed
}

//assignment operator
Token& Token::operator=(const Token& src) {
	this->type = src.type; //assign the type field
	this->value = src.value; //assign the value field
	return *this; //and return the instance
}

//getType method - gets the type of the Token
TokenType Token::getType() const {
	return this->type; //return the type field
}

//getValue method - gets the value of the Token
const Value& Token::getValue() const {
	return this->value; //return the value field
}

//end of implementation
