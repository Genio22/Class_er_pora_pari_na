# ============================================================
# Makefile — Stock Market Order Matching Engine
# ============================================================
CC      = gcc
CFLAGS  = -Wall -Wextra -pedantic -O2 -g
LDFLAGS =

# Source files grouped by module
SRCS = \
    main.c        \
    order.c       \
    trade.c       \
    baseline.c    \
    rbtree.c      \
    fibheap.c     \
    optimized.c   \
    scenario.c    \
    performance.c

OBJS   = $(SRCS:.c=.o)
TARGET = stock_engine

# ---- Default target -------------------------------------------
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

# ---- Compile each .c with dependency on its own .h -----------
main.o       : main.c order.h trade.h baseline.h optimized.h scenario.h performance.h
order.o      : order.c order.h
trade.o      : trade.c trade.h
baseline.o   : baseline.c baseline.h order.h trade.h
rbtree.o     : rbtree.c rbtree.h order.h
fibheap.o    : fibheap.c fibheap.h order.h
optimized.o  : optimized.c optimized.h order.h trade.h rbtree.h fibheap.h
scenario.o   : scenario.c scenario.h order.h
performance.o: performance.c performance.h

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

# ---- Convenience targets -------------------------------------
run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)

# Rebuild everything from scratch
rebuild: clean all

# Run under Valgrind for memory leak checking
memcheck: $(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all \
	         --track-origins=yes ./$(TARGET)

.PHONY: all run clean rebuild memcheck
