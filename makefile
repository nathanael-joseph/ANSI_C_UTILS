#-------------------------------------------------------------------------------
# Author: Nathanael J Y
# Last Modified: 20/04/2021
# Written for: The Open University Of Israel
# Course: 20465 - C Programming Workshop
# Assignment: Maman 22 Question 1
#-------------------------------------------------------------------------------


objects = system_utils/memory_management.o \
		  datastructures/bitmap.o \
		  datastructures/nodes.o \
		  type_utils/char_utils.o \
		  type_utils/string_utils.o \
		  test.o 

debugFlags = -g -ansi -Wall -pedantic -I ./

All: $(objects)
	gcc $(debugFlags) $(objects) -o test
	find . -name '*.o' -type f -delete

%.o: %.c %.h
	gcc -c $(debugFlags) $< -o $@


run: All
	./test

clean:
	find . -name '*.o' -type f -delete


