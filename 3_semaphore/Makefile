# compile condition
CC	=	gcc
CFLAGS	=	-g 	-Wall
INCLUDE	=	-I.
PTHREADLIB	=	-pthread

#all
# all:	semaphore_cond
all:	sem_ProductAndConsume

# target file link
semaphore_cond:	semaphore_cond.o	semaphore_mutex.o
	$(CC)	$^	-o	$@	$(PTHREADLIB)

sem_ProductAndConsume:	sem_ProductAndConsume.o semaphore_mutex.o
	$(CC)	$^	-o	$@	$(PTHREADLIB)

# *.o file compile
semaphore_mutex.o: semaphore_mutex.c semaphore_api.h
	$(CC)	$(CFLAGS)	-c	$(INCLUDE)	$<	-o	$@

semaphore_cond.o: semaphore_cond.c semaphore_api.h
	$(CC)	$(CFLAGS)	-c	$(INCLUDE)	$<	-o	$@

sem_ProductAndConsume.o: sem_ProductAndConsume.c semaphore_api.h
	$(CC)	$(CFLAGS)	-c	$(INCLUDE)	$<	-o	$@


#clean
clean:	
	@echo	"cleanning compile file "
	-rm	*.o
	-rm	semaphore_cond	sem_ProductAndConsume
	@echo	"cleanning  target file"
.PHONY:	clean