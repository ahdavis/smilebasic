/*
 * VariableRegistry.h 
 * Declares a singleton that acts as a registry of Variables
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

//include guard
#pragma once 

//includes
#include <string>
#include <map>
#include "Variable.h"

/**
 * A singleton that acts as a registry
 * of Variable instances
 */
class VariableRegistry final {
	//public fields and methods
	public:
		/**
		 * Destructs a VariableRegistry instance
		 */
		~VariableRegistry();

		//delete the copy constructor
		VariableRegistry(const VariableRegistry& vr) = delete;

		//delete the assignment operator
		VariableRegistry& operator=(const VariableRegistry& src) = delete;

		/**
		 * Gets an instance of the registry
		 *
		 * @returns The instance of the singleton
		 */
		static VariableRegistry& getInstance();

		/**
		 * Gets a Variable with a given name
		 *
		 * @param name The name of the desired Variable
		 *
		 * @returns The Variable with the given name
		 *
		 * @throws VarNotRegisteredException If there is no registered Variable with the given name
		 */
		const Variable& getVariable(const std::string& name) const;

		/**
		 * Registers or updates a Variable in the registry
		 *
		 * @param var The Variable to register or update
		 */
		void setVariable(const Variable& var);

		/**
		 * Determines whether a Variable with a given name is registered
		 *
		 * @param name The name to check
		 *
		 * @returns Whether a Variable with the given name is registered
		 */
		bool hasVariable(const std::string& name) const;

	//private fields and methods
	private:
		/**
		 * Constructs a VariableRegistry instance
		 */
		VariableRegistry();

		/**
		 * The Variable database
		 */
		std::map<std::string, Variable> db;
};

//end of header
