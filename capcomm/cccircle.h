// cccircle.h
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

#ifndef CCCIRCLE_H
#define CCCIRCLE_H

#include <capcomm/ccpoint.h>

 class CCCircle
 {
 public:
  CCCircle(const CCPoint &pt,float r);
  CCCircle();
  CCPoint center() const;
  void setCenter(const CCPoint &pt);
  float radius() const;
  void setRadius(float r);

 private:
  CCPoint d_center;
  float d_radius;
 };


#endif  // CCCIRCLE_H
