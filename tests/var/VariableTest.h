/*
 * VariableTest.h 
 * Defines unit tests for the Variable class
 * Created on 5/22/2020
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
#include "../../src/var/Variable.h"
#include "../../src/var/VariableType.h"
#include <sstream>

//test class definition
class VariableTest : public ::testing::Test {
	protected:

		//Constructor
		VariableTest()
			: numVar("answer", 42), strVar("greeting$", "Hello!") //init the fields 
		{
			//no code needed
		}

		//fields
		Variable numVar;
		Variable strVar;
};

//Tests that variable types are set correctly
TEST_F(VariableTest, CorrectTypes) {
	EXPECT_EQ(numVar.getType(), VariableType::NUMBER);
	EXPECT_EQ(strVar.getType(), VariableType::STRING);
	Variable otherVar("other", 13);
	EXPECT_EQ(otherVar.getType(), VariableType::NUMBER);
	otherVar.setValue("Hello, World!");
	EXPECT_EQ(otherVar.getType(), VariableType::STRING);
}

//Tests that variables of different types are always non-equivalent
TEST_F(VariableTest, DifferentTypesNotEqual) {
	strVar.setValue("42");
	EXPECT_FALSE(numVar == strVar);
	EXPECT_TRUE(numVar != strVar);
}

//Tests the == operator
TEST_F(VariableTest, Equals) {
	EXPECT_EQ(numVar, numVar);
	EXPECT_EQ(strVar, strVar);
}

//Tests the != operator
TEST_F(VariableTest, NotEquals) {
	Variable numVar2("pi", 3.14);
	Variable strVar2("greeting2$", "Salute!");
	EXPECT_NE(numVar, numVar2);
	EXPECT_NE(numVar2, numVar);
	EXPECT_NE(strVar, strVar2);
	EXPECT_NE(strVar2, strVar);
}

//Tests the < operator
TEST_F(VariableTest, LessThan) {
	Variable numVar2("thirty", 30);
	Variable apple("apple$", "Apple");
	EXPECT_LT(numVar2, numVar);
	EXPECT_LT(apple, strVar);
}

//Tests the > operator
TEST_F(VariableTest, GreaterThan) {
	Variable numVar2("eighty", 80);
	Variable pie("pie$", "Pie");
	EXPECT_GT(numVar2, numVar);
	EXPECT_GT(pie, strVar);
}

//Tests the <= operator
TEST_F(VariableTest, LessThanOrEqualTo) {
	Variable numVar2("thirty", 30);
	Variable apple("apple$", "Apple");
	EXPECT_LE(numVar2, numVar);
	EXPECT_LE(numVar, numVar);
	EXPECT_LE(apple, strVar);
	EXPECT_LE(strVar, strVar);
}

//Tests the >= operator
TEST_F(VariableTest, GreaterThanOrEqualTo) {
	Variable numVar2("eighty", 80);
	Variable pie("pie$", "Pie");
	EXPECT_GE(numVar2, numVar);
	EXPECT_GE(numVar, numVar);
	EXPECT_GE(pie, strVar);
	EXPECT_GE(strVar, strVar);
}

//Tests the insertion operator
TEST_F(VariableTest, InsertionOperator) {
	std::stringstream ss;
	ss << numVar;
	EXPECT_EQ(ss.str(), "42");
	ss.str("");
	ss << strVar;
	EXPECT_EQ(ss.str(), "Hello!");
}

//Tests the extraction operator
TEST_F(VariableTest, ExtractionOperator) {
	std::stringstream ss;
	ss << 13;
	ss >> numVar;
	EXPECT_EQ(numVar.getValue().intValue(), 13);
	ss.clear();
	ss << "Hi!";
	ss >> strVar;
	EXPECT_EQ(strVar.getValue().stringValue(), "Hi!");
}

//Tests the getline function
TEST_F(VariableTest, GetLine) {
	std::stringstream ss;
	ss << 13;
	getline(ss, numVar);
	EXPECT_EQ(numVar.getValue().intValue(), 13);
	ss.clear();
	ss << "Hi there!";
	getline(ss, strVar);
	EXPECT_EQ(strVar.getValue().stringValue(), "Hi there!");
}

//end of tests
