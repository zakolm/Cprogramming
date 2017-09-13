CC := gcc
OPTS = -g0
CFLAGS := -std=c99 -Wall -Werror -pedantic

main.exe : main.o program_math.o program_resource.o
	$(CC) $^ -o $@ 
	
%.o : %.c *.h
	$(CC) $(CFLAGS) $(OPTS) -c $<
	
clean :
	rm *.o *.exe
