PROG=game
CC=g++
CPPFLAGS=-Wc++11-extensions
LDFLAGS=-lncurses
SRC=$(wildcard *.cpp)
OBJS=$(SRC:.cpp=.o)

$(PROG): $(OBJS)
	$(CC) $(LDFLAGS) -o $(PROG) $(OBJS)
.cpp.o:
	$(CC) $(CPPFLAGS) -c $< -o $@
clean:
	rm -f $(PROG) $(OBJS)
run: clean $(PROG)
	./game
