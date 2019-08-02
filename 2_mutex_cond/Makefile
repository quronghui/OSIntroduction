# compile condition
CC	=	gcc
CFLAGS	=	-g 	-Wall
INCLUDE	=	-I.
PTHREADLIB	=	-pthread

#all
# all:	condition_vailable	
all:	producter_comsumer

# target file link
condition_vailable:	condition_vailable.o	mutex_api.o		cond_api.o
	$(CC)	$^	-o	$@	$(PTHREADLIB)

producter_comsumer:	producter_comsumer.o mutex_api.o	cond_api.o
	$(CC)	$^	-o	$@	$(PTHREADLIB)

# *.o file compile
mutex_api.o: mutex_api.c mutex_api.h
	$(CC)	$(CFLAGS)	-c	$(INCLUDE)	$<	-o	$@

cond_api.o: cond_api.c mutex_api.h
	$(CC)	$(CFLAGS)	-c	$(INCLUDE)	$<	-o	$@

condition_vailable.o: condition_vailable.c mutex_api.h cond_api.h
	$(CC)	$(CFLAGS)	-c	$(INCLUDE)	$<	-o	$@

producter_comsumer.o: producter_comsumer.c mutex_api.h cond_api.h
	$(CC)	$(CFLAGS)	-c	$(INCLUDE)	$<	-o	$@


clean:	
	@echo "cleanning project"
	-rm	condition_vailable	producter_comsumer
	-rm *.o 
	@echo "cleanning complie"
.PHONY:	clean

