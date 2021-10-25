CC = g++
CXXFLAGS = -g -O2
OBJS = addr_decoder.o main.o
TARGET = ../bin/addr_decoder.out

%.o: %.cc
	$(CC) $(CXXFLAGS) -c $<

main : $(OBJS)
	$(CC) $(CXXFLAGS) $(OBJS) -o $(TARGET)

.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET)
