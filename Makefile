CXX = g++
LDFLAGS = -Wall -Wcpp -I/usr/local/include/ImageMagick-7 -L/usr/local/lib -lMagick++-7.Q16 -lMagickWand-7.Q16 -lMagickCore-7.Q16

SOURCES = fulmokreilo.cpp

OBJECTS = $(SOURCES: .cpp = .o)

TARGET = fulmokreilo

$(TARGET): $(OBJECTS)
	$(CXX) $^ $(LDFLAGS) -o $@

clean:
	$(RM) $(TARGET) $(OBJECTS)


