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
CMAKE_COMMAND = /home/zcy/Applications/clion-2020.1.1/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/zcy/Applications/clion-2020.1.1/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/zcy/桌面/GoBackN/gobackn

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zcy/桌面/GoBackN/gobackn/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/GoBackN.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/GoBackN.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/GoBackN.dir/flags.make

CMakeFiles/GoBackN.dir/main.cpp.o: CMakeFiles/GoBackN.dir/flags.make
CMakeFiles/GoBackN.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zcy/桌面/GoBackN/gobackn/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/GoBackN.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GoBackN.dir/main.cpp.o -c /home/zcy/桌面/GoBackN/gobackn/main.cpp

CMakeFiles/GoBackN.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GoBackN.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zcy/桌面/GoBackN/gobackn/main.cpp > CMakeFiles/GoBackN.dir/main.cpp.i

CMakeFiles/GoBackN.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GoBackN.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zcy/桌面/GoBackN/gobackn/main.cpp -o CMakeFiles/GoBackN.dir/main.cpp.s

CMakeFiles/GoBackN.dir/protocol/go_back_n.cpp.o: CMakeFiles/GoBackN.dir/flags.make
CMakeFiles/GoBackN.dir/protocol/go_back_n.cpp.o: ../protocol/go_back_n.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zcy/桌面/GoBackN/gobackn/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/GoBackN.dir/protocol/go_back_n.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GoBackN.dir/protocol/go_back_n.cpp.o -c /home/zcy/桌面/GoBackN/gobackn/protocol/go_back_n.cpp

CMakeFiles/GoBackN.dir/protocol/go_back_n.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GoBackN.dir/protocol/go_back_n.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zcy/桌面/GoBackN/gobackn/protocol/go_back_n.cpp > CMakeFiles/GoBackN.dir/protocol/go_back_n.cpp.i

CMakeFiles/GoBackN.dir/protocol/go_back_n.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GoBackN.dir/protocol/go_back_n.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zcy/桌面/GoBackN/gobackn/protocol/go_back_n.cpp -o CMakeFiles/GoBackN.dir/protocol/go_back_n.cpp.s

CMakeFiles/GoBackN.dir/socket/socket_udp.cpp.o: CMakeFiles/GoBackN.dir/flags.make
CMakeFiles/GoBackN.dir/socket/socket_udp.cpp.o: ../socket/socket_udp.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zcy/桌面/GoBackN/gobackn/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/GoBackN.dir/socket/socket_udp.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GoBackN.dir/socket/socket_udp.cpp.o -c /home/zcy/桌面/GoBackN/gobackn/socket/socket_udp.cpp

CMakeFiles/GoBackN.dir/socket/socket_udp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GoBackN.dir/socket/socket_udp.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zcy/桌面/GoBackN/gobackn/socket/socket_udp.cpp > CMakeFiles/GoBackN.dir/socket/socket_udp.cpp.i

CMakeFiles/GoBackN.dir/socket/socket_udp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GoBackN.dir/socket/socket_udp.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zcy/桌面/GoBackN/gobackn/socket/socket_udp.cpp -o CMakeFiles/GoBackN.dir/socket/socket_udp.cpp.s

# Object files for target GoBackN
GoBackN_OBJECTS = \
"CMakeFiles/GoBackN.dir/main.cpp.o" \
"CMakeFiles/GoBackN.dir/protocol/go_back_n.cpp.o" \
"CMakeFiles/GoBackN.dir/socket/socket_udp.cpp.o"

# External object files for target GoBackN
GoBackN_EXTERNAL_OBJECTS =

GoBackN: CMakeFiles/GoBackN.dir/main.cpp.o
GoBackN: CMakeFiles/GoBackN.dir/protocol/go_back_n.cpp.o
GoBackN: CMakeFiles/GoBackN.dir/socket/socket_udp.cpp.o
GoBackN: CMakeFiles/GoBackN.dir/build.make
GoBackN: CMakeFiles/GoBackN.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zcy/桌面/GoBackN/gobackn/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable GoBackN"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/GoBackN.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/GoBackN.dir/build: GoBackN

.PHONY : CMakeFiles/GoBackN.dir/build

CMakeFiles/GoBackN.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/GoBackN.dir/cmake_clean.cmake
.PHONY : CMakeFiles/GoBackN.dir/clean

CMakeFiles/GoBackN.dir/depend:
	cd /home/zcy/桌面/GoBackN/gobackn/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zcy/桌面/GoBackN/gobackn /home/zcy/桌面/GoBackN/gobackn /home/zcy/桌面/GoBackN/gobackn/cmake-build-debug /home/zcy/桌面/GoBackN/gobackn/cmake-build-debug /home/zcy/桌面/GoBackN/gobackn/cmake-build-debug/CMakeFiles/GoBackN.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/GoBackN.dir/depend

