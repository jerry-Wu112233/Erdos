# Executable Name
EXENAME = Erdos

# Object Types
OBJS = main.o

# Compilation Flags
CXX = clang++
CXXFLAGS = $(CS225) -std=c++14 -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic
LD = clang++
LDFLAGS = -std=c++14 -stdlib=libc++ -lc++abi -lm

# Custom Clang Enforcement
include Make/customClangEnforcement.mk

# Define Makefile Rules
.PHONY: all test clean output_msg

all : $(EXENAME)

output_msg: ; $(CLANG_VERSION_MSG)

$(EXENAME): output_msg $(OBJS)
	$(LD) $(OBJS) $(LDFLAGS) -o $(EXENAME)
#readFromFile.o: main.cpp
	#$(CXX) $(CXXFLAGS) main.cpp

test: output_msg catch/catchmain.cpp Tests/test.cpp
	$(LD) catch/catchmain.cpp Tests/test.cpp $(LDFLAGS) -o test

clean:
	-rm -f *.o $(EXENAME) test