# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /mnt/d/project/my/lern-cpp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/d/project/my/lern-cpp/cmake-build-debug-wsl

# Include any dependencies generated for this target.
include CMakeFiles/TypeTest.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/TypeTest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TypeTest.dir/flags.make

CMakeFiles/TypeTest.dir/type/TypeTest.cpp.o: CMakeFiles/TypeTest.dir/flags.make
CMakeFiles/TypeTest.dir/type/TypeTest.cpp.o: ../type/TypeTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/project/my/lern-cpp/cmake-build-debug-wsl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TypeTest.dir/type/TypeTest.cpp.o"
	/usr/bin/g++-10  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TypeTest.dir/type/TypeTest.cpp.o -c /mnt/d/project/my/lern-cpp/type/TypeTest.cpp

CMakeFiles/TypeTest.dir/type/TypeTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TypeTest.dir/type/TypeTest.cpp.i"
	/usr/bin/g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/project/my/lern-cpp/type/TypeTest.cpp > CMakeFiles/TypeTest.dir/type/TypeTest.cpp.i

CMakeFiles/TypeTest.dir/type/TypeTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TypeTest.dir/type/TypeTest.cpp.s"
	/usr/bin/g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/project/my/lern-cpp/type/TypeTest.cpp -o CMakeFiles/TypeTest.dir/type/TypeTest.cpp.s

# Object files for target TypeTest
TypeTest_OBJECTS = \
"CMakeFiles/TypeTest.dir/type/TypeTest.cpp.o"

# External object files for target TypeTest
TypeTest_EXTERNAL_OBJECTS =

TypeTest: CMakeFiles/TypeTest.dir/type/TypeTest.cpp.o
TypeTest: CMakeFiles/TypeTest.dir/build.make
TypeTest: CMakeFiles/TypeTest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/d/project/my/lern-cpp/cmake-build-debug-wsl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable TypeTest"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TypeTest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TypeTest.dir/build: TypeTest

.PHONY : CMakeFiles/TypeTest.dir/build

CMakeFiles/TypeTest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TypeTest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TypeTest.dir/clean

CMakeFiles/TypeTest.dir/depend:
	cd /mnt/d/project/my/lern-cpp/cmake-build-debug-wsl && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/d/project/my/lern-cpp /mnt/d/project/my/lern-cpp /mnt/d/project/my/lern-cpp/cmake-build-debug-wsl /mnt/d/project/my/lern-cpp/cmake-build-debug-wsl /mnt/d/project/my/lern-cpp/cmake-build-debug-wsl/CMakeFiles/TypeTest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TypeTest.dir/depend

