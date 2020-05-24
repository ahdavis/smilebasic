/*
 * Variable.h 
 * Declares a class that represents a program variable
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

//include guard
#pragma once 

//includes
#include <string>
#include <iostream>
#include "./Value.h"
#include "./VariableType.h"

/**
 * A scalar program variable
 */
class Variable {
	//public fields and methods
	public:
		/**
		 * Constructs a Variable with a given name
		 * and a value of 0
		 *
		 * @param newName The name of the Variable
		 */
		explicit Variable(const std::string& newName);

		/**
		 * Constructs a Variable with a name and a value
		 *
		 * @param newName The name of the Variable
		 * @param newValue The value of the Variable
		 */
		Variable(const std::string& newName, const Value& newValue);

		/**
		 * Destructs a Variable instance
		 */
		virtual ~Variable();

		/**
		 * Constructs a copy of a Variable instance
		 *
		 * @param v The Variable to copy
		 */
		Variable(const Variable& v);

		/**
		 * Assigns another Variable to this one
		 *
		 * @param src The Variable to assign to this
		 * 
		 * @returns The updated instance
		 */
		Variable& operator=(const Variable& src);

		/**
		 * Gets the name of the Variable
		 *
		 * @returns The name of the Variable
		 */
		const std::string& getName() const;

		/**
		 * Gets the type of the Variable
		 *
		 * @returns The type of the Variable
		 */
		VariableType getType() const;

		/**
		 * Gets the value of the Variable
		 *
		 * @returns The value of the Variable
		 */
		const Value& getValue() const;

		/**
		 * Sets the value of the Variable
		 *
		 * @param newValue The new value of the Variable
		 */
		void setValue(const Value& newValue);

		/**
		 * Swaps the values of two Variables
		 *
		 * @param other The Variable to swap with this
		 */
		void swapWith(Variable& other);

		/**
		 * Determines whether two Variables are equivalent
		 *
		 * @param other The Variable to compare to this
		 *
		 * @returns Whether other is equal to this
		 */
		bool operator==(const Variable& other) const;

		/**
		 * Determines whether two Variables are not equivalent
		 *
		 * @param other The Variable to compare to this
		 *
		 * @returns Whether other is not equal to this
		 */
		bool operator!=(const Variable& other) const;

		/**
		 * Determines whether this Variable is less than another
		 *
		 * @param other The Variable to compare to this
		 *
		 * @returns Whether this is less than other
		 */
		bool operator<(const Variable& other) const;

		/**
		 * Determines whether this Variable is greater than another
		 *
		 * @param other The Variable to compare to this
		 *
		 * @returns Whether this is greater than other
		 */
		bool operator>(const Variable& other) const;

		/**
		 * Determines whether this Variable is less than or equal to another
		 *
		 * @param other The Variable to compare to this
		 *
		 * @returns Whether this is less than or equal to other
		 */
		bool operator<=(const Variable& other) const;

		/**
		 * Determines whether this Variable is greater than or equal to another
		 *
		 * @param other The Variable to compare to this
		 *
		 * @returns Whether this is greater than or equal to other
		 */
		bool operator>=(const Variable& other) const;

		/**
		 * Writes a Variable to a stream
		 *
		 * @param os The stream to write to
		 * @param v The Variable to write
		 *
		 * @returns The updated stream
		 */
		friend std::ostream& operator<<(std::ostream& os, const Variable& v);

		/**
		 * Reads into a Variable from a stream
		 *
		 * @param is The stream to read from
		 * @param v The Variable to read into
		 *
		 * @returns The updated stream
		 */
		friend std::istream& operator>>(std::istream& is, Variable& v);

		/**
		 * Reads a line into a Variable
		 *
		 * @param is The stream to read from
		 * @param v The Variable to read into
		 *
		 * @returns The updated stream
		 */
		friend std::istream& getline(std::istream& is, Variable& v);

	//protected fields and methods
	protected:
		/**
		 * Updates the type of the Variable
		 */
		void updateType();

		/**
		 * The name of the Variable
		 */
		std::string name;

		/**
		 * The value of the Variable
		 */
		Value value;

		/**
		 * The type of the Variable
		 */
		VariableType type;
};

//end of header
