wavio: main.o wav.o wavheader.o wavManager.o
	g++ -o wavio main.o wav.o wavheader.o wavManager.o
main.o: main.cpp wav.h wavheader.h wavManager.h
	g++ -c main.cpp
wav.o: wav.cpp wav.h
	g++ -c wav.cpp
wavManager.o: wavManager.cpp wavManager.h wavheader.h wav.h
	g++ -c wavManager.cpp
wavheader.o: wavheader.cpp wavheader.h
	g++ -c wavheader.cpp
clean:
	rm wav *.o
