# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ilya/CLionProjects/da_01

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ilya/CLionProjects/da_01/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/serega.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/serega.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/serega.dir/flags.make

CMakeFiles/serega.dir/serega.cpp.o: CMakeFiles/serega.dir/flags.make
CMakeFiles/serega.dir/serega.cpp.o: ../serega.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ilya/CLionProjects/da_01/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/serega.dir/serega.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/serega.dir/serega.cpp.o -c /home/ilya/CLionProjects/da_01/serega.cpp

CMakeFiles/serega.dir/serega.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/serega.dir/serega.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ilya/CLionProjects/da_01/serega.cpp > CMakeFiles/serega.dir/serega.cpp.i

CMakeFiles/serega.dir/serega.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/serega.dir/serega.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ilya/CLionProjects/da_01/serega.cpp -o CMakeFiles/serega.dir/serega.cpp.s

CMakeFiles/serega.dir/serega.cpp.o.requires:

.PHONY : CMakeFiles/serega.dir/serega.cpp.o.requires

CMakeFiles/serega.dir/serega.cpp.o.provides: CMakeFiles/serega.dir/serega.cpp.o.requires
	$(MAKE) -f CMakeFiles/serega.dir/build.make CMakeFiles/serega.dir/serega.cpp.o.provides.build
.PHONY : CMakeFiles/serega.dir/serega.cpp.o.provides

CMakeFiles/serega.dir/serega.cpp.o.provides.build: CMakeFiles/serega.dir/serega.cpp.o


# Object files for target serega
serega_OBJECTS = \
"CMakeFiles/serega.dir/serega.cpp.o"

# External object files for target serega
serega_EXTERNAL_OBJECTS =

serega: CMakeFiles/serega.dir/serega.cpp.o
serega: CMakeFiles/serega.dir/build.make
serega: CMakeFiles/serega.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ilya/CLionProjects/da_01/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable serega"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/serega.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/serega.dir/build: serega

.PHONY : CMakeFiles/serega.dir/build

CMakeFiles/serega.dir/requires: CMakeFiles/serega.dir/serega.cpp.o.requires

.PHONY : CMakeFiles/serega.dir/requires

CMakeFiles/serega.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/serega.dir/cmake_clean.cmake
.PHONY : CMakeFiles/serega.dir/clean

CMakeFiles/serega.dir/depend:
	cd /home/ilya/CLionProjects/da_01/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ilya/CLionProjects/da_01 /home/ilya/CLionProjects/da_01 /home/ilya/CLionProjects/da_01/cmake-build-debug /home/ilya/CLionProjects/da_01/cmake-build-debug /home/ilya/CLionProjects/da_01/cmake-build-debug/CMakeFiles/serega.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/serega.dir/depend

