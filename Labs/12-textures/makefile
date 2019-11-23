tex: texlab2D.c
	gcc -o x texlab2D.c -lglut -lGL -lGLU -lm

run: tex
	./x

.PHONY: clean

clean:
	rm x
