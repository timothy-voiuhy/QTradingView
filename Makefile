# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.29

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

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

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# Special rule for the target list_install_components
list_install_components:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "Available install components are: \"Unspecified\""
.PHONY : list_install_components

# Special rule for the target list_install_components
list_install_components/fast: list_install_components
.PHONY : list_install_components/fast

# Special rule for the target install
install: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "Install the project..."
	/usr/bin/cmake -P cmake_install.cmake
.PHONY : install

# Special rule for the target install
install/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "Install the project..."
	/usr/bin/cmake -P cmake_install.cmake
.PHONY : install/fast

# Special rule for the target install/local
install/local: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "Installing only the local directory..."
	/usr/bin/cmake -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local

# Special rule for the target install/local
install/local/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "Installing only the local directory..."
	/usr/bin/cmake -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local/fast

# Special rule for the target install/strip
install/strip: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "Installing the project stripped..."
	/usr/bin/cmake -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip

# Special rule for the target install/strip
install/strip/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "Installing the project stripped..."
	/usr/bin/cmake -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /media/program/data_drive/MYAPPLICATIONS/QTradingView/CMakeFiles /media/program/data_drive/MYAPPLICATIONS/QTradingView//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /media/program/data_drive/MYAPPLICATIONS/QTradingView/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named QTradingView

# Build rule for target.
QTradingView: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 QTradingView
.PHONY : QTradingView

# fast build rule for target.
QTradingView/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/QTradingView.dir/build.make CMakeFiles/QTradingView.dir/build
.PHONY : QTradingView/fast

#=============================================================================
# Target rules for targets named QTradingView_autogen_timestamp_deps

# Build rule for target.
QTradingView_autogen_timestamp_deps: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 QTradingView_autogen_timestamp_deps
.PHONY : QTradingView_autogen_timestamp_deps

# fast build rule for target.
QTradingView_autogen_timestamp_deps/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/QTradingView_autogen_timestamp_deps.dir/build.make CMakeFiles/QTradingView_autogen_timestamp_deps.dir/build
.PHONY : QTradingView_autogen_timestamp_deps/fast

#=============================================================================
# Target rules for targets named QTradingView_autogen

# Build rule for target.
QTradingView_autogen: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 QTradingView_autogen
.PHONY : QTradingView_autogen

# fast build rule for target.
QTradingView_autogen/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/QTradingView_autogen.dir/build.make CMakeFiles/QTradingView_autogen.dir/build
.PHONY : QTradingView_autogen/fast

GraphingView.o: GraphingView.cpp.o
.PHONY : GraphingView.o

# target to build an object file
GraphingView.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/QTradingView.dir/build.make CMakeFiles/QTradingView.dir/GraphingView.cpp.o
.PHONY : GraphingView.cpp.o

GraphingView.i: GraphingView.cpp.i
.PHONY : GraphingView.i

# target to preprocess a source file
GraphingView.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/QTradingView.dir/build.make CMakeFiles/QTradingView.dir/GraphingView.cpp.i
.PHONY : GraphingView.cpp.i

GraphingView.s: GraphingView.cpp.s
.PHONY : GraphingView.s

# target to generate assembly for a file
GraphingView.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/QTradingView.dir/build.make CMakeFiles/QTradingView.dir/GraphingView.cpp.s
.PHONY : GraphingView.cpp.s

QTradingView_autogen/mocs_compilation.o: QTradingView_autogen/mocs_compilation.cpp.o
.PHONY : QTradingView_autogen/mocs_compilation.o

# target to build an object file
QTradingView_autogen/mocs_compilation.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/QTradingView.dir/build.make CMakeFiles/QTradingView.dir/QTradingView_autogen/mocs_compilation.cpp.o
.PHONY : QTradingView_autogen/mocs_compilation.cpp.o

QTradingView_autogen/mocs_compilation.i: QTradingView_autogen/mocs_compilation.cpp.i
.PHONY : QTradingView_autogen/mocs_compilation.i

# target to preprocess a source file
QTradingView_autogen/mocs_compilation.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/QTradingView.dir/build.make CMakeFiles/QTradingView.dir/QTradingView_autogen/mocs_compilation.cpp.i
.PHONY : QTradingView_autogen/mocs_compilation.cpp.i

QTradingView_autogen/mocs_compilation.s: QTradingView_autogen/mocs_compilation.cpp.s
.PHONY : QTradingView_autogen/mocs_compilation.s

# target to generate assembly for a file
QTradingView_autogen/mocs_compilation.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/QTradingView.dir/build.make CMakeFiles/QTradingView.dir/QTradingView_autogen/mocs_compilation.cpp.s
.PHONY : QTradingView_autogen/mocs_compilation.cpp.s

axes.o: axes.cpp.o
.PHONY : axes.o

# target to build an object file
axes.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/QTradingView.dir/build.make CMakeFiles/QTradingView.dir/axes.cpp.o
.PHONY : axes.cpp.o

axes.i: axes.cpp.i
.PHONY : axes.i

# target to preprocess a source file
axes.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/QTradingView.dir/build.make CMakeFiles/QTradingView.dir/axes.cpp.i
.PHONY : axes.cpp.i

axes.s: axes.cpp.s
.PHONY : axes.s

# target to generate assembly for a file
axes.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/QTradingView.dir/build.make CMakeFiles/QTradingView.dir/axes.cpp.s
.PHONY : axes.cpp.s

candleBody.o: candleBody.cpp.o
.PHONY : candleBody.o

# target to build an object file
candleBody.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/QTradingView.dir/build.make CMakeFiles/QTradingView.dir/candleBody.cpp.o
.PHONY : candleBody.cpp.o

candleBody.i: candleBody.cpp.i
.PHONY : candleBody.i

# target to preprocess a source file
candleBody.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/QTradingView.dir/build.make CMakeFiles/QTradingView.dir/candleBody.cpp.i
.PHONY : candleBody.cpp.i

candleBody.s: candleBody.cpp.s
.PHONY : candleBody.s

# target to generate assembly for a file
candleBody.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/QTradingView.dir/build.make CMakeFiles/QTradingView.dir/candleBody.cpp.s
.PHONY : candleBody.cpp.s

candleStickDataStream.o: candleStickDataStream.cpp.o
.PHONY : candleStickDataStream.o

# target to build an object file
candleStickDataStream.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/QTradingView.dir/build.make CMakeFiles/QTradingView.dir/candleStickDataStream.cpp.o
.PHONY : candleStickDataStream.cpp.o

candleStickDataStream.i: candleStickDataStream.cpp.i
.PHONY : candleStickDataStream.i

# target to preprocess a source file
candleStickDataStream.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/QTradingView.dir/build.make CMakeFiles/QTradingView.dir/candleStickDataStream.cpp.i
.PHONY : candleStickDataStream.cpp.i

candleStickDataStream.s: candleStickDataStream.cpp.s
.PHONY : candleStickDataStream.s

# target to generate assembly for a file
candleStickDataStream.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/QTradingView.dir/build.make CMakeFiles/QTradingView.dir/candleStickDataStream.cpp.s
.PHONY : candleStickDataStream.cpp.s

candleStickState.o: candleStickState.cpp.o
.PHONY : candleStickState.o

# target to build an object file
candleStickState.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/QTradingView.dir/build.make CMakeFiles/QTradingView.dir/candleStickState.cpp.o
.PHONY : candleStickState.cpp.o

candleStickState.i: candleStickState.cpp.i
.PHONY : candleStickState.i

# target to preprocess a source file
candleStickState.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/QTradingView.dir/build.make CMakeFiles/QTradingView.dir/candleStickState.cpp.i
.PHONY : candleStickState.cpp.i

candleStickState.s: candleStickState.cpp.s
.PHONY : candleStickState.s

# target to generate assembly for a file
candleStickState.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/QTradingView.dir/build.make CMakeFiles/QTradingView.dir/candleStickState.cpp.s
.PHONY : candleStickState.cpp.s

candleStickWick.o: candleStickWick.cpp.o
.PHONY : candleStickWick.o

# target to build an object file
candleStickWick.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/QTradingView.dir/build.make CMakeFiles/QTradingView.dir/candleStickWick.cpp.o
.PHONY : candleStickWick.cpp.o

candleStickWick.i: candleStickWick.cpp.i
.PHONY : candleStickWick.i

# target to preprocess a source file
candleStickWick.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/QTradingView.dir/build.make CMakeFiles/QTradingView.dir/candleStickWick.cpp.i
.PHONY : candleStickWick.cpp.i

candleStickWick.s: candleStickWick.cpp.s
.PHONY : candleStickWick.s

# target to generate assembly for a file
candleStickWick.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/QTradingView.dir/build.make CMakeFiles/QTradingView.dir/candleStickWick.cpp.s
.PHONY : candleStickWick.cpp.s

dbManager.o: dbManager.cpp.o
.PHONY : dbManager.o

# target to build an object file
dbManager.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/QTradingView.dir/build.make CMakeFiles/QTradingView.dir/dbManager.cpp.o
.PHONY : dbManager.cpp.o

dbManager.i: dbManager.cpp.i
.PHONY : dbManager.i

# target to preprocess a source file
dbManager.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/QTradingView.dir/build.make CMakeFiles/QTradingView.dir/dbManager.cpp.i
.PHONY : dbManager.cpp.i

dbManager.s: dbManager.cpp.s
.PHONY : dbManager.s

# target to generate assembly for a file
dbManager.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/QTradingView.dir/build.make CMakeFiles/QTradingView.dir/dbManager.cpp.s
.PHONY : dbManager.cpp.s

graph.o: graph.cpp.o
.PHONY : graph.o

# target to build an object file
graph.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/QTradingView.dir/build.make CMakeFiles/QTradingView.dir/graph.cpp.o
.PHONY : graph.cpp.o

graph.i: graph.cpp.i
.PHONY : graph.i

# target to preprocess a source file
graph.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/QTradingView.dir/build.make CMakeFiles/QTradingView.dir/graph.cpp.i
.PHONY : graph.cpp.i

graph.s: graph.cpp.s
.PHONY : graph.s

# target to generate assembly for a file
graph.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/QTradingView.dir/build.make CMakeFiles/QTradingView.dir/graph.cpp.s
.PHONY : graph.cpp.s

graphTimeFrameNode.o: graphTimeFrameNode.cpp.o
.PHONY : graphTimeFrameNode.o

# target to build an object file
graphTimeFrameNode.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/QTradingView.dir/build.make CMakeFiles/QTradingView.dir/graphTimeFrameNode.cpp.o
.PHONY : graphTimeFrameNode.cpp.o

graphTimeFrameNode.i: graphTimeFrameNode.cpp.i
.PHONY : graphTimeFrameNode.i

# target to preprocess a source file
graphTimeFrameNode.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/QTradingView.dir/build.make CMakeFiles/QTradingView.dir/graphTimeFrameNode.cpp.i
.PHONY : graphTimeFrameNode.cpp.i

graphTimeFrameNode.s: graphTimeFrameNode.cpp.s
.PHONY : graphTimeFrameNode.s

# target to generate assembly for a file
graphTimeFrameNode.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/QTradingView.dir/build.make CMakeFiles/QTradingView.dir/graphTimeFrameNode.cpp.s
.PHONY : graphTimeFrameNode.cpp.s

graphWindow.o: graphWindow.cpp.o
.PHONY : graphWindow.o

# target to build an object file
graphWindow.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/QTradingView.dir/build.make CMakeFiles/QTradingView.dir/graphWindow.cpp.o
.PHONY : graphWindow.cpp.o

graphWindow.i: graphWindow.cpp.i
.PHONY : graphWindow.i

# target to preprocess a source file
graphWindow.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/QTradingView.dir/build.make CMakeFiles/QTradingView.dir/graphWindow.cpp.i
.PHONY : graphWindow.cpp.i

graphWindow.s: graphWindow.cpp.s
.PHONY : graphWindow.s

# target to generate assembly for a file
graphWindow.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/QTradingView.dir/build.make CMakeFiles/QTradingView.dir/graphWindow.cpp.s
.PHONY : graphWindow.cpp.s

main.o: main.cpp.o
.PHONY : main.o

# target to build an object file
main.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/QTradingView.dir/build.make CMakeFiles/QTradingView.dir/main.cpp.o
.PHONY : main.cpp.o

main.i: main.cpp.i
.PHONY : main.i

# target to preprocess a source file
main.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/QTradingView.dir/build.make CMakeFiles/QTradingView.dir/main.cpp.i
.PHONY : main.cpp.i

main.s: main.cpp.s
.PHONY : main.s

# target to generate assembly for a file
main.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/QTradingView.dir/build.make CMakeFiles/QTradingView.dir/main.cpp.s
.PHONY : main.cpp.s

mainwindow.o: mainwindow.cpp.o
.PHONY : mainwindow.o

# target to build an object file
mainwindow.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/QTradingView.dir/build.make CMakeFiles/QTradingView.dir/mainwindow.cpp.o
.PHONY : mainwindow.cpp.o

mainwindow.i: mainwindow.cpp.i
.PHONY : mainwindow.i

# target to preprocess a source file
mainwindow.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/QTradingView.dir/build.make CMakeFiles/QTradingView.dir/mainwindow.cpp.i
.PHONY : mainwindow.cpp.i

mainwindow.s: mainwindow.cpp.s
.PHONY : mainwindow.s

# target to generate assembly for a file
mainwindow.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/QTradingView.dir/build.make CMakeFiles/QTradingView.dir/mainwindow.cpp.s
.PHONY : mainwindow.cpp.s

pathGraphPoint.o: pathGraphPoint.cpp.o
.PHONY : pathGraphPoint.o

# target to build an object file
pathGraphPoint.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/QTradingView.dir/build.make CMakeFiles/QTradingView.dir/pathGraphPoint.cpp.o
.PHONY : pathGraphPoint.cpp.o

pathGraphPoint.i: pathGraphPoint.cpp.i
.PHONY : pathGraphPoint.i

# target to preprocess a source file
pathGraphPoint.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/QTradingView.dir/build.make CMakeFiles/QTradingView.dir/pathGraphPoint.cpp.i
.PHONY : pathGraphPoint.cpp.i

pathGraphPoint.s: pathGraphPoint.cpp.s
.PHONY : pathGraphPoint.s

# target to generate assembly for a file
pathGraphPoint.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/QTradingView.dir/build.make CMakeFiles/QTradingView.dir/pathGraphPoint.cpp.s
.PHONY : pathGraphPoint.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... install"
	@echo "... install/local"
	@echo "... install/strip"
	@echo "... list_install_components"
	@echo "... rebuild_cache"
	@echo "... QTradingView_autogen"
	@echo "... QTradingView_autogen_timestamp_deps"
	@echo "... QTradingView"
	@echo "... GraphingView.o"
	@echo "... GraphingView.i"
	@echo "... GraphingView.s"
	@echo "... QTradingView_autogen/mocs_compilation.o"
	@echo "... QTradingView_autogen/mocs_compilation.i"
	@echo "... QTradingView_autogen/mocs_compilation.s"
	@echo "... axes.o"
	@echo "... axes.i"
	@echo "... axes.s"
	@echo "... candleBody.o"
	@echo "... candleBody.i"
	@echo "... candleBody.s"
	@echo "... candleStickDataStream.o"
	@echo "... candleStickDataStream.i"
	@echo "... candleStickDataStream.s"
	@echo "... candleStickState.o"
	@echo "... candleStickState.i"
	@echo "... candleStickState.s"
	@echo "... candleStickWick.o"
	@echo "... candleStickWick.i"
	@echo "... candleStickWick.s"
	@echo "... dbManager.o"
	@echo "... dbManager.i"
	@echo "... dbManager.s"
	@echo "... graph.o"
	@echo "... graph.i"
	@echo "... graph.s"
	@echo "... graphTimeFrameNode.o"
	@echo "... graphTimeFrameNode.i"
	@echo "... graphTimeFrameNode.s"
	@echo "... graphWindow.o"
	@echo "... graphWindow.i"
	@echo "... graphWindow.s"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
	@echo "... mainwindow.o"
	@echo "... mainwindow.i"
	@echo "... mainwindow.s"
	@echo "... pathGraphPoint.o"
	@echo "... pathGraphPoint.i"
	@echo "... pathGraphPoint.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

