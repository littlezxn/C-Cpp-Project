CXX      = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

# ─── File Handling ─────────────────────────────────────────
file01: Cpp/File\ Handling/File01/File01.cpp
	$(CXX) $(CXXFLAGS) -o bin/file01 $

file02: Cpp/File\ Handling/File02/File02.cpp
	$(CXX) $(CXXFLAGS) -o bin/file02 $

# ─── OOP ───────────────────────────────────────────────────
oop01: Cpp/oops/oops01/oop01.cpp
	$(CXX) $(CXXFLAGS) -o bin/oop01 $

oop02: Cpp/oops/oops02/oop02.cpp
	$(CXX) $(CXXFLAGS) -o bin/oop02 $

oop03: Cpp/oops/oops03/oop03.cpp
	$(CXX) $(CXXFLAGS) -o bin/oop03 $

oop04: Cpp/oops/oops04/oop04.cpp
	$(CXX) $(CXXFLAGS) -o bin/oop04 $

oop05: Cpp/oops/oops05/oop05.cpp
	$(CXX) $(CXXFLAGS) -o bin/oop05 $

# ─── Recursion ─────────────────────────────────────────────
factorial: Cpp/recursion/Factorial/Factorial.cpp
	$(CXX) $(CXXFLAGS) -o bin/factorial $

# ─── Build All ─────────────────────────────────────────────
all: bin file01 file02 oop01 oop02 oop03 oop04 oop05 factorial

bin:
	mkdir -p bin

clean:
	rm -rf bin/

.PHONY: all clean file01 file02 oop01 oop02 oop03 oop04 oop05 factorial