/*
 * TokenType.cpp
 * Implements the insertion operator for the TokenType enum
 * Created on 5/29/2020
 * Created by Andrew Davis
 *
 * Copyright (C) 2020  Andrew Davis
 *
 * This program is free software: you can redistribute it and/or modify   
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your optiodn) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

//include
#include "TokenType.h"

//overloaded insertion operator
std::ostream& operator<<(std::ostream& os, TokenType tt) {
	//handle different token types and write their
	//names to the stream
	switch(tt) {
		case TokenType::NUMBER: {
			os << "number";
			break;
		}
		
		case TokenType::STRING: {
			os << "string";
			break;
		}

		case TokenType::PLUS: {
			os << "addition operator";
			break;
		}

		case TokenType::MINUS: {
			os << "subtraction operator";
			break;
		}

		case TokenType::MULTIPLY: {
			os << "multiplication operator";
			break;
		}

		case TokenType::DIVIDE: {
			os << "division operator";
			break;
		}

		case TokenType::MODULUS: {
			os << "modulus operator";
			break;
		}

		case TokenType::LPAREN: {
			os << "left parenthesis";
			break;
		}

		case TokenType::RPAREN: {
			os << "right parenthesis";
			break;
		}

		case TokenType::EOL: {
			os << "end of line";
			break;
		}
	}

	//and return the stream
	return os;
}

//end of implementation
