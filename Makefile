CC:=g++
OUTPUT=CONVERSOR
SRC_DIR := src
OBJ_DIR := build/obj
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))
LDFLAGS := 
CPPFLAGS := 
CXXFLAGS := -std=c++17


 
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC)   $(CXXFLAGS)   -c -o $@ $^  

$(OUTPUT): $(OBJ_FILES)
	$(CC)  -o $@ $^   $(CXXFLAGS) 
clean :
	rm -rf build
	rm $(OUTPUT)
build:
	mkdir build
	mkdir build/obj

