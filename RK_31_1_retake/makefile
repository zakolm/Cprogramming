CC := gcc
OPTS := -std=c99
CFLAGS := -Wall -Werror

all: app.exe test.exe
test.exe: uni_test.o array.o constant.o
	$(CC) $(OPTS) $(CFLAGS) $^ -o $@
app.exe: main.o array.o constant.o
	$(CC) $(OPTS) $(CFLAGS) $^ -o $@
%.o: %.c *.h
	$(CC) $(OPTS) $(CFLAGS) -c $^
clean:
	rm *.o *.exe