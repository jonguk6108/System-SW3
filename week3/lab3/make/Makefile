# Makefile variable and clean rule

# Makefile variable is similar to <#define>.
# first you can define some veriable on the top of Makefile.
# to use variables, use $(variable name).
# $(variable name) will be translate variable value when makefile runs. 
# and there is some automatic variables in Makefile
# $@ : <Target>
# $^ : <Dependencies>
# $< : first element of <Dependencies>

# you can make some rules like clean rule.
# just typing what you want to run
# in clean rule, 'rm' command is used.

CC = g++
CFLAGS = -O2
TARGET = calc
OBJS = main.o adder.o multiplier.o 

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o : %.cpp
	$(CC) $(CFLAGS) -c $<

clean :
	rm -f *.o calc
