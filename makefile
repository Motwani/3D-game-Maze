all: 
	g++ -o game maze.cpp glad.c -lGL -lglfw -L/usr/local/lib -ldl
