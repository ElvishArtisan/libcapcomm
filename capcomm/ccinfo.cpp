// ccinfo.cpp
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

#include "ccinfo.h"
 
CCInfo::CCInfo()
{
  clear();
}


QString CCInfo::language() const
{
  return d_language;
}


void CCInfo::setLanguage(const QString &str)
{
  d_language=str;
}


int CCInfo::categoryQuantity() const
{
  return d_categories.size();
}


CCInfo::Category CCInfo::categoryAt(int n) const
{
  return d_categories.at(n);
}


int CCInfo::addCategory(CCInfo::Category category)
{
  d_categories.push_back(category);
  return d_categories.size()-1;
}


int CCInfo::addCategory(const QString &str)
{
  return addCategory(CCInfo::categoryFromString(str));
}


void CCInfo::removeCategoryAt(int n)
{
  d_categories.removeAt(n);
}


QString CCInfo::event() const
{
  return d_event;
}


void CCInfo::setEvent(const QString &str)
{
  d_event=str;
}


int CCInfo::responseTypeQuantity() const
{
  return d_response_types.size();
}


CCInfo::ResponseType CCInfo::responseTypeAt(int n)
{
  return d_response_types.at(n);
}


int CCInfo::addResponseType(const ResponseType &resp_type)
{
  d_response_types.push_back(resp_type);
  return d_response_types.size()-1;
}


int CCInfo::addResponseType(const QString &str)
{
  return addResponseType(CCInfo::responseTypeFromString(str));
}


void CCInfo::removeResponseTypeAt(int n)
{
  d_response_types.removeAt(n);
}


CCInfo::Urgency CCInfo::urgency() const
{
  return d_urgency;
}


void CCInfo::setUrgency(CCInfo::Urgency urg)
{
  d_urgency=urg;
}


void CCInfo::setUrgency(const QString &str)
{
  setUrgency(CCInfo::urgencyFromString(str));
}


CCInfo::Severity CCInfo::severity() const
{
  return d_severity;
}


void CCInfo::setSeverity(CCInfo::Severity sev)
{
  d_severity=sev;
}


void CCInfo::setSeverity(const QString &str)
{
  setSeverity(CCInfo::severityFromString(str));
}


CCInfo::Certainty CCInfo::certainty() const
{
  return d_certainty;
}


void CCInfo::setCertainty(CCInfo::Certainty cert)
{
  d_certainty=cert;
}


void CCInfo::setCertainty(const QString &str)
{
  setCertainty(CCInfo::certaintyFromString(str));
}


QString CCInfo::audience() const
{
  return d_audience;
}


void CCInfo::setAudience(const QString &str)
{
  d_audience=str;
}


QStringList CCInfo::eventCodeNames() const
{
  return d_event_codes.keys();
}


QString CCInfo::eventCodeValue(const QString &name) const
{
  return d_event_codes.value(name);
}


void CCInfo::addEventCode(const QString &name,const QString &value)
{
  d_event_codes[name]=value;
}


void CCInfo::removeEventCode(const QString &name)
{
  d_event_codes.remove(name);
}

QDateTime CCInfo::effective() const
{
  return d_effective;
}


void CCInfo::setEffective(const QDateTime &dt)
{
  d_effective=dt;
}


void CCInfo::setEffective(const QString &str)
{
  setEffective(QDateTime::fromString(str,Qt::ISODate));
}


QDateTime CCInfo::onset() const
{
  return d_onset;
}


void CCInfo::setOnset(const QDateTime &dt)
{
  d_onset=dt;
}


void CCInfo::setOnset(const QString &str)
{
  setOnset(QDateTime::fromString(str,Qt::ISODate));
}


QDateTime CCInfo::expires() const
{
  return d_expires;
}


void CCInfo::setExpires(const QDateTime &dt)
{
  d_expires=dt;
}


void CCInfo::setExpires(const QString &str)
{
  setExpires(QDateTime::fromString(str,Qt::ISODate));
}


QString CCInfo::senderName() const
{
  return d_sender_name;
}


void CCInfo::setSenderName(const QString &str)
{
  d_sender_name=str;
}


QString CCInfo::headline() const
{
  return d_headline;
}


void CCInfo::setHeadline(const QString &str)
{
  d_headline=str;
}


QString CCInfo::description() const
{
  return d_description;
}


void CCInfo::setDescription(const QString &str)
{
  d_description=str;
}


QString CCInfo::instruction() const
{
  return d_instruction;
}


void CCInfo::setInstruction(const QString &str)
{
  d_instruction=str;
}


QString CCInfo::web() const
{
  return d_web;
}


void CCInfo::setWeb(const QString &url)
{
  d_web=url;
}


QString CCInfo::contact() const
{
  return d_contact;
}


void CCInfo::setContact(const QString &str)
{
  d_contact=str;
}


QStringList CCInfo::parameterNames() const
{
  return d_parameters.keys();
}


QString CCInfo::parameterValue(const QString &name) const
{
  return d_parameters.value(name);
}


void CCInfo::addParameter(const QString &name,const QString &value)
{
  d_parameters[name]=value;
}


void CCInfo::removeParameter(const QString &name)
{
  d_parameters.remove(name);
}


int CCInfo::resourceQuantity() const
{
  return d_resources.size();
}


CCResource CCInfo::resourceAt(int n) const
{
  return d_resources.at(n);
}


int CCInfo::addResource(const CCResource &res)
{
  d_resources.push_back(res);
  return d_resources.size()-1;
}


void CCInfo::removeResourceAt(int n)
{
  d_resources.removeAt(n);
}


int CCInfo::areaQuantity() const
{
  return d_areas.size();
}


CCArea CCInfo::areaAt(int n) const
{
  return d_areas.at(n);
}


int CCInfo::addArea(const CCArea &res)
{
  d_areas.push_back(res);
  return d_areas.size()-1;
}


void CCInfo::removeAreaAt(int n)
{
  d_areas.removeAt(n);
}


void CCInfo::clear()
{
  d_language="en_US";
  d_categories.clear();
  d_event=QString();;
  d_response_types.clear();
  d_urgency=CCInfo::UrgencyUnknown;
  d_severity=CCInfo::SeverityUnknown;
  d_certainty=CCInfo::CertaintyUnknown;
  d_audience=QString();
  d_event_codes.clear();
  d_effective=QDateTime();
  d_onset=QDateTime();
  d_expires=QDateTime();
  d_sender_name=QString();
  d_headline=QString();
  d_description=QString();
  d_instruction=QString();
  d_web=QString();
  d_contact=QString();
  d_resources.clear();
  d_areas.clear();
}



QString CCInfo::categoryString(CCInfo::Category cat)
{
  QString ret="Unknown";

  switch(cat) {
  case CCInfo::CategoryGeo:
    ret="Geo";
    break;

  case CCInfo::CategoryMet:
    ret="Met";
    break;

  case CCInfo::CategorySafety:
    ret="Safety";
    break;

  case CCInfo::CategorySecurity:
    ret="Security";
    break;

  case CCInfo::CategoryRescue:
    ret="Rescue";
    break;

  case CCInfo::CategoryFire:
    ret="Fire";
    break;

  case CCInfo::CategoryHealth:
    ret="Healeth";
    break;

  case CCInfo::CategoryEnv:
    ret="Env";
    break;

  case CCInfo::CategoryTransport:
    ret="Transport";
    break;

  case CCInfo::CategoryInfra:
    ret="Infra";
    break;

  case CCInfo::CategoryCBRNE:
    ret="CBRNE";
    break;

  case CCInfo::CategoryOther:
    ret="Other";
    break;

  case CCInfo::CategoryUnknown:
  case CCInfo::CategoryLast:
    break;
  }

  return ret;
}


CCInfo::Category CCInfo::categoryFromString(const QString &str)
{
  CCInfo::Category ret=CCInfo::CategoryUnknown;

  for(int i=0;i<CCInfo::CategoryLast;i++) {
    if(CCInfo::categoryString((CCInfo::Category)i)==str) {
      ret=(CCInfo::Category)i;
    }
  }
  
  return ret;
}


QString CCInfo::responseTypeString(CCInfo::ResponseType resp)
{
  QString ret="Unknown";

  switch(resp) {
  case CCInfo::ResponseTypeShelter:
    ret="Shelter";
    break;

  case CCInfo::ResponseTypeEvacuate:
    ret="Evacuate";
    break;

  case CCInfo::ResponseTypePrepare:
    ret="Prepare";
    break;

  case CCInfo::ResponseTypeExecute:
    ret="Execute";
    break;

  case CCInfo::ResponseTypeAvoid:
    ret="Avoid";
    break;

  case CCInfo::ResponseTypeMonitor:
    ret="Monitor";
    break;

  case CCInfo::ResponseTypeAssess:
    ret="Assess";
    break;

  case CCInfo::ResponseTypeAllClear:
    ret="AllClear";
    break;

  case CCInfo::ResponseTypeNone:
    ret="None";
    break;

  case CCInfo::ResponseTypeUnknown:
  case CCInfo::ResponseTypeLast:
    break;
  }

  return ret;
}


CCInfo::ResponseType CCInfo::responseTypeFromString(const QString &str)
{
  CCInfo::ResponseType ret=CCInfo::ResponseTypeUnknown;

  for(int i=0;i<CCInfo::ResponseTypeLast;i++) {
    if(CCInfo::responseTypeString((CCInfo::ResponseType)i)==str) {
      ret=(CCInfo::ResponseType)i;
    }
  }
  
  return ret;
}


QString CCInfo::urgencyString(CCInfo::Urgency urg)
{
  QString ret="Unknown";

  switch(urg) {
  case CCInfo::UrgencyImmediate:
    ret="Immediate";
    break;

  case CCInfo::UrgencyExpected:
    ret="Expected";
    break;

  case CCInfo::UrgencyFuture:
    ret="Future";
    break;

  case CCInfo::UrgencyPast:
    ret="Past";
    break;

  case CCInfo::UrgencyUnknown:
  case CCInfo::UrgencyLast:
    break;
  }

  return ret;
}


CCInfo::Urgency CCInfo::urgencyFromString(const QString &str)
{
  CCInfo::Urgency ret=CCInfo::UrgencyUnknown;

  for(int i=0;i<CCInfo::UrgencyLast;i++) {
    if(CCInfo::urgencyString((CCInfo::Urgency)i)==str) {
      ret=(CCInfo::Urgency)i;
    }
  }
  
  return ret;
}


QString CCInfo::severityString(CCInfo::Severity sev)
{
  QString ret="Unknown";

  switch(sev) {
  case CCInfo::SeverityExtreme:
    ret="Extreme";
    break;

  case CCInfo::SeveritySevere:
    ret="Severe";
    break;

  case CCInfo::SeverityModerate:
    ret="Moderate";
    break;

  case CCInfo::SeverityMinor:
    ret="Minor";
    break;

  case CCInfo::SeverityUnknown:
  case CCInfo::SeverityLast:
    break;
  }

  return ret;
}


CCInfo::Severity CCInfo::severityFromString(const QString &str)
{
  CCInfo::Severity ret=CCInfo::SeverityUnknown;

  for(int i=0;i<CCInfo::SeverityLast;i++) {
    if(CCInfo::severityString((CCInfo::Severity)i)==str) {
      ret=(CCInfo::Severity)i;
    }
  }
  
  return ret;
}


QString CCInfo::certaintyString(CCInfo::Certainty cert)
{
  QString ret="Unknown";

  switch(cert) {
  case CCInfo::CertaintyObserved:
    ret="Observed";
    break;

  case CCInfo::CertaintyLikely:
    ret="Likely";
    break;

  case CCInfo::CertaintyPossible:
    ret="Possible";
    break;

  case CCInfo::CertaintyUnlikely:
    ret="Unlikely";
    break;

  case CCInfo::CertaintyUnknown:
  case CCInfo::CertaintyLast:
    break;
  }

  return ret;
}


CCInfo::Certainty CCInfo::certaintyFromString(const QString &str)
{
  CCInfo::Certainty ret=CCInfo::CertaintyUnknown;

  for(int i=0;i<CCInfo::CertaintyLast;i++) {
    if(CCInfo::certaintyString((CCInfo::Certainty)i)==str) {
      ret=(CCInfo::Certainty)i;
    }
  }
  
  return ret;
}
