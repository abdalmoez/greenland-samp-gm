# This file demonstrates how to compile the GreenLand project on Linux.
#
# To compile GreenLand do:
#
# make greenland
#

GPP = g++ -m32 -std=c++11 -Ilib -fno-stack-protector -nodefaultlibs
GCC = gcc -m32 -Ilib -fno-stack-protector -nodefaultlibs
LINK = $(GCC)
OUTPUT_FILE = "GreenLand.so"
TARGET_OS=LINUX
TARGET_OS=WIN32
COMPILE_FLAGS = -c -O3 -fPIC -w -D${TARGET_OS}

GL = -D GREEN_LAND $(COMPILE_FLAGS)

all: greenland

clean:
	-rm -f *~ *.o *.so
  
static: GPP = g++ -m32 -std=c++11 -Ilib -fno-stack-protector -static-libgcc -static-libstdc++
static: GCC = gcc -m32 -Ilib -fno-stack-protector -static-libgcc -static-libstdc++
static: LINK = $(GPP)
static: all

greenland: clean
#	$(GPP) $(GL) ./lib/sampgdk/*.cpp  
	$(GPP) $(GL) ./src/*.cpp
	$(LINK) -fshort-wchar -shared -o $(OUTPUT_FILE) *.o
