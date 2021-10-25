CC = g++
CXXFLAGS = -g
OBJS = my_sort.o main.o
TARGET = ../bin/main.out

%.o: %.cc
	$(CC) $(CXXFLAGS) -c $<

main : $(OBJS)
	$(CC) $(CXXFLAGS) $(OBJS) -o $(TARGET)

.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET)
