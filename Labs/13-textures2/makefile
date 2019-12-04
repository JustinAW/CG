tex: cubemap.c
	gcc -o x cubemap.c SOIL/SOIL.c SOIL/image_DXT.c SOIL/image_helper.c SOIL/stb_image_aug.c -lglut -lGL -lGLU -lm

run: tex
	./x

.PHONY: clean

clean:
	rm x
