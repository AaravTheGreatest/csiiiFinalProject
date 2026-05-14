main:
	g++ -o build/main src/main.cpp src/entity.cpp $(shell pkg-config --cflags --libs sfml-all) -Iinclude
clean:
	rm main
