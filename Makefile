# --- CONFIGURACIÓN DEL COMPILADOR ---
CXX = g++.exe

# --- CONFIGURACIÓN DEL PROYECTO ---
TARGET = output/recetario_game.exe

# --- CONFIGURACIÓN DE LIBRERÍAS ---
SDL3_DIR = lib/SDL3/x86_64-w64-mingw32
SDL_TTF_DIR = lib/SDL_ttf/x86_64-w64-mingw32
SDL3_image_DIR = lib/SDL3_image/x86_64-w64-mingw32

INCLUDES = -Iinclude -I$(SDL3_DIR)/include -I$(SDL_TTF_DIR)/include -I$(SDL3_image_DIR)/include
LIBS = -L$(SDL3_DIR)/lib -L$(SDL_TTF_DIR)/lib -L$(SDL3_image_DIR)/lib -lSDL3_image -lSDL3_ttf -lSDL3

# --- BANDERAS (FLAGS) ---
CXXFLAGS = -std=c++14 $(INCLUDES) -m64
LDFLAGS = $(LIBS)

# --- BÚSQUEDA RECURSIVA DE ARCHIVOS ---
SOURCES = $(shell find src -name '*.cpp')
OBJECTS = $(SOURCES:.cpp=.o)

# --- REGLAS DE MAKEFILE ---
all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) -o $(TARGET) $(OBJECTS) $(LDFLAGS)

%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) $< -o $@

# --- REGLAS ADICIONALES ---
clean:
	rm -f $(OBJECTS) $(TARGET)

run: all
	./$(TARGET)