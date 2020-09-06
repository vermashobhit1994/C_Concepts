Here after linking both files we get x value as garbage, which is bug.
command used : gcc *.o -o myexe -> myexe is final executable file
To solve this issue:
1. Try to avoid the use of global symbol.
2. If not avoid then use static with global symbol thus make it local to paricular file.
3. If not use static initialize it with some value to make it strong symbol.
