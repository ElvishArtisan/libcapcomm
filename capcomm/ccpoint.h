// ccpoint.h
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

#ifndef CCPOINT_H
#define CCPOINT_H

class CCPoint
 {
 public:
  CCPoint(float x,float y);
  CCPoint();
  float x() const;
  void setX(float x);
  float y() const;
  void setY(float y);
  bool operator==(const CCPoint &other) const;

 private:
  float d_x;
  float d_y;
 };


#endif  // CCPOINT_H
