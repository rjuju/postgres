# contrib/pg_freespacemap/Makefile

MODULE_big = pg_freespacemap
OBJS = \
	$(WIN32RES) \
	pg_freespacemap.o

EXTENSION = pg_freespacemap
DATA = pg_freespacemap--1.1.sql \
	pg_freespacemap--1.2--1.3.sql \
	pg_freespacemap--1.1--1.2.sql \
	pg_freespacemap--1.0--1.1.sql
PGFILEDESC = "pg_freespacemap - monitoring of free space map"

REGRESS_OPTS = --temp-config $(top_srcdir)/contrib/pg_freespacemap/pg_freespacemap.conf
REGRESS = pg_freespacemap

# Disabled because these tests require "autovacuum=off", which
# typical installcheck users do not have (e.g. buildfarm clients).
NO_INSTALLCHECK = 1

ifdef USE_PGXS
PG_CONFIG = pg_config
PGXS := $(shell $(PG_CONFIG) --pgxs)
include $(PGXS)
else
subdir = contrib/pg_freespacemap
top_builddir = ../..
include $(top_builddir)/src/Makefile.global
include $(top_srcdir)/contrib/contrib-global.mk
endif
