/*
 * typecheck.cpp
 * Implements functions that check strings for given types
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
#include "typecheck.h"
#include <regex>

//constant strings that contain regexes
const std::string regexInt = "^(\\+|-)?[0-9]+$"; //matches int
const std::string regexFloat = "[\\+-]?([0-9]*)?[.][0-9]+$"; //matches float

//checkInt function - checks for an integer
bool checkInt(const std::string& val) {
	std::regex intRegex(regexInt); //get a regex to match an integer
	return std::regex_match(val, intRegex); //and return the match
}

//checkFloat function - checks for a float
bool checkFloat(const std::string& val) {
	std::regex floatRegex(regexFloat); //get a regex to match a float
	return std::regex_match(val, floatRegex); //and return the match
}

//checkBool function - checks for a boolean
bool checkBool(const std::string& val) {
	return (val == "TRUE") || (val == "FALSE");
}

//end of implementation
