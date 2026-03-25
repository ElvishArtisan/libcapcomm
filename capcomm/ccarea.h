// ccarea.h
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

#ifndef CCAREA_H
#define CCAREA_H

#include <QList>
#include <QString>
#include <QStringList>

#include <capcomm/cccircle.h>
#include <capcomm/ccpolygon.h>

class CCArea
{
 public:
  CCArea(const QString &desc="");
  QString areaDesc() const;
  void setAreaDesc(const QString &str);
  int altitude() const;
  void setAltitude(int feet);
  int ceiling() const;
  void setCeiling(int feet);
  int polygonQuantity() const;
  CCPolygon polygonAt(int n);
  int addPolygon(const CCPolygon &pg);
  void removePolygonAt(int n);
  int circleQuantity() const;
  CCCircle circleAt(int n) const;
  int addCircle(const CCCircle &cir);
  void removeCircleAt(int n);
  int geocodeQuantity() const;
  QString geocodeNameAt(int n) const;
  QString geocodeValueAt(int n) const;
  int addGeocode(const QString &name,const QString &value);
  void removeGeocodeAt(int n);
  void clear();

 private:
  QString d_area_desc;
  int d_altitude;
  int d_ceiling;
  QList<CCPolygon> d_polygons;
  QList<CCCircle> d_circles;
  QStringList d_geocode_names;
  QStringList d_geocode_values;
};


#endif  // CCAREA_H
