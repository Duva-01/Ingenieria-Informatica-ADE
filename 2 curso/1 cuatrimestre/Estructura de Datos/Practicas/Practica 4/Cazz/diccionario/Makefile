INC = include
OBJ = obj
SRC = src
BIN = bin
LIB = lib
DATOS = datos
CXX = g++
CPPFLAGS = -Wall -g -std=c++11
CXXFLAGS = -c -I./$(INC)

all: diccionario
	./$(BIN)/usodiccionario ./$(DATOS)/data.txt

diccionario: $(BIN)/usodiccionario

$(BIN)/usodiccionario: $(OBJ)/usodiccionario.o $(LIB)/libdiccionario.a
	$(CXX) -o $@ $< -ldiccionario -L./$(LIB)

$(LIB)/libdiccionario.a: $(OBJ)/diccionario.o
	ar -rvs $@ $^

$(OBJ)/usodiccionario.o: $(SRC)/usodiccionario.cpp $(INC)/diccionario.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $< -o $@

$(OBJ)/diccionario.o: $(SRC)/diccionario.cpp $(INC)/diccionario.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $< -o $@

clean:
	@rm $(OBJ)/*.o
	@rm $(BIN)/*
	@rm $(LIB)/*.a
	@echo "Archivos borrados con exito"

autor:
	@echo "FRANCISCO RODRIGUEZ JIMENEZ"
