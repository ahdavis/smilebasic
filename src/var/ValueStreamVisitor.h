/*
 * ValueStreamVisitor.h 
 * Declares a visitor class for streaming out Values
 * Created on 5/9/2020
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
#include <iostream>
#include <string>

/**
 * Streams out the contents of a Value by visiting
 * its variant types
 */
class ValueStreamVisitor final {
	//public fields and methods
	public:
		/**
		 * Constructs a new ValueStreamVisitor instance
		 *
		 * @param newStream The stream to write the visited value to
		 */
		explicit ValueStreamVisitor(std::ostream& newStream);

		/**
		 * Destructs a ValueStreamVisitor instance
		 */
		~ValueStreamVisitor();

		//delete the copy constructor
		ValueStreamVisitor(const ValueStreamVisitor& vsv) = delete;

		//delete the assignment operator
		ValueStreamVisitor& operator=(const ValueStreamVisitor& src) = delete;

		/**
		 * Visits an integer value
		 *
		 * @param i The value to visit
		 */
		void operator()(int i) const;

		/**
		 * Visits a double value
		 *
		 * @param d The value to visit
		 */
		void operator()(double d) const;

		/**
		 * Visits a Boolean value
		 *
		 * @param b The value to visit
		 */
		void operator()(bool b) const;

		/**
		 * Visits a string value
		 *
		 * @param s The string to visit
		 */
		void operator()(const std::string& s) const;

	//private fields and methods
	private:
		//field
		
		/**
		 * The stream to write visited values to
		 */
		std::ostream& os;
};

//end of header
