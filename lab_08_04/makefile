CC := gcc
OPTS := -g0
OPTS2 := -fprofile-arcs -ftest-coverage
CFLAGS := -std=c99 -Wall -Werror -pedantic

app.exe : main.o matrix.o
	$(CC) $(OPTS2) $^ -o $@

%.o : %.c *.h
	$(CC) $(CFLAGS) $(OPTS2) $(OPTS) -c $<
clean :
	rm *o *.exe

