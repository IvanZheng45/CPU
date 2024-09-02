# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ivan/cpu

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ivan/cpu/build

# Include any dependencies generated for this target.
include ASSEMBLER/CMakeFiles/assembler.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include ASSEMBLER/CMakeFiles/assembler.dir/compiler_depend.make

# Include the progress variables for this target.
include ASSEMBLER/CMakeFiles/assembler.dir/progress.make

# Include the compile flags for this target's objects.
include ASSEMBLER/CMakeFiles/assembler.dir/flags.make

ASSEMBLER/CMakeFiles/assembler.dir/src/assemble.cpp.o: ASSEMBLER/CMakeFiles/assembler.dir/flags.make
ASSEMBLER/CMakeFiles/assembler.dir/src/assemble.cpp.o: ../ASSEMBLER/src/assemble.cpp
ASSEMBLER/CMakeFiles/assembler.dir/src/assemble.cpp.o: ASSEMBLER/CMakeFiles/assembler.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ivan/cpu/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object ASSEMBLER/CMakeFiles/assembler.dir/src/assemble.cpp.o"
	cd /home/ivan/cpu/build/ASSEMBLER && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT ASSEMBLER/CMakeFiles/assembler.dir/src/assemble.cpp.o -MF CMakeFiles/assembler.dir/src/assemble.cpp.o.d -o CMakeFiles/assembler.dir/src/assemble.cpp.o -c /home/ivan/cpu/ASSEMBLER/src/assemble.cpp

ASSEMBLER/CMakeFiles/assembler.dir/src/assemble.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/assembler.dir/src/assemble.cpp.i"
	cd /home/ivan/cpu/build/ASSEMBLER && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ivan/cpu/ASSEMBLER/src/assemble.cpp > CMakeFiles/assembler.dir/src/assemble.cpp.i

ASSEMBLER/CMakeFiles/assembler.dir/src/assemble.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/assembler.dir/src/assemble.cpp.s"
	cd /home/ivan/cpu/build/ASSEMBLER && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ivan/cpu/ASSEMBLER/src/assemble.cpp -o CMakeFiles/assembler.dir/src/assemble.cpp.s

# Object files for target assembler
assembler_OBJECTS = \
"CMakeFiles/assembler.dir/src/assemble.cpp.o"

# External object files for target assembler
assembler_EXTERNAL_OBJECTS =

ASSEMBLER/libassembler.a: ASSEMBLER/CMakeFiles/assembler.dir/src/assemble.cpp.o
ASSEMBLER/libassembler.a: ASSEMBLER/CMakeFiles/assembler.dir/build.make
ASSEMBLER/libassembler.a: ASSEMBLER/CMakeFiles/assembler.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ivan/cpu/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libassembler.a"
	cd /home/ivan/cpu/build/ASSEMBLER && $(CMAKE_COMMAND) -P CMakeFiles/assembler.dir/cmake_clean_target.cmake
	cd /home/ivan/cpu/build/ASSEMBLER && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/assembler.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
ASSEMBLER/CMakeFiles/assembler.dir/build: ASSEMBLER/libassembler.a
.PHONY : ASSEMBLER/CMakeFiles/assembler.dir/build

ASSEMBLER/CMakeFiles/assembler.dir/clean:
	cd /home/ivan/cpu/build/ASSEMBLER && $(CMAKE_COMMAND) -P CMakeFiles/assembler.dir/cmake_clean.cmake
.PHONY : ASSEMBLER/CMakeFiles/assembler.dir/clean

ASSEMBLER/CMakeFiles/assembler.dir/depend:
	cd /home/ivan/cpu/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ivan/cpu /home/ivan/cpu/ASSEMBLER /home/ivan/cpu/build /home/ivan/cpu/build/ASSEMBLER /home/ivan/cpu/build/ASSEMBLER/CMakeFiles/assembler.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : ASSEMBLER/CMakeFiles/assembler.dir/depend

