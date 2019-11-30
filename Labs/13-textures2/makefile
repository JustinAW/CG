tex: tex-lab2-zoom.c
	gcc -o x tex-lab2-zoom.c SOIL/SOIL.c SOIL/image_DXT.c SOIL/image_helper.c SOIL/stb_image_aug.c -lglut -lGL -lGLU -lm

run: tex
	./x

.PHONY: clean

clean:
	rm x
