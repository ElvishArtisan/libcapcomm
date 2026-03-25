// ccreference.h
//
// Container class for CAP Reference objects
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

#ifndef CCREFERENCE_H
#define CCREFERENCE_H

#include <QDateTime>
#include <QString>

 class CCReference
 {
 public:
  CCReference();
  QString sender() const;
  void setSender(const QString &str);
  QString identifier() const;
  void setIdentifier(const QString &str);
  QDateTime sent() const;
  void setSent(const QDateTime &dt);
  void clear();

 private:
   QString d_sender;
  QString d_identifier;
  QDateTime d_sent;
};


#endif  // CCREFERENCE_H
