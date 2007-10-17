CFLAGS?=-pedantic -Wall

all:
	$(CC) $(CFLAGS) -o xdmshutdown xdmshutdown.c -lX11 -lXm -lSM -lXt -lICE -lXext

clean:
	rm -f xdmshutdown
