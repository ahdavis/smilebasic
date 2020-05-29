/*
 * ArrayRegistry.cpp
 * Implements a singleton that acts as a registry of Arrays
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
#include "ArrayRegistry.h"
#include "../except/ArrayNotRegisteredException.h"

//private constructor
ArrayRegistry::ArrayRegistry()
	: db() //init the database
{
	//no code needed
}

//destructor
ArrayRegistry::~ArrayRegistry() {
	//no code needed
}

//copy constructor is deleted

//assignment operator is deleted

//static getInstance method - gets an instance of the singleton
ArrayRegistry& ArrayRegistry::getInstance() {
	static ArrayRegistry instance; //this instance will only be created once
	return instance; //return the instance
}

//getArray method - gets a registered Array from the registry
const Array& ArrayRegistry::getArray(const std::string& name) const {
	//ensure that the given name is valid
	if(!this->hasArray(name)) { //if the name is invalid
		//then throw an exception
		throw ArrayNotRegisteredException(name);
	}

	//and return the Array
	return this->db.at(name);
}

//setArray method - updates or registers an Array
void ArrayRegistry::setArray(const Array& arr) {
	this->db.insert_or_assign(arr.getName(), arr); //set the database entry for the Array
}

//hasArray method - determines whether an Array exists in the registry 
bool ArrayRegistry::hasArray(const std::string& name) const {
	return this->db.count(name) != 0;
}

//end of implementation
