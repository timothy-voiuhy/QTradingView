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

# Utility rule file for QTradingView_qmlimportscan.

# Include any custom commands dependencies for this target.
include CMakeFiles/QTradingView_qmlimportscan.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/QTradingView_qmlimportscan.dir/progress.make

CMakeFiles/QTradingView_qmlimportscan: .qt_plugins/Qt6_QmlPlugins_Imports_QTradingView.cmake

.qt_plugins/Qt6_QmlPlugins_Imports_QTradingView.cmake: /usr/lib/qt6/libexec/qmlimportscanner
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/media/program/data_drive/MYAPPLICATIONS/QTradingView/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Running qmlimportscanner for QTradingView"
	/usr/lib/qt6/libexec/qmlimportscanner @/media/program/data_drive/MYAPPLICATIONS/QTradingView/.qt_plugins/Qt6_QmlPlugins_Imports_QTradingView.rsp

QTradingView_qmlimportscan: .qt_plugins/Qt6_QmlPlugins_Imports_QTradingView.cmake
QTradingView_qmlimportscan: CMakeFiles/QTradingView_qmlimportscan
QTradingView_qmlimportscan: CMakeFiles/QTradingView_qmlimportscan.dir/build.make
.PHONY : QTradingView_qmlimportscan

# Rule to build all files generated by this target.
CMakeFiles/QTradingView_qmlimportscan.dir/build: QTradingView_qmlimportscan
.PHONY : CMakeFiles/QTradingView_qmlimportscan.dir/build

CMakeFiles/QTradingView_qmlimportscan.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/QTradingView_qmlimportscan.dir/cmake_clean.cmake
.PHONY : CMakeFiles/QTradingView_qmlimportscan.dir/clean

CMakeFiles/QTradingView_qmlimportscan.dir/depend:
	cd /media/program/data_drive/MYAPPLICATIONS/QTradingView && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /media/program/data_drive/MYAPPLICATIONS/QTradingView /media/program/data_drive/MYAPPLICATIONS/QTradingView /media/program/data_drive/MYAPPLICATIONS/QTradingView /media/program/data_drive/MYAPPLICATIONS/QTradingView /media/program/data_drive/MYAPPLICATIONS/QTradingView/CMakeFiles/QTradingView_qmlimportscan.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/QTradingView_qmlimportscan.dir/depend

