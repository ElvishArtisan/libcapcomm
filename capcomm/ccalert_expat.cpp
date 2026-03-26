// ccalert_expat.h
//
// Routines for parsing CAP v1.2 documents
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

#include <expat.h>

#include <capcomm/ccalert.h>

class ParserState
{
 public:
  ParserState(CCAlert *alert); 
  CCAlert *alert() const;
  CCInfo *info() const;
  void setInfo(CCInfo *info);
  void freeInfo();
  CCResource *resource() const;
  void setResource(CCResource *res);
  void freeResource();
  CCArea *area() const;
  void setArea(CCArea *area);
  void freeArea();
  QByteArray currentPath() const;
  void pushTag(const QByteArray &tag);
  void popTag();
  QByteArray value(const QString &key="") const;
  void appendValue(const QByteArray &value,const QString &key="");
  void appendValue(const XML_Char *s,int len,const QString &key="");
  void clearValue(const QString &key);

 private:
  CCAlert *ps_alert;
  CCInfo *ps_info;
  CCResource *ps_resource;
  CCArea *ps_area;
  QList<QByteArray> ps_current_path;
  QMap<QString,QByteArray> ps_values;
};


ParserState::ParserState(CCAlert *alert)
{
  ps_alert=alert;
  ps_info=NULL;
}


CCAlert *ParserState::alert() const
{
  return ps_alert;
}


CCInfo *ParserState::info() const
{
  return ps_info;
}


void ParserState::setInfo(CCInfo *info)
{
  ps_info=info;
}


void ParserState::freeInfo()
{
  if(ps_info!=NULL) {
    delete ps_info;
    ps_info=NULL;
  }
}


CCResource *ParserState::resource() const
{
  return ps_resource;
}


void ParserState::setResource(CCResource *res)
{
  ps_resource=res;
}


void ParserState::freeResource()
{
  if(ps_resource!=NULL) {
    delete ps_resource;
    ps_resource=NULL;
  }
}


CCArea *ParserState::area() const
{
  return ps_area;
}


void ParserState::setArea(CCArea *area)
{
  ps_area=area;
}


void ParserState::freeArea()
{
  if(ps_area!=NULL) {
    delete ps_area;
    ps_area=NULL;
  }
}


QByteArray ParserState::currentPath() const
{
  QByteArray ret;
  for(int i=0;i<ps_current_path.size();i++) {
    ret+="/"+ps_current_path.at(i);
  }
  return ret;
}
  

void ParserState::pushTag(const QByteArray &tag)
{
  ps_current_path.push_back(tag);
}


void ParserState::popTag()
{
  ps_current_path.removeLast();
  ps_values[""].clear();
}


QByteArray ParserState::value(const QString &key) const
{
  return ps_values.value(key,QByteArray());
}


void ParserState::appendValue(const QByteArray &value,const QString &key)
{
  ps_values[key]+=value;
}


void ParserState::appendValue(const XML_Char *s,int len,const QString &key)
{
  ps_values[key]+=QByteArray(s,len);
}


void ParserState::clearValue(const QString &key)
{
  ps_values.remove(key);
}




//
// Expat Callbacks
//
static void XMLCALL __Capcomm_XmlElementStart(void *data, const char *el, 
				      const char **attr)
{
  static struct ParserState *pstate=(struct ParserState *)data;
  pstate->pushTag(el);
  static CCAlert *alert=pstate->alert();
  QByteArray tag_path=pstate->currentPath();
  if(tag_path=="alert") {
    alert->clear();
  }
  if(tag_path=="/alert/info") {
    pstate->setInfo(new CCInfo());
  }
  if(tag_path=="/alert/info/resource") {
    pstate->setResource(new CCResource());
  }
  if(tag_path=="/alert/info/area") {
    pstate->setArea(new CCArea());
  }
}


static void XMLCALL __Capcomm_XmlElementData(void *data,const XML_Char *s,int len)
{
  static struct ParserState *pstate=(struct ParserState *)data;

  pstate->appendValue(s,len);
}


static void XMLCALL __Capcomm_XmlElementEnd(void *data, const char *el)
{
  static struct ParserState *pstate=(struct ParserState *)data;
  static CCAlert *alert=pstate->alert();
  QByteArray tag_path=pstate->currentPath();
  QString value=QString::fromUtf8(pstate->value().trimmed());

  //
  // <alert> Tags
  //
  if(tag_path=="/alert/identifier") {
    alert->setIdentifier(value);
  }
  if(tag_path=="/alert/sender") {
    alert->setSender(value);
  }
  if(tag_path=="/alert/sent") {
    alert->setSent(QDateTime::fromString(value,Qt::ISODate));
  }
  if(tag_path=="/alert/status") {
    alert->setStatus(value);
  }
  if(tag_path=="/alert/msgType") {
    alert->setMsgType(value);
  }
  if(tag_path=="/alert/source") {
    alert->setSource(value);
  }
  if(tag_path=="/alert/scope") {
    alert->setScope(value);
  }
  if(tag_path=="/alert/restriction") {
    alert->setRestriction(value);
  }
  if(tag_path=="/alert/addresses") {
    QStringList addrs=value.split(" ",QString::SkipEmptyParts);
    for(int i=0;i<addrs.size();i++) {
      alert->addAddress(addrs.at(i));
    }
  }
  if(tag_path=="/alert/code") {
    alert->addCode(value);
  }
  if(tag_path=="/alert/note") {
    alert->setNote(value);
  }
  if(tag_path=="/alert/references") {
    QStringList f0=value.split(" ",QString::SkipEmptyParts);
    for(int i=0;i<f0.size();i++) {
      QStringList f1=f0.at(i).split(",");
      if(f1.size()==3) {
	QDateTime dt=QDateTime::fromString(f1.at(2),Qt::ISODate);
	if(dt.isValid()) {
	  alert->addReference(CCReference(f1.at(0),f1.at(1),dt));
	}
      }
    }
  }
  if(tag_path=="/alert/incidents") {
    QStringList f0=value.split(" ",QString::SkipEmptyParts);
    for(int i=0;i<f0.at(i);i++) {
      alert->addIncident(f0.at(i));
    }
  }

  //
  // <info> Tags
  //
  CCInfo *info=pstate->info();
  if(info!=NULL) {
    if(tag_path=="/alert/info/language") {
      info->setLanguage(value);
    }
    if(tag_path=="/alert/info/category") {
      info->addCategory(value);
    }
    if(tag_path=="/alert/info/event") {
      info->setEvent(value);
    }
    if(tag_path=="/alert/info/responseType") {
      info->addResponseType(value);
    }
    if(tag_path=="/alert/info/urgency") {
      info->setUrgency(value);
    }
    if(tag_path=="/alert/info/severity") {
      info->setSeverity(value);
    }
    if(tag_path=="/alert/info/certainty") {
      info->setCertainty(value);
    }
    if(tag_path=="/alert/info/audience") {
      info->setAudience(value);
    }
    if(tag_path=="/alert/info/eventCode/valueName") {
      pstate->appendValue(value.toUtf8(),"valueName");
    }
    if(tag_path=="/alert/info/eventCode/value") {
      pstate->appendValue(value.toUtf8(),"value");
    }
    if(tag_path=="/alert/info/eventCode") {
      info->addEventCode(pstate->value("valueName"),pstate->value("value"));
      pstate->clearValue("valueName");
      pstate->clearValue("value");
    }
    if(tag_path=="/alert/info/effective") {
      info->setEffective(value);
    }
    if(tag_path=="/alert/info/onset") {
      info->setOnset(value);
    }
    if(tag_path=="/alert/info/expires") {
      info->setExpires(value);
    }
    if(tag_path=="/alert/info/senderName") {
      info->setSenderName(value);
    }
    if(tag_path=="/alert/info/headline") {
      info->setHeadline(value);
    }
    if(tag_path=="/alert/info/description") {
      info->setDescription(value);
    }
    if(tag_path=="/alert/info/instruction") {
      info->setInstruction(value);
    }
    if(tag_path=="/alert/info/web") {
      info->setWeb(value);
    }
    if(tag_path=="/alert/info/contact") {
      info->setContact(value);
    }
    if(tag_path=="/alert/info/parameter/valueName") {
      pstate->appendValue(value.toUtf8(),"valueName");
    }
    if(tag_path=="/alert/info/parameter/value") {
      pstate->appendValue(value.toUtf8(),"value");
    }
    if(tag_path=="/alert/info/parameter") {
      info->addParameter(pstate->value("valueName"),pstate->value("value"));
      pstate->clearValue("valueName");
      pstate->clearValue("value");
    }

    if(tag_path=="/alert/info") {
      alert->addInfo(*info);
      pstate->freeInfo();
    }
  }

  //
  // <resource> Tags
  //
  CCResource *res=pstate->resource();
  if(res!=NULL) {
    if(tag_path=="/alert/info/resource/resourceDesc") {
      res->setResourceDesc(value);
    }
    if(tag_path=="/alert/info/resource/mimeType") {
      res->setMimeType(value);
    }
    if(tag_path=="/alert/info/resource/size") {
      res->setSize(value.toInt());
    }
    if(tag_path=="/alert/info/resource/uri") {
      res->setUri(value);
    }
    //
    // FIXME: Support derefUri!
    //
    if(tag_path=="/alert/info/resource/digest") {
      res->setDigest(value);
    }
    if(tag_path=="/alert/info/resource") {
      info->addResource(*res);
      pstate->freeResource();
    }
  }

  //
  // <area> Tags
  //
  CCArea *area=pstate->area();
  if(area!=NULL) {
    if(tag_path=="/alert/info/area/areaDesc") {
      area->setAreaDesc(value);
    }
    if(tag_path=="/alert/info/area/polygon") {
      QList<CCPoint> pts;
      QStringList f0=value.split(" ",QString::SkipEmptyParts);
      if(f0.size()>=4) {
	for(int i=0;i<f0.size();i++) {
	  QStringList f1=f0.at(i).split(",");
	  if(f1.size()==2) {
	    pts.push_back(CCPoint(f1.at(0).toFloat(),f1.at(1).toFloat()));
	  }
	}
      }
      CCPolygon poly(pts);
      if(poly.isClosed()) {
	area->addPolygon(poly);
      }
    }
    if(tag_path=="/alert/info/area/circle") {
      QStringList f0=value.split(" ",QString::SkipEmptyParts);
      if(f0.size()==2) {
	QStringList f1=f0.at(0).split(",");
	if(f1.size()==2) {
	  area->
	    addCircle(CCCircle(CCPoint(f1.at(0).toFloat(),f1.at(1).toFloat()),
			       f0.at(1).toFloat()));
	}
      }
    }
    if(tag_path=="/alert/info/area/geocode/valueName") {
      pstate->appendValue(value.toUtf8(),"valueName");
    }
    if(tag_path=="/alert/info/area/geocode/value") {
      pstate->appendValue(value.toUtf8(),"value");
    }
    if(tag_path=="/alert/info/area/geocode") {
      area->addGeocode(pstate->value("valueName"),pstate->value("value"));
      pstate->clearValue("valueName");
      pstate->clearValue("value");
    }
    if(tag_path=="/alert/info/area/altitude") {
      area->setAltitude(value.toInt());
    }
    if(tag_path=="/alert/info/area/ceiling") {
      area->setCeiling(value.toInt());
    }
    if(tag_path=="/alert/info/area") {
      info->addArea(*area);
      pstate->freeArea();
    }
  }
  
  pstate->popTag();
}


CCAlert CCAlert::fromXml(const QByteArray &xml,bool *ok)
{
  XML_Parser parser=XML_ParserCreate("UTF-8");
  if(ok!=NULL) {
    *ok=true;
  }

  ParserState pstate(new CCAlert());
  XML_SetUserData(parser,&pstate);
  XML_SetElementHandler(parser,
			__Capcomm_XmlElementStart,__Capcomm_XmlElementEnd);
  XML_SetCharacterDataHandler(parser,__Capcomm_XmlElementData);

  if(XML_Parse(parser,xml.constData(),xml.size(),0)!=XML_STATUS_OK) {
    if(ok!=NULL) {
      *ok=false;
    }
    fprintf(stderr,"Parser error!\n");
    return CCAlert();
  }
  
  XML_ParserFree(parser);

  return *(pstate.alert());
}
