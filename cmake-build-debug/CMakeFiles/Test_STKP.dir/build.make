# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.9

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Users\netwo\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\173.4127.32\bin\cmake\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\netwo\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\173.4127.32\bin\cmake\bin\cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\netwo\Documents\Asd\Data-structures

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\netwo\Documents\Asd\Data-structures\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Test_STKP.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Test_STKP.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Test_STKP.dir/flags.make

CMakeFiles/Test_STKP.dir/tests/test_main.cpp.obj: CMakeFiles/Test_STKP.dir/flags.make
CMakeFiles/Test_STKP.dir/tests/test_main.cpp.obj: CMakeFiles/Test_STKP.dir/includes_CXX.rsp
CMakeFiles/Test_STKP.dir/tests/test_main.cpp.obj: ../tests/test_main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\netwo\Documents\Asd\Data-structures\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Test_STKP.dir/tests/test_main.cpp.obj"
	C:\Mingw\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Test_STKP.dir\tests\test_main.cpp.obj -c C:\Users\netwo\Documents\Asd\Data-structures\tests\test_main.cpp

CMakeFiles/Test_STKP.dir/tests/test_main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Test_STKP.dir/tests/test_main.cpp.i"
	C:\Mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\netwo\Documents\Asd\Data-structures\tests\test_main.cpp > CMakeFiles\Test_STKP.dir\tests\test_main.cpp.i

CMakeFiles/Test_STKP.dir/tests/test_main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Test_STKP.dir/tests/test_main.cpp.s"
	C:\Mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\netwo\Documents\Asd\Data-structures\tests\test_main.cpp -o CMakeFiles\Test_STKP.dir\tests\test_main.cpp.s

CMakeFiles/Test_STKP.dir/tests/test_main.cpp.obj.requires:

.PHONY : CMakeFiles/Test_STKP.dir/tests/test_main.cpp.obj.requires

CMakeFiles/Test_STKP.dir/tests/test_main.cpp.obj.provides: CMakeFiles/Test_STKP.dir/tests/test_main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\Test_STKP.dir\build.make CMakeFiles/Test_STKP.dir/tests/test_main.cpp.obj.provides.build
.PHONY : CMakeFiles/Test_STKP.dir/tests/test_main.cpp.obj.provides

CMakeFiles/Test_STKP.dir/tests/test_main.cpp.obj.provides.build: CMakeFiles/Test_STKP.dir/tests/test_main.cpp.obj


CMakeFiles/Test_STKP.dir/tests/test_StackPointer.cpp.obj: CMakeFiles/Test_STKP.dir/flags.make
CMakeFiles/Test_STKP.dir/tests/test_StackPointer.cpp.obj: CMakeFiles/Test_STKP.dir/includes_CXX.rsp
CMakeFiles/Test_STKP.dir/tests/test_StackPointer.cpp.obj: ../tests/test_StackPointer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\netwo\Documents\Asd\Data-structures\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Test_STKP.dir/tests/test_StackPointer.cpp.obj"
	C:\Mingw\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Test_STKP.dir\tests\test_StackPointer.cpp.obj -c C:\Users\netwo\Documents\Asd\Data-structures\tests\test_StackPointer.cpp

CMakeFiles/Test_STKP.dir/tests/test_StackPointer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Test_STKP.dir/tests/test_StackPointer.cpp.i"
	C:\Mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\netwo\Documents\Asd\Data-structures\tests\test_StackPointer.cpp > CMakeFiles\Test_STKP.dir\tests\test_StackPointer.cpp.i

CMakeFiles/Test_STKP.dir/tests/test_StackPointer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Test_STKP.dir/tests/test_StackPointer.cpp.s"
	C:\Mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\netwo\Documents\Asd\Data-structures\tests\test_StackPointer.cpp -o CMakeFiles\Test_STKP.dir\tests\test_StackPointer.cpp.s

CMakeFiles/Test_STKP.dir/tests/test_StackPointer.cpp.obj.requires:

.PHONY : CMakeFiles/Test_STKP.dir/tests/test_StackPointer.cpp.obj.requires

CMakeFiles/Test_STKP.dir/tests/test_StackPointer.cpp.obj.provides: CMakeFiles/Test_STKP.dir/tests/test_StackPointer.cpp.obj.requires
	$(MAKE) -f CMakeFiles\Test_STKP.dir\build.make CMakeFiles/Test_STKP.dir/tests/test_StackPointer.cpp.obj.provides.build
.PHONY : CMakeFiles/Test_STKP.dir/tests/test_StackPointer.cpp.obj.provides

CMakeFiles/Test_STKP.dir/tests/test_StackPointer.cpp.obj.provides.build: CMakeFiles/Test_STKP.dir/tests/test_StackPointer.cpp.obj


# Object files for target Test_STKP
Test_STKP_OBJECTS = \
"CMakeFiles/Test_STKP.dir/tests/test_main.cpp.obj" \
"CMakeFiles/Test_STKP.dir/tests/test_StackPointer.cpp.obj"

# External object files for target Test_STKP
Test_STKP_EXTERNAL_OBJECTS =

Test_STKP.exe: CMakeFiles/Test_STKP.dir/tests/test_main.cpp.obj
Test_STKP.exe: CMakeFiles/Test_STKP.dir/tests/test_StackPointer.cpp.obj
Test_STKP.exe: CMakeFiles/Test_STKP.dir/build.make
Test_STKP.exe: lib/googletest/libgtestd.a
Test_STKP.exe: lib/googletest/libgtest_maind.a
Test_STKP.exe: lib/googletest/libgtestd.a
Test_STKP.exe: CMakeFiles/Test_STKP.dir/linklibs.rsp
Test_STKP.exe: CMakeFiles/Test_STKP.dir/objects1.rsp
Test_STKP.exe: CMakeFiles/Test_STKP.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\netwo\Documents\Asd\Data-structures\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Test_STKP.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Test_STKP.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Test_STKP.dir/build: Test_STKP.exe

.PHONY : CMakeFiles/Test_STKP.dir/build

CMakeFiles/Test_STKP.dir/requires: CMakeFiles/Test_STKP.dir/tests/test_main.cpp.obj.requires
CMakeFiles/Test_STKP.dir/requires: CMakeFiles/Test_STKP.dir/tests/test_StackPointer.cpp.obj.requires

.PHONY : CMakeFiles/Test_STKP.dir/requires

CMakeFiles/Test_STKP.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Test_STKP.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Test_STKP.dir/clean

CMakeFiles/Test_STKP.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\netwo\Documents\Asd\Data-structures C:\Users\netwo\Documents\Asd\Data-structures C:\Users\netwo\Documents\Asd\Data-structures\cmake-build-debug C:\Users\netwo\Documents\Asd\Data-structures\cmake-build-debug C:\Users\netwo\Documents\Asd\Data-structures\cmake-build-debug\CMakeFiles\Test_STKP.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Test_STKP.dir/depend

