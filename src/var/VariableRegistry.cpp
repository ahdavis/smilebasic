/*
 * VariableRegistry.cpp
 * Implements a singleton that acts as a registry of Variables
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
#include "VariableRegistry.h"
#include "../except/VarNotRegisteredException.h"

//private constructor
VariableRegistry::VariableRegistry()
	: db() //init the database
{
	//no code needed
}

//destructor
VariableRegistry::~VariableRegistry() {
	//no code needed
}

//copy constructor is deleted

//assignment operator is deleted

//static getInstance method - gets an instance of the singleton
VariableRegistry& VariableRegistry::getInstance() {
	static VariableRegistry instance; //this instance will only be created once
	return instance; //return the instance
}

//getVariable method - gets a registered Variable from the registry
const Variable& VariableRegistry::getVariable(const std::string& name) const {
	//ensure that the given name is valid
	if(!this->hasVariable(name)) { //if the name is invalid
		//then throw an exception
		throw VarNotRegisteredException(name);
	}

	//and return the Variable
	return this->db.at(name);
}

//setVariable method - updates or registers a Variable
void VariableRegistry::setVariable(const Variable& var) {
	this->db.emplace(var.getName(), var); //set the database entry for the Variable
}

//hasVariable method - determines whether a Variable exists in the registry 
bool VariableRegistry::hasVariable(const std::string& name) const {
	return this->db.count(name) != 0;
}

//end of implementation
