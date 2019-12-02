tex: texlab2d-zoom.c
	gcc -o x texlab2d-zoom.c SOIL/SOIL.c SOIL/image_DXT.c SOIL/image_helper.c SOIL/stb_image_aug.c -lglut -lGL -lGLU -lm

run: tex
	./x

.PHONY: clean

clean:
	rm x
