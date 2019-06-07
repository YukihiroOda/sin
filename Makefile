# For project sin

a.out: main.c sin.c
	gcc $^

test: test.c sin.c
	gcc $^ -o test

.PHONY: clean
clean:
	rm -f *.o
