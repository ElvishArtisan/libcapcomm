// cccircle.cpp
//
// Abstract a circular region
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

#include "cccircle.h"

CCCircle::CCCircle(const CCPoint &pt,float r)
{
  d_center=pt;
  d_radius=r;
}


CCCircle::CCCircle()
{
  d_radius=0.0;
}


CCPoint CCCircle::center() const
{
  return d_center;
}


void CCCircle::setCenter(const CCPoint &pt)
{
  d_center=pt;
}


float CCCircle::radius() const
{
  return d_radius;
}


void CCCircle::setRadius(float r)
{
  d_radius=r;
}
