/*
 * VariableRegistryTest.h 
 * Defines unit tests for the VariableRegistry singleton
 * Created on 5/23/2020
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
#include "../../src/var/VariableRegistry.h"
#include "../../src/var/Variable.h"
#include "../../src/except/VarNotRegisteredException.h"

//test class definition
class VariableRegistryTest : public ::testing::Test {
	protected:

		//Constructor
		VariableRegistryTest() 
			: numVar("answer", 42), strVar("name$", "Bob")
		{
			//no code needed
		}

		//Called before each test
		void SetUp() override {
			VariableRegistry::getInstance().setVariable(numVar);
			VariableRegistry::getInstance().setVariable(strVar);
		}

		//fields
		Variable numVar;
		Variable strVar;
};

//Tests retrieving a Variable from the registry
TEST_F(VariableRegistryTest, GetVariable) {
	Variable v = VariableRegistry::getInstance().getVariable(numVar.getName());
	EXPECT_EQ(v, numVar);
}

//Tests setting a Variable in the registry
TEST_F(VariableRegistryTest, SetVariable) {
	Variable otherVar("pi", 3.14);
	VariableRegistry::getInstance().setVariable(otherVar);
	Variable v = VariableRegistry::getInstance().getVariable(otherVar.getName());
	EXPECT_EQ(v, otherVar);
}

//Tests checking whether a Variable exists in the registry
TEST_F(VariableRegistryTest, HasVariable) {
	EXPECT_FALSE(VariableRegistry::getInstance().hasVariable("greeting$"));
	EXPECT_TRUE(VariableRegistry::getInstance().hasVariable("name$"));
}

//Tests that a VarNotRegisteredException is thrown when an invalid name is given
TEST_F(VariableRegistryTest, NotRegisteredException) {
	EXPECT_THROW(VariableRegistry::getInstance().getVariable("unused1"), VarNotRegisteredException);
}

//end of tests
