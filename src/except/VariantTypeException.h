/*
 * VariantTypeException.h 
 * Declares an exception thrown when a value of the wrong type
 * is requested from a Variant
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

/**
 * Thrown when a value of the wrong type 
 * is requested from a Variant
 */
class VariantTypeException final : public std::exception {
	//public fields and methods
	public:
		/**
		 * Constructs a new VariantTypeException instance
		 *
		 * @param expected The name of the expected variant type
		 * @param actual The name of the actual variant type
		 */
		VariantTypeException(const std::string& expected,
					const std::string& actual);

		/**
		 * Destructs a VariantTypeException instance
		 */
		~VariantTypeException();

		/**
		 * Copies a VariantTypeException instance
		 *
		 * @param vte The instance to copy
		 */
		VariantTypeException(const VariantTypeException& vte);

		/**
		 * Assigns one VariantTypeException instance to another
		 *
		 * @param src The instance to assign to this instance
		 *
		 * @returns The updated instance
		 */
		VariantTypeException& operator=(const VariantTypeException& src);

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
