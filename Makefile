
CC=gcc

bmeter : bmeter.o
	$(CC) -o $@ $^ $(LDFLAGS) $(LIBS)
