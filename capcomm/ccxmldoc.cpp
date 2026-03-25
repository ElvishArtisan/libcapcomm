// ccxmldoc.cpp
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

#include <QChar>

#include "ccxmldoc.h"
 
CCXmlDoc::CCXmlDoc(int indent_step,const QString &eol)
{
  d_indent_step=indent_step;
  d_eol=eol;
  d_indent="";

  //
  // Create escape map
  //
  d_escape_map[QChar('<')]="&lt;";
  d_escape_map[QChar('>')]="&gt;";
  d_escape_map[QChar('&')]="&amp;";
  d_escape_map[QChar('"')]="&quot;";
  d_escape_map[QChar('\'')]="&apos;";
}


QString CCXmlDoc::writeField(const QString &tag,const QString &value) const
{
  return d_indent+
    "<"+tag+">"+
    escape(value)+
    "</"+tag+">"+d_eol;
}


QString CCXmlDoc::writeField(const QString &tag,const QDateTime &value) const
{
  QString dt_str=value.toString(Qt::ISODate);
  if(dt_str.right(1).toUpper()=="Z") { // CAP v1.2 doesn't allow this notation!
    dt_str=dt_str.left(dt_str.length()-1)+"+00:00";
  }
  return d_indent+
    "<"+tag+">"+
    dt_str+
    "</"+tag+">"+d_eol;
}


QString CCXmlDoc::writeField(const QString &tag,int value) const
{
  return d_indent+"<"+tag+">"+
    QString::asprintf("%d",value)+
    "</"+tag+">"+d_eol;
}


QString CCXmlDoc::writeField(const QString &tag,float value) const
{
  return d_indent+"<"+tag+">"+
    QString::asprintf("%8.2f",value)+
    "</"+tag+">"+d_eol;
}


QString CCXmlDoc::writeOpenTag(const QString &tag,QMap<QString,QString> attrs)

{
  QString ret=d_indent+"<"+tag;
  if(attrs.size()>0) {
    for(QMap<QString,QString>::const_iterator it=attrs.begin();it!=attrs.end();
	it++) {
      ret+=" "+it.key()+"=\""+it.value()+"\"";
    }
  }
  ret+=">";
  ret+=d_eol;
  for(int i=0;i<d_indent_step;i++) {
    d_indent+=" ";
  }
  return ret;
}


QString CCXmlDoc::writeCloseTag(const QString &tag)
{
  d_indent=d_indent.left(d_indent.length()-d_indent_step);
  QString ret=d_indent+ 
    "</"+tag+">"+d_eol;

  return ret;
}


QString CCXmlDoc::toString(float num,int dec_pts) const
{
  QString fmt=QString::asprintf("%%20.%df",dec_pts);

  return QString::asprintf(fmt.toUtf8(),num).trimmed();
}


QString CCXmlDoc::escape(const QString &str) const
{
  QString ret;

  for(int i=0;i<str.length();i++) {
    ret+=d_escape_map.value(str.at(i),str.at(i));
  }

  return ret;
}
