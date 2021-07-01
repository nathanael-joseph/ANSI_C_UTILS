#-------------------------------------------------------------------------------
# Author: Nathanael J Y
# Last Modified: 20/04/2021
# Written for: The Open University Of Israel
# Course: 20465 - C Programming Workshop
# Assignment: Maman 22 Question 1
#-------------------------------------------------------------------------------


ansi_c_utils_obj := ANSI_C_UTILS/system_utils/memory_management.o \
		  ANSI_C_UTILS/datastructures/bitmap.o \
		  ANSI_C_UTILS/datastructures/singlelinkedlist.o \
		  ANSI_C_UTILS/datastructures/dictionary.o \
		  ANSI_C_UTILS/type_utils/char_utils.o \
		  ANSI_C_UTILS/type_utils/string_utils.o 

ansi_c_utils_inlcudePath := -I ./ANSI_C_UTILS/


