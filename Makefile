# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

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
CMAKE_COMMAND = "/Applications/CMake 2.8-12.app/Contents/bin/cmake"

# The command to remove a file.
RM = "/Applications/CMake 2.8-12.app/Contents/bin/cmake" -E remove -f

# Escaping for special characters.
EQUALS = =

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = "/Applications/CMake 2.8-12.app/Contents/bin/ccmake"

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/nEwUnivErsE/In-air-interaction/In-air

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/nEwUnivErsE/In-air-interaction/In-air

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	"/Applications/CMake 2.8-12.app/Contents/bin/ccmake" -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	"/Applications/CMake 2.8-12.app/Contents/bin/cmake" -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/nEwUnivErsE/In-air-interaction/In-air/CMakeFiles /Users/nEwUnivErsE/In-air-interaction/In-air/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/nEwUnivErsE/In-air-interaction/In-air/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named In-air

# Build rule for target.
In-air: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 In-air
.PHONY : In-air

# fast build rule for target.
In-air/fast:
	$(MAKE) -f CMakeFiles/In-air.dir/build.make CMakeFiles/In-air.dir/build
.PHONY : In-air/fast

ThirdParty/tinyxml2/tinyxml2.o: ThirdParty/tinyxml2/tinyxml2.cpp.o
.PHONY : ThirdParty/tinyxml2/tinyxml2.o

# target to build an object file
ThirdParty/tinyxml2/tinyxml2.cpp.o:
	$(MAKE) -f CMakeFiles/In-air.dir/build.make CMakeFiles/In-air.dir/ThirdParty/tinyxml2/tinyxml2.cpp.o
.PHONY : ThirdParty/tinyxml2/tinyxml2.cpp.o

ThirdParty/tinyxml2/tinyxml2.i: ThirdParty/tinyxml2/tinyxml2.cpp.i
.PHONY : ThirdParty/tinyxml2/tinyxml2.i

# target to preprocess a source file
ThirdParty/tinyxml2/tinyxml2.cpp.i:
	$(MAKE) -f CMakeFiles/In-air.dir/build.make CMakeFiles/In-air.dir/ThirdParty/tinyxml2/tinyxml2.cpp.i
.PHONY : ThirdParty/tinyxml2/tinyxml2.cpp.i

ThirdParty/tinyxml2/tinyxml2.s: ThirdParty/tinyxml2/tinyxml2.cpp.s
.PHONY : ThirdParty/tinyxml2/tinyxml2.s

# target to generate assembly for a file
ThirdParty/tinyxml2/tinyxml2.cpp.s:
	$(MAKE) -f CMakeFiles/In-air.dir/build.make CMakeFiles/In-air.dir/ThirdParty/tinyxml2/tinyxml2.cpp.s
.PHONY : ThirdParty/tinyxml2/tinyxml2.cpp.s

includes/moc_mainWindowController.o: includes/moc_mainWindowController.cxx.o
.PHONY : includes/moc_mainWindowController.o

# target to build an object file
includes/moc_mainWindowController.cxx.o:
	$(MAKE) -f CMakeFiles/In-air.dir/build.make CMakeFiles/In-air.dir/includes/moc_mainWindowController.cxx.o
.PHONY : includes/moc_mainWindowController.cxx.o

includes/moc_mainWindowController.i: includes/moc_mainWindowController.cxx.i
.PHONY : includes/moc_mainWindowController.i

# target to preprocess a source file
includes/moc_mainWindowController.cxx.i:
	$(MAKE) -f CMakeFiles/In-air.dir/build.make CMakeFiles/In-air.dir/includes/moc_mainWindowController.cxx.i
.PHONY : includes/moc_mainWindowController.cxx.i

includes/moc_mainWindowController.s: includes/moc_mainWindowController.cxx.s
.PHONY : includes/moc_mainWindowController.s

# target to generate assembly for a file
includes/moc_mainWindowController.cxx.s:
	$(MAKE) -f CMakeFiles/In-air.dir/build.make CMakeFiles/In-air.dir/includes/moc_mainWindowController.cxx.s
.PHONY : includes/moc_mainWindowController.cxx.s

main.o: main.cxx.o
.PHONY : main.o

# target to build an object file
main.cxx.o:
	$(MAKE) -f CMakeFiles/In-air.dir/build.make CMakeFiles/In-air.dir/main.cxx.o
.PHONY : main.cxx.o

main.i: main.cxx.i
.PHONY : main.i

# target to preprocess a source file
main.cxx.i:
	$(MAKE) -f CMakeFiles/In-air.dir/build.make CMakeFiles/In-air.dir/main.cxx.i
.PHONY : main.cxx.i

main.s: main.cxx.s
.PHONY : main.s

# target to generate assembly for a file
main.cxx.s:
	$(MAKE) -f CMakeFiles/In-air.dir/build.make CMakeFiles/In-air.dir/main.cxx.s
.PHONY : main.cxx.s

moc_ui_mainWindow.o: moc_ui_mainWindow.cxx.o
.PHONY : moc_ui_mainWindow.o

# target to build an object file
moc_ui_mainWindow.cxx.o:
	$(MAKE) -f CMakeFiles/In-air.dir/build.make CMakeFiles/In-air.dir/moc_ui_mainWindow.cxx.o
.PHONY : moc_ui_mainWindow.cxx.o

moc_ui_mainWindow.i: moc_ui_mainWindow.cxx.i
.PHONY : moc_ui_mainWindow.i

# target to preprocess a source file
moc_ui_mainWindow.cxx.i:
	$(MAKE) -f CMakeFiles/In-air.dir/build.make CMakeFiles/In-air.dir/moc_ui_mainWindow.cxx.i
.PHONY : moc_ui_mainWindow.cxx.i

moc_ui_mainWindow.s: moc_ui_mainWindow.cxx.s
.PHONY : moc_ui_mainWindow.s

# target to generate assembly for a file
moc_ui_mainWindow.cxx.s:
	$(MAKE) -f CMakeFiles/In-air.dir/build.make CMakeFiles/In-air.dir/moc_ui_mainWindow.cxx.s
.PHONY : moc_ui_mainWindow.cxx.s

sources/LeapControllerModel.o: sources/LeapControllerModel.cxx.o
.PHONY : sources/LeapControllerModel.o

# target to build an object file
sources/LeapControllerModel.cxx.o:
	$(MAKE) -f CMakeFiles/In-air.dir/build.make CMakeFiles/In-air.dir/sources/LeapControllerModel.cxx.o
.PHONY : sources/LeapControllerModel.cxx.o

sources/LeapControllerModel.i: sources/LeapControllerModel.cxx.i
.PHONY : sources/LeapControllerModel.i

# target to preprocess a source file
sources/LeapControllerModel.cxx.i:
	$(MAKE) -f CMakeFiles/In-air.dir/build.make CMakeFiles/In-air.dir/sources/LeapControllerModel.cxx.i
.PHONY : sources/LeapControllerModel.cxx.i

sources/LeapControllerModel.s: sources/LeapControllerModel.cxx.s
.PHONY : sources/LeapControllerModel.s

# target to generate assembly for a file
sources/LeapControllerModel.cxx.s:
	$(MAKE) -f CMakeFiles/In-air.dir/build.make CMakeFiles/In-air.dir/sources/LeapControllerModel.cxx.s
.PHONY : sources/LeapControllerModel.cxx.s

sources/LeapListener.o: sources/LeapListener.cpp.o
.PHONY : sources/LeapListener.o

# target to build an object file
sources/LeapListener.cpp.o:
	$(MAKE) -f CMakeFiles/In-air.dir/build.make CMakeFiles/In-air.dir/sources/LeapListener.cpp.o
.PHONY : sources/LeapListener.cpp.o

sources/LeapListener.i: sources/LeapListener.cpp.i
.PHONY : sources/LeapListener.i

# target to preprocess a source file
sources/LeapListener.cpp.i:
	$(MAKE) -f CMakeFiles/In-air.dir/build.make CMakeFiles/In-air.dir/sources/LeapListener.cpp.i
.PHONY : sources/LeapListener.cpp.i

sources/LeapListener.s: sources/LeapListener.cpp.s
.PHONY : sources/LeapListener.s

# target to generate assembly for a file
sources/LeapListener.cpp.s:
	$(MAKE) -f CMakeFiles/In-air.dir/build.make CMakeFiles/In-air.dir/sources/LeapListener.cpp.s
.PHONY : sources/LeapListener.cpp.s

sources/graphicalModel.o: sources/graphicalModel.cxx.o
.PHONY : sources/graphicalModel.o

# target to build an object file
sources/graphicalModel.cxx.o:
	$(MAKE) -f CMakeFiles/In-air.dir/build.make CMakeFiles/In-air.dir/sources/graphicalModel.cxx.o
.PHONY : sources/graphicalModel.cxx.o

sources/graphicalModel.i: sources/graphicalModel.cxx.i
.PHONY : sources/graphicalModel.i

# target to preprocess a source file
sources/graphicalModel.cxx.i:
	$(MAKE) -f CMakeFiles/In-air.dir/build.make CMakeFiles/In-air.dir/sources/graphicalModel.cxx.i
.PHONY : sources/graphicalModel.cxx.i

sources/graphicalModel.s: sources/graphicalModel.cxx.s
.PHONY : sources/graphicalModel.s

# target to generate assembly for a file
sources/graphicalModel.cxx.s:
	$(MAKE) -f CMakeFiles/In-air.dir/build.make CMakeFiles/In-air.dir/sources/graphicalModel.cxx.s
.PHONY : sources/graphicalModel.cxx.s

sources/mainWindowController.o: sources/mainWindowController.cxx.o
.PHONY : sources/mainWindowController.o

# target to build an object file
sources/mainWindowController.cxx.o:
	$(MAKE) -f CMakeFiles/In-air.dir/build.make CMakeFiles/In-air.dir/sources/mainWindowController.cxx.o
.PHONY : sources/mainWindowController.cxx.o

sources/mainWindowController.i: sources/mainWindowController.cxx.i
.PHONY : sources/mainWindowController.i

# target to preprocess a source file
sources/mainWindowController.cxx.i:
	$(MAKE) -f CMakeFiles/In-air.dir/build.make CMakeFiles/In-air.dir/sources/mainWindowController.cxx.i
.PHONY : sources/mainWindowController.cxx.i

sources/mainWindowController.s: sources/mainWindowController.cxx.s
.PHONY : sources/mainWindowController.s

# target to generate assembly for a file
sources/mainWindowController.cxx.s:
	$(MAKE) -f CMakeFiles/In-air.dir/build.make CMakeFiles/In-air.dir/sources/mainWindowController.cxx.s
.PHONY : sources/mainWindowController.cxx.s

sources/robotModel.o: sources/robotModel.cxx.o
.PHONY : sources/robotModel.o

# target to build an object file
sources/robotModel.cxx.o:
	$(MAKE) -f CMakeFiles/In-air.dir/build.make CMakeFiles/In-air.dir/sources/robotModel.cxx.o
.PHONY : sources/robotModel.cxx.o

sources/robotModel.i: sources/robotModel.cxx.i
.PHONY : sources/robotModel.i

# target to preprocess a source file
sources/robotModel.cxx.i:
	$(MAKE) -f CMakeFiles/In-air.dir/build.make CMakeFiles/In-air.dir/sources/robotModel.cxx.i
.PHONY : sources/robotModel.cxx.i

sources/robotModel.s: sources/robotModel.cxx.s
.PHONY : sources/robotModel.s

# target to generate assembly for a file
sources/robotModel.cxx.s:
	$(MAKE) -f CMakeFiles/In-air.dir/build.make CMakeFiles/In-air.dir/sources/robotModel.cxx.s
.PHONY : sources/robotModel.cxx.s

sources/toolModel.o: sources/toolModel.cxx.o
.PHONY : sources/toolModel.o

# target to build an object file
sources/toolModel.cxx.o:
	$(MAKE) -f CMakeFiles/In-air.dir/build.make CMakeFiles/In-air.dir/sources/toolModel.cxx.o
.PHONY : sources/toolModel.cxx.o

sources/toolModel.i: sources/toolModel.cxx.i
.PHONY : sources/toolModel.i

# target to preprocess a source file
sources/toolModel.cxx.i:
	$(MAKE) -f CMakeFiles/In-air.dir/build.make CMakeFiles/In-air.dir/sources/toolModel.cxx.i
.PHONY : sources/toolModel.cxx.i

sources/toolModel.s: sources/toolModel.cxx.s
.PHONY : sources/toolModel.s

# target to generate assembly for a file
sources/toolModel.cxx.s:
	$(MAKE) -f CMakeFiles/In-air.dir/build.make CMakeFiles/In-air.dir/sources/toolModel.cxx.s
.PHONY : sources/toolModel.cxx.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... In-air"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... ThirdParty/tinyxml2/tinyxml2.o"
	@echo "... ThirdParty/tinyxml2/tinyxml2.i"
	@echo "... ThirdParty/tinyxml2/tinyxml2.s"
	@echo "... includes/moc_mainWindowController.o"
	@echo "... includes/moc_mainWindowController.i"
	@echo "... includes/moc_mainWindowController.s"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
	@echo "... moc_ui_mainWindow.o"
	@echo "... moc_ui_mainWindow.i"
	@echo "... moc_ui_mainWindow.s"
	@echo "... sources/LeapControllerModel.o"
	@echo "... sources/LeapControllerModel.i"
	@echo "... sources/LeapControllerModel.s"
	@echo "... sources/LeapListener.o"
	@echo "... sources/LeapListener.i"
	@echo "... sources/LeapListener.s"
	@echo "... sources/graphicalModel.o"
	@echo "... sources/graphicalModel.i"
	@echo "... sources/graphicalModel.s"
	@echo "... sources/mainWindowController.o"
	@echo "... sources/mainWindowController.i"
	@echo "... sources/mainWindowController.s"
	@echo "... sources/robotModel.o"
	@echo "... sources/robotModel.i"
	@echo "... sources/robotModel.s"
	@echo "... sources/toolModel.o"
	@echo "... sources/toolModel.i"
	@echo "... sources/toolModel.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

