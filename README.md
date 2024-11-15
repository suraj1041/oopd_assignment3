# OOPD assignment 3A
Command 1: g++ -c main.cpp
g++: This is the GNU C++ compiler.
-c: This option tells the compiler to compile the file into an object file (.o) without linking.
main.cpp: The C++ source file to compile.
Result: Generates an object file named main.o containing the compiled code for main.cpp.

Command 2: g++ -g -o debug main.o
-g: This option includes debugging information in the generated executable.
-o debug: Specifies the name of the output executable file as debug.
main.o: The object file generated in the first command.

Command 3: g++ -O3 -o optimize main.o
g++: GNU C++ compiler.
-O3: This option enables high-level optimizations for performance.
-o optimize: Specifies the name of the output executable file as optimize.

main.cpp : test user program to test the library.
library.h : 
### Railway Scheduling Library

This library is designed to manage railway systems with the following features:

Stations: Each station can be associated with multiple railway lines.
Lines: Represents a collection of stations connected by a specific railway route.
Platforms: Each station has a single platform to handle train schedules.

### Platform Scheduling Rules:
- A platform can accommodate stopping trains with a minimum interval of 30 minutes between consecutive stoppages.
- Through trains (non-stopping) can pass through the platform with a minimum interval of 10 minutes.

### The user program is responsible for inputting train timings and ensuring schedules comply with these rules.

-As mentioned above same works for questions 2.
-Code block for reading CSV file was taken from chatBot.