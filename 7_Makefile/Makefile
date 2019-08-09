# specify all source files here
SRCS	=	main.c
SRCS	=	 hello.c

# specify target here (name of executable)
# TARG	=	main	
TARG	=	hello


# specify compiler, compile flags, and needed libs
CC	=	gcc
CFLAGS = -g -Wall
LIBS 	=	-lm 

# this translates	.c	file	in	src	list to .o's
OBJS	=	$(SRCS:	.c=.o)

#	all is not really	needed	, but is used to generate the target
all:	$(TARG)

# this generates the target executable
$(TARG):	$(OBJS)
	$(CC)	$(OBJS)		-o 	$(TARG)	

# this is a generic rule for .o files
%.o:	%.c 
	$(CC)	$(CFLAGS)	-c 	$<	$@

#clean
clean:	
	@echo "cleaning project"
	-rm *.o 	$(TARG)
	@echo "cleaning complie"
.PHONY:	clean