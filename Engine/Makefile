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
INCLUDE	   += -I"$(LIB)/glm"
INCLUDE    += -I"dependencies/spdlog/include"
INCLUDE    += -I"$(GLAD)/include"
INCLUDE    += -I"$(INC)"

LIBGLFWDIR := $(LIB)\glfw
LIBSLOGDIR := $(LIB)\spdlog

CFLAGS      = -std=c++2a -g -ggdb
CFLAGS	   += $(INCLUDE)
LFLAGS	    = -L"$(BINLIB)/glfw/src" 
LFLAGS	   += -L"$(BINLIB)/spdlog" 
LFLAGS 	   += -m32 -static 

LIBRARIES   = -lglfw3 -lspdlog
LIBRARIES  += -lkernel32 -lopengl32 -lgdi32 -luser32

# @TODO: defines for dirs
DEFINES		= -DDEBUG -DWINDOWS 

SRCS	   := $(wildcard $(SRC)/*.cpp)
SRCSREND   := $(wildcard $(SRC)/renderer/*.cpp)
OBJS		= $(patsubst $(SRC)/%.cpp,$(OBJ)/%.o,$(SRCS))
OBJSREND   := $(patsubst $(SRC)/renderer/%.cpp, $(OBJ)/renderer/%.o, $(SRCSREND))
HEADERS    := $(wildcard $(SRC)/*.hpp)
EXE	       := $(BIN)\Out.exe
ENGLIBSTAT := $(BINARIES)\libEngine.a
ENGLIBSHAR := $(BINARIES)\libMagna.dll
PCH 	   := $(INC)\std.hpp
GLAD       := $(LIB)\glad
GLADSRC    := $(GLAD)\src\glad.c
OPENGL     := $(OBJ)\glad.o

.PHONY: all-scratch all run clean cbuild

all: make-dir $(ENGLIBSHAR)

all-scratch: clean make-dir dependencies all

make-dir: 
	@if not exist $(BIN)\ ($(MKDIR) $(BIN))
	@if not exist $(OBJ)\ ($(MKDIR) $(OBJ))
	@if not exist $(BINLIB)\ ($(MKDIR) $(BINLIB))
	@if not exist $(BINLIB)\glfw\ ($(MKDIR) $(BINLIB)\glfw\)
	@if not exist $(BINLIB)\spdlog\ ($(MKDIR) $(BINLIB)\spdlog\)
	@if not exist $(BINARIES)\ ($(MKDIR) $(BINARIES))
	@if not exist $(OBJ)\renderer\ ($(MKDIR) $(OBJ)\renderer\)

$(SRC)/%.cpp:
	@if 0

$(OBJ)/%.o: $(SRC)/%.cpp | $(OBJ)
	@echo [MAGNA] Building $@
	@if not exist $@ echo > $@
	$(CC) $(CFLAGS) $(DEFINES) -c $^ -o $@

$(OBJ)/renderer/%.o: $(SRC)/renderer/%.cpp | $(OBJ)
	@echo [MAGNA] Building $@
	@if not exist $@ echo > $@
	$(CC) $(CFLAGS) $(DEFINES) -c $^ -o $@

$(ENGLIBSHAR): $(OBJS) $(OBJSREND) $(OPENGL) | $(BIN) $(OBJ) $(PCH) dependencies
	@echo [MAGNA] Creating CXX Shared Library 
	@echo [MAGNA] Linking Source  $(SRCS) $(SRCSREND)
	$(CC) -shared -o $(ENGLIBSHAR) $^ $(LFLAGS) $(LIBRARIES)
	@echo [MAGNA] Done

$(PCH):
	@echo [MAGNA] Rebuilding PCH ...
	$(CC) -c $@ -o $(INC)\std.hpp.gch

$(GLADSRC):

$(OPENGL): $(GLADSRC) | $(OBJ)
	@echo [Magna] Building OpenGL API File : $@
	@if not exist $@ echo > $@
	$(CC) $(CFLAGS) $(DEFINES) -o $@ -c $^

dependencies: $(BINLIB)/glfw/src/libglfw3.a $(BINLIB)/spdlog/libspdlog.a

$(BINLIB)/glfw/src/libglfw3.a: | $(BINLIB)
	@echo [MAGNA] Building target glfw ...
	@if not exist $(BINLIB)\glfw ($(MKDIR) "$(BINLIB)/glfw") 
	cmake -S $(LIBGLFWDIR) -B $(BINLIB)/glfw -G "MinGW Makefiles" -DGLFW_BUILD_DOCS=OFF -DGLFW_BUILD_TESTS=OFF -DGLFW_BUILD_EXAMPLES=OFF -DBUILD_SHARED_LIBS=OFF
	$(MAKE) -C "$(BINLIB)/glfw" --no-print-directory -j 4

$(BINLIB)/spdlog/libspdlog.a: | $(BINLIB)
	@echo [MAGNA] Building target spdlog ...
	@if not exist $(BINLIB)\spdlog ($(MKDIR) "$(BINLIB)/spdlog")
	cmake -S $(LIBSLOGDIR)/ -B $(BINLIB)/spdlog -G "MinGW Makefiles" -DSPDLOG_ENABLE_PCH=ON -DSPDLOG_BUILD_EXAMPLE=OFF -DSPDLOG_BUILD_TESTS=OFF -DSPDLOG_BUILD_BENCH=OFF
	$(MAKE) -C "$(BINLIB)/spdlog/" --no-print-directory -j 4

$(BIN):
	@if not exist $(BIN)\ ($(MKDIR) $(BIN))

$(OBJ): | $(BIN)
	@if not exist $(OBJ)\ ($(MKDIR) $(OBJ))

$(LIB): | $(BIN)
	@if not exist $(BIN)\ ($(MKDIR) $(OBJ))

$(OBJ)/renderer/: | $(OBJ)
	@if not exist $(OBJ)\renderer\ ($(MKDIR) $(OBJ)\renderer\)

run: $(EXE)
	@$<

clean:
	$(RMDIR) $(BIN)
# @TODO: Figure out a way for us to not need to make libraries all the time

debugger: $(EXE)
	gdb $<

cbuild: clean all
