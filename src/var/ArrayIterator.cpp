/*
 * ArrayIterator.cpp
 * Implements a class that represents a SmileBASIC array iterator
 * Created on 5/27/2020
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
#include "ArrayIterator.h"
#include "Array.h"

//constructor
ArrayIterator::ArrayIterator(Array* arrayPtr, std::size_t newPos)
	: arr(arrayPtr), pos(newPos) //init the fields
{
	//no code needed
}

//destructor
ArrayIterator::~ArrayIterator() {
	//no code needed
}

//copy constructor
ArrayIterator::ArrayIterator(const ArrayIterator& ai)
	: arr(ai.arr), pos(ai.pos) //copy the fields
{
	//no code needed
}

//assignment operator
ArrayIterator& ArrayIterator::operator=(const ArrayIterator& src) {
	this->arr = src.arr; //assign the array pointer
	this->pos = src.pos; //assign the position
	return *this; //and return the instance
}

//overloaded inequality operator
bool ArrayIterator::operator!=(const ArrayIterator& other) const {
	return this->pos != other.pos;
}

//overloaded dereference operator
Value& ArrayIterator::operator*() const {
	return (*this->arr)[this->pos];
}

//overloaded increment operator
ArrayIterator& ArrayIterator::operator++() {
	this->pos++; //increment the position
	return *this; //and return the instance
}

//end of implementation
