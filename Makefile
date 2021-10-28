default:
	g++ src/main.cpp src/Functions.cpp -Wall -o Game.exe -static -O2 -Wno-missing-braces -I include/ -L lib/ -lraylib -lopengl32 -lgdi32 -lwinmm

