#-------------------------------------------------------------------------------
# Author: Nathanael J Y
# Last Modified: 20/04/2021
# Written for: The Open University Of Israel
# Course: 20465 - C Programming Workshop
# Assignment: Maman 22 Question 1
#-------------------------------------------------------------------------------


objects = memory_management.o \
		  error_management.o \
		  bitmap_128.o \
		  char_utils.o \
		  string_utils.o \
		  test.o 

debugFlags = -g -ansi -Wall -pedantic

All: $(objects)
	gcc $(debugFlags) $(objects) -o test
$(objects):


run: All
	./test

clean:
	rm $(objects)


