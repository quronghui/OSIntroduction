# 编译条件
CC	=	gcc
CFLAGS	=	-g -Wall 
THREADLIB	=	 -lpthread	# 线程的动态连接库
INCLUDE	=	-I.
#all
# all: thread_create share_data
all:	thread_join

# 目标文件编译
thread_create:	thread_create.o 
	$(CC) $^ -o $@	$(THREADLIB)

share_data:	share_data.o 
	$(CC) $^ -o $@	$(THREADLIB)

thread_join:	thread_join.o 
	$(CC) $^ -o $@	$(THREADLIB)

# .o文件编译
thread_create.o: thread_create.c
	$(CC)	$(CFLAGS)	-c   $(INCLUDE) $<	-o $@

share_data.o: share_data.c
	$(CC)	$(CFLAGS)	-c $(INCLUDE) $<	-o $@

thread_join.o: thread_join.c
	$(CC)	$(CFLAGS)	-c  $(INCLUDE) $<	-o $@



clean:	
	@echo "cleanning project"
	-rm thread_create share_data
	-rm thread_join
	-rm *.o 
	@echo "cleanning complie"
.PHONY:	clean