/*
 * main.cpp
 * Entry point for SmileBASIC's unit tests
 * Created on 3/19/2020
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

//include GoogleTest
#include <gtest/gtest.h>

//include test suites
#include "./var/ValueStreamVisitorTest.h"
#include "./util/TypecheckTest.h"

//main function - main entry point for the test suite
int main(int argc, char* argv[]) {
	::testing::InitGoogleTest(&argc, argv); //init GoogleTest
	return RUN_ALL_TESTS(); // and run the tests
}

//end of file
