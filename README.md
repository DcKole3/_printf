> # 0x11. C - printf
## Requirements
<em>General</em>
<ul>
<li>Allowed editors: vi, vim, emacs</li>
<li>All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89</li>
<li>All your files should end with a new line</li>
<li>A README.md file, at the root of the folder of the project is mandatory</li>
<li>Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl</li>
<li>You are not allowed to use global variables</li>
<li>No more than 5 functions per file</li>
<li>In the following examples, the main.c files are shown as examples. You can use them to test your functions, but you don’t have to push them to your repo (if you do we won’t take them into account). We will use our own main.c files at compilation. Our main.c files might be different from the one shown in the examples</li>
<li>The prototypes of all your functions should be included in your header file called main.h</li>
<li>Don’t forget to push your header file</li>
<li>All your header files should be include guarded</li>
<li>Note that we will not provide the _putchar function for this project</li>
</ul>

## Task
Write a function that produces output according to a format.

Prototype: int _printf(const char *format, ...);
Returns: the number of characters printed (excluding the null byte used to end output to strings)
write output to stdout, the standard output stream
format is a character string. The format string is composed of zero or more directives. See man 3 printf for more detail. You need to handle the following conversion specifiers:
<ul>
<li>c</li>
<li>s</li>
<li>%</li>
<li>d</li>
<li>i</li>
<li>You don’t have to reproduce the buffer handling of the C library printf function</li>
<li>You don’t have to handle the flag characters</li>
<li>You don’t have to handle field width</li>
<li>You don’t have to handle precision</li>
<li>You don’t have to handle the length modifiers</li>
</ul>

### Contributors
<ul>
<li>Seyi Alagbe</li>
<li>Kolawole Taiwo</li>
</ul>