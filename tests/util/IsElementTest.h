/*
 * IsElementTest.h 
 * Defines unit tests for the isElement function
 * Created on 5/30/2020
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
#include "../../src/util/isElement.h"
#include <vector>
#include <string>

//use string literals
using namespace std::string_literals;

//test class definition
class IsElementTest : public ::testing::Test {
	protected:

		//Constructor
		IsElementTest()
			: intVec(), strVec()
		{
			//no code needed
		}

		//Called before each test is run
		void SetUp() override {
			for(int i = 1; i <= 5; i++) {
				intVec.push_back(i);
			}
			strVec.push_back("Hello"s);
			strVec.push_back("World"s);
		}

		//fields
		std::vector<int> intVec;
		std::vector<std::string> strVec; 
};

//Tests checking an existing element
TEST_F(IsElementTest, ExistingElement) {
	for(int i = 1; i <= 5; i++) {
		EXPECT_TRUE(isElement(intVec, i));
	}
	EXPECT_TRUE(isElement(strVec, "Hello"s));
	EXPECT_TRUE(isElement(strVec, "World"s));
}

//Tests checking a nonexistent element
TEST_F(IsElementTest, NonexistentElement) {
	EXPECT_FALSE(isElement(intVec, 0));
	EXPECT_FALSE(isElement(intVec, 6));
	EXPECT_FALSE(isElement(strVec, "Salute"s));
	EXPECT_FALSE(isElement(strVec, "Terra"s));
}

//end of tests
