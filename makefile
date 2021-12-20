SRCS=${wildcard *.c}
OBJS=${SRCS:.c=.o}
INC = ./include
LIB = lib
LIBS = SDL2-2.0.0
CC = gcc
C_FLAGS = -Wall -Wextra -Werror

NAME = snake

%.o: %.c
	${CC} ${C_FLAGS} -c $< -o $@ -I${INC}

all: ${NAME}
${NAME}: ${OBJS}
	${CC} ${C_FLAGS} $^ -o $@ -I${INC} -L ${LIB} -l ${LIBS}
