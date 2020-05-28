/*
 * ArrayNotRegisteredException.h 
 * Declares an exception thrown when a non-registered Array
 * is requested from the array registry
 * Created on 5/28/2020
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

/**
 * Thrown when the array registry does not 
 * contain a requested Array
 */
class ArrayNotRegisteredException final : public std::exception {
	//public fields and methods
	public:

		/**
		 * Constructs a new ArrayNotRegisteredException instance
		 *
		 * @param arrName The name of the requested array
		 */
		explicit ArrayNotRegisteredException(const std::string& arrName);

		/**
		 * Destructs an ArrayNotRegisteredException instance
		 */
		~ArrayNotRegisteredException();

		/**
		 * Constructs a copy of an ArrayNotRegisteredException instance
		 *
		 * @param anre The instance to copy
		 */
		ArrayNotRegisteredException(const ArrayNotRegisteredException& anre);

		/**
		 * Assigns one ArrayNotRegisteredException instance to another
		 *
		 * @param src The instance to assign to this
		 *
		 * @returns The updated instance
		 */
		ArrayNotRegisteredException& operator=(const ArrayNotRegisteredException& src);

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
