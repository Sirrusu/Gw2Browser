/** \file       FileReader.cpp
 *  \brief      Contains the definition for the base class of readers for the 
 *              various file types.
 *  \author     Rhoot
 */

/*	Copyright (C) 2012 Rhoot <https://github.com/rhoot>

    This file is part of Gw2Browser.

    Gw2Browser is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "stdafx.h"
#include "FileReader.h"

#include "Readers/ImageReader.h"

namespace gw2b
{
    
FileReader::FileReader(const Array<byte>& pData, ANetFileType pFileType)
    : mData(pData)
    , mFileType(pFileType)
{
}

FileReader::~FileReader()
{
}

void FileReader::Clean()
{
    mData.Clear();
    mFileType = ANFT_Unknown;
}

Array<byte> FileReader::ConvertData() const
{
    return mData;
}

FileReader* FileReader::GetReaderForData(const Array<byte>& pData, ANetFileType pFileType)
{
    switch (pFileType) {
    case ANFT_ATEX:
    case ANFT_ATTX:
    case ANFT_ATEC:
    case ANFT_ATEP:
    case ANFT_ATEU:
    case ANFT_ATET:
    case ANFT_DDS:
        if (ImageReader::IsValidHeader(pData.GetPointer(), pData.GetSize())) {
            return new ImageReader(pData, pFileType);
        }
        break;
    default:
        break;
    }
    return new FileReader(pData, pFileType);
}

}; // namespace gw2b
