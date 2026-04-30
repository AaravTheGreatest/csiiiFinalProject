main:
	g++ -o main main.cpp $(shell pkg-config --cflags --libs sfml-all) -Iinclude
clean:
	rm main
