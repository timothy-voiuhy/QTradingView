# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.29

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
CMAKE_SOURCE_DIR = /media/program/data_drive/MYAPPLICATIONS/QTradingView

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /media/program/data_drive/MYAPPLICATIONS/QTradingView

# Utility rule file for QTradingView_autogen.

# Include any custom commands dependencies for this target.
include CMakeFiles/QTradingView_autogen.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/QTradingView_autogen.dir/progress.make

CMakeFiles/QTradingView_autogen: QTradingView_autogen/timestamp

QTradingView_autogen/timestamp: /usr/lib/qt6/libexec/moc
QTradingView_autogen/timestamp: /usr/lib/qt6/libexec/uic
QTradingView_autogen/timestamp: CMakeFiles/QTradingView_autogen.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/media/program/data_drive/MYAPPLICATIONS/QTradingView/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target QTradingView"
	/usr/bin/cmake -E cmake_autogen /media/program/data_drive/MYAPPLICATIONS/QTradingView/CMakeFiles/QTradingView_autogen.dir/AutogenInfo.json ""
	/usr/bin/cmake -E touch /media/program/data_drive/MYAPPLICATIONS/QTradingView/QTradingView_autogen/timestamp

QTradingView_autogen: CMakeFiles/QTradingView_autogen
QTradingView_autogen: QTradingView_autogen/timestamp
QTradingView_autogen: CMakeFiles/QTradingView_autogen.dir/build.make
.PHONY : QTradingView_autogen

# Rule to build all files generated by this target.
CMakeFiles/QTradingView_autogen.dir/build: QTradingView_autogen
.PHONY : CMakeFiles/QTradingView_autogen.dir/build

CMakeFiles/QTradingView_autogen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/QTradingView_autogen.dir/cmake_clean.cmake
.PHONY : CMakeFiles/QTradingView_autogen.dir/clean

CMakeFiles/QTradingView_autogen.dir/depend:
	cd /media/program/data_drive/MYAPPLICATIONS/QTradingView && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /media/program/data_drive/MYAPPLICATIONS/QTradingView /media/program/data_drive/MYAPPLICATIONS/QTradingView /media/program/data_drive/MYAPPLICATIONS/QTradingView /media/program/data_drive/MYAPPLICATIONS/QTradingView /media/program/data_drive/MYAPPLICATIONS/QTradingView/CMakeFiles/QTradingView_autogen.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/QTradingView_autogen.dir/depend

