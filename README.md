This project is about C - Stacks, Queues - LIFO, FIFO - Created by Luis Baute and Germán Izquierdo


List of files

main.c: contains the main function. Checks for arguments and if found, exectues the opfile function

opfile_function.c: This function opens and reads the file and tokenize its contents. Then, it executes the function "function_check" to search for a match with a command. If a match (!= NULL) is found it exectues it's function

function_check.c: Uses a struct to check if the argumment recieved matchs with a command, then it returns that function (if found, if not returns null)

auxiliary_functions.c: Auxiliary functions for managing frees and error exits

stack_functions.c: Functions used for manipulating the stack

monty.h: project's library
