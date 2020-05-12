/*
 * TypecheckTest.h 
 * Defines unit tests for the type-checking functions
 * Created on 5/12/2020
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
#include "../../src/util/typecheck.h"
#include <string>

//test class definition
class TypecheckTest : public ::testing::Test {
	protected:

		//Constructor
		TypecheckTest()
			: intStr(), fltStr(), trueStr(), falseStr()
		{
			//no code needed
		}

		//Called before each test is run
		void SetUp() override {
			intStr = "42";
			fltStr = "3.1419";
			trueStr = "true";
			falseStr = "false";
		}

		//fields
		std::string intStr;
		std::string fltStr;
		std::string trueStr;
		std::string falseStr;
};

//Tests checking an int
TEST_F(TypecheckTest, IntCheck) {
	EXPECT_TRUE(checkInt(intStr));
	EXPECT_FALSE(checkInt(fltStr));
	EXPECT_FALSE(checkInt(trueStr));
	EXPECT_FALSE(checkInt(falseStr));
}

//Tests checking a float
TEST_F(TypecheckTest, FloatCheck) {
	EXPECT_FALSE(checkFloat(intStr));
	EXPECT_TRUE(checkFloat(fltStr));
	EXPECT_FALSE(checkFloat(trueStr));
	EXPECT_FALSE(checkFloat(falseStr));
}

//Tests checking a Boolean
TEST_F(TypecheckTest, BoolCheck) {
	EXPECT_FALSE(checkBool(intStr));
	EXPECT_FALSE(checkBool(fltStr));
	EXPECT_TRUE(checkBool(trueStr));
	EXPECT_TRUE(checkBool(falseStr));
}


//end of tests
