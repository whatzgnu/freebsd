# $FreeBSD$

PACKAGE=runtime
PROG=	rc-service
LINKS=	${BINDIR}/rc-service ${BINDIR}/service
SRCS=	rc-service.c \
       	${.CURDIR}/../../contrib/openrc/rc-misc.c \
       	${.CURDIR}/../../contrib/openrc/_usage.c
CFLAGS+=	-I${.CURDIR}/../../contrib/openrc \
	       	-I${.CURDIR}/../../lib/libeinfo \
	       	-I${.CURDIR}/../../lib/librc \
	       	-I${.CURDIR}/../../include

WARNS?=	3
MAN=	rc-service.8 service.8

LIBADD=	einfo rc util

.include <bsd.prog.mk>
