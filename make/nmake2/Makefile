package=soft
version=1.0
tarname=$(package)
distdir=$(tarname)-$(version)

all clean soft:
	cd src && $(MAKE) $@

dist:$(distdir).tar.gz

$(distdir).tar.gz:$(distdir)
	tar chof -$(distdir) | gzip -9 -c > $@

$(distdir):FORCE
	mkdir -p $(distdir)/src
	cp Makefile $(distdir)
	cp src/Makefile src/app.c $(distdir)/src

FORCE:
	rm -rf $(distdir).tar.gz

.PHONY:FORCE all clean dist
