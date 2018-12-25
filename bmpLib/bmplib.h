/*
	Copyright 2018-2019 Artyom Korobov

	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#pragma once

#include <stdio.h>
#include <malloc.h>
// Main header for classes prototypes.

namespace image
{
	class bmpImage
	{
	protected:
		char* imageData;
		bool allocated;
	public:
		bmpImage(void);
		~bmpImage(void);
		int init(const char imagePath[]);
	};
}