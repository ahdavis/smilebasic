/*
 * isElement.cpp
 * Implements a function that determines whether a given value is an element of a vector
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
#include <vector>
#include <algorithm>

//isElement function - determines whether a value exists in a vector
template<typename T>
bool isElement(const std::vector<T>& vec, const T& val) {
	//determine whether the vector contains the value
	if(std::find(vec.begin(), vec.end(), val) != vec.end()) { //if the value was found
		return true; //then return true
	} else { //if the value was not found
		return false; //then return false
	}
}

//end of implementation
