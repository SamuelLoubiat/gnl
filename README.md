*This project has been created as part of the 42 curriculum by sloubiat*

# get_next_line

# Description

The get_next_line project aims to implement a function that reads a file or standard input line by line. The goal is to return one line at a time, including the newline character if present, until the end of the file is reached.

This project involves parsing a format string and handling different format specifiers to print various types of data, such as characters, strings, and integers. It helps improve understanding of C programming concepts, including variadic functions and output formatting.

# Resources
References and Tools

The C Standard Library documentation and the man pages for read, malloc, and free were used to understand file I/O and memory management. The Francinette tester was used to validate that the function correctly reads files line by line.

Artificial Intelligence was only used to help write and improve the README documentation. AI was not used to generate or implement the project code.

# instructions

To compile your program using get_next_line, simply compile the source file(s) together with your main program. For example:
> `cc -Wall -Wextra -Werror main.c get_next_line.c get_next_line_utils.c -o my_program`
You can also set a custom buffer size at compilation by defining BUFFER_SIZE with the -D flag. For example, to use a buffer size of 100:
> `cc -Wall -Wextra -Werror -D BUFFER_SIZE=100 main.c get_next_line.c get_next_line_utils.c -o my_program`
Then run your program normally:
> `./my_program`



# Additional
## Algorithm and Data Structures

The get_next_line function works by reading a fixed-size buffer from the file descriptor repeatedly until a newline character is found. The read data is stored and combined with any leftover data from the previous call to form a complete line.

The main data structure used is a static buffer to store the rest of buffer. Dynamic memory is used to store each line before returning it.