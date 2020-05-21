/*
 * Value.h 
 * Declares a class that represents a variant value
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

//include guard
#pragma once

//includes
#include <string>
#include <variant>
#include <iostream>
#include "ValueType.h"

/**
 * A value that can be an integer, a double, a bool, or a string
 */
class Value {
	//public fields and methods
	public:
		/**
		 * Default constructor - constructs a Value
		 * with an integer value of 0
		 */
		Value();

		/**
		 * Constructs a Value from an integer
		 *
		 * @param i The integer to initialize the Value with 
		 */
		Value(int i);

		/**
		 * Constructs a Value from a double
		 *
		 * @param d The double to initialize the Value with 
		 */
		Value(double d);

		/**
		 * Constructs a Value from a bool
		 *
		 * @param b The bool to initialize the Value with
		 */
		Value(bool b);

		/**
		 * Constructs a Value from a character string
		 *
		 * @param s The char* string to initialize the Value with
		 */
		Value(const char* s);

		/**
		 * Constructs a Value from a string object
		 *
		 * @param s The std::string to initialize the Value with
		 */
		Value(const std::string& s);

		/**
		 * Destructs a Value instance
		 */
		virtual ~Value();

		/**
		 * Copies a Value instance
		 *
		 * @param v The Value to copy
		 */
		Value(const Value& v);

		/**
		 * Assigns one Value instance to another 
		 *
		 * @param src The instance to assign to this instance
		 *
		 * @returns The updated instance
		 */
		Value& operator=(const Value& src);

		/**
		 * Assigns an integer to a Value
		 *
		 * @param i The integer to assign to this instance
		 *
		 * @returns The updated instance
		 */
		Value& operator=(int i);

		/**
		 * Assigns a double to a Value
		 *
		 * @param d The double to assign to this instance
		 *
		 * @returns The updated instance
		 */
		Value& operator=(double d);

		/**
		 * Assigns a bool to a Value
		 *
		 * @param b The bool to assign to this instance
		 *
		 * @returns The updated instance
		 */
		Value& operator=(bool b);

		/**
		 * Assigns a character string to a Value
		 *
		 * @param s The char* string to assign to this instance
		 *
		 * @returns The updated instance
		 */
		Value& operator=(const char* s);

		/**
		 * Assigns a string object to a Value
		 *
		 * @param s The std::string to assign to this instance
		 *
		 * @returns The updated instance
		 */
		Value& operator=(const std::string& s);

		/**
		 * Gets the type currently held by the Value
		 *
		 * @returns The ValueType signifying the current type
		 */
		ValueType getType() const;

		/**
		 * Returns the integer value of the Value
		 *
		 * @returns The Value as an integer
		 *
		 * @throws ValueTypeException If the Value is not convertible to an integer
		 */
		int intValue() const;

		/**
		 * Returns the double value of the Value
		 *
		 * @returns The Value as a double
		 *
		 * @throws ValueTypeException If the Value is not convertible to a double
		 */
		double doubleValue() const;

		/**
		 * Returns the Boolean value of the Value
		 *
		 * @returns The Value as a bool
		 *
		 * @throws ValueTypeException If the Value is not convertible to a bool
		 */
		bool boolValue() const;

		/**
		 * Returns the string value of the Value
		 *
		 * @returns The Value as a std::string object
		 */
		std::string stringValue() const;

		/**
		 * Determines whether two Values are equivalent
		 *
		 * @param other The Value to compare this to
		 *
		 * @returns Whether this and other are equivalent
		 */
		bool operator==(const Value& other) const;

		/**
		 * Determines whether two Values are not equivalent
		 *
		 * @param other The Value to compare this to
		 *
		 * @returns Whether this and other are not equivalent
		 */
		bool operator!=(const Value& other) const;

		/**
		 * Determines whether this Value is less than another
		 *
		 * @param other The Value to compare this to
		 *
		 * @returns Whether this is less than other
		 *
		 * @throws ComparisonException If this is not comparable to other
		 */
		bool operator<(const Value& other) const;

		/**
		 * Determines whether this Value is greater than another
		 *
		 * @param other The Value to compare this to
		 *
		 * @returns Whether this is less than other
		 *
		 * @throws ComparisonException If this is not comparable to other
		 */
		bool operator>(const Value& other) const;

		/**
		 * Determines whether this Value is less than or equal to another
		 *
		 * @param other The Value to compare this to
		 *
		 * @returns Whether this is less than or equal to other
		 *
		 * @throws ComparisonException If this is not comparable to other
		 */
		bool operator<=(const Value& other) const;

		/**
		 * Determines whether this Value is greater than or equal to another
		 *
		 * @param other The Value to compare this to
		 *
		 * @returns Whether this is greater than or equal to another
		 *
		 * @throws ComparisonException If this is not comparable to other
		 */
		bool operator>=(const Value& other) const;

		/**
		 * Adds two Values together
		 *
		 * @param other The Value to add to this
		 *
		 * @returns The result of the addition
		 *
		 * @throws OperationException If other cannot be added to this
		 */
		Value operator+(const Value& other) const;

		/**
		 * Subtracts one Value from another
		 *
		 * @param other The Value to subtract from this
		 *
		 * @returns The result of the subtraction
		 *
		 * @throws OperationException If other cannot be subtracted from this
		 */
		Value operator-(const Value& other) const;

		/**
		 * Multiplies two Values together
		 *
		 * @param other The Value to multiply this by
		 *
		 * @returns The result of the multiplication
		 *
		 * @throws OperationException If this cannot be multiplied by other
		 */
		Value operator*(const Value& other) const;

		/**
		 * Divides one Value by another
		 *
		 * @param other The Value to divide this by
		 *
		 * @returns The result of the division
		 *
		 * @throws OperationException If this cannot be divided by other
		 */
		Value operator/(const Value& other) const;

		/**
		 * Calculates one Value modulus another
		 *
		 * @param other The Value to modulate this by
		 *
		 * @returns The result of this modulus other
		 *
		 * @throws OperationException If this cannot be modulated by other
		 */
		Value operator%(const Value& other) const;

		/**
		 * Negates a Value
		 *
		 * @returns The negation of the Value
		 */
		Value operator!() const;


		/**
		 * Swaps two Values in place
		 *
		 * @param other The Value to swap with this
		 */
		void swapWith(Value& other);

		/**
		 * Writes the Value to a stream
		 *
		 * @param os The stream to write to
		 * @param v The Value to write
		 *
		 * @returns The updated stream
		 */
		friend std::ostream& operator<<(std::ostream& os, const Value& v);

		/**
		 * Reads into the Value from a stream
		 *
		 * @param is The stream to read from
		 * @param v The Value to read into
		 *
		 * @returns The updated stream
		 */
		friend std::istream& operator>>(std::istream& is, Value& v);

		/**
		 * Reads a single line from a stream into the Value
		 *
		 * @param is The stream to read from
		 * @param v The Value to read into
		 *
		 * @returns The updated stream
		 */
		friend std::istream& getline(std::istream& is, Value& v);

	//protected fields and methods
	protected:
		//fields
		/**
		 * The variant data for the Value
		 */
		std::variant<int, double, bool, std::string> data;

		/**
		 * The type currently held by the Value
		 */
		ValueType type;
};

//end of header
