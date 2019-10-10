pillar: pillar.c
	gcc -o pillar pillar.c -lglut -lGL -lGLU -lm

run: pillar
	bspc rule -a \* -o state=floating && ./pillar

.PHONY: clean

clean:
	rm pillar
