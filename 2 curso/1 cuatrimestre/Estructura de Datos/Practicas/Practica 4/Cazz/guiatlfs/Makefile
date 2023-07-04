INC = include
OBJ = obj
SRC = src
BIN = bin
LIB = lib
DATOS = datos
CXX = g++
CPPFLAGS = -Wall -g -std=c++11
CXXFLAGS = -c -I./$(INC)

all: $(BIN)/usoguia
	$(BIN)/usoguia ./$(DATOS)/guia.txt

$(BIN)/usoguia: $(OBJ)/usoguia.o
	$(CXX) -o $(BIN)/usoguia $(OBJ)/usoguia.o

$(OBJ)/usoguia.o: $(SRC)/usoguia.cpp
	$(CXX) $(CXXFLAGS) -o  $(OBJ)/usoguia.o $(SRC)/usoguia.cpp

# all: guiatlf
# 	./$(BIN)/usoguia ./$(DATOS)/guia.txt

# guiatlf: $(BIN)/usoguia

# $(BIN)/usoguia: $(OBJ)/usoguia.o $(LIB)/libtlf.a
# 	$(CXX) -o $@ $< -ltlf -L./$(LIB)

# $(LIB)/libtlf.a: $(OBJ)/guiatlf.o
# 	ar -rvs $@ $^

# $(OBJ)/usoguia.o: $(SRC)/usoguia.cpp $(INC)/guiatlf.h
# 	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $< -o $@

# $(OBJ)/guiatlf.o: $(SRC)/guiatlf.cpp $(INC)/guiatlf.h
# 	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $< -o $@

clean:
	@rm $(OBJ)/*.o
	@rm $(BIN)/*
	@echo "Archivos borrados con exito"

autor:
	@echo "FRANCISCO RODRIGUEZ JIMENEZ"


	
