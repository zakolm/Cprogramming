CC := gcc
OPTS := -std=c99
#CFLAGS := -Wall #-Werror #-pedantic

all: test.exe

test.exe: uni_tests.o my_string.o
	$(CC) $(OPTS) $^ -o $@
%.o: %.c *.h
	$(CC) $(OPTS) -c $<
clean:
	rm *.o *.exe
