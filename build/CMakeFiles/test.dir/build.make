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
CMAKE_COMMAND = /opt/cmake-3.16.3-Linux-x86_64/bin/cmake

# The command to remove a file.
RM = /opt/cmake-3.16.3-Linux-x86_64/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/mikengo/Documents/Coding/C(++)/C++/Projects/CardTemplate"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/mikengo/Documents/Coding/C(++)/C++/Projects/CardTemplate/build"

# Include any dependencies generated for this target.
include CMakeFiles/test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test.dir/flags.make

CMakeFiles/test.dir/src/card.cpp.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/src/card.cpp.o: ../src/card.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/mikengo/Documents/Coding/C(++)/C++/Projects/CardTemplate/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test.dir/src/card.cpp.o"
	/usr/bin/g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test.dir/src/card.cpp.o -c "/home/mikengo/Documents/Coding/C(++)/C++/Projects/CardTemplate/src/card.cpp"

CMakeFiles/test.dir/src/card.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.dir/src/card.cpp.i"
	/usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/mikengo/Documents/Coding/C(++)/C++/Projects/CardTemplate/src/card.cpp" > CMakeFiles/test.dir/src/card.cpp.i

CMakeFiles/test.dir/src/card.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.dir/src/card.cpp.s"
	/usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/mikengo/Documents/Coding/C(++)/C++/Projects/CardTemplate/src/card.cpp" -o CMakeFiles/test.dir/src/card.cpp.s

CMakeFiles/test.dir/src/deck.cpp.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/src/deck.cpp.o: ../src/deck.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/mikengo/Documents/Coding/C(++)/C++/Projects/CardTemplate/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/test.dir/src/deck.cpp.o"
	/usr/bin/g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test.dir/src/deck.cpp.o -c "/home/mikengo/Documents/Coding/C(++)/C++/Projects/CardTemplate/src/deck.cpp"

CMakeFiles/test.dir/src/deck.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.dir/src/deck.cpp.i"
	/usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/mikengo/Documents/Coding/C(++)/C++/Projects/CardTemplate/src/deck.cpp" > CMakeFiles/test.dir/src/deck.cpp.i

CMakeFiles/test.dir/src/deck.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.dir/src/deck.cpp.s"
	/usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/mikengo/Documents/Coding/C(++)/C++/Projects/CardTemplate/src/deck.cpp" -o CMakeFiles/test.dir/src/deck.cpp.s

CMakeFiles/test.dir/src/player.cpp.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/src/player.cpp.o: ../src/player.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/mikengo/Documents/Coding/C(++)/C++/Projects/CardTemplate/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/test.dir/src/player.cpp.o"
	/usr/bin/g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test.dir/src/player.cpp.o -c "/home/mikengo/Documents/Coding/C(++)/C++/Projects/CardTemplate/src/player.cpp"

CMakeFiles/test.dir/src/player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.dir/src/player.cpp.i"
	/usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/mikengo/Documents/Coding/C(++)/C++/Projects/CardTemplate/src/player.cpp" > CMakeFiles/test.dir/src/player.cpp.i

CMakeFiles/test.dir/src/player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.dir/src/player.cpp.s"
	/usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/mikengo/Documents/Coding/C(++)/C++/Projects/CardTemplate/src/player.cpp" -o CMakeFiles/test.dir/src/player.cpp.s

CMakeFiles/test.dir/src/test.cpp.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/src/test.cpp.o: ../src/test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/mikengo/Documents/Coding/C(++)/C++/Projects/CardTemplate/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/test.dir/src/test.cpp.o"
	/usr/bin/g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test.dir/src/test.cpp.o -c "/home/mikengo/Documents/Coding/C(++)/C++/Projects/CardTemplate/src/test.cpp"

CMakeFiles/test.dir/src/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.dir/src/test.cpp.i"
	/usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/mikengo/Documents/Coding/C(++)/C++/Projects/CardTemplate/src/test.cpp" > CMakeFiles/test.dir/src/test.cpp.i

CMakeFiles/test.dir/src/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.dir/src/test.cpp.s"
	/usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/mikengo/Documents/Coding/C(++)/C++/Projects/CardTemplate/src/test.cpp" -o CMakeFiles/test.dir/src/test.cpp.s

# Object files for target test
test_OBJECTS = \
"CMakeFiles/test.dir/src/card.cpp.o" \
"CMakeFiles/test.dir/src/deck.cpp.o" \
"CMakeFiles/test.dir/src/player.cpp.o" \
"CMakeFiles/test.dir/src/test.cpp.o"

# External object files for target test
test_EXTERNAL_OBJECTS =

test: CMakeFiles/test.dir/src/card.cpp.o
test: CMakeFiles/test.dir/src/deck.cpp.o
test: CMakeFiles/test.dir/src/player.cpp.o
test: CMakeFiles/test.dir/src/test.cpp.o
test: CMakeFiles/test.dir/build.make
test: CMakeFiles/test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/mikengo/Documents/Coding/C(++)/C++/Projects/CardTemplate/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test.dir/build: test

.PHONY : CMakeFiles/test.dir/build

CMakeFiles/test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test.dir/clean

CMakeFiles/test.dir/depend:
	cd "/home/mikengo/Documents/Coding/C(++)/C++/Projects/CardTemplate/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/mikengo/Documents/Coding/C(++)/C++/Projects/CardTemplate" "/home/mikengo/Documents/Coding/C(++)/C++/Projects/CardTemplate" "/home/mikengo/Documents/Coding/C(++)/C++/Projects/CardTemplate/build" "/home/mikengo/Documents/Coding/C(++)/C++/Projects/CardTemplate/build" "/home/mikengo/Documents/Coding/C(++)/C++/Projects/CardTemplate/build/CMakeFiles/test.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/test.dir/depend

