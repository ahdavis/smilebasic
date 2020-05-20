/*
 * Value.cpp
 * Implements a class that represents a variant value
 * Created on 5/20/2020
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
#include "Value.h"
#include "ValueStreamVisitor.h"
#include "../except/ComparisonException.h"
#include "../except/OperationException.h"
#include "../except/ValueTypeException.h"
#include "../util/typecheck.h"
#include <stdexcept>
#include <sstream>
#include <limits>
#include <cmath>

//default constructor
Value::Value()
	: Value(0) //call the int constructor
{
	//no code needed
}

//int constructor
Value::Value(int i)
	: data(i), type(ValueType::INT) //init the fields
{
	//no code needed
}

//double constructor
Value::Value(double d)
	: data(d), type(ValueType::DOUBLE) //init the fields
{
	//no code needed
}

//bool constructor
Value::Value(bool b)
	: data(b), type(ValueType::BOOL) //init the fields
{
	//no code needed
}

//char string constructor
Value::Value(const char* s)
	: Value(std::string(s)) //call the string object constructor
{
	//no code needed
}

//string object constructor
Value::Value(const std::string& s)
	: data(s), type(ValueType::STRING) //init the fields
{
	//no code needed
}

//destructor
Value::~Value() {
	//no code needed
}

//copy constructor
Value::Value(const Value& v)
	: data(v.data), type(v.type) //copy the fields
{
	//no code needed
}

//Value assignment operator
Value& Value::operator=(const Value& src) {
	this->data = src.data; //assign the data
	this->type = src.type; //assign the type
	return *this; //and return the instance
}

//int assignment operator
Value& Value::operator=(int i) {
	this->data = i; //update the data
	this->type = ValueType::INT; //update the type
	return *this; //and return the instance
}

//double assignment operator
Value& Value::operator=(double d) {
	this->data = d; //update the data
	this->type = ValueType::DOUBLE; //update the type
	return *this; //and return the instance
}

//bool assignment operator
Value& Value::operator=(bool b) {
	this->data = b; //update the data
	this->type = ValueType::BOOL; //update the type
	return *this; //and return the instance
}

//char string assignment operator
Value& Value::operator=(const char* s) {
	Value::operator=(std::string(s)); //call the string object assignment operator
	return *this; //and return the instance
}

//string object assignment operator
Value& Value::operator=(const std::string& s) {
	this->data = s; //update the data
	this->type = ValueType::STRING; //update the type
	return *this; //and return the instance
}

//getType method - gets the type of the Value
ValueType Value::getType() const {
	return this->type; //return the type field
}

//intValue method - gets the integer value of the Value
int Value::intValue() const {
	//handle different types
	switch(this->type) {
		case ValueType::INT: { //if the Value holds an int
			return std::get<int>(this->data); //then return it
		}

		case ValueType::DOUBLE: { //if the Value holds a double
			double d = std::get<double>(this->data); //then get the double
			return static_cast<int>(d); //and return it cast to an int
		}

		case ValueType::BOOL: { //if the Value holds a bool
			bool b = std::get<bool>(this->data); //then get the bool
			return b? 1 : 0; //and return it as an int
		}

		case ValueType::STRING: { //if the Value holds a string
			std::string s = std::get<std::string>(this->data); //then get the string

			//attempt to cast it to an int
			try {
				int i = std::stoi(s); //convert the string to an int
				return i; //and return the int
			} catch(const std::invalid_argument& ia) {
				throw ValueTypeException(ValueType::INT, ValueType::STRING);
			}
		}
	}
}

//doubleValue method - gets the double value of the Value
double Value::doubleValue() const {
	//handle different types
	switch(this->type) {
		case ValueType::INT: { //if the Value holds an int
			int i = std::get<int>(this->data); //then get the int
			return static_cast<double>(i); //and return it cast to a double
		}

		case ValueType::DOUBLE: { //if the Value holds a double
			return std::get<double>(this->data); //then return it
		}

		case ValueType::BOOL: { //if the Value holds a bool
			bool b = std::get<bool>(this->data); //then get the boolean
			int i = b? 1 : 0; //convert it to an int
			return static_cast<double>(i); //and return that int as a double
		}

		case ValueType::STRING: { //if the Value holds a string
			std::string s = std::get<std::string>(this->data); //then get the string

			//attempt to cast it to a double
			try {
				double d = std::stod(s); //convert the string to a double
				return d; //and return the double
			} catch(const std::invalid_argument& ia) {
				throw ValueTypeException(ValueType::DOUBLE, ValueType::STRING);
			}
		}
	}
}

//boolValue method - gets the Boolean value of the Value
bool Value::boolValue() const {
	//handle different types 
	switch(this->type) {
		case ValueType::INT: { //if the Value holds an int
			int i = std::get<int>(this->data); //then get the int
			return !(i == 0); //and convert it to a bool
		}	

		case ValueType::DOUBLE: { //if the Value holds a double
			double d = std::get<double>(this->data); //then get the double
			int i = static_cast<int>(d); //convert it to an int
			return !(i == 0); //and convert the int to a bool
		}

		case ValueType::BOOL: { //if the Value holds a bool
			return std::get<bool>(this->data); //then return the bool
		}

		case ValueType::STRING: { //if the Value holds a string
			std::string s = std::get<std::string>(this->data); //then get the string
			return s == "true"; //and return whether the string is equal to "true"
		}
	}
}

//stringValue method - gets the string value of the Value
std::string Value::stringValue() const {
	//declare the return string
	std::string ret;

	//populate it
	switch(this->type) {
		case ValueType::INT: { //if the Value holds an int
			int i = std::get<int>(this->data); //then get the int
			ret = std::to_string(i); //and convert it to a string
			break;
		}

		case ValueType::DOUBLE: { //if the Value holds a double
			double d = std::get<double>(this->data); //then get the double
			ret = std::to_string(d); //and convert it to a string
			break;
		}

		case ValueType::BOOL: { //if the Value holds a Boolean
			bool b = std::get<bool>(this->data); //then get the bool
			
			//and convert it to a string using a stream
			std::stringstream ss;
			ss << std::boolalpha << b;
			ret = ss.str();
			break;
		}

		case ValueType::STRING: { //if the Value holds a string
			ret = std::get<std::string>(this->data); //then get the string
			break;
		}
	}

	//and return the populated string
	return ret;
}

//overloaded equality operator
bool Value::operator==(const Value& other) const {
	//handle different LHS types
	switch(this->type) {
		case ValueType::INT: { //if the LHS is an int
			//try to get the value of the RHS as an int
			//and compare it
			try {
				int lhs = std::get<int>(this->data);
				int rhs = other.intValue();
				return lhs == rhs;
			} catch(const ValueTypeException& vte) {
				return false;
			}
		}

		case ValueType::DOUBLE: { //if the LHS is a double
			//try to get the value of the RHS as a double
			//and compare it
			try {
				//get the values to compare
				double lhs = std::get<double>(this->data);
				double rhs = other.doubleValue();

				//and compare the values using the float comparison algorithm
				double diff = lhs - rhs;
				double diffAbs = std::fabs(diff);
				return diffAbs < std::numeric_limits<double>::epsilon();
			} catch(const ValueTypeException& vte) {
				return false;
			}
		}

		case ValueType::BOOL: { //if the LHS is a Boolean
			//then get the values to compare
			bool lhs = std::get<bool>(this->data);
			bool rhs = other.boolValue();

			//and compare them
			return lhs == rhs;
		}

		case ValueType::STRING: { //if the LHS is a string
			//then get the values to compare
			std::string lhs = std::get<std::string>(this->data);
			std::string rhs = other.stringValue();

			//and compare them
			return lhs == rhs;
		}
	}
}

//overloaded inequality operator
bool Value::operator!=(const Value& other) const {
	bool areEqual = *this == other; //check whether this and other are equal
	return !areEqual; //and return the opposite of that
}

//overloaded less than operator
bool Value::operator<(const Value& other) const {
	//handle different LHS types
	switch(this->type) {
		case ValueType::INT: { //if the LHS is an int
			//try to get the value of the RHS as an int
			//and compare it
			try {
				int lhs = std::get<int>(this->data);
				int rhs = other.intValue();
				return lhs < rhs;
			} catch(const ValueTypeException& vte) {
				throw ComparisonException(*this, other);
			}
		}

		case ValueType::DOUBLE: { //if the LHS is a double
			//try to get the value of the RHS as a double
			//and compare it
			try {
				//get the values to compare
				double lhs = std::get<double>(this->data);
				double rhs = other.doubleValue();

				//and compare the values 
				return lhs < rhs;
			} catch(const ValueTypeException& vte) {
				throw ComparisonException(*this, other);
			}
		}

		case ValueType::BOOL: { //if the LHS is a Boolean
			//then get the values to compare
			bool lhs = std::get<bool>(this->data);
			bool rhs = other.boolValue();

			//convert them to ints
			int lhsi = static_cast<int>(lhs);
			int rhsi = static_cast<int>(rhs);

			//and compare them
			return lhsi < rhsi;
		}

		case ValueType::STRING: { //if the LHS is a string
			//then get the values to compare
			std::string lhs = std::get<std::string>(this->data);
			std::string rhs = other.stringValue();

			//and compare them
			return lhs < rhs;
		}
	}
}

//overloaded greater than operator
bool Value::operator>(const Value& other) const {
	//handle different LHS types
	switch(this->type) {
		case ValueType::INT: { //if the LHS is an int
			//try to get the value of the RHS as an int
			//and compare it
			try {
				int lhs = std::get<int>(this->data);
				int rhs = other.intValue();
				return lhs > rhs;
			} catch(const ValueTypeException& vte) {
				throw ComparisonException(*this, other);
			}
		}

		case ValueType::DOUBLE: { //if the LHS is a double
			//try to get the value of the RHS as a double
			//and compare it
			try {
				//get the values to compare
				double lhs = std::get<double>(this->data);
				double rhs = other.doubleValue();

				//and compare the values 
				return lhs > rhs;
			} catch(const ValueTypeException& vte) {
				throw ComparisonException(*this, other);
			}
		}

		case ValueType::BOOL: { //if the LHS is a Boolean
			//then get the values to compare
			bool lhs = std::get<bool>(this->data);
			bool rhs = other.boolValue();

			//convert them to ints
			int lhsi = static_cast<int>(lhs);
			int rhsi = static_cast<int>(rhs);

			//and compare them
			return lhsi > rhsi;
		}

		case ValueType::STRING: { //if the LHS is a string
			//then get the values to compare
			std::string lhs = std::get<std::string>(this->data);
			std::string rhs = other.stringValue();

			//and compare them
			return lhs > rhs;
		}
	}
}

//overloaded less than or equal operator
bool Value::operator<=(const Value& other) const {
	//calculate the components of the comparison
	bool isEqual = *this == other;
	bool isLess = *this < other;

	//and combine them (<= is the same as < || ==)
	return isLess || isEqual;
}

//overloaded greater than or equal operator
bool Value::operator>=(const Value& other) const {
	//calculate the components of the comparison 
	bool isEqual = *this == other;
	bool isGreater = *this > other;

	//and combine them (>= is the same as > || ==)
	return isGreater || isEqual;
}

//overloaded addition operator
Value Value::operator+(const Value& other) const {
	//handle different LHS types
	switch(this->type) {
		case ValueType::INT: { //if the LHS is an int
			//try to get the value of the operands
			//and add them together
			try {
				int lhs = std::get<int>(this->data);
				int rhs = other.intValue();
				return lhs + rhs;
			} catch(const ValueTypeException& vte) {
				throw OperationException(*this, other, '+');
			}
		}

		case ValueType::DOUBLE: { //if the LHS is a double
			//try to get the value of the operands
			//and add them together
			try {
				double lhs = std::get<double>(this->data);
				double rhs = other.doubleValue();
				return lhs + rhs;
			} catch(ValueTypeException& vte) {
				throw OperationException(*this, other, '+');
			}
		}

		case ValueType::BOOL: { //if the LHS is a Boolean
			//bools cannot be operated on
			throw OperationException(*this, other, '+');
		}

		case ValueType::STRING: { //if the LHS is a string
			//get the value of the operands
			std::string ret;
			std::string lhs = std::get<std::string>(this->data);
			std::string rhs = other.stringValue();

			//and concatenate them
			ret += lhs;
			ret += rhs;
			return ret;
		}
	}
}

//overloaded subtraction operator
Value Value::operator-(const Value& other) const {
	//handle different LHS types
	switch(this->type) {
		case ValueType::INT: { //if the LHS is an int
			//try to get the value of the operands
			//and subtract the RHS from the LHS
			try {
				int lhs = std::get<int>(this->data);
				int rhs = other.intValue();
				return lhs - rhs;
			} catch(const ValueTypeException& vte) {
				throw OperationException(*this, other, '-');
			}
		}

		case ValueType::DOUBLE: { //if the LHS is a double
			//try to get the value of the operands
			//and subtract the RHS from the LHS
			try {
				double lhs = std::get<double>(this->data);
				double rhs = other.doubleValue();
				return lhs - rhs;
			} catch(ValueTypeException& vte) {
				throw OperationException(*this, other, '-');
			}
		}

		case ValueType::BOOL: { //if the LHS is a Boolean
			//bools cannot be operated on
			throw OperationException(*this, other, '-');
		}

		case ValueType::STRING: { //if the LHS is a string
			//strings cannot be subtracted
			throw OperationException(*this, other, '-');
		}
	}
}

//overloaded multiplication operator
Value Value::operator*(const Value& other) const {
	//handle different LHS types
	switch(this->type) {
		case ValueType::INT: { //if the LHS is an int
			//try to get the value of the operands
			//and multiply them together
			try {
				int lhs = std::get<int>(this->data);
				int rhs = other.intValue();
				return lhs * rhs;
			} catch(const ValueTypeException& vte) {
				throw OperationException(*this, other, '*');
			}
		}

		case ValueType::DOUBLE: { //if the LHS is a double
			//try to get the value of the operands
			//and multiply them together
			try {
				double lhs = std::get<double>(this->data);
				double rhs = other.doubleValue();
				return lhs * rhs;
			} catch(ValueTypeException& vte) {
				throw OperationException(*this, other, '*');
			}
		}

		case ValueType::BOOL: { //if the LHS is a Boolean
			//bools cannot be operated on
			throw OperationException(*this, other, '*');
		}

		case ValueType::STRING: { //if the LHS is a string
			//only allow multiplication between a LHS string
			//and a RHS int
			if(other.type != ValueType::INT) {
				throw OperationException(*this, other, '*');
			} else {
				//get the operands
				std::string lhs = std::get<std::string>(this->data);
				int rhs = other.intValue();

				//multiply the string
				std::string ret;
				for(int i = 0; i < rhs; i++) {
					ret += lhs;
				}

				//and return the multiplied string
				return ret;
			}
		}
	}
}

//overloaded division operator
Value Value::operator/(const Value& other) const {
	//handle different LHS types
	switch(this->type) {
		case ValueType::INT: { //if the LHS is an int
			//try to get the value of the operands
			//and divide the LHS by the RHS
			try {
				int lhs = std::get<int>(this->data);
				int rhs = other.intValue();
				return lhs / rhs;
			} catch(const ValueTypeException& vte) {
				throw OperationException(*this, other, '/');
			}
		}

		case ValueType::DOUBLE: { //if the LHS is a double
			//try to get the value of the operands
			//and divide the LHS by the RHS
			try {
				double lhs = std::get<double>(this->data);
				double rhs = other.doubleValue();
				return lhs / rhs;
			} catch(ValueTypeException& vte) {
				throw OperationException(*this, other, '/');
			}
		}

		case ValueType::BOOL: { //if the LHS is a Boolean
			//bools cannot be operated on
			throw OperationException(*this, other, '/');
		}

		case ValueType::STRING: { //if the LHS is a string
			//strings cannot be operated on
			throw OperationException(*this, other, '/');
		}
	}
}

//overloaded modulus operator
Value Value::operator%(const Value& other) const {
	//handle different LHS types
	switch(this->type) {
		case ValueType::INT: { //if the LHS is an int
			//try to get the value of the operands
			//and return LHS % RHS
			try {
				int lhs = std::get<int>(this->data);
				int rhs = other.intValue();
				return lhs % rhs;
			} catch(const ValueTypeException& vte) {
				throw OperationException(*this, other, '%');
			}
		}

		case ValueType::DOUBLE: { //if the LHS is a double
			//try to get the value of the operands
			//and return LHS % RHS
			try {
				double lhs = std::get<double>(this->data);
				double rhs = other.doubleValue();
				return std::fmod(lhs, rhs);
			} catch(ValueTypeException& vte) {
				throw OperationException(*this, other, '%');
			}
		}

		case ValueType::BOOL: { //if the LHS is a Boolean
			//bools cannot be operated on
			throw OperationException(*this, other, '%');
		}

		case ValueType::STRING: { //if the LHS is a string
			//strings cannot be operated on
			throw OperationException(*this, other, '%');
		}
	}
}

//overloaded negation operator
Value Value::operator!() const {
	//handle different value types
	switch(this->type) {
		case ValueType::INT: { //if the Value holds an int
			int v = std::get<int>(this->data); //get the value of the variant
			return (v == 0)? true : false; //and return its negation
		}
		
		case ValueType::DOUBLE: { //if the Value holds a double
			return (*this == 0.0)? true : false; //then return its negation
		}

		case ValueType::BOOL: { //if the Value holds a Boolean
			bool b = std::get<bool>(this->data); //get the value of the variant
			return !b; //and return its negation
		}

		case ValueType::STRING: { //if the Value holds a string
			bool b = this->boolValue(); //get the Boolean value of the string
			return !b; //and return its negation
		}
	}
}

//swapWith method - swaps two Values in-place
void Value::swapWith(Value& other) {
	//save the first swap value
	Value tmp = *this; 

	//load the fields of other into this
	this->data = other.data;
	this->type = other.type;

	//and swap in the saved value
	other = tmp;
}

//friendly insertion operator - writes the Value to a stream
std::ostream& operator<<(std::ostream& os, const Value& v) {
	std::visit(ValueStreamVisitor(os), v.data); //visit the value and write it to the stream
	return os; //and return the stream
}

//friendly extraction operator - reads into the Value from a stream
std::istream& operator>>(std::istream& is, Value& v) {
	//read in the input
	std::string input;
	is >> input;

	//determine the type of the input
	if(checkInt(input)) {
		v = std::stoi(input);
	} else if(checkFloat(input)) {
		v = std::stod(input);
	} else if(checkBool(input)) {
		v = (input == "true");
	} else { //default to a string
		v = input;
	}

	//and return the stream
	return is;
}

//friendly getline function - reads an entire line into the Value from a stream
void getline(std::istream& is, Value& v) {
	//read in the input
	std::string input; //the string to read into
	char c; //the current character being read

	//get the first character
	is.get(c);

	//loop and read the line
	while((c != '\n') && !is.eof()) {
		input += c;
		is.get(c);
	}

	//and determine the type of the input
	if(checkInt(input)) {
		v = std::stoi(input);
	} else if(checkFloat(input)) {
		v = std::stod(input);
	} else if(checkBool(input)) {
		v = (input == "true");
	} else { //default to a string
		v = input;
	}
}

//end of implementation
