3dpillarlab: 3dpillarlab.c
	gcc -o pillar 3dpillarlab.c -lglut -lGL -lGLU -lm

run: 3dpillarlab
	bspc rule -a \* -o state=floating && ./pillar

.PHONY: clean

clean:
	rm pillar
