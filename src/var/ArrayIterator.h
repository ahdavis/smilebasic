/*
 * ArrayIterator.h 
 * Declares a class that represents a SmileBASIC array iterator
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

//forward declare the Array class
class Array;

//includes
#include <cstdlib>
#include "Value.h"

/**
 * An iterator for an Array
 */
class ArrayIterator final {
	//public fields and methods
	public:
		/**
		 * Constructs a new ArrayIterator instance
		 *
		 * @param arrayPtr A pointer to the Array to iterate
		 * @param newPos The position in the Array to start iterating at
		 */
		ArrayIterator(Array* arrayPtr, std::size_t newPos);

		/**
		 * Destructs an ArrayIterator instance
		 */
		~ArrayIterator();

		/**
		 * Constructs a copy of an ArrayIterator instance
		 *
		 * @param ai The instance to copy
		 */
		ArrayIterator(const ArrayIterator& ai);

		/**
		 * Assigns one ArrayIterator instance to another
		 *
		 * @param src The instance to assign to this
		 *
		 * @returns The updated instance
		 */
		ArrayIterator& operator=(const ArrayIterator& src);

		/**
		 * Determines whether two ArrayIterator instances 
		 * are not equivalent
		 *
		 * @param other The instance to compare to this
		 *
		 * @returns Whether this is not equivalent to other
		 */
		bool operator!=(const ArrayIterator& other) const;

		/**
		 * Dereferences the iterator
		 *
		 * @returns The current Value being iterated
		 */
		Value& operator*() const;

		/**
		 * Moves the iterator to the next element in the Array
		 *
		 * @returns The updated iterator
		 */
		ArrayIterator& operator++();

	//private fields and methods
	private:
		/**
		 * The Array being iterated
		 */
		Array* arr;

		/**
		 * The current position in the Array
		 */
		std::size_t pos;
};

//end of header
