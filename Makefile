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

.c.o:		#.cファイルから.oファイルを作成
	cc -c -o ${.TARGET} ${.IMPSRC}	#${.ALLSRC}ではない 

cl.o: cl_cal.h	#.hのファイルを依存関係を定義
cl_cal.o: cl_cal.h

${PROG}: ${OBJS}
	cc    -o ${.TARGET} ${.ALLSRC}

clean:
	rm -f ${PROG} ${OBJS}

install:
	cp ${PROG} /usr/local/bin/

test:
	./${PROG} 1 2 3 4 x + /
