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
include CMakeFiles/structTest.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/structTest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/structTest.dir/flags.make

CMakeFiles/structTest.dir/type/StructTest.cpp.o: CMakeFiles/structTest.dir/flags.make
CMakeFiles/structTest.dir/type/StructTest.cpp.o: ../type/StructTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/project/my/lern-cpp/cmake-build-debug-wsl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/structTest.dir/type/StructTest.cpp.o"
	/usr/bin/g++-10  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/structTest.dir/type/StructTest.cpp.o -c /mnt/d/project/my/lern-cpp/type/StructTest.cpp

CMakeFiles/structTest.dir/type/StructTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/structTest.dir/type/StructTest.cpp.i"
	/usr/bin/g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/project/my/lern-cpp/type/StructTest.cpp > CMakeFiles/structTest.dir/type/StructTest.cpp.i

CMakeFiles/structTest.dir/type/StructTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/structTest.dir/type/StructTest.cpp.s"
	/usr/bin/g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/project/my/lern-cpp/type/StructTest.cpp -o CMakeFiles/structTest.dir/type/StructTest.cpp.s

CMakeFiles/structTest.dir/type/Uu.cpp.o: CMakeFiles/structTest.dir/flags.make
CMakeFiles/structTest.dir/type/Uu.cpp.o: ../type/Uu.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/project/my/lern-cpp/cmake-build-debug-wsl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/structTest.dir/type/Uu.cpp.o"
	/usr/bin/g++-10  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/structTest.dir/type/Uu.cpp.o -c /mnt/d/project/my/lern-cpp/type/Uu.cpp

CMakeFiles/structTest.dir/type/Uu.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/structTest.dir/type/Uu.cpp.i"
	/usr/bin/g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/project/my/lern-cpp/type/Uu.cpp > CMakeFiles/structTest.dir/type/Uu.cpp.i

CMakeFiles/structTest.dir/type/Uu.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/structTest.dir/type/Uu.cpp.s"
	/usr/bin/g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/project/my/lern-cpp/type/Uu.cpp -o CMakeFiles/structTest.dir/type/Uu.cpp.s

# Object files for target structTest
structTest_OBJECTS = \
"CMakeFiles/structTest.dir/type/StructTest.cpp.o" \
"CMakeFiles/structTest.dir/type/Uu.cpp.o"

# External object files for target structTest
structTest_EXTERNAL_OBJECTS =

structTest: CMakeFiles/structTest.dir/type/StructTest.cpp.o
structTest: CMakeFiles/structTest.dir/type/Uu.cpp.o
structTest: CMakeFiles/structTest.dir/build.make
structTest: CMakeFiles/structTest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/d/project/my/lern-cpp/cmake-build-debug-wsl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable structTest"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/structTest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/structTest.dir/build: structTest

.PHONY : CMakeFiles/structTest.dir/build

CMakeFiles/structTest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/structTest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/structTest.dir/clean

CMakeFiles/structTest.dir/depend:
	cd /mnt/d/project/my/lern-cpp/cmake-build-debug-wsl && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/d/project/my/lern-cpp /mnt/d/project/my/lern-cpp /mnt/d/project/my/lern-cpp/cmake-build-debug-wsl /mnt/d/project/my/lern-cpp/cmake-build-debug-wsl /mnt/d/project/my/lern-cpp/cmake-build-debug-wsl/CMakeFiles/structTest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/structTest.dir/depend

