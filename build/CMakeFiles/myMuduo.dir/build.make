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
CMAKE_SOURCE_DIR = /home/yyf/Pro/myMuduo

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/yyf/Pro/myMuduo/build

# Include any dependencies generated for this target.
include CMakeFiles/myMuduo.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/myMuduo.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/myMuduo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/myMuduo.dir/flags.make

CMakeFiles/myMuduo.dir/Channel.o: CMakeFiles/myMuduo.dir/flags.make
CMakeFiles/myMuduo.dir/Channel.o: /home/yyf/Pro/myMuduo/Channel.cc
CMakeFiles/myMuduo.dir/Channel.o: CMakeFiles/myMuduo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/yyf/Pro/myMuduo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/myMuduo.dir/Channel.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/myMuduo.dir/Channel.o -MF CMakeFiles/myMuduo.dir/Channel.o.d -o CMakeFiles/myMuduo.dir/Channel.o -c /home/yyf/Pro/myMuduo/Channel.cc

CMakeFiles/myMuduo.dir/Channel.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/myMuduo.dir/Channel.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yyf/Pro/myMuduo/Channel.cc > CMakeFiles/myMuduo.dir/Channel.i

CMakeFiles/myMuduo.dir/Channel.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/myMuduo.dir/Channel.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yyf/Pro/myMuduo/Channel.cc -o CMakeFiles/myMuduo.dir/Channel.s

CMakeFiles/myMuduo.dir/DefaultPoller.o: CMakeFiles/myMuduo.dir/flags.make
CMakeFiles/myMuduo.dir/DefaultPoller.o: /home/yyf/Pro/myMuduo/DefaultPoller.cc
CMakeFiles/myMuduo.dir/DefaultPoller.o: CMakeFiles/myMuduo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/yyf/Pro/myMuduo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/myMuduo.dir/DefaultPoller.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/myMuduo.dir/DefaultPoller.o -MF CMakeFiles/myMuduo.dir/DefaultPoller.o.d -o CMakeFiles/myMuduo.dir/DefaultPoller.o -c /home/yyf/Pro/myMuduo/DefaultPoller.cc

CMakeFiles/myMuduo.dir/DefaultPoller.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/myMuduo.dir/DefaultPoller.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yyf/Pro/myMuduo/DefaultPoller.cc > CMakeFiles/myMuduo.dir/DefaultPoller.i

CMakeFiles/myMuduo.dir/DefaultPoller.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/myMuduo.dir/DefaultPoller.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yyf/Pro/myMuduo/DefaultPoller.cc -o CMakeFiles/myMuduo.dir/DefaultPoller.s

CMakeFiles/myMuduo.dir/EpollPoller.o: CMakeFiles/myMuduo.dir/flags.make
CMakeFiles/myMuduo.dir/EpollPoller.o: /home/yyf/Pro/myMuduo/EpollPoller.cc
CMakeFiles/myMuduo.dir/EpollPoller.o: CMakeFiles/myMuduo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/yyf/Pro/myMuduo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/myMuduo.dir/EpollPoller.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/myMuduo.dir/EpollPoller.o -MF CMakeFiles/myMuduo.dir/EpollPoller.o.d -o CMakeFiles/myMuduo.dir/EpollPoller.o -c /home/yyf/Pro/myMuduo/EpollPoller.cc

CMakeFiles/myMuduo.dir/EpollPoller.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/myMuduo.dir/EpollPoller.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yyf/Pro/myMuduo/EpollPoller.cc > CMakeFiles/myMuduo.dir/EpollPoller.i

CMakeFiles/myMuduo.dir/EpollPoller.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/myMuduo.dir/EpollPoller.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yyf/Pro/myMuduo/EpollPoller.cc -o CMakeFiles/myMuduo.dir/EpollPoller.s

CMakeFiles/myMuduo.dir/EventLoop.o: CMakeFiles/myMuduo.dir/flags.make
CMakeFiles/myMuduo.dir/EventLoop.o: /home/yyf/Pro/myMuduo/EventLoop.cc
CMakeFiles/myMuduo.dir/EventLoop.o: CMakeFiles/myMuduo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/yyf/Pro/myMuduo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/myMuduo.dir/EventLoop.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/myMuduo.dir/EventLoop.o -MF CMakeFiles/myMuduo.dir/EventLoop.o.d -o CMakeFiles/myMuduo.dir/EventLoop.o -c /home/yyf/Pro/myMuduo/EventLoop.cc

CMakeFiles/myMuduo.dir/EventLoop.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/myMuduo.dir/EventLoop.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yyf/Pro/myMuduo/EventLoop.cc > CMakeFiles/myMuduo.dir/EventLoop.i

CMakeFiles/myMuduo.dir/EventLoop.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/myMuduo.dir/EventLoop.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yyf/Pro/myMuduo/EventLoop.cc -o CMakeFiles/myMuduo.dir/EventLoop.s

CMakeFiles/myMuduo.dir/InetAddress.o: CMakeFiles/myMuduo.dir/flags.make
CMakeFiles/myMuduo.dir/InetAddress.o: /home/yyf/Pro/myMuduo/InetAddress.cc
CMakeFiles/myMuduo.dir/InetAddress.o: CMakeFiles/myMuduo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/yyf/Pro/myMuduo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/myMuduo.dir/InetAddress.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/myMuduo.dir/InetAddress.o -MF CMakeFiles/myMuduo.dir/InetAddress.o.d -o CMakeFiles/myMuduo.dir/InetAddress.o -c /home/yyf/Pro/myMuduo/InetAddress.cc

CMakeFiles/myMuduo.dir/InetAddress.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/myMuduo.dir/InetAddress.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yyf/Pro/myMuduo/InetAddress.cc > CMakeFiles/myMuduo.dir/InetAddress.i

CMakeFiles/myMuduo.dir/InetAddress.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/myMuduo.dir/InetAddress.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yyf/Pro/myMuduo/InetAddress.cc -o CMakeFiles/myMuduo.dir/InetAddress.s

CMakeFiles/myMuduo.dir/Logger.o: CMakeFiles/myMuduo.dir/flags.make
CMakeFiles/myMuduo.dir/Logger.o: /home/yyf/Pro/myMuduo/Logger.cc
CMakeFiles/myMuduo.dir/Logger.o: CMakeFiles/myMuduo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/yyf/Pro/myMuduo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/myMuduo.dir/Logger.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/myMuduo.dir/Logger.o -MF CMakeFiles/myMuduo.dir/Logger.o.d -o CMakeFiles/myMuduo.dir/Logger.o -c /home/yyf/Pro/myMuduo/Logger.cc

CMakeFiles/myMuduo.dir/Logger.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/myMuduo.dir/Logger.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yyf/Pro/myMuduo/Logger.cc > CMakeFiles/myMuduo.dir/Logger.i

CMakeFiles/myMuduo.dir/Logger.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/myMuduo.dir/Logger.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yyf/Pro/myMuduo/Logger.cc -o CMakeFiles/myMuduo.dir/Logger.s

CMakeFiles/myMuduo.dir/Poller.o: CMakeFiles/myMuduo.dir/flags.make
CMakeFiles/myMuduo.dir/Poller.o: /home/yyf/Pro/myMuduo/Poller.cc
CMakeFiles/myMuduo.dir/Poller.o: CMakeFiles/myMuduo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/yyf/Pro/myMuduo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/myMuduo.dir/Poller.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/myMuduo.dir/Poller.o -MF CMakeFiles/myMuduo.dir/Poller.o.d -o CMakeFiles/myMuduo.dir/Poller.o -c /home/yyf/Pro/myMuduo/Poller.cc

CMakeFiles/myMuduo.dir/Poller.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/myMuduo.dir/Poller.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yyf/Pro/myMuduo/Poller.cc > CMakeFiles/myMuduo.dir/Poller.i

CMakeFiles/myMuduo.dir/Poller.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/myMuduo.dir/Poller.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yyf/Pro/myMuduo/Poller.cc -o CMakeFiles/myMuduo.dir/Poller.s

CMakeFiles/myMuduo.dir/TcpServer.o: CMakeFiles/myMuduo.dir/flags.make
CMakeFiles/myMuduo.dir/TcpServer.o: /home/yyf/Pro/myMuduo/TcpServer.cc
CMakeFiles/myMuduo.dir/TcpServer.o: CMakeFiles/myMuduo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/yyf/Pro/myMuduo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/myMuduo.dir/TcpServer.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/myMuduo.dir/TcpServer.o -MF CMakeFiles/myMuduo.dir/TcpServer.o.d -o CMakeFiles/myMuduo.dir/TcpServer.o -c /home/yyf/Pro/myMuduo/TcpServer.cc

CMakeFiles/myMuduo.dir/TcpServer.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/myMuduo.dir/TcpServer.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yyf/Pro/myMuduo/TcpServer.cc > CMakeFiles/myMuduo.dir/TcpServer.i

CMakeFiles/myMuduo.dir/TcpServer.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/myMuduo.dir/TcpServer.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yyf/Pro/myMuduo/TcpServer.cc -o CMakeFiles/myMuduo.dir/TcpServer.s

CMakeFiles/myMuduo.dir/TimeStamp.o: CMakeFiles/myMuduo.dir/flags.make
CMakeFiles/myMuduo.dir/TimeStamp.o: /home/yyf/Pro/myMuduo/TimeStamp.cc
CMakeFiles/myMuduo.dir/TimeStamp.o: CMakeFiles/myMuduo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/yyf/Pro/myMuduo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/myMuduo.dir/TimeStamp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/myMuduo.dir/TimeStamp.o -MF CMakeFiles/myMuduo.dir/TimeStamp.o.d -o CMakeFiles/myMuduo.dir/TimeStamp.o -c /home/yyf/Pro/myMuduo/TimeStamp.cc

CMakeFiles/myMuduo.dir/TimeStamp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/myMuduo.dir/TimeStamp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yyf/Pro/myMuduo/TimeStamp.cc > CMakeFiles/myMuduo.dir/TimeStamp.i

CMakeFiles/myMuduo.dir/TimeStamp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/myMuduo.dir/TimeStamp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yyf/Pro/myMuduo/TimeStamp.cc -o CMakeFiles/myMuduo.dir/TimeStamp.s

# Object files for target myMuduo
myMuduo_OBJECTS = \
"CMakeFiles/myMuduo.dir/Channel.o" \
"CMakeFiles/myMuduo.dir/DefaultPoller.o" \
"CMakeFiles/myMuduo.dir/EpollPoller.o" \
"CMakeFiles/myMuduo.dir/EventLoop.o" \
"CMakeFiles/myMuduo.dir/InetAddress.o" \
"CMakeFiles/myMuduo.dir/Logger.o" \
"CMakeFiles/myMuduo.dir/Poller.o" \
"CMakeFiles/myMuduo.dir/TcpServer.o" \
"CMakeFiles/myMuduo.dir/TimeStamp.o"

# External object files for target myMuduo
myMuduo_EXTERNAL_OBJECTS =

/home/yyf/Pro/myMuduo/lib/libmyMuduo.so: CMakeFiles/myMuduo.dir/Channel.o
/home/yyf/Pro/myMuduo/lib/libmyMuduo.so: CMakeFiles/myMuduo.dir/DefaultPoller.o
/home/yyf/Pro/myMuduo/lib/libmyMuduo.so: CMakeFiles/myMuduo.dir/EpollPoller.o
/home/yyf/Pro/myMuduo/lib/libmyMuduo.so: CMakeFiles/myMuduo.dir/EventLoop.o
/home/yyf/Pro/myMuduo/lib/libmyMuduo.so: CMakeFiles/myMuduo.dir/InetAddress.o
/home/yyf/Pro/myMuduo/lib/libmyMuduo.so: CMakeFiles/myMuduo.dir/Logger.o
/home/yyf/Pro/myMuduo/lib/libmyMuduo.so: CMakeFiles/myMuduo.dir/Poller.o
/home/yyf/Pro/myMuduo/lib/libmyMuduo.so: CMakeFiles/myMuduo.dir/TcpServer.o
/home/yyf/Pro/myMuduo/lib/libmyMuduo.so: CMakeFiles/myMuduo.dir/TimeStamp.o
/home/yyf/Pro/myMuduo/lib/libmyMuduo.so: CMakeFiles/myMuduo.dir/build.make
/home/yyf/Pro/myMuduo/lib/libmyMuduo.so: CMakeFiles/myMuduo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/yyf/Pro/myMuduo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX shared library /home/yyf/Pro/myMuduo/lib/libmyMuduo.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/myMuduo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/myMuduo.dir/build: /home/yyf/Pro/myMuduo/lib/libmyMuduo.so
.PHONY : CMakeFiles/myMuduo.dir/build

CMakeFiles/myMuduo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/myMuduo.dir/cmake_clean.cmake
.PHONY : CMakeFiles/myMuduo.dir/clean

CMakeFiles/myMuduo.dir/depend:
	cd /home/yyf/Pro/myMuduo/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/yyf/Pro/myMuduo /home/yyf/Pro/myMuduo /home/yyf/Pro/myMuduo/build /home/yyf/Pro/myMuduo/build /home/yyf/Pro/myMuduo/build/CMakeFiles/myMuduo.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/myMuduo.dir/depend

