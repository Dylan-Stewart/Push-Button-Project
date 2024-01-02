# build an executable
all: MYLIGHTSLIB.o Blink.c
	gcc -c MYLIGHTSLIB.o MYLIGHTSLIB.c -lbcm2835
	gcc -o Blink Blink.c MYLIGHTSLIB.o -lbcm2835
clean:
	$(RM) MYLIGHTSLIB.o
	$(RM) Blink
