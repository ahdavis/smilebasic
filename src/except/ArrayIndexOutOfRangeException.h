/*
 * ArrayIndexOutOfRangeException.h 
 * Declares an exception thrown when an array index is out of range
 * Created on 5/24/2020
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
#include <exception>
#include <string>
#include <cstdlib>

/**
 * Thrown when an Array index is out of range
 */
class ArrayIndexOutOfRangeException final : public std::exception {
	//public fields and methods
	public:
		/**
		 * Constructs a new ArrayIndexOutOfRangeException instance
		 *
		 * @param badIdx The out of range index
		 * @param arraySize The size of the Array
		 */
		ArrayIndexOutOfRangeException(std::size_t badIdx, std::size_t arraySize);

		/**
		 * Destructs an ArrayIndexOutOfRangeException instance
		 */
		~ArrayIndexOutOfRangeException();

		/**
		 * Constructs a copy of an ArrayIndexOutOfRangeException instance
		 *
		 * @param exc The ArrayIndexOutOfRangeException instance to copy
		 */
		ArrayIndexOutOfRangeException(const ArrayIndexOutOfRangeException& exc);

		/**
		 * Assigns one ArrayIndexOutOfRangeException to another
		 *
		 * @param src The instance to assign to this
		 *
		 * @returns The updated instance
		 */
		ArrayIndexOutOfRangeException& operator=(const ArrayIndexOutOfRangeException& src);

		/**
		 * Called when the exception is thrown
		 *
		 * @returns The error message
		 */
		const char* what() const throw() override;

	//private fields and methods
	private:
		/**
		 * The error message
		 */
		std::string errMsg;
};

//end of header
