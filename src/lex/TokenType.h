/*
 * TokenType.h 
 * Enumerates types of parser Tokens
 * Created on 5/29/2020
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

//include
#include <iostream>

/**
 * The type of a parser Token
 */
enum class TokenType {
	//data tokens
	
	/**
	 * A number
	 */
	NUMBER,

	/**
	 * A string of text
	 */
	STRING,

	//operator tokens 
	
	/**
	 * An addition sign
	 */
	PLUS,

	/**
	 * A subtraction sign
	 */
	MINUS,

	/**
	 * A multiplication sign
	 */
	MULTIPLY,

	/**
	 * A division sign
	 */
	DIVIDE,

	/**
	 * A modulus sign
	 */
	MODULUS,

	/**
	 * A left parenthesis
	 */
	LPAREN,

	/**
	 * A right parenthesis
	 */
	RPAREN,

	//symbol tokens
	
	/**
	 * The end of a line
	 */
	EOL,
};

/**
 * Writes the TokenType to a stream
 *
 * @param os The stream to write to
 * @param tt The TokenType to write
 *
 * @returns The updated stream
 */
std::ostream& operator<<(std::ostream& os, TokenType tt);

//end of header
