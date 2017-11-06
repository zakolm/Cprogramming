CC := gcc
OPTS := -std=c99
#OPTS1 := -g0
OPTS2 := -fprofile-arcs -ftest-coverage -g0
FLAGS := -Wall -Werror -pedantic

app.exe: main.o MyMath.o WorkFile.o
	$(CC) $(OPTS) $(OPTS2) $^ -o $@
%.o: %.c *.h
	$(CC) $(OPTS) $(OPTS2) $(FLAGS) -c $<
clean:
	rm *.o *.exe
clean_gcov:
	rm *.gcno *.gcda *.gcov
