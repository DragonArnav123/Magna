# Find out how to use clang++
CC		   := g++ 
MKDIR	   := md 
RMDIR	   := rd /S /Q

BIN		   := .\bin
SRC		   := .\src
LIB        := .\dependencies
OBJ		   := $(BIN)\Obj
INC        := .\include
BINLIB     := $(BIN)\Lib
BINARIES   := $(BIN)\Binaries

INCLUDE     = -I"$(LIB)/glfw/include"
INCLUDE    += -I"$(LIB)/glew_/include"
INCLUDE	   += -I"$(LIB)/glm"
INCLUDE    += -I"$(INC)"

LIBGLFWDIR := $(LIB)\glfw
LIBGLEWDIR := $(LIB)\glew_

CFLAGS      = -std=c++2a -g -ggdb
CFLAGS	   += $(INCLUDE)
LFLAGS	    = -L"$(BINLIB)/glfw/src" 
LFLAGS     += -L"$(BINLIB)/glew/lib"

LIBRARIES   = -lglfw3 -lglew32
LIBRARIES  += -lkernel32 -lopengl32 -lgdi32 -luser32

# @TODO: defines for dirs
DEFINES		= -DDEBUG -DWINDOWS -DGLEW_STATIC

SRCS	   := $(wildcard $(SRC)/*.cpp)
OBJS		= $(patsubst $(SRC)/%.cpp,$(OBJ)/%.o,$(SRCS))
HEADERS    := $(wildcard $(SRC)/*.hpp)
EXE	       := $(BIN)\Out.exe
ENGLIB     := $(BINARIES)\libEngine.a
PCH 	   := $(INC)\std.hpp

.PHONY: all run clean

all: make-dir $(ENGLIB)

make-dir: 
	@if not exist $(BIN)\ ($(MKDIR) $(BIN))
	@if not exist $(OBJ)\ ($(MKDIR) $(OBJ))
	@if not exist $(BINLIB)\ ($(MKDIR) $(BINLIB))
	@if not exist $(BINARIES)\ ($(MKDIR) $(BINARIES))

$(SRC)/%.cpp:
	@if 0

$(OBJ)/%.o: $(SRC)/%.cpp | $(OBJ)
	@echo [ENGINE] Building $@
	@if not exist $@ echo > $@
	$(CC) $(CFLAGS) $(DEFINES) -c $^ -o $@

$(ENGLIB): build-lib $(OBJS) $(PCH) | $(BIN)
	@echo [ENGINE] Linking CXX Static Library 
	ar -qc $(ENGLIB) $(OBJS) "$(OBJ)\glfw\*" "$(OBJ)\glew\*"
	@echo [ENGINE] Done

$(PCH):
	@echo [ENGINE] Rebuilding PCH ...
	$(CC) -c $(PCH) -o $(INC)\std.hpp.gch

.SILENT: build-lib
build-lib: lib-glfw lib-glew
	@if not exist $(OBJ)\glfw\ ($(MKDIR) $(OBJ)\glfw\)
	@if not exist $(OBJ)\glew\ ($(MKDIR) $(OBJ)\glew\)
	@$(shell cd $(OBJ)\glfw\ && ar -x ..\..\lib\glfw\src\libglfw3.a)
	@$(shell cd $(OBJ)\glew\ && ar -x ..\..\lib\glew\lib\libglew32.a)

lib-glfw: | $(BINLIB)
	@echo [ENGINE] Building target glfw ...
	@if not exist $(BINLIB)\glfw ($(MKDIR) "$(BINLIB)/glfw" && cmake -S $(LIBGLFWDIR) -B $(BINLIB)/glfw -G "MinGW Makefiles" -DGLFW_BUILD_DOCS=OFF -DGLFW_BUILD_TESTS=OFF -DGLFW_BUILD_EXAMPLES=OFF)
	$(MAKE) -C "$(BINLIB)/glfw" --no-print-directory
# Target Examples off 

lib-glew: | $(BINLIB)
	@echo [ENGINE] Building target glew...
	@if not exist $(BINLIB)\glew ($(MKDIR) "$(BINLIB)/glew" && cmake -S $(LIBGLEWDIR)/build/cmake -B $(BINLIB)/glew -G "MinGW Makefiles" -DBUILD_UTILS=OFF)
	$(MAKE) -C "$(BINLIB)/glew/" --no-print-directory
# Target Examples off 

run: $(EXE)
	@$<

clean:
	$(RMDIR) $(BIN)

debugger: $(EXE)
	ggdb $<
