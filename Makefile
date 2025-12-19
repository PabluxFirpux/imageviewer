CFLAGS = -Wall -pedantic
SDLFLAGS = `sdl2-config --cflags --libs`

SRC = main.o

all: imageviewer
	./imageviewer ./gojo.ppm

imageviewer: $(SRC)
	gcc $(CFLAGS) $(SRC) -o imageviewer $(SDLFLAGS)

%.o : %.c
	gcc -c $(CFLAGS) $?

clean :
	@echo "Removing trash"
	@rm *.o || rm *.out || echo "Already clean :)"