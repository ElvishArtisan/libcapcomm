// ccalert.cpp
//
// Container class for CAP Alert objects
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

#include "ccalert.h"
 
CCAlert::CCAlert()
  : CCXmlDoc(2,"\n")
{
  clear();
}


QString CCAlert::identifier() const
{
  return d_identifier;
}


void CCAlert::setIdentifier(const QString &str)
{
  d_identifier=str;
}


QString CCAlert::sender() const
{
  return d_sender;
}


void CCAlert::setSender(const QString &str)
{
  d_sender=str;
}


QDateTime CCAlert::sent() const
{
  return d_sent;
}


void CCAlert::setSent(const QDateTime &dt)
{
  d_sent=dt;
}


CCAlert::AlertStatus CCAlert::status() const
{
  return d_status;
}


void CCAlert::setStatus(CCAlert::AlertStatus status)
{
  d_status=status;
}


void CCAlert::setStatus(const QString &str)
{
  setStatus(CCAlert::statusFromString(str));
}


CCAlert::MsgType CCAlert::msgType() const
{
  return d_msg_type;
}


void CCAlert::setMsgType(const MsgType type)
{
  d_msg_type=type;
}


void CCAlert::setMsgType(const QString &str)
{
  setMsgType(CCAlert::msgTypeFromString(str));
}


QString CCAlert::source() const
{
  return d_source;
}


void CCAlert::setSource(const QString &str)
{
  d_source=str;
}


CCAlert::Scope CCAlert::scope() const
{
  return d_scope;
}


void CCAlert::setScope(CCAlert::Scope scope)
{
  d_scope=scope;
}


void CCAlert::setScope(const QString &str)
{
  setScope(CCAlert::scopeFromString(str));
}


QString CCAlert::restriction() const
{
  return d_restriction;
}


void CCAlert::setRestriction(const QString &str)
{
  d_restriction=str;
}


int CCAlert::addressQuantity() const
{
  return d_addresses.size();
}


QString CCAlert::addressAt(int n) const
{
  return d_addresses.at(n);
}


int CCAlert::addAddress(const QString &addr)
{
  d_addresses.push_back(addr);
  return d_addresses.size()-1;
}


void CCAlert::removeAddress(int n)
{
  d_addresses.removeAt(n);
}


int CCAlert::codeQuantity() const
{
  return d_codes.size();
}


QString CCAlert::codeAt(int n) const
{
  return d_codes.at(n);
}


int CCAlert::addCode(const QString &str)
{
  d_codes.push_back(str);
  return d_codes.size()-1;
}


void CCAlert::removeCodeAt(int n)
{
  d_codes.removeAt(n);
}


QString CCAlert::note() const
{
  return d_note;
}


void CCAlert::setNote(const QString &str)
{
  d_note=str;
}


int CCAlert::referenceQuantity() const
{
  return d_references.size();
}


CCReference CCAlert::referenceAt(int n) const
{
  return d_references.at(n);
}


int CCAlert::addReference(const CCReference &ref)
{
  d_references.push_back(ref);
  return d_references.size()-1;
}


void CCAlert::removeReferenceAt(int n)
{
  d_references.removeAt(n);
}


int CCAlert::incidentQuantity() const
{
  return d_incidents.size();
}


QString CCAlert::incidentAt(int n) const
{
  return d_incidents.at(n);
}


int CCAlert::addIncident(const QString &identifier)
{
  d_incidents.push_back(identifier);
  return d_incidents.size()-1;
}


void CCAlert::removeIncidentAt(int n)
{
  d_incidents.removeAt(n);
}


int CCAlert::infoQuantity() const
{
  return d_infos.size();
}


CCInfo *CCAlert::infoAt(int n) const
{
  return d_infos.at(n);
}


int CCAlert::addInfo(const CCInfo &info)
{
  d_infos.push_back(new CCInfo(info));
  return d_infos.size()-1;
}


void CCAlert::removeInfoAt(int n)
{
  d_infos.removeAt(n);
}


QByteArray CCAlert::toXml()
{
  QMap<QString,QString> attrs;
  QString ret;

  //
  // Header
  //
  ret+="<?xml version = \"1.0\" encoding = \"UTF-8\"?>\n";

  //
  // <alert> Section
  //
  attrs.clear();
  attrs["xmlns"]="urn:oasis:names:tc:emergency:cap:1.2";
  ret+=writeOpenTag("cap:alert",attrs);
  ret+=writeField("identifier",identifier());
  ret+=writeField("sender",sender());
  ret+=writeField("sent",sent());
  ret+=writeField("status",CCAlert::statusString(status()));
  ret+=writeField("msgType",CCAlert::msgTypeString(msgType()));
  if(!source().isEmpty()) {
    ret+=writeField("source",source());
  }
  ret+=writeField("scope",CCAlert::scopeString(scope()));
  if(scope()==CCAlert::ScopeRestricted) {
    ret+=writeField("restriction",restriction());
  }
  if(d_addresses.size()>0) {
    ret+=writeField("addresses",d_addresses.join(" "));
  }
  for(int i=0;i<codeQuantity();i++) {
    ret+=writeField("code",codeAt(i));
  }
  if(!note().isEmpty()) {
    ret+=writeField("note",note());
  }
  if(referenceQuantity()>0) {
    QString field="";
    for(int i=0;i<referenceQuantity();i++) {
      field+=referenceAt(i).sender()+",";
      field+=referenceAt(i).identifier()+",";
      field+=referenceAt(i).sent().toString(Qt::ISODate)+" ";
    }
    ret+=writeField("references",field.trimmed());
  }
  if(incidentQuantity()>0) {
    QString field="";
    for(int i=0;i<incidentQuantity();i++) {
      field+=incidentAt(i)+" ";
    }
    ret+=writeField("incidents",field.trimmed());
  }
  
  //
  // <info> Section(s)
  //
  for(int i=0;i<d_infos.size();i++) {
    CCInfo *info=d_infos.at(i);
    ret+=writeOpenTag("info");
    if(!info->language().isEmpty()) {
      ret+=writeField("language",info->language());
    }
    for(int j=0;j<info->categoryQuantity();j++) {
      ret+=writeField("category",CCInfo::categoryString(info->categoryAt(j)));
    }
    ret+=writeField("event",info->event());
    for(int j=0;j<info->responseTypeQuantity();j++) {
      ret+=writeField("responseType",
		      CCInfo::responseTypeString(info->responseTypeAt(j)));
    }
    ret+=writeField("urgency",CCInfo::urgencyString(info->urgency()));
    ret+=writeField("severity",CCInfo::severityString(info->severity()));
    ret+=writeField("certainty",CCInfo::certaintyString(info->certainty()));
    if(!info->audience().isEmpty()) {
      ret+=writeField("audience",info->audience());
    }
    QStringList names=info->eventCodeNames();
    for(int j=0;j<names.size();j++) {
      ret+=writeField("eventCode",info->eventCodeValue(names.at(j)));
    }
    if(info->effective().isValid()) {
      ret+=writeField("effective",info->effective());
    }
    if(info->onset().isValid()) {
      ret+=writeField("onset",info->onset());
    }
    if(info->expires().isValid()) {
      ret+=writeField("expires",info->expires());
    }
    if(!info->senderName().isEmpty()) {
      ret+=writeField("senderName",info->senderName());
    }
    if(!info->headline().isEmpty()) {
      ret+=writeField("headline",info->headline());
    }
    if(!info->instruction().isEmpty()) {
      ret+=writeField("instruction",info->instruction());
    }
    if(!info->web().isEmpty()) {
      ret+=writeField("web",info->web());
    }
    if(!info->contact().isEmpty()) {
      ret+=writeField("contact",info->contact());
    }
    names=info->parameterNames();
    for(int j=0;j<names.size();j++) {
      ret+=writeOpenTag("parameter");
      ret+=writeField("valueName",names.at(j));
      ret+=writeField("value",info->parameterValue(names.at(j)));
      ret+=writeCloseTag("parameter");
    }

    //
    // <resource> Sections
    //
    for(int j=0;j<info->resourceQuantity();j++) {
      CCResource res=info->resourceAt(j);
      ret+=writeOpenTag("resource");
      ret+=writeField("resourceDesc",res.resourceDesc());
      ret+=writeField("mimeType",res.mimeType());
      if(res.size()>0) {
	ret+=writeField("size",res.size());
      }
      if(!res.uri().isEmpty()) {
	ret+=writeField("uri",res.uri());
      }
      if(!res.derefUri().isEmpty()) {
	ret+=writeField("derefUri",res.derefUri());
      }
      if(!res.digest().isEmpty()) {
	ret+=writeField("digest",res.digest());
      }
      
      ret+=writeCloseTag("resource");
    }

    //
    // <area> Sections
    //
    for(int j=0;j<info->areaQuantity();j++) {
      CCArea area=info->areaAt(j);
      ret+=writeOpenTag("area");
      ret+=writeField("areaDesc",area.areaDesc());
      if(area.altitude()>=0) {
	ret+=writeField("altitude",area.altitude());
	if(area.ceiling()>=area.altitude()) {
	  ret+=writeField("ceiling",area.ceiling());
	}
      }
      for(int k=0;k<area.polygonQuantity();k++) {
	CCPolygon poly=area.polygonAt(k);
	if(poly.isClosed()) {
	  QList<CCPoint> pts=poly.points();
	  QString field="";
	  for(int l=0;l<pts.size();l++) {
	    field+=toString(pts.at(l).x())+",";
	    field+=toString(pts.at(l).y())+" ";
	  }
	  ret+=writeField("polygon",field.trimmed());
	}
      }
      for(int k=0;k<area.circleQuantity();k++) {
	CCCircle cir=area.circleAt(k);
	ret+=writeField("circle",
			toString(cir.center().x())+","+
			toString(cir.center().y())+" "+
			toString(cir.radius()));
      }
      for(int k=0;k<area.geocodeQuantity();k++) {
	ret+=writeOpenTag("geocode");
	ret+=writeField("valueName",area.geocodeNameAt(k));
	ret+=writeField("value",area.geocodeValueAt(k));
	
	ret+=writeCloseTag("geocode");
      }
      
      ret+=writeCloseTag("area");
    }

    ret+=writeCloseTag("info");
  }
  
  ret+=writeCloseTag("cap:alert");

  return ret.toUtf8();
}


void CCAlert::clear()
{
  d_identifier=QString();
  d_sender=QString();
  d_sent=QDateTime();
  d_status=CCAlert::StatusUnknown;
  d_msg_type=CCAlert::MsgTypeUnknown;
  d_source=QString();
  d_scope=CCAlert::ScopeUnknown;
  d_restriction=QString();
  d_codes.clear();
  d_note=QString();
  d_references.clear();
  d_incidents.clear();
  d_infos.clear();
}


QString CCAlert::statusString(CCAlert::AlertStatus status)
{
  QString ret="Unknown";

  switch(status) {
  case CCAlert::StatusActual:
    ret="Actual";
    break;

  case CCAlert::StatusExercise:
    ret="Exercise";
    break;

  case CCAlert::StatusSystem:
    ret="System";
    break;

  case CCAlert::StatusTest:
    ret="Test";
    break;

  case CCAlert::StatusDraft:
    ret="Draft";
    break;

  case CCAlert::StatusUnknown:
  case CCAlert::StatusLast:
    break;
  }

  return ret;
}


CCAlert::AlertStatus CCAlert::statusFromString(const QString &str)
{
  CCAlert::AlertStatus ret=CCAlert::StatusUnknown;

  for(int i=0;i<CCAlert::StatusLast;i++) {
    if(CCAlert::statusString((CCAlert::AlertStatus)i)==str) {
      ret=(CCAlert::AlertStatus)i;
    }
  }
  
  return ret;
}


QString CCAlert::msgTypeString(CCAlert::MsgType type)
{
  QString ret="Unknown";

  switch(type) {
  case CCAlert::MsgTypeAlert:
    ret="Alert";
    break;

  case CCAlert::MsgTypeUpdate:
    ret="Update";
    break;

  case CCAlert::MsgTypeCancel:
    ret="Cancel";
    break;

  case CCAlert::MsgTypeAck:
    ret="Ack";
    break;

  case CCAlert::MsgTypeError:
    ret="Error";
    break;

  case CCAlert::MsgTypeUnknown:
  case CCAlert::MsgTypeLast:
    break;
  }

  return ret;
}


CCAlert::MsgType CCAlert::msgTypeFromString(const QString &str)
{
  CCAlert::MsgType ret=CCAlert::MsgTypeUnknown;

  for(int i=0;i<CCAlert::MsgTypeLast;i++) {
    if(CCAlert::msgTypeString((CCAlert::MsgType)i)==str) {
      ret=(CCAlert::MsgType)i;
    }
  }
  
  return ret;
}


QString CCAlert::scopeString(CCAlert::Scope scope)
{
  QString ret="Unknown";

  switch(scope) {
  case CCAlert::ScopePublic:
    ret="Public";
    break;

  case CCAlert::ScopeRestricted:
    ret="Restricted";
    break;

  case CCAlert::ScopePrivate:
    ret="Private";
    break;

  case CCAlert::ScopeUnknown:
  case CCAlert::ScopeLast:
    break;
  }

  return ret;
}


CCAlert::Scope CCAlert::scopeFromString(const QString &str)
{
  CCAlert::Scope ret=CCAlert::ScopeUnknown;

  for(int i=0;i<CCAlert::ScopeLast;i++) {
    if(CCAlert::scopeString((CCAlert::Scope)i)==str) {
      ret=(CCAlert::Scope)i;
    }
  }
  
  return ret;
}
