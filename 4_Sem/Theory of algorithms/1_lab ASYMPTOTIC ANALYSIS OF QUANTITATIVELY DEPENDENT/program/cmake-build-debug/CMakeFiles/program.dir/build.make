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
CMAKE_SOURCE_DIR = "D:\SevSU_IS\4_Sem\Theory of algorithms\1_lab ASYMPTOTIC ANALYSIS OF QUANTITATIVELY DEPENDENT\program"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\SevSU_IS\4_Sem\Theory of algorithms\1_lab ASYMPTOTIC ANALYSIS OF QUANTITATIVELY DEPENDENT\program\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/program.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/program.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/program.dir/flags.make

CMakeFiles/program.dir/main.c.obj: CMakeFiles/program.dir/flags.make
CMakeFiles/program.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\SevSU_IS\4_Sem\Theory of algorithms\1_lab ASYMPTOTIC ANALYSIS OF QUANTITATIVELY DEPENDENT\program\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/program.dir/main.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\program.dir\main.c.obj   -c "D:\SevSU_IS\4_Sem\Theory of algorithms\1_lab ASYMPTOTIC ANALYSIS OF QUANTITATIVELY DEPENDENT\program\main.c"

CMakeFiles/program.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/program.dir/main.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "D:\SevSU_IS\4_Sem\Theory of algorithms\1_lab ASYMPTOTIC ANALYSIS OF QUANTITATIVELY DEPENDENT\program\main.c" > CMakeFiles\program.dir\main.c.i

CMakeFiles/program.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/program.dir/main.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "D:\SevSU_IS\4_Sem\Theory of algorithms\1_lab ASYMPTOTIC ANALYSIS OF QUANTITATIVELY DEPENDENT\program\main.c" -o CMakeFiles\program.dir\main.c.s

# Object files for target program
program_OBJECTS = \
"CMakeFiles/program.dir/main.c.obj"

# External object files for target program
program_EXTERNAL_OBJECTS =

program.exe: CMakeFiles/program.dir/main.c.obj
program.exe: CMakeFiles/program.dir/build.make
program.exe: CMakeFiles/program.dir/linklibs.rsp
program.exe: CMakeFiles/program.dir/objects1.rsp
program.exe: CMakeFiles/program.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\SevSU_IS\4_Sem\Theory of algorithms\1_lab ASYMPTOTIC ANALYSIS OF QUANTITATIVELY DEPENDENT\program\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable program.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\program.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/program.dir/build: program.exe

.PHONY : CMakeFiles/program.dir/build

CMakeFiles/program.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\program.dir\cmake_clean.cmake
.PHONY : CMakeFiles/program.dir/clean

CMakeFiles/program.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\SevSU_IS\4_Sem\Theory of algorithms\1_lab ASYMPTOTIC ANALYSIS OF QUANTITATIVELY DEPENDENT\program" "D:\SevSU_IS\4_Sem\Theory of algorithms\1_lab ASYMPTOTIC ANALYSIS OF QUANTITATIVELY DEPENDENT\program" "D:\SevSU_IS\4_Sem\Theory of algorithms\1_lab ASYMPTOTIC ANALYSIS OF QUANTITATIVELY DEPENDENT\program\cmake-build-debug" "D:\SevSU_IS\4_Sem\Theory of algorithms\1_lab ASYMPTOTIC ANALYSIS OF QUANTITATIVELY DEPENDENT\program\cmake-build-debug" "D:\SevSU_IS\4_Sem\Theory of algorithms\1_lab ASYMPTOTIC ANALYSIS OF QUANTITATIVELY DEPENDENT\program\cmake-build-debug\CMakeFiles\program.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/program.dir/depend

