# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.28.3/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.28.3/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/mikemikulin/desktop/labs/2_sem/lab_08/lab_08_1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/mikemikulin/desktop/labs/2_sem/lab_08/lab_08_1/build

# Include any dependencies generated for this target.
include CMakeFiles/lab_08.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/lab_08.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/lab_08.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lab_08.dir/flags.make

CMakeFiles/lab_08.dir/first.cpp.o: CMakeFiles/lab_08.dir/flags.make
CMakeFiles/lab_08.dir/first.cpp.o: /Users/mikemikulin/desktop/labs/2_sem/lab_08/lab_08_1/first.cpp
CMakeFiles/lab_08.dir/first.cpp.o: CMakeFiles/lab_08.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/mikemikulin/desktop/labs/2_sem/lab_08/lab_08_1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lab_08.dir/first.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lab_08.dir/first.cpp.o -MF CMakeFiles/lab_08.dir/first.cpp.o.d -o CMakeFiles/lab_08.dir/first.cpp.o -c /Users/mikemikulin/desktop/labs/2_sem/lab_08/lab_08_1/first.cpp

CMakeFiles/lab_08.dir/first.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/lab_08.dir/first.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mikemikulin/desktop/labs/2_sem/lab_08/lab_08_1/first.cpp > CMakeFiles/lab_08.dir/first.cpp.i

CMakeFiles/lab_08.dir/first.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/lab_08.dir/first.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mikemikulin/desktop/labs/2_sem/lab_08/lab_08_1/first.cpp -o CMakeFiles/lab_08.dir/first.cpp.s

# Object files for target lab_08
lab_08_OBJECTS = \
"CMakeFiles/lab_08.dir/first.cpp.o"

# External object files for target lab_08
lab_08_EXTERNAL_OBJECTS =

lab_08: CMakeFiles/lab_08.dir/first.cpp.o
lab_08: CMakeFiles/lab_08.dir/build.make
lab_08: CMakeFiles/lab_08.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/mikemikulin/desktop/labs/2_sem/lab_08/lab_08_1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable lab_08"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lab_08.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lab_08.dir/build: lab_08
.PHONY : CMakeFiles/lab_08.dir/build

CMakeFiles/lab_08.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lab_08.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lab_08.dir/clean

CMakeFiles/lab_08.dir/depend:
	cd /Users/mikemikulin/desktop/labs/2_sem/lab_08/lab_08_1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/mikemikulin/desktop/labs/2_sem/lab_08/lab_08_1 /Users/mikemikulin/desktop/labs/2_sem/lab_08/lab_08_1 /Users/mikemikulin/desktop/labs/2_sem/lab_08/lab_08_1/build /Users/mikemikulin/desktop/labs/2_sem/lab_08/lab_08_1/build /Users/mikemikulin/desktop/labs/2_sem/lab_08/lab_08_1/build/CMakeFiles/lab_08.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/lab_08.dir/depend

