Name: 		    Navitha Kokkat
Student ID: 	101257023

## Assignment #3: Structs and Dynamic Memory

This program implements a database that stores data representing evidence of potential paranormal activity using structures and dynamic memory allocation. The program allows the user to enter and remove data from the existing database of sample data, as well as view all the evidence in a sorted and organized format. 

## List of Files

- defs.h:       Header file containing forward declarations of functions, type definitions, and constant definitions
- main.c: 	    Contains the source code for entry point of the program where user can interact with the database
- init.c:       Contains the source code for initializing structures and loading sample data
- evidence.c:   Contains the source code for the overall functionality of the structures
- README.md:	Contains this description

## Compiling and Running Instructions

1. In a terminal, move to the directory of the folder containing the files listed above.
2. Once in that folder, use the command `gcc -Wall -Wextra -o a3 main.c init.c evidence.c` to create an executable file named a3.
3. To run the program, use the command `./a3` while in the folder containing the executable file. 
4. To run the program with valgrind, use the command `valgrind ./a3` while in the folder containing the executable file. 

## Usage Instructions

1. When prompted by the menu, type in one of the numbers 1, 2, 3 or 0. Number 1 is to add evidence, 2 is to delete evidence, 3 is to print 
    evidence, and 0 is to exit. If 1, 2, or 3 are entered, after the task is done, the program will redirect to the menu again. If 0 is entered, the program will terminate.
2. If 1 was typed: when prompted for each of the following, enter the correct input: evidence ID (integer, 4 digits long), room name 
    (string), device code for the corresponding device (integer from 1 to 3 inclusive), the evidence value (float), and the timestamp (3 integers, separated by a space, representing numbers of hours, minutes, and seconds). If the device code is not valid, an error message will be printed and there will be a prompt to enter a valid device code again.
3. If 2 was typed: when prompted, enter the ID of the evidence to remove. If deleted successfully, a message will indicate so. If that ID 
    does not exist in the database, an error message will be printed. 
4. If 3 was typed: this prints the evidence, no user input is needed.
