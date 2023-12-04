# ExpressionParser

Debugging between Bison 2.3 (default on my machine) and Bison 3.8.2 (path specified BISON = /usr/local/Cellar/bison/3.8.2/bin/bison)

Trying to switch from Makefile (with some hacked manually inserted function signature), to CMake build with newer version (will use %code {} directive available at least as early as Bison 3.7.15 ref: https://www.gnu.org/software/bison/manual/html_node/_0025code-Summary.html )

Should be able to build using ExpressionParser/Makefile (trying to shift away from this)
$ make
$ ./simple-c
[should output a lot of print statements finishing with some sort of parse tree in the following format:
parser prettyprint:
PDF:
    POW:
        ALIAS: (alias x maps to Variable 'sim/Ux')
        NUM:
    ALIAS: (alias y maps to Variable 'sim/Uy')
PDF:
    POW:
        ALIAS: (alias x maps to Variable 'sim/Ux')
        NUM:
    ALIAS: (alias y maps to Variable 'sim/Uy')
]

Building with CMake (not working yet)
$ mkdir build
$ cd build
$ cmake ../
$ make
