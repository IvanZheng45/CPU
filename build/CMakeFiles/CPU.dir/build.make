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
CMAKE_SOURCE_DIR = /home/ivan/cpu/CPU

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ivan/cpu/CPU/build

# Include any dependencies generated for this target.
include CMakeFiles/CPU.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/CPU.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/CPU.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CPU.dir/flags.make

CMakeFiles/CPU.dir/src/cpu.cpp.o: CMakeFiles/CPU.dir/flags.make
CMakeFiles/CPU.dir/src/cpu.cpp.o: ../src/cpu.cpp
CMakeFiles/CPU.dir/src/cpu.cpp.o: CMakeFiles/CPU.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ivan/cpu/CPU/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CPU.dir/src/cpu.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/CPU.dir/src/cpu.cpp.o -MF CMakeFiles/CPU.dir/src/cpu.cpp.o.d -o CMakeFiles/CPU.dir/src/cpu.cpp.o -c /home/ivan/cpu/CPU/src/cpu.cpp

CMakeFiles/CPU.dir/src/cpu.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CPU.dir/src/cpu.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ivan/cpu/CPU/src/cpu.cpp > CMakeFiles/CPU.dir/src/cpu.cpp.i

CMakeFiles/CPU.dir/src/cpu.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CPU.dir/src/cpu.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ivan/cpu/CPU/src/cpu.cpp -o CMakeFiles/CPU.dir/src/cpu.cpp.s

CMakeFiles/CPU.dir/src/decoder.cpp.o: CMakeFiles/CPU.dir/flags.make
CMakeFiles/CPU.dir/src/decoder.cpp.o: ../src/decoder.cpp
CMakeFiles/CPU.dir/src/decoder.cpp.o: CMakeFiles/CPU.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ivan/cpu/CPU/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/CPU.dir/src/decoder.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/CPU.dir/src/decoder.cpp.o -MF CMakeFiles/CPU.dir/src/decoder.cpp.o.d -o CMakeFiles/CPU.dir/src/decoder.cpp.o -c /home/ivan/cpu/CPU/src/decoder.cpp

CMakeFiles/CPU.dir/src/decoder.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CPU.dir/src/decoder.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ivan/cpu/CPU/src/decoder.cpp > CMakeFiles/CPU.dir/src/decoder.cpp.i

CMakeFiles/CPU.dir/src/decoder.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CPU.dir/src/decoder.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ivan/cpu/CPU/src/decoder.cpp -o CMakeFiles/CPU.dir/src/decoder.cpp.s

CMakeFiles/CPU.dir/src/control.cpp.o: CMakeFiles/CPU.dir/flags.make
CMakeFiles/CPU.dir/src/control.cpp.o: ../src/control.cpp
CMakeFiles/CPU.dir/src/control.cpp.o: CMakeFiles/CPU.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ivan/cpu/CPU/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/CPU.dir/src/control.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/CPU.dir/src/control.cpp.o -MF CMakeFiles/CPU.dir/src/control.cpp.o.d -o CMakeFiles/CPU.dir/src/control.cpp.o -c /home/ivan/cpu/CPU/src/control.cpp

CMakeFiles/CPU.dir/src/control.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CPU.dir/src/control.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ivan/cpu/CPU/src/control.cpp > CMakeFiles/CPU.dir/src/control.cpp.i

CMakeFiles/CPU.dir/src/control.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CPU.dir/src/control.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ivan/cpu/CPU/src/control.cpp -o CMakeFiles/CPU.dir/src/control.cpp.s

CMakeFiles/CPU.dir/src/alu.cpp.o: CMakeFiles/CPU.dir/flags.make
CMakeFiles/CPU.dir/src/alu.cpp.o: ../src/alu.cpp
CMakeFiles/CPU.dir/src/alu.cpp.o: CMakeFiles/CPU.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ivan/cpu/CPU/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/CPU.dir/src/alu.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/CPU.dir/src/alu.cpp.o -MF CMakeFiles/CPU.dir/src/alu.cpp.o.d -o CMakeFiles/CPU.dir/src/alu.cpp.o -c /home/ivan/cpu/CPU/src/alu.cpp

CMakeFiles/CPU.dir/src/alu.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CPU.dir/src/alu.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ivan/cpu/CPU/src/alu.cpp > CMakeFiles/CPU.dir/src/alu.cpp.i

CMakeFiles/CPU.dir/src/alu.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CPU.dir/src/alu.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ivan/cpu/CPU/src/alu.cpp -o CMakeFiles/CPU.dir/src/alu.cpp.s

CMakeFiles/CPU.dir/src/adder.cpp.o: CMakeFiles/CPU.dir/flags.make
CMakeFiles/CPU.dir/src/adder.cpp.o: ../src/adder.cpp
CMakeFiles/CPU.dir/src/adder.cpp.o: CMakeFiles/CPU.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ivan/cpu/CPU/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/CPU.dir/src/adder.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/CPU.dir/src/adder.cpp.o -MF CMakeFiles/CPU.dir/src/adder.cpp.o.d -o CMakeFiles/CPU.dir/src/adder.cpp.o -c /home/ivan/cpu/CPU/src/adder.cpp

CMakeFiles/CPU.dir/src/adder.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CPU.dir/src/adder.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ivan/cpu/CPU/src/adder.cpp > CMakeFiles/CPU.dir/src/adder.cpp.i

CMakeFiles/CPU.dir/src/adder.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CPU.dir/src/adder.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ivan/cpu/CPU/src/adder.cpp -o CMakeFiles/CPU.dir/src/adder.cpp.s

CMakeFiles/CPU.dir/src/logical.cpp.o: CMakeFiles/CPU.dir/flags.make
CMakeFiles/CPU.dir/src/logical.cpp.o: ../src/logical.cpp
CMakeFiles/CPU.dir/src/logical.cpp.o: CMakeFiles/CPU.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ivan/cpu/CPU/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/CPU.dir/src/logical.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/CPU.dir/src/logical.cpp.o -MF CMakeFiles/CPU.dir/src/logical.cpp.o.d -o CMakeFiles/CPU.dir/src/logical.cpp.o -c /home/ivan/cpu/CPU/src/logical.cpp

CMakeFiles/CPU.dir/src/logical.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CPU.dir/src/logical.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ivan/cpu/CPU/src/logical.cpp > CMakeFiles/CPU.dir/src/logical.cpp.i

CMakeFiles/CPU.dir/src/logical.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CPU.dir/src/logical.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ivan/cpu/CPU/src/logical.cpp -o CMakeFiles/CPU.dir/src/logical.cpp.s

CMakeFiles/CPU.dir/src/shifter.cpp.o: CMakeFiles/CPU.dir/flags.make
CMakeFiles/CPU.dir/src/shifter.cpp.o: ../src/shifter.cpp
CMakeFiles/CPU.dir/src/shifter.cpp.o: CMakeFiles/CPU.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ivan/cpu/CPU/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/CPU.dir/src/shifter.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/CPU.dir/src/shifter.cpp.o -MF CMakeFiles/CPU.dir/src/shifter.cpp.o.d -o CMakeFiles/CPU.dir/src/shifter.cpp.o -c /home/ivan/cpu/CPU/src/shifter.cpp

CMakeFiles/CPU.dir/src/shifter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CPU.dir/src/shifter.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ivan/cpu/CPU/src/shifter.cpp > CMakeFiles/CPU.dir/src/shifter.cpp.i

CMakeFiles/CPU.dir/src/shifter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CPU.dir/src/shifter.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ivan/cpu/CPU/src/shifter.cpp -o CMakeFiles/CPU.dir/src/shifter.cpp.s

CMakeFiles/CPU.dir/src/display.cpp.o: CMakeFiles/CPU.dir/flags.make
CMakeFiles/CPU.dir/src/display.cpp.o: ../src/display.cpp
CMakeFiles/CPU.dir/src/display.cpp.o: CMakeFiles/CPU.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ivan/cpu/CPU/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/CPU.dir/src/display.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/CPU.dir/src/display.cpp.o -MF CMakeFiles/CPU.dir/src/display.cpp.o.d -o CMakeFiles/CPU.dir/src/display.cpp.o -c /home/ivan/cpu/CPU/src/display.cpp

CMakeFiles/CPU.dir/src/display.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CPU.dir/src/display.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ivan/cpu/CPU/src/display.cpp > CMakeFiles/CPU.dir/src/display.cpp.i

CMakeFiles/CPU.dir/src/display.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CPU.dir/src/display.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ivan/cpu/CPU/src/display.cpp -o CMakeFiles/CPU.dir/src/display.cpp.s

CMakeFiles/CPU.dir/src/assemble.cpp.o: CMakeFiles/CPU.dir/flags.make
CMakeFiles/CPU.dir/src/assemble.cpp.o: ../src/assemble.cpp
CMakeFiles/CPU.dir/src/assemble.cpp.o: CMakeFiles/CPU.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ivan/cpu/CPU/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/CPU.dir/src/assemble.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/CPU.dir/src/assemble.cpp.o -MF CMakeFiles/CPU.dir/src/assemble.cpp.o.d -o CMakeFiles/CPU.dir/src/assemble.cpp.o -c /home/ivan/cpu/CPU/src/assemble.cpp

CMakeFiles/CPU.dir/src/assemble.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CPU.dir/src/assemble.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ivan/cpu/CPU/src/assemble.cpp > CMakeFiles/CPU.dir/src/assemble.cpp.i

CMakeFiles/CPU.dir/src/assemble.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CPU.dir/src/assemble.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ivan/cpu/CPU/src/assemble.cpp -o CMakeFiles/CPU.dir/src/assemble.cpp.s

# Object files for target CPU
CPU_OBJECTS = \
"CMakeFiles/CPU.dir/src/cpu.cpp.o" \
"CMakeFiles/CPU.dir/src/decoder.cpp.o" \
"CMakeFiles/CPU.dir/src/control.cpp.o" \
"CMakeFiles/CPU.dir/src/alu.cpp.o" \
"CMakeFiles/CPU.dir/src/adder.cpp.o" \
"CMakeFiles/CPU.dir/src/logical.cpp.o" \
"CMakeFiles/CPU.dir/src/shifter.cpp.o" \
"CMakeFiles/CPU.dir/src/display.cpp.o" \
"CMakeFiles/CPU.dir/src/assemble.cpp.o"

# External object files for target CPU
CPU_EXTERNAL_OBJECTS =

CPU: CMakeFiles/CPU.dir/src/cpu.cpp.o
CPU: CMakeFiles/CPU.dir/src/decoder.cpp.o
CPU: CMakeFiles/CPU.dir/src/control.cpp.o
CPU: CMakeFiles/CPU.dir/src/alu.cpp.o
CPU: CMakeFiles/CPU.dir/src/adder.cpp.o
CPU: CMakeFiles/CPU.dir/src/logical.cpp.o
CPU: CMakeFiles/CPU.dir/src/shifter.cpp.o
CPU: CMakeFiles/CPU.dir/src/display.cpp.o
CPU: CMakeFiles/CPU.dir/src/assemble.cpp.o
CPU: CMakeFiles/CPU.dir/build.make
CPU: CMakeFiles/CPU.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ivan/cpu/CPU/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX executable CPU"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CPU.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CPU.dir/build: CPU
.PHONY : CMakeFiles/CPU.dir/build

CMakeFiles/CPU.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/CPU.dir/cmake_clean.cmake
.PHONY : CMakeFiles/CPU.dir/clean

CMakeFiles/CPU.dir/depend:
	cd /home/ivan/cpu/CPU/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ivan/cpu/CPU /home/ivan/cpu/CPU /home/ivan/cpu/CPU/build /home/ivan/cpu/CPU/build /home/ivan/cpu/CPU/build/CMakeFiles/CPU.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CPU.dir/depend

