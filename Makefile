#OBJS specifies which files to compile as part of the project
OBJS = SDL3.cpp

#CC specifies which compiler we're using:
CC = g++

#COMPILER_FLAGS specifies the additional options we're using:
COMPILER_FLAGS = -w

#LINKER_FLAGS specifies the libraries we're linking against:
LINKER_FLAGS = -lSDL2

#OBJ_NAME specifies the name of our exectuable:
OBJ_NAME = SDL3

#This is the target that compiles our executable:
all : $(OBJS)
	$(CC) $(OBJS) -ISDL $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME) 
