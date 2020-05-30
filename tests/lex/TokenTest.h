/*
 * TokenTest.h 
 * Defines unit tests for the Token class
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

//includes
#include <gtest/gtest.h>
#include "../../src/lex/Token.h"
#include "../../src/lex/TokenType.h"

//test class definition
class TokenTest : public ::testing::Test {
	protected:

		//Constructor
		TokenTest()
			: eolToken(Token::EOLToken)
		{
			//no code needed
		}

		//field
		Token eolToken;
};

//Tests that an EOL Token has the proper type
TEST_F(TokenTest, EOLTokenType) {
	EXPECT_EQ(eolToken.getType(), TokenType::EOL);
}

//Tests that an EOL Token has the proper value
TEST_F(TokenTest, EOLTokenValue) {
	EXPECT_EQ(eolToken.getValue(), "");
}

//end of tests
