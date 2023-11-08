CC = g++
MKDIR = md
RMDIR = rd /S /Q
BIN = .\bin
SRC = .\src
OBJ = $(BIN)\Obj
EXE = $(BIN)\Out.exe
ENGINEDIR = ../Engine
INCLUDE = -I$(ENGINEDIR)/include
LFLAGS = -L$(ENGINEDIR)/bin/Binaries
LIBRARIES = -lEngine -lkernel32 -lgdi32 -luser32
CFLAGS = -std=c++2a -g -ggdb
CFLAGS += $(INCLUDE)
DEFINES = -DDEBUG
SRCS = $(wildcard $(SRC)/*.cpp)
HEADER = $(widlcard $(SRC)/*.hpp)
OBJS = $(patsubst $(SRC)/%.cpp, $(OBJ)/%.o, $(SRCS))

.PHONY: all clean run

all: make-dir $(EXE)

.SILENT: make-dir
make-dir:
	if not exist $(BIN)\ ($(MKDIR) $(BIN))
	if not exist $(OBJ)\ ($(MKDIR) $(OBJ))

$(EXE): $(OBJS) | $(OBJ)
	@echo [BUILD] Linking CXX Executable
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LFLAGS) $(LIBRARIES) 
	@echo [BUILD] Done

$(SRC)/%.cpp:
	@if 0

$(OBJ)/%.o: $(SRC)/%.cpp | $(OBJ)
	@echo [BUILD] Building $@
	@if not exist $@ echo > $@
	$(CC) $(CLFAGS) $(DEFINES) -c $^ -o $@

clean:
	$(RMDIR) $(BIN)

run: $(EXE)
	$^

.PHONY: engine
engine:
	$(MAKE) -C $(ENGINEDIR) --no-print-directory

.PHONY: dbg
dbg:
	@gdb $(EXE)
