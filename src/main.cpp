/*
 * main.cpp
 * Entry point for SmileBASIC
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

//includes
#include <iostream>
#include <cstdlib>
#include "./util/constants.h"

/**
 * Main entry point for SmileBASIC
 *
 * @param argc The number of arguments to the interpreter
 * @param argv The actual arguments to the interpreter
 *
 * @returns The exit code of the program
 */
int main(int argc, char* argv[]) {
	//display a greeting
	std::cout << "Welcome to "
		<< Constants::PROG_NAME 
		<< " v"
		<< Constants::VERSION 
		<< "!"
		<< std::endl;

	//display a temporary message
	std::cout << Constants::PROG_NAME << " is under construction." << std::endl;
	std::cout << "Check back later for more features!" << std::endl;

	//and return with no errors
	return EXIT_SUCCESS;
}

//end of program
