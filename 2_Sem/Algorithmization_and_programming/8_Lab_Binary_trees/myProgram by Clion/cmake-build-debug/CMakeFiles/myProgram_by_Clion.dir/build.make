# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.1\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\SevSu\2_sem\A i P\8\myProgram by Clion"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\SevSu\2_sem\A i P\8\myProgram by Clion\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/myProgram_by_Clion.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/myProgram_by_Clion.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/myProgram_by_Clion.dir/flags.make

CMakeFiles/myProgram_by_Clion.dir/main.c.obj: CMakeFiles/myProgram_by_Clion.dir/flags.make
CMakeFiles/myProgram_by_Clion.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\SevSu\2_sem\A i P\8\myProgram by Clion\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/myProgram_by_Clion.dir/main.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\myProgram_by_Clion.dir\main.c.obj   -c "D:\SevSu\2_sem\A i P\8\myProgram by Clion\main.c"

CMakeFiles/myProgram_by_Clion.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/myProgram_by_Clion.dir/main.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "D:\SevSu\2_sem\A i P\8\myProgram by Clion\main.c" > CMakeFiles\myProgram_by_Clion.dir\main.c.i

CMakeFiles/myProgram_by_Clion.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/myProgram_by_Clion.dir/main.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "D:\SevSu\2_sem\A i P\8\myProgram by Clion\main.c" -o CMakeFiles\myProgram_by_Clion.dir\main.c.s

# Object files for target myProgram_by_Clion
myProgram_by_Clion_OBJECTS = \
"CMakeFiles/myProgram_by_Clion.dir/main.c.obj"

# External object files for target myProgram_by_Clion
myProgram_by_Clion_EXTERNAL_OBJECTS =

myProgram_by_Clion.exe: CMakeFiles/myProgram_by_Clion.dir/main.c.obj
myProgram_by_Clion.exe: CMakeFiles/myProgram_by_Clion.dir/build.make
myProgram_by_Clion.exe: CMakeFiles/myProgram_by_Clion.dir/linklibs.rsp
myProgram_by_Clion.exe: CMakeFiles/myProgram_by_Clion.dir/objects1.rsp
myProgram_by_Clion.exe: CMakeFiles/myProgram_by_Clion.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\SevSu\2_sem\A i P\8\myProgram by Clion\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable myProgram_by_Clion.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\myProgram_by_Clion.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/myProgram_by_Clion.dir/build: myProgram_by_Clion.exe

.PHONY : CMakeFiles/myProgram_by_Clion.dir/build

CMakeFiles/myProgram_by_Clion.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\myProgram_by_Clion.dir\cmake_clean.cmake
.PHONY : CMakeFiles/myProgram_by_Clion.dir/clean

CMakeFiles/myProgram_by_Clion.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\SevSu\2_sem\A i P\8\myProgram by Clion" "D:\SevSu\2_sem\A i P\8\myProgram by Clion" "D:\SevSu\2_sem\A i P\8\myProgram by Clion\cmake-build-debug" "D:\SevSu\2_sem\A i P\8\myProgram by Clion\cmake-build-debug" "D:\SevSu\2_sem\A i P\8\myProgram by Clion\cmake-build-debug\CMakeFiles\myProgram_by_Clion.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/myProgram_by_Clion.dir/depend

