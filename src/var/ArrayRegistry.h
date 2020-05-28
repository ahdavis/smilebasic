/*
 * ArrayRegistry.h 
 * Declares a singleton that acts as a registry of Arrays
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

//include guard
#pragma once 

//includes
#include <string>
#include <map>
#include "Array.h"

/**
 * A singleton that acts as a registry
 * of Array instances
 */
class ArrayRegistry final {
	//public fields and methods
	public:
		/**
		 * Destructs an ArrayRegistry instance
		 */
		~ArrayRegistry();

		//delete the copy constructor
		ArrayRegistry(const ArrayRegistry& vr) = delete;

		//delete the assignment operator
		ArrayRegistry& operator=(const ArrayRegistry& src) = delete;

		/**
		 * Gets an instance of the registry
		 *
		 * @returns The instance of the singleton
		 */
		static ArrayRegistry& getInstance();

		/**
		 * Gets an Array with a given name
		 *
		 * @param name The name of the desired Array
		 *
		 * @returns The Array with the given name
		 *
		 * @throws ArrayNotRegisteredException If there is no registered Array with the given name
		 */
		const Array& getArray(const std::string& name) const;

		/**
		 * Registers or updates an Array in the registry
		 *
		 * @param arr The Array to register or update
		 */
		void setArray(const Array& arr);

		/**
		 * Determines whether an Array with a given name is registered
		 *
		 * @param name The name to check
		 *
		 * @returns Whether an Array with the given name is registered
		 */
		bool hasArray(const std::string& name) const;

	//private fields and methods
	private:
		/**
		 * Constructs an ArrayRegistry instance
		 */
		ArrayRegistry();

		/**
		 * The Array database
		 */
		std::map<std::string, Array> db;
};

//end of header
