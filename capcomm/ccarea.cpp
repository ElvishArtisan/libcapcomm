// ccarea.cpp
//
// Container class for CAP Area objects
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

#include "ccarea.h"

CCArea::CCArea(const QString &desc)
{
  clear();
  d_area_desc=desc;
}


QString CCArea::areaDesc() const
{
  return d_area_desc;
}


void CCArea::setAreaDesc(const QString &str)
{
  d_area_desc=str;
}


int CCArea::altitude() const
{
  return d_altitude;
}


void CCArea::setAltitude(int feet)
{
  d_altitude=feet;
}


int CCArea::ceiling() const
{
  return d_ceiling;
}


void CCArea::setCeiling(int feet)
{
  d_ceiling=feet;
}


int CCArea::polygonQuantity() const
{
  return d_polygons.size();
}


CCPolygon CCArea::polygonAt(int n)
{
  return d_polygons.at(n);
}


int CCArea::addPolygon(const CCPolygon &pg)
{
  d_polygons.push_back(pg);
  return d_polygons.size()-1;
}


void CCArea::removePolygonAt(int n)
{
  d_polygons.removeAt(n);
}


int CCArea::circleQuantity() const
{
  return d_circles.size();
}


CCCircle CCArea::circleAt(int n) const
{
  return d_circles.at(n);
}


int CCArea::addCircle(const CCCircle &cir)
{
  d_circles.push_back(cir);
  return d_circles.size()-1;
}


void CCArea::removeCircleAt(int n)
{
  d_circles.removeAt(n);
}


int CCArea::geocodeQuantity() const
{
  return d_geocode_names.size();
}


QString CCArea::geocodeNameAt(int n) const
{
  return d_geocode_names.at(n);
}


QString CCArea::geocodeValueAt(int n) const
{
  return d_geocode_values.at(n);
}


int CCArea::addGeocode(const QString &name,const QString &value)
{
  d_geocode_names.push_back(name);
  d_geocode_values.push_back(value);
  return d_geocode_names.size()-1;
}


void CCArea::removeGeocodeAt(int n)
{
  d_geocode_names.removeAt(n);
  d_geocode_values.removeAt(n);
}


void CCArea::clear()
{
  d_area_desc=QString();
  d_altitude=-1;
  d_ceiling=-1;
  d_polygons.clear();
  d_circles.clear();
  d_geocode_names.clear();
  d_geocode_values.clear();
}
