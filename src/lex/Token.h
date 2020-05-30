/*
 * Token.h 
 * Declares a class that represents a parser token
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

//includes
#include "TokenType.h"
#include "../var/Value.h"

/**
 * A parser token
 */
class Token {
	//public fields and methods
	public:
		/**
		 * A special Token that signifies the end 
		 * of a line of code
		 */
		static const Token EOLToken;

		/**
		 * Constructs a Token instance
		 *
		 * @param newType The type of the Token
		 * @param newValue The value of the Token
		 */
		Token(TokenType newType, const Value& newValue);

		/**
		 * Destructs a Token instance
		 */
		virtual ~Token();

		/**
		 * Constructs a copy of a Token instance
		 *
		 * @param t The Token to copy
		 */
		Token(const Token& t);

		/**
		 * Assigns one Token to another
		 *
		 * @param src The instance to assign to this
		 *
		 * @returns The updated instance
		 */
		Token& operator=(const Token& src);

		/**
		 * Gets the type of the Token
		 *
		 * @returns The type of the Token
		 */
		TokenType getType() const;

		/**
		 * Gets the value of the Token
		 *
		 * @returns The value of the Token
		 */
		const Value& getValue() const;

	//protected fields and methods
	protected:
		/**
		 * The type of the Token
		 */
		TokenType type;

		/**
		 * The value of the Token
		 */
		Value value;
};

//end of header
