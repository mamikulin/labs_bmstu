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
CMAKE_SOURCE_DIR = /Users/mikemikulin/desktop/labs/2_sem/lab_08/lab_08_3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/mikemikulin/desktop/labs/2_sem/lab_08/lab_08_3/build

# Include any dependencies generated for this target.
include CMakeFiles/lab_08_3.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/lab_08_3.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/lab_08_3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lab_08_3.dir/flags.make

CMakeFiles/lab_08_3.dir/third.cpp.o: CMakeFiles/lab_08_3.dir/flags.make
CMakeFiles/lab_08_3.dir/third.cpp.o: /Users/mikemikulin/desktop/labs/2_sem/lab_08/lab_08_3/third.cpp
CMakeFiles/lab_08_3.dir/third.cpp.o: CMakeFiles/lab_08_3.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/mikemikulin/desktop/labs/2_sem/lab_08/lab_08_3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lab_08_3.dir/third.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lab_08_3.dir/third.cpp.o -MF CMakeFiles/lab_08_3.dir/third.cpp.o.d -o CMakeFiles/lab_08_3.dir/third.cpp.o -c /Users/mikemikulin/desktop/labs/2_sem/lab_08/lab_08_3/third.cpp

CMakeFiles/lab_08_3.dir/third.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/lab_08_3.dir/third.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mikemikulin/desktop/labs/2_sem/lab_08/lab_08_3/third.cpp > CMakeFiles/lab_08_3.dir/third.cpp.i

CMakeFiles/lab_08_3.dir/third.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/lab_08_3.dir/third.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mikemikulin/desktop/labs/2_sem/lab_08/lab_08_3/third.cpp -o CMakeFiles/lab_08_3.dir/third.cpp.s

# Object files for target lab_08_3
lab_08_3_OBJECTS = \
"CMakeFiles/lab_08_3.dir/third.cpp.o"

# External object files for target lab_08_3
lab_08_3_EXTERNAL_OBJECTS =

lab_08_3: CMakeFiles/lab_08_3.dir/third.cpp.o
lab_08_3: CMakeFiles/lab_08_3.dir/build.make
lab_08_3: CMakeFiles/lab_08_3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/mikemikulin/desktop/labs/2_sem/lab_08/lab_08_3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable lab_08_3"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lab_08_3.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lab_08_3.dir/build: lab_08_3
.PHONY : CMakeFiles/lab_08_3.dir/build

CMakeFiles/lab_08_3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lab_08_3.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lab_08_3.dir/clean

CMakeFiles/lab_08_3.dir/depend:
	cd /Users/mikemikulin/desktop/labs/2_sem/lab_08/lab_08_3/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/mikemikulin/desktop/labs/2_sem/lab_08/lab_08_3 /Users/mikemikulin/desktop/labs/2_sem/lab_08/lab_08_3 /Users/mikemikulin/desktop/labs/2_sem/lab_08/lab_08_3/build /Users/mikemikulin/desktop/labs/2_sem/lab_08/lab_08_3/build /Users/mikemikulin/desktop/labs/2_sem/lab_08/lab_08_3/build/CMakeFiles/lab_08_3.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/lab_08_3.dir/depend

