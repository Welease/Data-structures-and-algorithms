# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/tanzilya/Downloads/clion-2020.3.1/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/tanzilya/Downloads/clion-2020.3.1/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/tanzilya/Data-structures-and-algorithms/lab7

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tanzilya/Data-structures-and-algorithms/lab7/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/lab7.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lab7.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lab7.dir/flags.make

CMakeFiles/lab7.dir/lab7.cpp.o: CMakeFiles/lab7.dir/flags.make
CMakeFiles/lab7.dir/lab7.cpp.o: ../lab7.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tanzilya/Data-structures-and-algorithms/lab7/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lab7.dir/lab7.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lab7.dir/lab7.cpp.o -c /home/tanzilya/Data-structures-and-algorithms/lab7/lab7.cpp

CMakeFiles/lab7.dir/lab7.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab7.dir/lab7.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tanzilya/Data-structures-and-algorithms/lab7/lab7.cpp > CMakeFiles/lab7.dir/lab7.cpp.i

CMakeFiles/lab7.dir/lab7.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab7.dir/lab7.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tanzilya/Data-structures-and-algorithms/lab7/lab7.cpp -o CMakeFiles/lab7.dir/lab7.cpp.s

# Object files for target lab7
lab7_OBJECTS = \
"CMakeFiles/lab7.dir/lab7.cpp.o"

# External object files for target lab7
lab7_EXTERNAL_OBJECTS =

lab7: CMakeFiles/lab7.dir/lab7.cpp.o
lab7: CMakeFiles/lab7.dir/build.make
lab7: CMakeFiles/lab7.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/tanzilya/Data-structures-and-algorithms/lab7/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable lab7"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lab7.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lab7.dir/build: lab7

.PHONY : CMakeFiles/lab7.dir/build

CMakeFiles/lab7.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lab7.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lab7.dir/clean

CMakeFiles/lab7.dir/depend:
	cd /home/tanzilya/Data-structures-and-algorithms/lab7/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tanzilya/Data-structures-and-algorithms/lab7 /home/tanzilya/Data-structures-and-algorithms/lab7 /home/tanzilya/Data-structures-and-algorithms/lab7/cmake-build-debug /home/tanzilya/Data-structures-and-algorithms/lab7/cmake-build-debug /home/tanzilya/Data-structures-and-algorithms/lab7/cmake-build-debug/CMakeFiles/lab7.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lab7.dir/depend

