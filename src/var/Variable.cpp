/*
 * Variable.cpp
 * Implements a class that represents a program variable
 * Created on 5/22/2020
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
#include "Variable.h"
#include "ValueType.h"

//first constructor - constructs from a name
Variable::Variable(const std::string& newName)
	: Variable(newName, 0) //call the second constructor
{
	//no code needed
}

//second constructor - constructs from a name and a value
Variable::Variable(const std::string& newName, const Value& newValue)
	: name(newName), value(), type() //init the fields
{
	//and set the value (this updates the type field as well)
	this->setValue(newValue);
}

//destructor
Variable::~Variable() {
	//no code needed
}

//copy constructor
Variable::Variable(const Variable& v)
	: name(v.name), value(v.value), type(v.type) //copy the fields
{
	//no code needed
}

//assignment operator
Variable& Variable::operator=(const Variable& src) {
	this->name = src.name; //assign the name
	this->value = src.value; //assign the value
	this->type = src.type; //assign the type
	return *this; //and return the instance
}

//getName method - gets the name of the Variable
const std::string& Variable::getName() const {
	return this->name; //return the name field
}

//getType method - gets the type of the Variable
VariableType Variable::getType() const {
	return this->type; //return the type field
}

//getValue method - gets the value of the Variable
const Value& Variable::getValue() const {
	return this->value; //return the value field
}

//setValue method - sets the value of the Variable
void Variable::setValue(const Value& newValue) {
	this->value = newValue; //assign the value field
	this->updateType(); //and update the type
}

//swapWith method - swaps the values of two Variables
void Variable::swapWith(Variable& other) {
	this->value.swapWith(other.value); //swap the values of the Variables
}

//overloaded equality operator
bool Variable::operator==(const Variable& other) const {
	//ensure that comparing a number variable to a string variable
	//always results in a "not equal" result
	if(this->type != other.type) {
		return false;
	}

	//and compare the Variables' underlying values
	return this->value == other.value;
}

//overloaded inequality operator
bool Variable::operator!=(const Variable& other) const {
	//ensure that comparing a number variable to a string variable
	//always results in a "not equal" result
	if(this->type != other.type) {
		return true;
	}

	//and compare the Variables' underlying values
	return this->value != other.value;
}

//overloaded less-than operator
bool Variable::operator<(const Variable& other) const {
	return this->value < other.value; //compare the underlying values
}

//overloaded greater-than operator
bool Variable::operator>(const Variable& other) const {
	return this->value > other.value; //compare the underlying values
}

//overloaded less-than-or-equal-to operator
bool Variable::operator<=(const Variable& other) const {
	//get the components of the comparison
	bool equal = *this == other; 
	bool lessThan = *this < other;

	//and OR them together
	return equal || lessThan;
}

//overloaded greater-than-or-equal-to operator
bool Variable::operator>=(const Variable& other) const {
	//get the components of the comparison
	bool equal = *this == other;
	bool greaterThan = *this > other;

	//and OR them together
	return equal || greaterThan;
}

//overloaded insertion operator
std::ostream& operator<<(std::ostream& os, const Variable& v) {
	os << v.value; //write the value to the stream
	return os; //and return the stream
}

//overloaded extraction operator
std::istream& operator>>(std::istream& is, Variable& v) {
	is >> v.value; //read the value from the stream
	v.updateType(); //update the type of the Variable
	return is; //and return the stream
}

//overloaded getline function - reads an entire line into the Variable
std::istream& getline(std::istream& is, Variable& v) {
	getline(is, v.value); //call the Value getline function
	v.updateType(); //update the type
	return is; //and return the stream
}

//protected updateType method - updates the type of the Variable
void Variable::updateType() {
	if(this->value.getType() == ValueType::STRING) { //if the value field holds a string
		this->type = VariableType::STRING; //then set the type field to STRING
	} else { //if the value field holds a number
		this->type = VariableType::NUMBER; //then set the type field to NUMBER
	}
}

//end of implementation
