CC = g++

all: 
	# $(CC) main.cpp -lglut -lGLU -lGL -I. -o cgprog
	$(CC) -o ./build/cgprog -Wall ./src/main.cpp -mwindows -lglut32 -lopengl32 -lglu32 -I.
	cgprog.exe
clean:
	rm ./build/cgprog.*

