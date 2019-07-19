# 编译条件
CC	=	gcc
CFLAGS	=	-g -Wall 

#all
all: valgrind_demo

# 目标文件编译
valgrind_demo:	valgrind_demo.o 
	$(CC) $^ -o $@

# .o文件编译
valgrind_demo.o: valgrind_demo.c
	$(CC)	$(CFLAGS)	-c $<	-o $@



clean:	
	@echo "cleanning project"
	-rm valgrind_demo 
	-rm *.o 
	@echo "cleanning complie"
.PHONY:	clean