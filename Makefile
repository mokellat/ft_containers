COMPILE = clang++
FLAGS = -std=c++98 -Wall -Wextra -Werror

VVector:
	$(COMPILE) $(FLAGS) main-vector.cpp -o vec

SStack:
	$(COMPILE) $(FLAGS) main-stack.cpp -o st

MMap:
	$(COMPILE) $(FLAGS) main-map.cpp -o maap