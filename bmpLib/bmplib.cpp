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

#include "bmplib.h"

namespace image
{
	bmpImage::bmpImage(void)
	{
		//TODO: normalize constructor.
		allocated = 0;
	}

	bmpImage::~bmpImage(void)
	{
		//TODO: normalize destructor.
		if (allocated)
			free(imageData);
	}

	int bmpImage::init(const char imagePath[])
	{
		int n = 0;
		FILE* pFile;

		int err = fopen_s(&pFile, imagePath, "r");
		if (err != NULL)
			return -1;

		for (char chr = getc(pFile); chr != EOF; chr = getc(pFile))
		{
			bmpImage::imageData = (char*)realloc(bmpImage::imageData, (n + 1) * sizeof(char));
			bmpImage::imageData[n] = chr;
			n++;
		}
		fclose(pFile);
		allocated = true;
		return n;
	}
}