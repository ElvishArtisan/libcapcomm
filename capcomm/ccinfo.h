// ccinfo.h
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

#ifndef CCINFO_H
#define CCINFO_H

#include <QDateTime>
#include <QList>
#include <QMap>
#include <QString>
#include <QStringList>

#include <capcomm/ccarea.h>
#include <capcomm/ccresource.h>
 
class CCInfo
{
 public:
  enum Category {CategoryUnknown=0,CategoryGeo=1,CategoryMet=2,
		 CategorySafety=3,CategorySecurity=4,CategoryRescue=5,
		 CategoryFire=6,CategoryHealth=7,CategoryEnv=8,
		 CategoryTransport=9,CategoryInfra=10,CategoryCBRNE=11,
		 CategoryOther=12,CategoryLast=13};
  enum ResponseType {ResponseTypeUnknown=0,ResponseTypeShelter=1,
		     ResponseTypeEvacuate=2,ResponseTypePrepare=3,
		     ResponseTypeExecute=4,ResponseTypeAvoid=5,
		     ResponseTypeMonitor=6,ResponseTypeAssess=7,
		     ResponseTypeAllClear=8,ResponseTypeNone=9,
		     ResponseTypeLast=10};
  enum Urgency {UrgencyUnknown=0,UrgencyImmediate=1,UrgencyExpected=2,
		UrgencyFuture=3,UrgencyPast=4,UrgencyLast=5};
  enum Severity {SeverityUnknown=0,SeverityExtreme=1,SeveritySevere=2,
		 SeverityModerate=3,SeverityMinor=4,SeverityLast=5};
  enum Certainty {CertaintyUnknown=0,CertaintyObserved=1,CertaintyLikely=2,
		  CertaintyPossible=3,CertaintyUnlikely=4,CertaintyLast=5};
  CCInfo();
  QString language() const;
  void setLanguage(const QString &str);
  int categoryQuantity() const;
  Category categoryAt(int n) const;
  int addCategory(Category category);
  int addCategory(const QString &str);
  void removeCategoryAt(int n);
  QString event() const;
  void setEvent(const QString &str);
  int responseTypeQuantity() const;
  ResponseType responseTypeAt(int n);
  int addResponseType(const ResponseType &resp_type);
  int addResponseType(const QString &str);
  void removeResponseTypeAt(int n);
  Urgency urgency() const;
  void setUrgency(Urgency urg);
  void setUrgency(const QString &str);
  Severity severity() const;
  void setSeverity(Severity sev);
  void setSeverity(const QString &str);
  Certainty certainty() const;
  void setCertainty(Certainty cert);
  void setCertainty(const QString &str);
  QString audience() const;
  void setAudience(const QString &str);
  QStringList eventCodeNames() const;
  QString eventCodeValue(const QString &name) const;
  void addEventCode(const QString &name,const QString &value);
  void removeEventCode(const QString &name);
  QDateTime effective() const;
  void setEffective(const QDateTime &dt);
  void setEffective(const QString &str);
  QDateTime onset() const;
  void setOnset(const QDateTime &dt);
  void setOnset(const QString &str);
  QDateTime expires() const;
  void setExpires(const QDateTime &dt);
  void setExpires(const QString &str);
  QString senderName() const;
  void setSenderName(const QString &str);
  QString headline() const;
  void setHeadline(const QString &str);
  QString description() const;
  void setDescription(const QString &str);
  QString instruction() const;
  void setInstruction(const QString &str);
  QString web() const;
  void setWeb(const QString &url);
  QString contact() const;
  void setContact(const QString &str);
  QStringList parameterNames() const;
  QString parameterValue(const QString &name) const;
  void addParameter(const QString &name,const QString &value);
  void removeParameter(const QString &name);
  int resourceQuantity() const;
  CCResource resourceAt(int n) const;
  int addResource(const CCResource &res);
  void removeResourceAt(int n);
  int areaQuantity() const;
  CCArea areaAt(int n) const;
  int addArea(const CCArea &res);
  void removeAreaAt(int n);
  void clear();
  static QString categoryString(Category cat);
  static Category categoryFromString(const QString &str);
  static QString responseTypeString(ResponseType resp);
  static ResponseType responseTypeFromString(const QString &str);
  static QString urgencyString(Urgency urg);
  static Urgency urgencyFromString(const QString &str);
  static QString severityString(Severity sev);
  static Severity severityFromString(const QString &str);
  static QString certaintyString(Certainty cert);
  static Certainty certaintyFromString(const QString &str);
  
 private:
  QString d_language;
  QList<Category> d_categories;
  QString d_event;
  QList<ResponseType> d_response_types;
  Urgency d_urgency;
  Severity d_severity;
  Certainty d_certainty;
  QString d_audience;
  QMap<QString,QString> d_event_codes;
  QDateTime d_effective;
  QDateTime d_onset;
  QDateTime d_expires;
  QString d_sender_name;
  QString d_headline;
  QString d_description;
  QString d_instruction;
  QString d_web;
  QString d_contact;
  QMap<QString,QString> d_parameters;
  QList<CCResource> d_resources;
  QList<CCArea> d_areas;
};


#endif  // CCALERT_H
