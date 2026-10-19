CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -Iinclude

SRC = src/main.cpp src/Gasto.cpp src/Categoria.cpp src/Carteira.cpp
BIN = sistema

$(BIN): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(BIN)

clean:
	rm -f $(BIN)

.PHONY: clean
