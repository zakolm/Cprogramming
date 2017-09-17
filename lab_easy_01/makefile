CC := gcc
OPTS = -g0
CFLAGS := -std=c99 

main.exe : main.o program_math.o program_resource.o
	$(CC) $^ -o $@ 
	
%.o : %.c *.h
	$(CC) $(CFLAGS) $(OPTS) -c $<
	
uni_tests : program_math.o program_resource.o uni_tests.o
	$(CC) $^ -o $@
	./uni_tests.exe
clean :
	rm *.o *.exe
