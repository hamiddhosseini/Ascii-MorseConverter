CC = gcc
CFlags= -std=c99 -Wall -g -I ./include/
Out = ./bin

both: ./src/morsetoascii.c ./src/asciitomorse.c
	$(CC) $(CFlags) ./src/morsetoascii.c -o $(Out)/morsetoascii
	$(CC) $(CFlags) ./src/asciitomorse.c -o $(Out)/asciitomorse
check-morsetoascii: ./src/morsetoascii.c
	$(CC) -c ./src/morsetoascii.c
check-asciitomorse: ./src/asciitomorse.c
	$(CC) -c ./src/asciitomorse.c
%.o: %.c
	$(CC) $(CFlags) -c $^
clean:
	rm -f $(Out)/morsetoascii $(Out)/asciitomorse
