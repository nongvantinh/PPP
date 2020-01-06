CXX		  := clang++
CXX_FLAGS := -Wall -Wextra -std=c++17 -g 

BIN		:= bin
SRC		:= src
INCLUDE	:= include /usr/include/cairo /usr/include/glib-2.0 /usr/lib/x86_64-linux-gnu/glib-2.0/include /usr/include/pixman-1 /usr/include/freetype2 /usr/include/libpng16 /usr/include/freetype2 
LIB		:= lib

LIBRARIES	:=
EXECUTABLE	:= main


all: $(BIN)/$(EXECUTABLE)

run: clean all
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/*.cpp
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) -L$(LIB) $^ -o $@ $(LIBRARIES)

clean:
	-rm $(BIN)/*