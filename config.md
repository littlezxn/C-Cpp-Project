# introduction
This is a simple C/C++ project that demonstrates how to compile and run C/C++ code
using standard tools like gcc and g++. The project is organized into separate directories for C and C++ source files, making it easy to navigate and understand the structure of the code. This README provides an overview of the project, instructions for setting up the development environment, and tips for compiling and running the code effectively. Whether you're a beginner or an experienced developer, this project serves as a practical example of how to work with C/C++ in a structured manner.

# Configuration
To compile and run the C/C++ files in this project, you can use the following commands
To execute the C/C++ file i'll highly recommand you to use linux OS but if you're using windows use gcc/g++ or Msys2 for better performance.
# gcc/g++ Command to compile and run C/C++ files
* To compile a C file:
```
gcc input_file.c
```
* To compile a C++ file:
```
g++ input_file.cpp
```
* To run the compiled output file:
```
./output_file_name
```

# msys2 Command to update and install gcc/g++
* command to update msys2
```
pacman -Suy
```
*  command to install gcc/g++ for windows
```
pacman -S --needed base-devel mingw-w64-x86_64-toolchain
```
* Add msys2 to your system path for better performance and easy access to gcc/g++ from command line.
Search for "Environment Variables" in Windows
Click on "Environment Variables"
Under "System variables", find and select the "Path" variable, then click "Edit"
Click "New" and add the path to your msys2 installation's bin directory
```
C:\msys64\usr\bin
C:\msys64\mingw64\bin
```
Click "OK" to save the changes and close all dialog boxes.