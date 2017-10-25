CC := gcc
OPTS := -std=c99
FLAGS := -Wall -Werror -pedantic

app.exe: main.o matrix.o
	$(CC) $(OPTS) $^ -o $@
%.o: %.c %.h
	$(CC) $(OPTS) $(FLAGS) -c $<
clean:
	rm *.o *.exe
