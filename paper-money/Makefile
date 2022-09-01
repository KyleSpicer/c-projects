.PHONY: all check clean profile debug
CFLAGS := -Wall -Werror -Wextra -Wpedantic -Wwrite-strings -Wstack-usage=1024 -Wfloat-equal -Waggregate-return -Winline
CC := gcc
EXE := money
EXE_MONEY_STATS := money_stats
OBJS := paper_money.o

all: $(EXE)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(EXE): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

$(EXE_MONEY_STATS): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ -pg

clean:
	rm -f *.o
	rm -f $(EXE) $(EXE_MONEY_STATS)
	rm -f *.out

check: $(EXE)
	@./$(EXE)

debug: $(EXE)
	 $(EXE) -n

profile: $(EXE)
	$(CC) -o $(EXE_MONEY_STATS) paper_money.c -pg
	./$(EXE_MONEY_STATS)
	gprof $(EXE_MONEY_STATS)