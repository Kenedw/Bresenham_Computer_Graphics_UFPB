CC = g++

all: 
	# $(CC) main.cpp -lglut -lGLU -lGL -I. -o cgprog
	$(CC) -o cgprog -Wall main.cpp -mwindows -lglut32 -lopengl32 -lglu32 -I.
	cgprog.exe
clean:
	rm cgprog.*

