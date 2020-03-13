#
#target: source
#<tab>command
#<tab>command
#
PROG=	cl
SRCS=	cl.c cl_cal.c
MK_MAN= no
WARNS?=	3
install:
	cp ${PROG} /usr/local/bin/

test:
	-./${PROG} +
	-./${PROG} 0 +
	-./${PROG} -1 2 3 4 5
	./${PROG} 4 2 / 3 + 5 x 6 -
	./${PROG} 1
	./${PROG} -1 2 +

.include <bsd.prog.mk>
