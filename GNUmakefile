#
#target: source
#<tab>command
#<tab>command
#
PROG=	cl
OBJS=	cl.o cl_cal.o

all: ${PROG}

.SUFFIXES:
.SUFFIXES: .c .o

#.cファイルから.oファイルを作成
#${.ALLSRC}ではない 
.c.o:		
#	cc -c -o ${.TARGET} ${.IMPSRC}
	cc -c -o $@ $<
#.hのファイルを依存関係を定義
cl.o: cl_cal.h
cl_cal.o: cl_cal.h

${PROG}: ${OBJS}
#	cc    -o ${.TARGET} ${.ALLSRC}
	cc    -o $@ $?
clean:
	rm -f ${PROG} ${OBJS}

install:
	cp ${PROG} /usr/local/bin/

test:
	-./${PROG} +
	-./${PROG} 0 +
	-./${PROG} -1 2 3 4 5
	./${PROG} 4 2 / 3 + 5 x 6 -
	./${PROG} 1
	./${PROG} -1 2 +

