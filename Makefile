CC = gcc

SRCS := $(wildcard src/*.c)
BINS := $(SRCS:src/%.c=%)
BINS_RM := $(SRCS:src/%.c=%.o)

all: $(BINS)

$(BINS):
	$(CC) src/$@.c -o $@.o

clean:
	rm -f $(BINS_RM)
