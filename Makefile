CC=gcc
CFLAGS=-Wall -Wextra -Iinclude/
LDFLAGS=-lm
OBJS=packet_filter.o

all: packet_filter

packet_filter: ${OBJS}
	${CC} -o $@ $^ ${LDFLAGS}

${OBJS}: %.o: %.c
	${CC} -c $< -o $@ ${CFLAGS}

install: packet_filter
	sudo cp packet_filter /usr/local/bin/

clean:
	rm -f ${OBJS} packet_filter

.PHONY: all install clean
