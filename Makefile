DESTDIR?=
PREFIX?=/usr
BINDIR?=$(PREFIX)/bin
all: advreboot
advreboot.o: advreboot.c
advreboot: advreboot.o
install: advreboot
	install -vDm755 advreboot -t $(DESTDIR)$(BINDIR)
clean:
	rm -f *.o *.a *.out *.lib *.obj *.dll *.so *.exe advreboot
.PHONY: all clean