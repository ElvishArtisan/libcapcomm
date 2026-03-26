// ccalert.h
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

#ifndef CCALERT_H
#define CCALERT_H

#include <QDateTime>
#include <QList>
#include <QString>
#include <QStringList>

#include <capcomm/ccinfo.h>
#include <capcomm/ccreference.h>
#include <capcomm/ccxmldoc.h>

class CCAlert : public CCXmlDoc
 {
  public:
   enum AlertStatus {StatusUnknown=0,StatusActual=1,StatusExercise=2,
		     StatusSystem=3,StatusTest=4,StatusDraft=5,StatusLast=6};
   enum MsgType {MsgTypeUnknown=0,MsgTypeAlert=1,MsgTypeUpdate=2,
		 MsgTypeCancel=3,MsgTypeAck=4,MsgTypeError=5,MsgTypeLast=6};
   enum Scope {ScopeUnknown=0,ScopePublic=1,ScopeRestricted=2,
	       ScopePrivate=3,ScopeLast=4};
   CCAlert();
   QString identifier() const;
   void setIdentifier(const QString &str);
   QString sender() const;
   void setSender(const QString &str);
   QDateTime sent() const;
   void setSent(const QDateTime &dt);
   AlertStatus status() const;
   void setStatus(AlertStatus status);
   void setStatus(const QString &str);
   MsgType msgType() const;
   void setMsgType(const MsgType type);
   void setMsgType(const QString &str);
   QString source() const;
   void setSource(const QString &str);
   Scope scope() const;
   void setScope(Scope scope);
   void setScope(const QString &str);
   QString restriction() const;
   void setRestriction(const QString &str);
   int addressQuantity() const;
   QString addressAt(int n) const;
   int addAddress(const QString &addr);
   void removeAddress(int n);
   int codeQuantity() const;
   QString codeAt(int n) const;
   int addCode(const QString &str);
   void removeCodeAt(int n);
   QString note() const;
   void setNote(const QString &str);
   int referenceQuantity() const;
   CCReference referenceAt(int n) const;
   int addReference(const CCReference &ref);
   void removeReferenceAt(int n);
   int incidentQuantity() const;
   QString incidentAt(int n) const;
   int addIncident(const QString &identifier);
   void removeIncidentAt(int n);
   int infoQuantity() const;
   CCInfo *infoAt(int n) const;
   int addInfo(const CCInfo &info);
   void removeInfoAt(int n);
   QByteArray toXml();
   void clear();
   static QString statusString(AlertStatus status);
   static AlertStatus statusFromString(const QString &str);
   static QString msgTypeString(MsgType type);
   static MsgType msgTypeFromString(const QString &str);
   static QString scopeString(Scope scope);
   static Scope scopeFromString(const QString &str);
   static CCAlert fromXml(const QByteArray &xml,bool *ok=NULL);

 private:
   QString d_identifier;
   QString d_sender;
   QDateTime d_sent;
   AlertStatus d_status;
   MsgType d_msg_type;
   QString d_source;
   Scope d_scope;
   QString d_restriction;
   QStringList d_addresses;
   QStringList d_codes;
   QString d_note;
   QList<CCReference> d_references;
   QStringList d_incidents;
   QList<CCInfo *> d_infos;
 };


#endif  // CCALERT_H
