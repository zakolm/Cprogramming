CC = gcc
OPTS = -g0
FLAGS = -std=c99 -Wall -Werror

app.exe: test.o str.o
	$(CC)  $^ -o $@
%.o: %.c *.h
	$(CC) $(FLAGS) $(OPTS) -c $<
clean:
	rm *.o *.exe
