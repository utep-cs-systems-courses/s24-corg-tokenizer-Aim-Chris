OBJS = uimain.o tokenizer.o history.o
CFLAGS = -g -O3
all: myprogram
myprogram: $(OBJS)
	cc -o myprogram $(CFLAGS) $(OBJS)
$(OBJS): tokenizer.h history.h
clean:
	rm -f *.o myprogram
run: myprogram
	./myprogram
