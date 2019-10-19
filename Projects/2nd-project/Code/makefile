rotary: weiglej_p2.c
	gcc -o rotary weiglej_p2.c hashtable.c drawfunctions.c showinfo.c -lglut -lGL -lGLU -lm

run: rotary
	bspc rule -a \* -o state=floating && ./rotary

.PHONY: clean

clean:
	rm rotary
