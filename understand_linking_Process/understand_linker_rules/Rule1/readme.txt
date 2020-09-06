
Here after we try to link the f1.o and f2.o the linker gives error as :
multiple defination of main . This is because the multiple strong symbols aren't allowed.

linking command : gcc *.o -o myexe , where myexe is the final executable file name
