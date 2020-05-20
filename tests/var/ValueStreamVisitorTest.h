/*
 * ValueStreamVisitorTest.h 
 * Defines unit tests for the ValueStreamVisitor class
 * Created on 5/9/2020
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
#include "../../src/var/ValueStreamVisitor.h"
#include <variant>
#include <string>
#include <sstream>

//using statement
using namespace std::string_literals;

//test class definition
class ValueStreamVisitorTest : public ::testing::Test {
	protected:

		//Constructor
		ValueStreamVisitorTest()
			: _ss(), _var() //init the fields 
		{
			//no code needed
		}

		//fields
		std::stringstream _ss; //the stream to write to
		std::variant<int, double, bool, std::string> _var; //the variant to stream 
};

//Tests visiting an int
TEST_F(ValueStreamVisitorTest, VisitInt) {
	_var = 13;
	std::visit(ValueStreamVisitor(_ss), _var);
	EXPECT_EQ(_ss.str(), "13");
}

//Tests visiting a double
TEST_F(ValueStreamVisitorTest, VisitDouble) {
	_var = 3.14;
	std::visit(ValueStreamVisitor(_ss), _var);
	EXPECT_EQ(_ss.str(), "3.14");
}

//Tests visiting a bool
TEST_F(ValueStreamVisitorTest, VisitBool) {
	_var = true;
	std::visit(ValueStreamVisitor(_ss), _var);
	EXPECT_EQ(_ss.str(), "true");
}

//Tests visiting a string
TEST_F(ValueStreamVisitorTest, VisitString) {
	_var = "Hello, World!"s;
	std::visit(ValueStreamVisitor(_ss), _var);
	EXPECT_EQ(_ss.str(), "Hello, World!");
}

//end of tests
