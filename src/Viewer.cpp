/** \file       Viewer.h
 *  \brief      Contains definition of the viewer base class.
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
#include "Viewer.h"

namespace gw2b
{

Viewer::Viewer(wxWindow* pParent, const wxPoint& pPos, const wxSize& pSize)
    : wxPanel(pParent, wxID_ANY, pPos, pSize)
    , mReader(NULL)
{
}

Viewer::~Viewer()
{
    DeletePointer(mReader);
}

void Viewer::Clear()
{
    DeletePointer(mReader);
}

void Viewer::SetReader(FileReader* pReader)
{
    this->Clear();
    mReader = pReader;
}

}; // namespace gw2b
