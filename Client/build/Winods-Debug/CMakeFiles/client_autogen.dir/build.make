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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/warg/Work/qt/Message/Client

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/warg/Work/qt/Message/Client/build/Winods-Debug

# Utility rule file for client_autogen.

# Include any custom commands dependencies for this target.
include CMakeFiles/client_autogen.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/client_autogen.dir/progress.make

CMakeFiles/client_autogen: client_autogen/timestamp

client_autogen/timestamp: /usr/lib/qt6/libexec/moc
client_autogen/timestamp: /usr/lib/qt6/libexec/uic
client_autogen/timestamp: CMakeFiles/client_autogen.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/home/warg/Work/qt/Message/Client/build/Winods-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target client"
	/usr/bin/cmake -E cmake_autogen /home/warg/Work/qt/Message/Client/build/Winods-Debug/CMakeFiles/client_autogen.dir/AutogenInfo.json Debug
	/usr/bin/cmake -E touch /home/warg/Work/qt/Message/Client/build/Winods-Debug/client_autogen/timestamp

client_autogen: CMakeFiles/client_autogen
client_autogen: client_autogen/timestamp
client_autogen: CMakeFiles/client_autogen.dir/build.make
.PHONY : client_autogen

# Rule to build all files generated by this target.
CMakeFiles/client_autogen.dir/build: client_autogen
.PHONY : CMakeFiles/client_autogen.dir/build

CMakeFiles/client_autogen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/client_autogen.dir/cmake_clean.cmake
.PHONY : CMakeFiles/client_autogen.dir/clean

CMakeFiles/client_autogen.dir/depend:
	cd /home/warg/Work/qt/Message/Client/build/Winods-Debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/warg/Work/qt/Message/Client /home/warg/Work/qt/Message/Client /home/warg/Work/qt/Message/Client/build/Winods-Debug /home/warg/Work/qt/Message/Client/build/Winods-Debug /home/warg/Work/qt/Message/Client/build/Winods-Debug/CMakeFiles/client_autogen.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/client_autogen.dir/depend

