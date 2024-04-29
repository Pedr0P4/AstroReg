all:
	g++ -c ./source/astro.cpp -I ./headers -o ./obj/astro.o
	g++ -c ./source/voo.cpp -I ./headers -o ./obj/voo.o
	g++ -c ./source/trip.cpp -I ./headers -o ./obj/trip.o
	g++ -c ./source/morto.cpp -I ./headers -o ./obj/morto.o
	g++ -c ./source/func.cpp -I ./headers -o ./obj/func.o
	g++ -c ./source/format.cpp -I ./headers -o ./obj/format.o
	g++ ./apps/main.cpp ./obj/*.o -I ./headers -o ./bin/AstroReg

run:
	./bin/AstroReg

clean:
	rm ./bin/* ./obj/*
