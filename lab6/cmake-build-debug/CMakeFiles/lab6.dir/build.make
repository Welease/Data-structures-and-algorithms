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
CMAKE_SOURCE_DIR = /home/tanzilya/Data-structures-and-algorithms/lab6

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tanzilya/Data-structures-and-algorithms/lab6/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/lab6.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lab6.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lab6.dir/flags.make

CMakeFiles/lab6.dir/main.cpp.o: CMakeFiles/lab6.dir/flags.make
CMakeFiles/lab6.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tanzilya/Data-structures-and-algorithms/lab6/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lab6.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lab6.dir/main.cpp.o -c /home/tanzilya/Data-structures-and-algorithms/lab6/main.cpp

CMakeFiles/lab6.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab6.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tanzilya/Data-structures-and-algorithms/lab6/main.cpp > CMakeFiles/lab6.dir/main.cpp.i

CMakeFiles/lab6.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab6.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tanzilya/Data-structures-and-algorithms/lab6/main.cpp -o CMakeFiles/lab6.dir/main.cpp.s

CMakeFiles/lab6.dir/DynamicList.cpp.o: CMakeFiles/lab6.dir/flags.make
CMakeFiles/lab6.dir/DynamicList.cpp.o: ../DynamicList.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tanzilya/Data-structures-and-algorithms/lab6/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/lab6.dir/DynamicList.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lab6.dir/DynamicList.cpp.o -c /home/tanzilya/Data-structures-and-algorithms/lab6/DynamicList.cpp

CMakeFiles/lab6.dir/DynamicList.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab6.dir/DynamicList.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tanzilya/Data-structures-and-algorithms/lab6/DynamicList.cpp > CMakeFiles/lab6.dir/DynamicList.cpp.i

CMakeFiles/lab6.dir/DynamicList.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab6.dir/DynamicList.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tanzilya/Data-structures-and-algorithms/lab6/DynamicList.cpp -o CMakeFiles/lab6.dir/DynamicList.cpp.s

# Object files for target lab6
lab6_OBJECTS = \
"CMakeFiles/lab6.dir/main.cpp.o" \
"CMakeFiles/lab6.dir/DynamicList.cpp.o"

# External object files for target lab6
lab6_EXTERNAL_OBJECTS =

lab6: CMakeFiles/lab6.dir/main.cpp.o
lab6: CMakeFiles/lab6.dir/DynamicList.cpp.o
lab6: CMakeFiles/lab6.dir/build.make
lab6: CMakeFiles/lab6.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/tanzilya/Data-structures-and-algorithms/lab6/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable lab6"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lab6.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lab6.dir/build: lab6

.PHONY : CMakeFiles/lab6.dir/build

CMakeFiles/lab6.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lab6.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lab6.dir/clean

CMakeFiles/lab6.dir/depend:
	cd /home/tanzilya/Data-structures-and-algorithms/lab6/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tanzilya/Data-structures-and-algorithms/lab6 /home/tanzilya/Data-structures-and-algorithms/lab6 /home/tanzilya/Data-structures-and-algorithms/lab6/cmake-build-debug /home/tanzilya/Data-structures-and-algorithms/lab6/cmake-build-debug /home/tanzilya/Data-structures-and-algorithms/lab6/cmake-build-debug/CMakeFiles/lab6.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lab6.dir/depend

