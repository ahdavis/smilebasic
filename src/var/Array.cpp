/*
 * Array.cpp
 * Implements a class that represents a SmileBASIC array
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
#include "Array.h"
#include "../except/ArrayIndexOutOfRangeException.h"

//constructor
Array::Array(std::size_t newSize, VariableType newType)
	: data(), size(newSize), type(newType) //init the fields
{
	//and load the array with empty values
	Value loadVal;
	if(this->type == VariableType::NUMBER) {
		loadVal = 0;
	} else {
		loadVal = "";
	}
	for(int i = 0; i < this->size; i++) {
		this->data.push_back(loadVal);
	}
}

//destructor
Array::~Array() {
	//no code needed
}

//copy constructor
Array::Array(const Array& a)
	: data(a.data), size(a.size), type(a.type) //copy the fields
{
	//no code needed
}

//assignment operator
Array& Array::operator=(const Array& src) {
	this->data = src.data; //assign the data field
	this->size = src.size; //assign the size field
	this->type = src.type; //assign the type field
	return *this; //and return the instance
}

//getSize method - gets the size of the Array
std::size_t Array::getSize() const {
	return this->size; //return the size field
}

//getType method - gets the type of the Array
VariableType Array::getType() const {
	return this->type; //return the type field
}

//first overloaded subscript operator - uses a Value as an index
Value& Array::operator[](const Value& idxVal) {
	return (*this)[idxVal.intValue()]; //call the third subscript operator
}

//second overloaded subscript operator - uses a Variable as an index
Value& Array::operator[](const Variable& idxVar) {
	return (*this)[idxVar.getValue()]; //call the first subscript operator
}

//third overloaded subscript operator - uses an int as an index
Value& Array::operator[](std::size_t idx) {
	//validate the index
	if(idx >= this->size) { //if the index is too large
		//then throw an exception
		throw ArrayIndexOutOfRangeException(idx, this->size);
	}

	//and return the value at the index
	return this->data[idx];
}

//begin method - returns an ArrayIterator pointing to the start of the Array
ArrayIterator Array::begin() {
	return ArrayIterator(this, 0); //return an ArrayIterator pointing to the start of the Array
}

//end method - returns an ArrayIterator pointing to the end of the Array
ArrayIterator Array::end() {
	return ArrayIterator(this, this->size); //return an ArrayIterator pointing to the end of the Array
}

//end of implementation
