/*
 * ArrayRegistryTest.h 
 * Defines unit tests for the ArrayRegistry singleton
 * Created on 5/28/2020
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
#include "../../src/var/ArrayRegistry.h"
#include "../../src/var/Array.h"
#include "../../src/var/VariableType.h"
#include "../../src/except/ArrayNotRegisteredException.h"

//test class definition
class ArrayRegistryTest : public ::testing::Test {
	protected:

		//Constructor
		ArrayRegistryTest() 
			: numArr("answers", 10, VariableType::NUMBER), strArr("names$", 5, VariableType::STRING)
		{
			//no code needed
		}

		//Called before each test
		void SetUp() override {
			ArrayRegistry::getInstance().setArray(numArr);
			ArrayRegistry::getInstance().setArray(strArr);
		}

		//fields
		Array numArr;
		Array strArr;
};

//Tests retrieving a Array from the registry
TEST_F(ArrayRegistryTest, GetArray) {
	Array a = ArrayRegistry::getInstance().getArray(numArr.getName());
	EXPECT_EQ(a.getSize(), numArr.getSize());
	EXPECT_EQ(a.getName(), numArr.getName());
	EXPECT_EQ(a.getType(), numArr.getType());
}

//Tests setting a Array in the registry
TEST_F(ArrayRegistryTest, SetArray) {
	Array otherArr("mathConstants", 5, VariableType::NUMBER);
	ArrayRegistry::getInstance().setArray(otherArr);
	Array a = ArrayRegistry::getInstance().getArray(otherArr.getName());
	EXPECT_EQ(a.getSize(), otherArr.getSize());
	EXPECT_EQ(a.getName(), otherArr.getName());
	EXPECT_EQ(a.getType(), otherArr.getType());
}

//Tests checking whether a Array exists in the registry
TEST_F(ArrayRegistryTest, HasArray) {
	EXPECT_FALSE(ArrayRegistry::getInstance().hasArray("greetings$"));
	EXPECT_TRUE(ArrayRegistry::getInstance().hasArray("names$"));
}

//Tests that an ArrayNotRegisteredException is thrown when an invalid name is given
TEST_F(ArrayRegistryTest, NotRegisteredException) {
	EXPECT_THROW(ArrayRegistry::getInstance().getArray("unused1"), ArrayNotRegisteredException);
}

//end of tests
