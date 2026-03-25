## automake.am
##
## Top level automake.am for Switchyard5
##
## Use automake to process this into a Makefile.in
##
##   (C) Copyright 2014-2022 Fred Gleason <fredg@paravelsystems.com>
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

SUBDIRS = capcomm\
          tests

ACLOCAL_AMFLAGS = -I m4

maintainer-clean-local:	
	rm -rf m4

deb:	dist
	./build_debs.sh

rpm:	dist
	cp libcapcomm-$(VERSION).tar.gz $(HOME)/rpmbuild/SOURCES/
	$(RPMBUILD) -ba --target $(ARCH)-$(VENDOR)-linux libcapcomm.spec
	mv $(HOME)/rpmbuild/RPMS/$(ARCH)/libcapcomm-*.rpm $(top_srcdir)/
	mv $(HOME)/rpmbuild/SRPMS/libcapcomm-*.src.rpm $(top_srcdir)/
	rm $(HOME)/rpmbuild/SOURCES/libcapcomm-$(VERSION).tar.gz
	rm -rf $(HOME)/rpmbuild/BUILD/libcapcomm-$(VERSION)

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = capcomm.pc

EXTRA_DIST = autogen.sh\
             capcomm.pc.in\
             get_distro.pl\
             get_target.sh\
             PACKAGE_VERSION

CLEANFILES = *~\
             *.buildinfo\
             *.changes\
             *.ddeb\
             *.deb\
             *.dsc\
             *.tar.gz\
             *.tar.xz\
             *.tgz\
             *.mo\
             *.rpm\
             *.zip
DISTCLEANFILES = *.spec\
                 build_debs.sh\
                 config.guess\
                 config.sub\
                 rc.syd
MAINTAINERCLEANFILES = *~\
                       *.pc\
                       *.tar.gz\
                       *.spec\
                       aclocal.m4\
                       compile\
                       configure\
                       config.guess\
                       config.status\
                       config.sub\
                       depcomp\
                       install-sh\
                       ltmain.sh\
                       Makefile.in\
                       missing\
                       mkinstalldirs
