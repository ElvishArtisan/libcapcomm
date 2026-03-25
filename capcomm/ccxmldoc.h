// ccxmldoc.h
//
// Base class for XML documents.
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

#ifndef CCXMLDOC_H
#define CCXMLDOC_H

#include <QDateTime>
#include <QMap>
#include <QString>
 
class CCXmlDoc
 {
  public:
   CCXmlDoc(int indent_step=2,const QString &eol="\n");
   QString writeField(const QString &tag,const QString &value) const;
   QString writeField(const QString &tag,const QDateTime &value) const;
   QString writeField(const QString &tag,int value) const;
   QString writeField(const QString &tag,float value) const;
   QString writeOpenTag(const QString &tag,
			QMap<QString,QString> attrs=QMap<QString,QString>());
   QString writeCloseTag(const QString &tag);
   QString escape(const QString &str) const;

 protected:
   QString toString(float num,int dec_pts=2) const;

 private:
   int d_indent_step;
   QString d_eol;
   QString d_indent;
   QMap<QChar,QString> d_escape_map;
 };


#endif  // CCXMLDOC_H
