FILE = kernel
NEWFILE = libkernel
CC = gcc
CFLAGS = -g -std=c99 -shared -O3 -Wall -Wvla

$(NEWFILE): $(FILE).c
	$(CC) $(CFLAGS) -o $@.so $^

clean:
	rm -rf $(NEWFILE) *.so *.a *.dylib *.dSYM
