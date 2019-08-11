CFLAGS	=		-Wall

OUTPUT	=		main
OBJS	=		$(patsubst %.c, %.o, $(wildcard *.c))
INCS	=		$(wildcard *.h)

$(OUTPUT):		$(OBJS) $(INCS)
				@echo "Compiling "$@
				$(CC) $(CFLAGS) $(OBJS) -o $@

%.o:			%.c $(INCS)
				@echo "Compiling "$<
				$(CC) $(CFLAGS) -c $<

.PHONY: clean
clean:
				@echo "Cleaning..."
				rm -f *.o $(OUTPUT)