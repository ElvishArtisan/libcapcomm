## Makefile.am
##
## Makefile.am for libcapcomm library routines
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

AM_CPPFLAGS = -Wall -Wno-strict-aliasing -std=c++11 -fPIC -I$(top_srcdir) @QT5_CFLAGS@
MOC = @QT_MOC@

# The dependency for qt's Meta Object Compiler (moc)
moc_%.cpp:	%.h
	$(MOC) $< -o $@

clean-local:	
	rm -rf debug release

lib_LTLIBRARIES = libcapcomm.la
dist_libcapcomm_la_SOURCES = ccalert.cpp ccalert.h\
                             ccarea.cpp ccarea.h\
                             cccircle.cpp cccircle.h\
                             ccinfo.cpp ccinfo.h\
                             ccpoint.cpp ccpoint.h\
                             ccpolygon.cpp ccpolygon.h\
                             ccreference.cpp ccreference.h\
                             ccresource.cpp ccresource.h\
                             ccxmldoc.cpp ccxmldoc.h

nodist_libcapcomm_la_SOURCES = 

includedir = $(prefix)/include/capcomm

include_HEADERS = ccalert.h\
                  ccarea.h\
                  cccircle.h\
                  ccinfo.h\
                  ccpoint.h\
                  ccpolygon.h\
                  ccreference.h\
                  ccresource.h\
                  ccxmldoc.h

libcapcomm_la_LDFLAGS = -version-info $(INTERFACE_CURRENT):$(INTERFACE_REVISION):$(INTERFACE_AGE)

EXTRA_DIST = sy.pro

CLEANFILES = *~\
             *.idb\
             *ilk\
             *.obj\
             *.pdb\
             moc_*
MAINTAINERCLEANFILES = *~\
                       Makefile.in
