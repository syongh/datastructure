CC=gcc
TARGET=leetcode

SRCS=$(wildcard *.c)
OBJS=$(patsubst %.c,%.o,$(SRCS))

$(TARGET):$(OBJS)
#	$(CC)  $(OBJS) -o $(TARGET) 
	$(CC)  $(OBJS) -o $(TARGET) -g 

$(OBJS):%.o:%.c
#	$(CC) -c $^ -o $@ 
	$(CC) -c $^ -o $@  -g

clean: 
	rm -rf *.o $(TARGET)
