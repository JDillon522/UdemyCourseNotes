/**
 * GDB - Gnu Project Debugging Tool
 * 
 * the app must be compiled with the `-g` option for gdb to work
 * from the command line: `gdb <binary file>
 * Will startup and then give you the gdb prompt: (gdb)
 *
 * GDB Command prompt commands:
 * run [args,...]       : start the program. It will run without breakpoints
 * show args            : see current cmd line args
 * quit                 : exit the GDB command prompt
 * info source          : get info about the current source file
 * help [command]       : get info on commands
 * 
 * list <func name>     : list all the lines of a function
 * list <line number>   : give code four lines before and after <line number>. Hit rtn to get more lines
 * list <line num>:<line num> : get the code between two line numbers
 * list ++ | --          : list next 10 or previous 10 lines
 *  
 * print <var name>     : give the value of a variable at time of crash
 * - shorthand: p
 * 
 * set var <var name>   : set a variable 
 * set var <func name>::<var name> : set the value of an inactive variable 
 * set var <file name>::<var name> : set global variable defined in a file
 * set var <ptr name>-><var name> : set the value of a struct pointer
 * 
 * info break          : see all breakpoints
 * break <line number> : set breakpoint on a line
 * break <func name>   : set a breakpoint on the first line of a function
 * break <file name>:<func or line> : set a breakpoint in a different file
 * continue            : continue execution
 * - shorthand: c
 * step [X number of lines] : step forward line by line. Step forward by X num of lines
 * - shorthand: s
 * clear <line number> : delete the breakpoint on X line
 * clear <func name>   : clear breakpoint in func
 * 
 * backtrace           : view the stack trace
 * - shorthand: bt 
 * 
 * 
 * Core Files
 * a core dump is generated when a program crashes or terminates abnormally due to seg fault. 
 * -- seg faults is a "you're accessing memory that doesnt belong to you" error
 * also know as: Memory Dump, Storage Dump, or just Dump
 * results in the creation of a file that contains a snapshot of the contents of the process's memory at the time it terminated
 * -- usually named `core.<process_id>` or `<exe name>.stackdump`. Some systems disable this creation
 * --- on linux you can try using `ulimit -c unlimited` to make sure the dumps are created. These files can be huge
 * 
 * 
 * Profiling
 * gprof
 * a bit outdated. Doesnt support libs or multithreading
 * - the GNU profiler uses a hybrid aproach of compiler assisted information and sampling
 * - not exact but offers a statisctical approximation
 * compile and run the app with: `gcc -pg ...` then run it. It will produce a `gmon.out` file
 * run gprof: gprof <exe name> <gmon.out> > analysis.txt
 * 
 * valgrind
 * Very good for detecting memory leaks but is very slow
 * `sudo apt install valgrind`
 * to run:
 * valgrind <opts> ./<exe>
 * --leak-check=yes
 * 
 * 
*/