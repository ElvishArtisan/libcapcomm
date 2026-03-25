// parsertest.cpp
//
// Test parsers.
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

#include <stdio.h>
#include <stdlib.h>

#include <QCoreApplication>

#include <capcomm/ccalert.h>
#include <capcomm/ccarea.h>
#include <capcomm/ccinfo.h>
#include <capcomm/ccresource.h>

#include "parsertest.h"

MainObject::MainObject()
  : QObject()
{
  CCAlert *alert=new CCAlert();
  alert->setIdentifier("123456");
  alert->setSender("fredg@paravelsystems.com");
  QDateTime now=QDateTime::currentDateTime();
  now.setTimeSpec(Qt::OffsetFromUTC);
  now.setOffsetFromUtc(-3600*4);
  alert->setSent(now);
  alert->setStatus(CCAlert::StatusTest);
  alert->setMsgType(CCAlert::MsgTypeError);
  alert->setSource("Freds House");
  alert->setScope(CCAlert::ScopeRestricted);
  alert->setRestriction("This is only for testing.");
  alert->addAddress("gleasonf1813@gmail.com");
  alert->addCode("CODE YELLOW");
  alert->addCode("Another code");
  alert->setNote("This is just an exercise.");
  CCReference ref;
  ref.setSender("fredg@paravelsystems.com");
  ref.setIdentifier("123456");
  ref.setSent(alert->sent());
  alert->addReference(ref);

  CCInfo info;
  info.setLanguage("es_US");
  info.setCategory(CCInfo::CategoryMet);
  info.setEvent("libcapcom test");
  info.addResponseType(CCInfo::ResponseTypeAssess);
  info.addResponseType(CCInfo::ResponseTypeAllClear);
  info.setUrgency(CCInfo::UrgencyImmediate);
  info.setSeverity(CCInfo::SeverityMinor);
  info.setCertainty(CCInfo::Certainty::CertaintyObserved);
  info.setAudience("libcapcomm developers");
  info.addEventCode("TEST","This is TEST");
  info.addEventCode("Something","Something else");
  info.setEffective(now.addSecs(-3600));
  info.setOnset(now.addSecs(0));
  info.setExpires(now.addSecs(3600));
  info.setSenderName("Fred Gleason");
  info.setHeadline("EasPanel Gets Full CAP Support!");
  info.setDescription("We needed to test a bunch of stuff.");
  info.setInstruction("Fix it and make it work!");
  info.setWeb("https://software.paravelsystems.com");
  info.setContact("Primary libcapcomm developer");
  info.addParameter("ZIP","22712");
  CCResource res;
  res.setResourceDesc("Test resource one");
  res.setMimeType("text/html");
  res.setSize(12);
  res.setUri("https://www.example.com/hello.html");
  res.setDerefUri("SGVsbG8gV29ybGQhCg==");
  res.setDigest("a0b65939670bc2c010f4d5d6a0b3e4e4590fb92b");
  info.addResource(res);
  CCArea area("Test Area");
  area.setAltitude(1000);
  area.setCeiling(2000);
  area.addCircle(CCCircle(CCPoint(1.0,2.0),3.0));
  CCPolygon polygon;
  QList<CCPoint> pts;
  pts.push_back(CCPoint(1.0,5.0));
  pts.push_back(CCPoint(2.0,6.0));
  pts.push_back(CCPoint(3.0,7.0));
  pts.push_back(CCPoint(1.0,5.0));
  polygon.setPoints(pts);
  area.addPolygon(polygon);
  area.addGeocode("SAME","123456");
  area.addGeocode("FIPS","654321");
  info.addArea(area);
  
  alert->addInfo(info);

  printf("%s\n",alert->toXml().constData());
  
  exit(0);
}


int main(int argc,char *argv[])
{
  QCoreApplication a(argc,argv);

  new MainObject();

  return a.exec();
}
