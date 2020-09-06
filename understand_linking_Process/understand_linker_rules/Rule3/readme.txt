 To understand what happens when multiple weak symbols are used with same name in different files.
gcc -c *.c -> Compile the code
gcc *.o -o myexe -> create an executable of name myexe using all .o files.
here the printing of value local to that file only.

