# the compiler: define as g++ for C++
CC = g++

# compiler flags:
CFLAGS  = -g -std=c++23 -Werror -Wall -Wno-unknown-pragmas -fno-elide-constructors

# define any libraries to link into executable:
LIBS = -lpthread -lrt

# the build target executable:
TARGET=main
mkfile_path:=$(abspath $(lastword $(MAKEFILE_LIST)))
#OUTPUT:=$(notdir $(patsubst %/,%,$(dir $(mkfile_path))))

all: 
	$(CC) $(TARGET).cpp -o a.out $(CFLAGS) $(LIBS)

clean:
	rm *.out
