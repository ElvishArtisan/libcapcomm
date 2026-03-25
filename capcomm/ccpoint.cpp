// ccpoint.cpp
//
// Abstract a two-dimensional point
//
// (C) Copyright 2026 Fred Gleason <fredg@paravelsystems.com>
//
//    This program is free software; you can redistribute it and/or modify
//    it under the terms of version 2.1 of the GNU Lesser General Public
//    License as published by the Free Software Foundation;
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU Lesser General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program; if not, write to the Free Software
//    Foundation, Inc., 59 Temple Place, Suite 330, 
//    Boston, MA  02111-1307  USA
//

#include "ccpoint.h"

CCPoint::CCPoint(float x,float y)
{
  d_x=x;
  d_y=y;
}


CCPoint::CCPoint()
{
  d_x=0;
  d_y=0;
}


float CCPoint::x() const
{
  return d_x;
}


void CCPoint::setX(float x)
{
  d_x=x;
}


float CCPoint::y() const
{
  return d_y;
}


void CCPoint::setY(float y)
{
  d_y=y;
}


bool CCPoint::operator==(const CCPoint &other) const
{
  return (d_x==other.d_x)&&(d_y==other.d_y);
}
