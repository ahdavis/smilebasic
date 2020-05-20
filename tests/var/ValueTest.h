/*
 * ValueTest.h 
 * Defines unit tests for the Value class
 * Created on 5/20/2020
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
#include <sstream>
#include <iostream>
#include "../../src/var/Value.h"
#include "../../src/var/ValueType.h"

//test class definition
class ValueTest : public ::testing::Test {
	protected:

		//Constructor
		ValueTest()
			: defVal(), intVal(), fltVal(), boolVal(), strVal()
		{
			//no code needed
		}

		//Called before each test is run
		void SetUp() override {
			intVal = 42;
			fltVal = 3.1415;
			boolVal = true;
			strVal = "Hello, World!";
		}

		//fields
		Value defVal;
		Value intVal;
		Value fltVal;
		Value boolVal;
		Value strVal;
};

//Tests that a default-constructed Value has an integer value of 0
TEST_F(ValueTest, DefaultValue) {
	EXPECT_EQ(defVal.getType(), ValueType::INT);
	EXPECT_EQ(defVal.intValue(), 0);
}

//Tests that the type of a value can be checked
TEST_F(ValueTest, TypeCheck) {
	EXPECT_EQ(intVal.getType(), ValueType::INT);
	EXPECT_EQ(fltVal.getType(), ValueType::DOUBLE);
	EXPECT_EQ(boolVal.getType(), ValueType::BOOL);
	EXPECT_EQ(strVal.getType(), ValueType::STRING);
}

//Tests that types are updated when values are assigned
TEST_F(ValueTest, TypeUpdatedOnAssign) {
	Value v = 13;
	EXPECT_EQ(v.getType(), ValueType::INT);
	v = 3.1415;
	EXPECT_EQ(v.getType(), ValueType::DOUBLE);
	v = true;
	EXPECT_EQ(v.getType(), ValueType::BOOL);
	v = "Test String";
	EXPECT_EQ(v.getType(), ValueType::STRING);
}

//Tests retrieving the integer value of a Value
TEST_F(ValueTest, GetIntValue) {
	strVal = "13"; 
	EXPECT_EQ(intVal.intValue(), 42);
	EXPECT_EQ(fltVal.intValue(), 3);
	EXPECT_EQ(boolVal.intValue(), 1);
	boolVal = false;
	EXPECT_EQ(boolVal.intValue(), 0);
	EXPECT_EQ(strVal.intValue(), 13);
}

//Tests retrieving the double value of a Value
TEST_F(ValueTest, GetDoubleValue) {
	strVal = "2.71"; 
	EXPECT_EQ(intVal.doubleValue(), 42.0);
	EXPECT_EQ(fltVal.doubleValue(), 3.1415);
	EXPECT_EQ(boolVal.doubleValue(), 1.0);
	boolVal = false;
	EXPECT_EQ(boolVal.doubleValue(), 0.0);
	EXPECT_EQ(strVal.doubleValue(), 2.71);
}

//Tests retrieving the Boolean value of a Value
TEST_F(ValueTest, GetBoolValue) {
	EXPECT_EQ(intVal.boolValue(), true);
	intVal = 0;
	EXPECT_EQ(intVal.boolValue(), false);
	EXPECT_EQ(fltVal.boolValue(), true);
	fltVal = 0.0;
	EXPECT_EQ(fltVal.boolValue(), false);
	EXPECT_EQ(boolVal.boolValue(), true);
	boolVal = false;
	EXPECT_EQ(boolVal.boolValue(), false);
	strVal = "false";
	EXPECT_EQ(strVal.boolValue(), false);
	strVal = "true";
	EXPECT_EQ(strVal.boolValue(), true);
}

//Tests retrieving the string value of a Value
TEST_F(ValueTest, GetStringValue) { 
	EXPECT_EQ(intVal.stringValue(), "42");
	EXPECT_EQ(fltVal.stringValue(), "3.141500");
	EXPECT_EQ(boolVal.stringValue(), "true");
	boolVal = false;
	EXPECT_EQ(boolVal.stringValue(), "false");
	EXPECT_EQ(strVal.stringValue(), "Hello, World!");
}

//Tests comparing the equality of two Values
TEST_F(ValueTest, EqualValues) {
	//check reflexivity
	EXPECT_TRUE(intVal == intVal);
	EXPECT_TRUE(fltVal == fltVal);
	EXPECT_TRUE(boolVal == boolVal);
	EXPECT_TRUE(strVal == strVal);

	//check int equality
	fltVal = 42.0;
	intVal = 42;
	EXPECT_TRUE(intVal == fltVal);
	EXPECT_TRUE(fltVal == intVal);
	boolVal = true;
	intVal = 1;
	EXPECT_TRUE(intVal == boolVal);
	EXPECT_TRUE(boolVal == intVal);
	intVal = 0;
	boolVal = false;
	EXPECT_TRUE(intVal == boolVal);
	EXPECT_TRUE(boolVal == intVal);
	strVal = "42";
	intVal = 42;
	EXPECT_TRUE(intVal == strVal);
	EXPECT_TRUE(strVal == intVal);

	//check float equality
	fltVal = 1.0;
	boolVal = true;
	EXPECT_TRUE(fltVal == boolVal);
	EXPECT_TRUE(boolVal == fltVal);
	fltVal = 0.0;
	boolVal = false;
	EXPECT_TRUE(fltVal == boolVal);
	EXPECT_TRUE(boolVal == fltVal);
	strVal = "0.000000";
	EXPECT_TRUE(fltVal == strVal);
	EXPECT_TRUE(strVal == fltVal);

	//and check bool equality
	strVal = "true";
	boolVal = true;
	EXPECT_TRUE(boolVal == strVal);
	EXPECT_TRUE(strVal == boolVal);
	strVal = "false";
	boolVal = false;
	EXPECT_TRUE(boolVal == strVal);
	EXPECT_TRUE(strVal == boolVal);
}

//Tests comparing the non-equality of two Values
TEST_F(ValueTest, NonEqualValues) {
	//check reflexivity
	EXPECT_FALSE(intVal != intVal);
	EXPECT_FALSE(fltVal != fltVal);
	EXPECT_FALSE(boolVal != boolVal);
	EXPECT_FALSE(strVal != strVal);

	//check int nonequality
	fltVal = 42.0;
	intVal = 42;
	EXPECT_FALSE(intVal != fltVal);
	EXPECT_FALSE(fltVal != intVal);
	boolVal = true;
	intVal = 1;
	EXPECT_FALSE(intVal != boolVal);
	EXPECT_FALSE(boolVal != intVal);
	intVal = 0;
	boolVal = false;
	EXPECT_FALSE(intVal != boolVal);
	EXPECT_FALSE(boolVal != intVal);
	strVal = "42";
	intVal = 42;
	EXPECT_FALSE(intVal != strVal);
	EXPECT_FALSE(strVal != intVal);

	//check float nonequality
	fltVal = 1.0;
	boolVal = true;
	EXPECT_FALSE(fltVal != boolVal);
	EXPECT_FALSE(boolVal != fltVal);
	fltVal = 0.0;
	boolVal = false;
	EXPECT_FALSE(fltVal != boolVal);
	EXPECT_FALSE(boolVal != fltVal);
	strVal = "0.000000";
	EXPECT_FALSE(fltVal != strVal);
	EXPECT_FALSE(strVal != fltVal);

	//and check bool nonequality
	strVal = "true";
	boolVal = true;
	EXPECT_FALSE(boolVal != strVal);
	EXPECT_FALSE(strVal != boolVal);
	strVal = "false";
	boolVal = false;
	EXPECT_FALSE(boolVal != strVal);
	EXPECT_FALSE(strVal != boolVal);
}

//Tests checking whether a Value is less than another
TEST_F(ValueTest, LessThan) {
	//check comparing ints
	Value lval = 3;
	Value rval = 4;
	EXPECT_TRUE(lval < rval);
	EXPECT_FALSE(rval < lval);
	rval = 4.23;
	EXPECT_TRUE(lval < rval);
	EXPECT_FALSE(rval < lval);
	lval = false;
	rval = 5;
	EXPECT_TRUE(lval < rval);
	EXPECT_FALSE(rval < lval);
	lval = true;
	rval = 2;
	EXPECT_FALSE(rval < lval);

	//check comparing floats
	lval = 4.5;
	rval = 5.2;
	EXPECT_TRUE(lval < rval);
	EXPECT_FALSE(rval < lval);
	lval = false;
	EXPECT_TRUE(lval < rval);
	EXPECT_FALSE(rval < lval);
	lval = true;
	EXPECT_FALSE(rval < lval);

	//check comparing booleans
	lval = false;
	rval = true;
	EXPECT_TRUE(lval < rval);
	EXPECT_FALSE(rval < lval);
	lval = true;
	rval = false;
	EXPECT_FALSE(lval < rval);
	EXPECT_TRUE(rval < lval);

	//check comparing strings
	lval = "apple";
	rval = "bear";
	EXPECT_TRUE(lval < rval);
	EXPECT_FALSE(rval < lval);
}

//Tests checking whether a Value is greater than another
TEST_F(ValueTest, GreaterThan) {
	//check comparing ints
	Value lval = 4;
	Value rval = 3;
	EXPECT_TRUE(lval > rval);
	EXPECT_FALSE(rval > lval);
	lval = 4.23;
	EXPECT_TRUE(lval > rval);
	EXPECT_FALSE(rval > lval);
	rval = false;
	lval = 5;
	EXPECT_TRUE(lval > rval);
	EXPECT_FALSE(rval > lval);
	rval = true;
	lval = 2;
	EXPECT_TRUE(lval > rval);
	EXPECT_FALSE(rval > lval);

	//check comparing floats
	rval = 4.5;
	lval = 5.2;
	EXPECT_TRUE(lval > rval);
	EXPECT_FALSE(rval > lval);
	rval = false;
	EXPECT_TRUE(lval > rval);
	EXPECT_FALSE(rval > lval);
	rval = true;
	EXPECT_TRUE(lval > rval);
	EXPECT_FALSE(rval > lval);

	//check comparing booleans
	rval = false;
	lval = true;
	EXPECT_TRUE(lval > rval);
	EXPECT_FALSE(rval > lval);
	rval = true;
	lval = false;
	EXPECT_FALSE(lval > rval);
	EXPECT_TRUE(rval > lval);

	//check comparing strings
	rval = "apple";
	lval = "bear";
	EXPECT_TRUE(lval > rval);
	EXPECT_FALSE(rval > lval);
}

//Tests checking whether a Value is less than or equal to another
TEST_F(ValueTest, LessThanOrEqualTo) {
	//check comparing ints
	Value lval = 3;
	Value rval = 4;
	EXPECT_TRUE(lval <= rval);
	EXPECT_FALSE(rval <= lval);
	rval = 3;
	EXPECT_TRUE(lval <= rval);
	rval = 4.23;
	EXPECT_TRUE(lval <= rval);
	EXPECT_FALSE(rval <= lval);
	lval = false;
	rval = 5;
	EXPECT_TRUE(lval <= rval);
	EXPECT_FALSE(rval <= lval);
	lval = true;
	rval = 2;
	EXPECT_TRUE(lval <= rval);
	EXPECT_FALSE(rval <= lval);

	//check comparing floats
	lval = 4.5;
	rval = 5.2;
	EXPECT_TRUE(lval <= rval);
	EXPECT_FALSE(rval <= lval);
	rval = 4.5;
	EXPECT_TRUE(lval <= rval);
	lval = false;
	EXPECT_TRUE(lval <= rval);
	EXPECT_FALSE(rval <= lval);
	lval = true;
	EXPECT_TRUE(lval <= rval);
	EXPECT_FALSE(rval <= lval);

	//check comparing booleans
	lval = false;
	rval = true;
	EXPECT_TRUE(lval <= rval);
	EXPECT_FALSE(rval <= lval);
	lval = true;
	rval = false;
	EXPECT_FALSE(lval <= rval);
	EXPECT_TRUE(rval <= lval);
	rval = true;
	EXPECT_TRUE(lval <= rval);

	//check comparing strings
	lval = "apple";
	rval = "bear";
	EXPECT_TRUE(lval <= rval);
	EXPECT_FALSE(rval <= lval);
	rval = "apple";
	EXPECT_TRUE(lval <= rval);
}

//Tests checking whether a Value is greater than or equal to another
TEST_F(ValueTest, GreaterThanOrEqualTo) {
	//check comparing ints
	Value lval = 3;
	Value rval = 4;
	EXPECT_FALSE(lval >= rval);
	EXPECT_TRUE(rval >= lval);
	rval = 3;
	EXPECT_TRUE(lval >= rval);
	rval = 4.23;
	EXPECT_FALSE(lval >= rval);
	EXPECT_TRUE(rval >= lval);
	lval = false;
	rval = 5;
	EXPECT_FALSE(lval >= rval);
	EXPECT_TRUE(rval >= lval);
	lval = true;
	rval = 2;
	EXPECT_TRUE(rval >= lval);

	//check comparing floats
	lval = 4.5;
	rval = 5.2;
	EXPECT_FALSE(lval >= rval);
	EXPECT_TRUE(rval >= lval);
	rval = 4.5;
	EXPECT_TRUE(lval >= rval);
	lval = false;
	EXPECT_FALSE(lval >= rval);
	EXPECT_TRUE(rval >= lval);
	lval = true;
	EXPECT_TRUE(rval >= lval);

	//check comparing booleans
	lval = false;
	rval = true;
	EXPECT_FALSE(lval >= rval);
	EXPECT_TRUE(rval >= lval);
	lval = true;
	rval = false;
	EXPECT_TRUE(lval >= rval);
	EXPECT_FALSE(rval >= lval);
	rval = true;
	EXPECT_TRUE(lval >= rval);

	//check comparing strings
	lval = "apple";
	rval = "bear";
	EXPECT_FALSE(lval >= rval);
	EXPECT_TRUE(rval >= lval);
	rval = "apple";
	EXPECT_TRUE(lval >= rval);
}

//Tests the addition operator
TEST_F(ValueTest, AddOperator) {
	Value v1 = 4;
	Value v2 = 5;
	EXPECT_EQ(v1 + v2, 9);
	v1 = 3.4;
	v2 = 5.7;
	EXPECT_EQ(v1 + v2, 9.1);
	v2 = 2;
	EXPECT_EQ(v1 + v2, 5.4);
	v1 = "Hello ";
	v2 = "World!";
	EXPECT_EQ(v1 + v2, "Hello World!");
}

//Tests the subtraction operator
TEST_F(ValueTest, SubtractOperator) {
	Value v1 = 4;
	Value v2 = 5;
	EXPECT_EQ(v1 - v2, -1);
	v1 = 3.4;
	v2 = 2.3;
	EXPECT_EQ(v1 - v2, 1.1);
	v2 = 2;
	EXPECT_EQ(v1 - v2, 1.4);
}

//Tests the multiplication operator
TEST_F(ValueTest, MultiplyOperator) {
	Value v1 = 4;
	Value v2 = 5;
	EXPECT_EQ(v1 * v2, 20);
	v1 = 2.5;
	v2 = 4.3;
	EXPECT_EQ(v1 * v2, 10.75);
	v2 = 2;
	EXPECT_EQ(v1 * v2, 5.0);
	v2 = 3;
	v1 = "*";
	EXPECT_EQ(v1 * v2, "***");
	v2 = 0;
	EXPECT_EQ(v1 * v2, "");
}

//Tests the division operator
TEST_F(ValueTest, DivideOperator) {
	Value v1 = 5;
	Value v2 = 4;
	EXPECT_EQ(v1 / v2, 1);
	EXPECT_EQ(v2 / v1, 0);
	v1 = 2.5;
	v2 = 0.5;
	EXPECT_EQ(v1 / v2, 5.0);
	v2 = 2;
	EXPECT_EQ(v1 / v2, 1.25); 
}

//Tests the modulus operator
TEST_F(ValueTest, ModulusOperator) {
	Value v1 = 6;
	Value v2 = 4;
	EXPECT_EQ(v1 % v2, 2);
	v1 = 5.625;
	v2 = 0.25;
	EXPECT_EQ(v1 % v2, 0.125);
	v1 = 5.25;
	v2 = 2;
	EXPECT_EQ(v1 % v2, 1.25);
}

//Tests the negation operator
TEST_F(ValueTest, NegateOperator) {
	Value vTrue = 1;
	Value vFalse = 0;
	ASSERT_FALSE(!vTrue == true);
	ASSERT_TRUE(!vFalse == true);
	vTrue = 4.5;
	vFalse = 0.0;
	ASSERT_FALSE(!vTrue == true);
	ASSERT_TRUE(!vFalse == true);
	vTrue = true;
	vFalse = false;
	ASSERT_FALSE(!vTrue == true);
	ASSERT_TRUE(!vFalse == true);
	vTrue = "true";
	vFalse = "false";
	ASSERT_FALSE(!vTrue == true);
	ASSERT_TRUE(!vFalse == true);
}

//Tests the swapWith method
TEST_F(ValueTest, SwapWith) {
	Value v1 = 42;
	Value v2 = 3.1415;
	Value v1Copy = v1;
	Value v2Copy = v2;
	ASSERT_EQ(v1, v1Copy);
	ASSERT_EQ(v2, v2Copy);
	ASSERT_EQ(v1.getType(), ValueType::INT);
	ASSERT_EQ(v2.getType(), ValueType::DOUBLE);
	v1.swapWith(v2);
	ASSERT_EQ(v1, v2Copy);
	ASSERT_EQ(v2, v1Copy);
	ASSERT_EQ(v1.getType(), ValueType::DOUBLE);
	ASSERT_EQ(v2.getType(), ValueType::INT);
}

//Tests the insertion operator
TEST_F(ValueTest, InsertionOperator) {
	std::stringstream ss;
	Value v = 42;
	ss << v;
	ASSERT_EQ(ss.str(), "42");
	ss.str("");
	v = 3.1415;
	ss << v;
	ASSERT_EQ(ss.str(), "3.1415");
	ss.str("");
	v = true;
	ss << v;
	ASSERT_EQ(ss.str(), "true");
	ss.str("");
	v = false;
	ss << v;
	ASSERT_EQ(ss.str(), "false");
	ss.str("");
	v = "Hello, World!";
	ss << v;
	ASSERT_EQ(ss.str(), "Hello, World!");
}

//Tests the extraction operator
TEST_F(ValueTest, ExtractionOperator) {
	std::stringstream ss;
	Value v;
	ss << 42;
	ss >> v;
	ASSERT_EQ(v, 42);
	ASSERT_EQ(v.getType(), ValueType::INT);
	ss.clear();
	ss << 3.1415;
	ss >> v;
	ASSERT_EQ(v, 3.1415);
	ASSERT_EQ(v.getType(), ValueType::DOUBLE);
	ss.clear();
	ss << std::boolalpha << true;
	ss >> v;
	ASSERT_EQ(v, true);
	ASSERT_EQ(v.getType(), ValueType::BOOL);
	ss.clear();
	ss << std::boolalpha << false;
	ss >> v;
	ASSERT_EQ(v, false);
	ASSERT_EQ(v.getType(), ValueType::BOOL);
	ss.clear();
	ss << "Test";
	ss >> v;
	ASSERT_EQ(v, "Test");
	ASSERT_EQ(v.getType(), ValueType::STRING);
}

//Tests the getline function
TEST_F(ValueTest, GetLine) {
	std::stringstream ss;
	Value v;
	ss << 42;
	getline(ss, v);
	ASSERT_EQ(v, 42);
	ASSERT_EQ(v.getType(), ValueType::INT);
	ss.clear();
	ss << 3.1415;
	getline(ss, v);
	ASSERT_EQ(v, 3.1415);
	ASSERT_EQ(v.getType(), ValueType::DOUBLE);
	ss.clear();
	ss << std::boolalpha << true;
	getline(ss, v);
	ASSERT_EQ(v, true);
	ASSERT_EQ(v.getType(), ValueType::BOOL);
	ss.clear();
	ss << std::boolalpha << false;
	getline(ss, v);
	ASSERT_EQ(v, false);
	ASSERT_EQ(v.getType(), ValueType::BOOL);
	ss.clear();
	ss << "Hello, World!";
	getline(ss, v);
	ASSERT_EQ(v, "Hello, World!");
	ASSERT_EQ(v.getType(), ValueType::STRING);
}

//end of tests
