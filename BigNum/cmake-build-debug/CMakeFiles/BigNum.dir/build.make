# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.19

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.1.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.1.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\Git Pet\BigNum\BigNum"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\Git Pet\BigNum\BigNum\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/BigNum.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/BigNum.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/BigNum.dir/flags.make

CMakeFiles/BigNum.dir/main.cpp.obj: CMakeFiles/BigNum.dir/flags.make
CMakeFiles/BigNum.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\Git Pet\BigNum\BigNum\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/BigNum.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\BigNum.dir\main.cpp.obj -c "D:\Git Pet\BigNum\BigNum\main.cpp"

CMakeFiles/BigNum.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BigNum.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\Git Pet\BigNum\BigNum\main.cpp" > CMakeFiles\BigNum.dir\main.cpp.i

CMakeFiles/BigNum.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BigNum.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\Git Pet\BigNum\BigNum\main.cpp" -o CMakeFiles\BigNum.dir\main.cpp.s

# Object files for target BigNum
BigNum_OBJECTS = \
"CMakeFiles/BigNum.dir/main.cpp.obj"

# External object files for target BigNum
BigNum_EXTERNAL_OBJECTS =

BigNum.exe: CMakeFiles/BigNum.dir/main.cpp.obj
BigNum.exe: CMakeFiles/BigNum.dir/build.make
BigNum.exe: CMakeFiles/BigNum.dir/linklibs.rsp
BigNum.exe: CMakeFiles/BigNum.dir/objects1.rsp
BigNum.exe: CMakeFiles/BigNum.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\Git Pet\BigNum\BigNum\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable BigNum.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\BigNum.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/BigNum.dir/build: BigNum.exe

.PHONY : CMakeFiles/BigNum.dir/build

CMakeFiles/BigNum.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\BigNum.dir\cmake_clean.cmake
.PHONY : CMakeFiles/BigNum.dir/clean

CMakeFiles/BigNum.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\Git Pet\BigNum\BigNum" "D:\Git Pet\BigNum\BigNum" "D:\Git Pet\BigNum\BigNum\cmake-build-debug" "D:\Git Pet\BigNum\BigNum\cmake-build-debug" "D:\Git Pet\BigNum\BigNum\cmake-build-debug\CMakeFiles\BigNum.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/BigNum.dir/depend

