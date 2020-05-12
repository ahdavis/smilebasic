/*
 * OperationException.h 
 * Declares an exception thrown when a symbolic operation is attempted
 * between incompatible values
 * Created on 5/11/2020
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
#include "../var/Value.h"

/**
 * Thrown when a symbolic operation is attempted between
 * incompatible Values
 */
class OperationException final : public std::exception {
	//public fields and methods
	public:
		/**
		 * Constructs a new OperationException instance
		 *
		 * @param lhs The left hand side of the bad operation
		 * @param rhs The right hand side of the bad operation
		 * @param opSym The symbol for the operation that was attempted
		 */
		OperationException(const Value& lhs, const Value& rhs, char opSym);

		/**
		 * Destructs an OperationException instance
		 */
		~OperationException();

		/**
		 * Copies an OperationException instance
		 *
		 * @param oe The instance to copy
		 */
		OperationException(const OperationException& oe);

		/**
		 * Assigns one OperationException instance to another
		 *
		 * @param src The instance to assign to this
		 *
		 * @returns The updated instance
		 */
		OperationException& operator=(const OperationException& src);

		/**
		 * Called when the exception is thrown
		 *
		 * @returns The error message
		 */
		const char* what() const throw() override;

	//private fields and methods
	private:
		//field
		/**
		 * The error message
		 */
		std::string errMsg;
};

//end of file
