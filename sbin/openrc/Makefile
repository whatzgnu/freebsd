# $FreeBSD$

PACKAGE=runtime
PROG=	openrc
LINKS=  ${BINDIR}/openrc ${BINDIR}/rc
SRCS=	rc.c rc-logger.c \
       	${.CURDIR}/../../contrib/openrc/rc-misc.c \
       	${.CURDIR}/../../contrib/openrc/rc-plugin.c \
       	${.CURDIR}/../../contrib/openrc/_usage.c
INCS=	rc-logger.h
CFLAGS+=	-I${.CURDIR}/../../contrib/openrc \
	       	-I${.CURDIR}/../../lib/libeinfo \
	       	-I${.CURDIR}/../../lib/librc \
	       	-I${.CURDIR}/../../include

WARNS?=	3
MAN=	openrc.8

LIBADD=	einfo rc util

.include <bsd.prog.mk>
