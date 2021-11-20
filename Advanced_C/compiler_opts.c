/**
 * GCC Compiler Options
 * 
 * Four stage process to produce a binary:
 * - preprocessing - handle preprocessing directives
 * - compilation   - creates assembly code that the assembler takes
 * - assembly      - takes the assembly code and creates the object file (.o)
 * - linking       - the linker takes the object file and assoicated libraries and links them into the binary
 * 
 * Options cannot be grouped since some options have multiple letter args. 
 * Order normally doesnt matter unless you use multiple options of the same kind
 * 
 * Compile Options:
 * -o <filename> : the name created by the binary
 * -c            : compile into an object file. Does not trigger linking.
 * -Wall         : enables all warnings 
 * -E            : will give the preprocessor code. Use with a redirect to another file. ex: gcc -E main.c > preMain.c
 * -S            : same as -E but gives assembly code
 * -save-temps <filename> : output all intermediery steps
 * -l <library>  : can do `-l m` to link the math library. Can also do `-lm`
 * -fPIC <filename> : to create a shared library then do...
 * ---shared -o <filename>.so : .so for shared objects 
 * -g            : create debugging information 
 * -v            : verbose
 * -ansi         : make things compliant with the older ansi standard
 * -funsigned-char : treat type as unsigned (if you wanted a char with a neg value. )
 * -fsigned-char : treat type as signed
 * -D <macro name> : defines a macro from the command line
 * -Werror       : treat all warnings as errors
 * @<filename>   : parse a file with arguments seperated by whitespace
 * 
 * Optimization Opts:
 * can make compiling slow and debugging difficult or impossible
 * -Q --help=optimizers : view all the available optimizers (thers a lot)
 * 
 * Group levels of optimization
 * -O  : the least flags turned on
 * -O1
 * -O2
 * -O3 : the most optimization flags turned on
 * -Ofast : disregard standards compliance. Enables all O3 opts as well as ones that are not valid for standard-compliant programs
 * -Og : optimize debugging experience
 * 
 * Other commands:
 * nm <object file>.o : list all the functions included in an object file
 * ldd <object file>.out : see all the external linked libraries included in an executibles 
 * 
*/