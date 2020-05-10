/*
 * ValueStreamVisitor.cpp
 * Implements a visitor class for streaming out Values
 * Created on 5/9/2020
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
#include "ValueStreamVisitor.h"

//constructor
ValueStreamVisitor::ValueStreamVisitor(std::ostream& newStream)
	: os(newStream) //init the field
{
	//no code needed
}

//destructor
ValueStreamVisitor::~ValueStreamVisitor() {
	//no code needed
}

//copy constructor is deleted

//assignment operator is deleted

//int visitor method
void ValueStreamVisitor::operator()(int i) const {
	this->os << i; //stream out the int 
}

//double visitor method
void ValueStreamVisitor::operator()(double d) const {
	this->os << d; //stream out the double 
}

//boolean visitor method
void ValueStreamVisitor::operator()(bool b) const {
	this->os << b; //stream out the bool
}

//string visitor method
void ValueStreamVisitor::operator()(const std::string& s) const {
	this->os << s;
}

//end of implementation
