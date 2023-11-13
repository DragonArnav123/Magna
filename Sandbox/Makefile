CC = g++
MKDIR = md
RMDIR = rd /S /Q
CLRSCR = cls 
BIN = .\bin
SRC = .\src
OBJ = $(BIN)\Obj
EXE = $(BIN)\Out.exe
ENGINEDIR = ..\Engine
INCLUDE = -I$(ENGINEDIR)/include
INCLUDE += -I$(ENGINEDIR)/dependencies/spdlog/include
LFLAGS = -L$(ENGINEDIR)/bin/Binaries
LIBRARIES = -lMagna -lkernel32 -lgdi32 -luser32 -lopengl32
CFLAGS = -std=c++2a -g -ggdb
CFLAGS += $(INCLUDE)
DEFINES = -DDEBUG
SRCS = $(wildcard $(SRC)/*.cpp)
HEADER = $(wildcard $(SRC)/*.hpp)
OBJS = $(patsubst $(SRC)/%.cpp, $(OBJ)/%.o, $(SRCS))


.PHONY: all run clean engine dbg clean-build

all: make-dir $(EXE)

.SILENT: make-dir
make-dir:
	if not exist $(BIN)\ ($(MKDIR) $(BIN))
	if not exist $(OBJ)\ ($(MKDIR) $(OBJ))

$(EXE): $(OBJS) | $(OBJ)
	@echo [BUILD] Linking CXX Executable ... 
	$(CC) $(CFLAGS) -o $@ $^ $(LFLAGS) $(LIBRARIES) 
	@echo [BUILD] Done

$(SRC)/%.cpp:
	@if 0

$(OBJ)/%.o: $(SRC)/%.cpp | $(OBJ)
	@echo [BUILD] Building $@
	@if not exist $@ echo > $@
	$(CC) $(CFLAGS) $(DEFINES) -c $^ -o $@

clean:
	$(RMDIR) $(BIN)

run: $(EXE)
	@echo [BUILD] Deleteting Old Engine Dll File ...
	@del $(BIN)\libMagna.dll > nul
	@echo [BUILD] Copying Engine DLL File ...
	@copy $(ENGINEDIR)\bin\binaries\libMagna.dll $(BIN) > nul
	$^

engine:
	$(MAKE) -C $(ENGINEDIR) --no-print-directory cbuild

dbg:
	@gdb $(EXE)

clean-build: clean all
