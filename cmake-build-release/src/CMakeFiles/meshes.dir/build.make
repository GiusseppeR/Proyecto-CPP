# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.28

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2024.1.1\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2024.1.1\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\rober\CLionProjects\Proyecto-CPP

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\rober\CLionProjects\Proyecto-CPP\cmake-build-release

# Include any dependencies generated for this target.
include src/CMakeFiles/meshes.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/meshes.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/meshes.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/meshes.dir/flags.make

src/CMakeFiles/meshes.dir/Point.cpp.obj: src/CMakeFiles/meshes.dir/flags.make
src/CMakeFiles/meshes.dir/Point.cpp.obj: src/CMakeFiles/meshes.dir/includes_CXX.rsp
src/CMakeFiles/meshes.dir/Point.cpp.obj: C:/Users/rober/CLionProjects/Proyecto-CPP/src/Point.cpp
src/CMakeFiles/meshes.dir/Point.cpp.obj: src/CMakeFiles/meshes.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\rober\CLionProjects\Proyecto-CPP\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/meshes.dir/Point.cpp.obj"
	cd /d C:\Users\rober\CLionProjects\Proyecto-CPP\cmake-build-release\src && C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/meshes.dir/Point.cpp.obj -MF CMakeFiles\meshes.dir\Point.cpp.obj.d -o CMakeFiles\meshes.dir\Point.cpp.obj -c C:\Users\rober\CLionProjects\Proyecto-CPP\src\Point.cpp

src/CMakeFiles/meshes.dir/Point.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/meshes.dir/Point.cpp.i"
	cd /d C:\Users\rober\CLionProjects\Proyecto-CPP\cmake-build-release\src && C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\rober\CLionProjects\Proyecto-CPP\src\Point.cpp > CMakeFiles\meshes.dir\Point.cpp.i

src/CMakeFiles/meshes.dir/Point.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/meshes.dir/Point.cpp.s"
	cd /d C:\Users\rober\CLionProjects\Proyecto-CPP\cmake-build-release\src && C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\rober\CLionProjects\Proyecto-CPP\src\Point.cpp -o CMakeFiles\meshes.dir\Point.cpp.s

src/CMakeFiles/meshes.dir/Polyhedron.cpp.obj: src/CMakeFiles/meshes.dir/flags.make
src/CMakeFiles/meshes.dir/Polyhedron.cpp.obj: src/CMakeFiles/meshes.dir/includes_CXX.rsp
src/CMakeFiles/meshes.dir/Polyhedron.cpp.obj: C:/Users/rober/CLionProjects/Proyecto-CPP/src/Polyhedron.cpp
src/CMakeFiles/meshes.dir/Polyhedron.cpp.obj: src/CMakeFiles/meshes.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\rober\CLionProjects\Proyecto-CPP\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/meshes.dir/Polyhedron.cpp.obj"
	cd /d C:\Users\rober\CLionProjects\Proyecto-CPP\cmake-build-release\src && C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/meshes.dir/Polyhedron.cpp.obj -MF CMakeFiles\meshes.dir\Polyhedron.cpp.obj.d -o CMakeFiles\meshes.dir\Polyhedron.cpp.obj -c C:\Users\rober\CLionProjects\Proyecto-CPP\src\Polyhedron.cpp

src/CMakeFiles/meshes.dir/Polyhedron.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/meshes.dir/Polyhedron.cpp.i"
	cd /d C:\Users\rober\CLionProjects\Proyecto-CPP\cmake-build-release\src && C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\rober\CLionProjects\Proyecto-CPP\src\Polyhedron.cpp > CMakeFiles\meshes.dir\Polyhedron.cpp.i

src/CMakeFiles/meshes.dir/Polyhedron.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/meshes.dir/Polyhedron.cpp.s"
	cd /d C:\Users\rober\CLionProjects\Proyecto-CPP\cmake-build-release\src && C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\rober\CLionProjects\Proyecto-CPP\src\Polyhedron.cpp -o CMakeFiles\meshes.dir\Polyhedron.cpp.s

src/CMakeFiles/meshes.dir/Parser.cpp.obj: src/CMakeFiles/meshes.dir/flags.make
src/CMakeFiles/meshes.dir/Parser.cpp.obj: src/CMakeFiles/meshes.dir/includes_CXX.rsp
src/CMakeFiles/meshes.dir/Parser.cpp.obj: C:/Users/rober/CLionProjects/Proyecto-CPP/src/Parser.cpp
src/CMakeFiles/meshes.dir/Parser.cpp.obj: src/CMakeFiles/meshes.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\rober\CLionProjects\Proyecto-CPP\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/meshes.dir/Parser.cpp.obj"
	cd /d C:\Users\rober\CLionProjects\Proyecto-CPP\cmake-build-release\src && C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/meshes.dir/Parser.cpp.obj -MF CMakeFiles\meshes.dir\Parser.cpp.obj.d -o CMakeFiles\meshes.dir\Parser.cpp.obj -c C:\Users\rober\CLionProjects\Proyecto-CPP\src\Parser.cpp

src/CMakeFiles/meshes.dir/Parser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/meshes.dir/Parser.cpp.i"
	cd /d C:\Users\rober\CLionProjects\Proyecto-CPP\cmake-build-release\src && C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\rober\CLionProjects\Proyecto-CPP\src\Parser.cpp > CMakeFiles\meshes.dir\Parser.cpp.i

src/CMakeFiles/meshes.dir/Parser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/meshes.dir/Parser.cpp.s"
	cd /d C:\Users\rober\CLionProjects\Proyecto-CPP\cmake-build-release\src && C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\rober\CLionProjects\Proyecto-CPP\src\Parser.cpp -o CMakeFiles\meshes.dir\Parser.cpp.s

src/CMakeFiles/meshes.dir/Triangle.cpp.obj: src/CMakeFiles/meshes.dir/flags.make
src/CMakeFiles/meshes.dir/Triangle.cpp.obj: src/CMakeFiles/meshes.dir/includes_CXX.rsp
src/CMakeFiles/meshes.dir/Triangle.cpp.obj: C:/Users/rober/CLionProjects/Proyecto-CPP/src/Triangle.cpp
src/CMakeFiles/meshes.dir/Triangle.cpp.obj: src/CMakeFiles/meshes.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\rober\CLionProjects\Proyecto-CPP\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/CMakeFiles/meshes.dir/Triangle.cpp.obj"
	cd /d C:\Users\rober\CLionProjects\Proyecto-CPP\cmake-build-release\src && C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/meshes.dir/Triangle.cpp.obj -MF CMakeFiles\meshes.dir\Triangle.cpp.obj.d -o CMakeFiles\meshes.dir\Triangle.cpp.obj -c C:\Users\rober\CLionProjects\Proyecto-CPP\src\Triangle.cpp

src/CMakeFiles/meshes.dir/Triangle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/meshes.dir/Triangle.cpp.i"
	cd /d C:\Users\rober\CLionProjects\Proyecto-CPP\cmake-build-release\src && C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\rober\CLionProjects\Proyecto-CPP\src\Triangle.cpp > CMakeFiles\meshes.dir\Triangle.cpp.i

src/CMakeFiles/meshes.dir/Triangle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/meshes.dir/Triangle.cpp.s"
	cd /d C:\Users\rober\CLionProjects\Proyecto-CPP\cmake-build-release\src && C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\rober\CLionProjects\Proyecto-CPP\src\Triangle.cpp -o CMakeFiles\meshes.dir\Triangle.cpp.s

src/CMakeFiles/meshes.dir/algorithms.cpp.obj: src/CMakeFiles/meshes.dir/flags.make
src/CMakeFiles/meshes.dir/algorithms.cpp.obj: src/CMakeFiles/meshes.dir/includes_CXX.rsp
src/CMakeFiles/meshes.dir/algorithms.cpp.obj: C:/Users/rober/CLionProjects/Proyecto-CPP/src/algorithms.cpp
src/CMakeFiles/meshes.dir/algorithms.cpp.obj: src/CMakeFiles/meshes.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\rober\CLionProjects\Proyecto-CPP\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/CMakeFiles/meshes.dir/algorithms.cpp.obj"
	cd /d C:\Users\rober\CLionProjects\Proyecto-CPP\cmake-build-release\src && C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/meshes.dir/algorithms.cpp.obj -MF CMakeFiles\meshes.dir\algorithms.cpp.obj.d -o CMakeFiles\meshes.dir\algorithms.cpp.obj -c C:\Users\rober\CLionProjects\Proyecto-CPP\src\algorithms.cpp

src/CMakeFiles/meshes.dir/algorithms.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/meshes.dir/algorithms.cpp.i"
	cd /d C:\Users\rober\CLionProjects\Proyecto-CPP\cmake-build-release\src && C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\rober\CLionProjects\Proyecto-CPP\src\algorithms.cpp > CMakeFiles\meshes.dir\algorithms.cpp.i

src/CMakeFiles/meshes.dir/algorithms.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/meshes.dir/algorithms.cpp.s"
	cd /d C:\Users\rober\CLionProjects\Proyecto-CPP\cmake-build-release\src && C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\rober\CLionProjects\Proyecto-CPP\src\algorithms.cpp -o CMakeFiles\meshes.dir\algorithms.cpp.s

# Object files for target meshes
meshes_OBJECTS = \
"CMakeFiles/meshes.dir/Point.cpp.obj" \
"CMakeFiles/meshes.dir/Polyhedron.cpp.obj" \
"CMakeFiles/meshes.dir/Parser.cpp.obj" \
"CMakeFiles/meshes.dir/Triangle.cpp.obj" \
"CMakeFiles/meshes.dir/algorithms.cpp.obj"

# External object files for target meshes
meshes_EXTERNAL_OBJECTS =

src/libmeshes.a: src/CMakeFiles/meshes.dir/Point.cpp.obj
src/libmeshes.a: src/CMakeFiles/meshes.dir/Polyhedron.cpp.obj
src/libmeshes.a: src/CMakeFiles/meshes.dir/Parser.cpp.obj
src/libmeshes.a: src/CMakeFiles/meshes.dir/Triangle.cpp.obj
src/libmeshes.a: src/CMakeFiles/meshes.dir/algorithms.cpp.obj
src/libmeshes.a: src/CMakeFiles/meshes.dir/build.make
src/libmeshes.a: src/CMakeFiles/meshes.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\rober\CLionProjects\Proyecto-CPP\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX static library libmeshes.a"
	cd /d C:\Users\rober\CLionProjects\Proyecto-CPP\cmake-build-release\src && $(CMAKE_COMMAND) -P CMakeFiles\meshes.dir\cmake_clean_target.cmake
	cd /d C:\Users\rober\CLionProjects\Proyecto-CPP\cmake-build-release\src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\meshes.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/meshes.dir/build: src/libmeshes.a
.PHONY : src/CMakeFiles/meshes.dir/build

src/CMakeFiles/meshes.dir/clean:
	cd /d C:\Users\rober\CLionProjects\Proyecto-CPP\cmake-build-release\src && $(CMAKE_COMMAND) -P CMakeFiles\meshes.dir\cmake_clean.cmake
.PHONY : src/CMakeFiles/meshes.dir/clean

src/CMakeFiles/meshes.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\rober\CLionProjects\Proyecto-CPP C:\Users\rober\CLionProjects\Proyecto-CPP\src C:\Users\rober\CLionProjects\Proyecto-CPP\cmake-build-release C:\Users\rober\CLionProjects\Proyecto-CPP\cmake-build-release\src C:\Users\rober\CLionProjects\Proyecto-CPP\cmake-build-release\src\CMakeFiles\meshes.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : src/CMakeFiles/meshes.dir/depend

