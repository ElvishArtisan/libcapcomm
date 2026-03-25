// ccresource.h
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

#ifndef CCRESOURCE_H
#define CCRESOURCE_H

#include <QString>

 class CCResource
 {
 public:
  CCResource();
  QString resourceDesc() const;
  void setResourceDesc(const QString &str);
  QString mimeType() const;
  void setMimeType(const QString &str);
  int size() const;
  void setSize(int size);
  QString uri() const;
  void setUri(const QString &uri);
  QString derefUri() const;
  void setDerefUri(const QString &base64);
  QString digest() const;
  void setDigest(const QString &sha1);
  void clear();

 private:
  QString d_resource_desc;
  QString d_mime_type;
  int d_size;
  QString d_uri;
  QString d_deref_uri;
  QString d_digest;
};


#endif  // CCRESOURCE_H
