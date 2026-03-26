## Makefile.am
##
## Tests
##
## (C) Copyright 2026 Fred Gleason <fredg@paravelsystems.com>
##
##    This program is free software; you can redistribute it and/or modify
##    it under the terms of version 2.1 of the GNU Lesser General Public
##    License as published by the Free Software Foundation;
##
##    This program is distributed in the hope that it will be useful,
##    but WITHOUT ANY WARRANTY; without even the implied warranty of
##    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
##    GNU Lesser General Public License for more details.
##
##    You should have received a copy of the GNU General Public License
##    along with this program; if not, write to the Free Software
##    Foundation, Inc., 59 Temple Place, Suite 330, 
##    Boston, MA  02111-1307  USA
##
## Use automake to process this into a Makefile.in

AM_CPPFLAGS = -Wall -DPREFIX=\"$(prefix)\" -pthread -I$(top_srcdir) -std=c++11 -fPIC @QT5_CFLAGS@ @EXPAT_CFLAGS@
LIBS = -L$(top_srcdir)/capcomm @QT5_LIBS@
MOC = @QT_MOC@

# The dependency for qt's Meta Object Compiler (moc)
moc_%.cpp:	%.h
	$(MOC) $< -o $@


noinst_PROGRAMS = parsertest

dist_parsertest_SOURCES = parsertest.cpp parsertest.h
nodist_parsertest_SOURCES = moc_parsertest.cpp
parsertest_LDADD = -lcapcomm @EXPAT_LIBS@
#parsertest_LDFLAGS = @SWITCHYARDFLAGS@

CLEANFILES = *~\
             *.idb\
             *ilk\
             *.obj\
             *.pdb\
             moc_*

DISTCLEANFILES = rc.syd

MAINTAINERCLEANFILES = *~\
                       Makefile.in
