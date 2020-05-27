/*
 * ArrayTest.h 
 * Defines unit tests for the Array class
 * Created on 5/27/2020
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
#include <cstdlib>
#include "../../src/var/Array.h"
#include "../../src/var/ArrayIterator.h"
#include "../../src/var/VariableType.h"
#include "../../src/var/Value.h"
#include "../../src/var/Variable.h"
#include "../../src/except/ArrayIndexOutOfRangeException.h"

//test class definition
class ArrayTest : public ::testing::Test {
	protected:

		//Constructor
		ArrayTest()
			: numArray(10, VariableType::NUMBER), strArray(2, VariableType::STRING) //init the fields 
		{
			//no code needed
		}

		//Called before each test
		void SetUp() override {
			//init the number array
			int i = 1;
			for(Value& v : numArray) {
				v = i++;
			}

			//init the string array
			strArray[0] = "Salute";
			strArray[1] = "Terra";
		}

		//fields
		Array numArray;
		Array strArray;
};

//Tests the default filler values in an array
TEST_F(ArrayTest, DefaultValues) {
	Array numArray2(10, VariableType::NUMBER);
	Array strArray2(5, VariableType::STRING);
	for(int i = 0; i < numArray2.getSize(); i++) {
		EXPECT_EQ(numArray2[i], 0);
	}
	for(int i = 0; i < strArray2.getSize(); i++) {
		EXPECT_EQ(strArray2[i], "");
	}
}

//Tests subscripting with a Value index
TEST_F(ArrayTest, ValueSubscript) {
	Value v = 0;

	//test getting the array element
	EXPECT_EQ(numArray[v], 1);
	EXPECT_EQ(strArray[v], "Salute");

	//then test setting it
	numArray[v] = 0;
	strArray[v] = "Hello";
	EXPECT_EQ(numArray[v], 0);
	EXPECT_EQ(strArray[v], "Hello");
}

//Tests subscripting with a Variable index
TEST_F(ArrayTest, VariableSubscript) {
	Variable v("idx", 1);

	//test getting the array element
	EXPECT_EQ(numArray[v], 2);
	EXPECT_EQ(strArray[v], "Terra");

	//then test setting it
	numArray[v] = 1;
	strArray[v] = "World";
	EXPECT_EQ(numArray[v], 1);
	EXPECT_EQ(strArray[v], "World"); 
}

//Tests subscripting with an int index
TEST_F(ArrayTest, IntSubscript) {
	std::size_t i = 0;

	//test getting the array element
	EXPECT_EQ(numArray[i], 1);
	EXPECT_EQ(strArray[i], "Salute");

	//then test setting it
	numArray[i] = 5;
	strArray[i] = "Test";
	EXPECT_EQ(numArray[i], 5);
	EXPECT_EQ(strArray[i], "Test");
}

//Tests out of range indexes
TEST_F(ArrayTest, OutOfRangeIndex) {
	EXPECT_THROW(Value v = numArray[10], ArrayIndexOutOfRangeException);
}

//Tests iterating through an array
TEST_F(ArrayTest, Iterator) {
	//test reading from the iterator
	int i = 1;
	ArrayIterator iter = numArray.begin();
	for(;iter != numArray.end(); ++iter) {
		EXPECT_NE(iter, numArray.end());
		EXPECT_EQ(*iter, i);
		i++;
	}
	EXPECT_FALSE(iter != numArray.end());

	//then test setting via the iterator
	iter = numArray.begin();
	++iter;
	*iter = 42;
	EXPECT_EQ(numArray[1], 42);
}

//end of tests 
