// ccresource.cpp
//
// Container class for CAP Info objects
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

#include "ccresource.h"

CCResource::CCResource()
{
  clear();
}


QString CCResource::resourceDesc() const
{
  return d_resource_desc;
}


void CCResource::setResourceDesc(const QString &str)
{
  d_resource_desc=str;
}


QString CCResource::mimeType() const
{
  return d_mime_type;
}


void CCResource::setMimeType(const QString &str)
{
  d_mime_type=str;
}


int CCResource::size() const
{
  return d_size;
}


void CCResource::setSize(int size)
{
  d_size=size;
}


QString CCResource::uri() const
{
  return d_uri;
}


void CCResource::setUri(const QString &uri)
{
  d_uri=uri;
}


QString CCResource::derefUri() const
{
  return d_deref_uri;
}


void CCResource::setDerefUri(const QString &base64)
{
  d_deref_uri=base64;
}


QString CCResource::digest() const
{
  return d_digest;
}


void CCResource::setDigest(const QString &sha1)
{
  d_digest=sha1;
}


void CCResource::clear()
{
  d_resource_desc=QString();
  d_mime_type=QString();
  d_size=0;
  d_uri=QString();
  d_deref_uri=QString();
  d_digest=QString();
}
