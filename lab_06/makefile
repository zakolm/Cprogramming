main.exe : main.o work_array.o result_ex.o
	gcc -o main.exe main.o work_array.o result_ex.o

main.o : main.c
	gcc -std=c99 -Wall -Werror -pedantic -c main.c

work_array.o : work_array.c
	gcc -std=c99 -Wall -Werror -pedantic -c work_array.c

result_ex.o : result_ex.c
	gcc -std=c99 -Wall -Werror -pedantic -c result_ex.c
	
clean :
	rm *.o *.exe