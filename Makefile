ifeq ($(OS),Windows)
    CXX = x86_64-w64-mingw32-g++
    LDFLAGS = -I/usr/x86_64-w64-mingw32/include/GraphicsMagick -L/usr/x86_64-w64-mingw32/lib $(shell /usr/x86_64-w64-mingw32/bin/GraphicsMagick++-config --cxxflags --libs)
else
    CXX = g++
    LDFLAGS = -I/usr/include/GraphicsMagick -L/usr/lib $(shell GraphicsMagick++-config --cxxflags --libs)
endif

CXXFLAGS = -Wall

SOURCES = fulmokreilo.cpp

OBJECTS = $(SOURCES: .cpp = .o)

TARGET = fulmokreilo

$(TARGET): $(OBJECTS)
	$(CXX) $^ $(LDFLAGS) -o $@

clean:
	$(RM) $(TARGET) $(OBJECTS)


