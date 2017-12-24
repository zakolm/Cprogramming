CC := gcc
OPTS := -std=c99
CFLAGS := -Wall -Werror -pedantic

test.exe: uni_tests.o my_string.o
	$(CC) $(OPTS) $(CFLAGS) $^ -o $@
%.o: %.c *.h
	$(CC) $(OPTS) $(CFLAGS) -c $<
clean:
	rm *.o *.exe
