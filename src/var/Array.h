/*
 * Array.h 
 * Declares a class that represents a SmileBASIC array
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

//include guard
#pragma once 

//includes
#include <vector>
#include <cstdlib>
#include "Value.h"
#include "VariableType.h"
#include "Variable.h"
#include "ArrayIterator.h"

/**
 * A SmileBASIC array
 */
class Array {
	//public fields and methods
	public:
		/**
		 * Constructs a new Array instance
		 *
		 * @param newSize The maximum number of Values in the Array
		 * @param newType The type of the Array 
		 */
		Array(std::size_t newSize, VariableType newType);

		/**
		 * Destructs an Array instance
		 */
		virtual ~Array();

		/**
		 * Constructs a copy of an Array instance
		 *
		 * @param a The instance to copy
		 */
		Array(const Array& a);

		/**
		 * Assigns one Array instance to another
		 *
		 * @param src The instance to assign to this
		 *
		 * @returns The updated instance
		 */
		Array& operator=(const Array& src);

		/**
		 * Gets the size of the Array
		 *
		 * @returns The size of the Array
		 */
		std::size_t getSize() const;

		/**
		 * Gets the type of the Array
		 *
		 * @returns The type of the Array
		 */
		VariableType getType() const;

		/**
		 * Accesses the Value at a given index in the Array
		 *
		 * @param idxVal A Value containing the index to access
		 *
		 * @returns A reference to the Value at the given index
		 *
		 * @throws ArrayIndexOutOfRangeException If an out-of-range index is given
		 */
		Value& operator[](const Value& idxVal);

		/**
		 * Accesses the Value at a given index in the Array
		 *
		 * @param idxVar A Variable containing the index to access
		 *
		 * @returns A reference to the Value at the given index
		 *
		 * @throws ArrayIndexOutOfRangeException If an out-of-range index is given
		 */
		Value& operator[](const Variable& idxVar);

		/**
		 * Accesses the Value at a given index in the Array
		 *
		 * @param idx The index to access
		 *
		 * @returns A reference to the Value at the given index
		 *
		 * @throws ArrayIndexOutOfRangeException If an out-of-range index is given
		 */
		Value& operator[](std::size_t idx);

		/**
		 * Iterates from the start of the Array
		 *
		 * @returns An ArrayIterator pointing to the start of the Array
		 */
		ArrayIterator begin();

		/**
		 * Iterates from the end of the Array
		 *
		 * @returns An ArrayIterator pointing to the end of the Array
		 */
		ArrayIterator end();

	//protected fields and methods
	protected:
		/**
		 * The array data
		 */
		std::vector<Value> data;

		/**
		 * The size of the Array
		 */
		std::size_t size;

		/**
		 * The type of the Array
		 */
		VariableType type;
};

//end of header
