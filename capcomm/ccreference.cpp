// ccreference.cpp
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

#include "ccreference.h"

CCReference::CCReference(const QString &sender,const QString &identifier,
			 const QDateTime &sent)
{
  d_sender=sender;
  d_identifier=identifier;
  d_sent=sent;
}


CCReference::CCReference()
{
  clear();
}


QString CCReference::sender() const
{
  return d_sender;
}


void CCReference::setSender(const QString &str)
{
  d_sender=str;
}


QString CCReference::identifier() const
{
  return d_identifier;
}


void CCReference::setIdentifier(const QString &str)
{
  d_identifier=str;
}


QDateTime CCReference::sent() const
{
  return d_sent;
}


void CCReference::setSent(const QDateTime &dt)
{
  d_sent=dt;
}


void CCReference::clear()
{
  d_sender=QString();
  d_identifier=QString();
  d_sent=QDateTime();
}
