CC := gcc
OPTS := -std=c99
CFLAGS := -Wall -Werror -pedantic

all: app.exe test.exe
app.exe: main.o list.o constant.o
	$(CC) $(OPTS) $(CFALGS) $^ -o $@
test.exe: uni_tests.o list.o
	$(CC) $(OPTS) $(CFALGS) $^ -o $@
%.o: %.c *.h
	$(CC) $(OPTS) $(CFALGS) -c $<
clean:
	rm *.o *.exe
