#variable
CC = gcc
CFLAGS = -Wall -std=c11 -Iinclude
OBJ_DIR = obj

# Ensure obj directory exists
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

all: log_parser

#linking
log_parser: obj/main.o obj/parser.o
	$(CC) obj/main.o obj/parser.o -o $@

obj/main.o:	src/main.c include/parser.h
	$(CC) $(CFLAGS) -c $< -o $@

obj/parser.o: src/parser.c include/parser.h
	$(CC) $(CFLAGS) -c $< -o $@

#run
run: log_parser
	./log_parser

#clean
clean:
	rm -f $(OBJ_DIR)/*.o log_parser