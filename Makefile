main:
	g++ -o main src/*.cpp $(shell pkg-config --cflags --libs sfml-all) -Iinclude
clean:
	rm main
