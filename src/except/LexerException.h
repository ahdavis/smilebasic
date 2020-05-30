/*
 * LexerException.h 
 * Declares an exception thrown when the SmileBASIC lexer 
 * encounters an unknown character
 * Created on 5/30/2020
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
 * Thrown when a Lexer encounters an unknown character
 */
class LexerException final : public std::exception {
	//public fields and methods
	public:
		/**
		 * Constructs a new LexerException instance
		 *
		 * @param line The line number the unknown character was found on
		 * @param column The column number the unknown character was found on
		 * @param badChar The unknown character
		 */
		LexerException(unsigned int line, unsigned int column, char badChar);

		/**
		 * Destructs a LexerException instance
		 */
		~LexerException();

		/**
		 * Constructs a copy of a LexerException instance
		 *
		 * @param le The instance to copy
		 */
		LexerException(const LexerException& le);

		/**
		 * Assigns one LexerException instance to another
		 *
		 * @param src The instance to assign to this
		 *
		 * @returns The updated instance
		 */
		LexerException& operator=(const LexerException& src);

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
