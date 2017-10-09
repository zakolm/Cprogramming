CC := gcc
OPTS := -g0
CFLAGS := -std=c99 -Wall -Werror -pedantic

app.exe : main.o matrix.o
	$(CC) $^ -o $@

%.o : %.c *.h
	$(CC) $(CFLAGS) $(OPTS) -c $<
clean :
	rm *o *.exe

