/*
 * ValueTypeException.h 
 * Declares an exception thrown when a value of the wrong type
 * is requested from a Value
 * Created on 3/19/2020
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
#include "../var/ValueType.h"

/**
 * Thrown when a value of the wrong type 
 * is requested from a Value
 */
class ValueTypeException final : public std::exception {
	//public fields and methods
	public:
		/**
		 * Constructs a new ValueTypeException instance
		 *
		 * @param expected The expected value type
		 * @param actual The actual value type
		 */
		ValueTypeException(ValueType expected, ValueType actual);

		/**
		 * Destructs a ValueTypeException instance
		 */
		~ValueTypeException();

		/**
		 * Copies a ValueTypeException instance
		 *
		 * @param vte The instance to copy
		 */
		ValueTypeException(const ValueTypeException& vte);

		/**
		 * Assigns one ValueTypeException instance to another
		 *
		 * @param src The instance to assign to this instance
		 *
		 * @returns The updated instance
		 */
		ValueTypeException& operator=(const ValueTypeException& src);

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
