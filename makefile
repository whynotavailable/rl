PROG=game
CC=g++
CPPFLAGS=
LDFLAGS=-lncurses
SRC=$(wildcard *.cpp)
OBJS=$(SRC:.cpp=.o)

$(PROG): $(OBJS)
	$(CC) -o $(PROG) $(OBJS) $(LDFLAGS)
.cpp.o:
	$(CC) $(CPPFLAGS) -c $< -o $@
clean:
	rm -f $(PROG) $(OBJS)
run: clean $(PROG)
	./game
