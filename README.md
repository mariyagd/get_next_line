# get_next_line!

```get_next_line()``` function let you read the text file pointed to by the file descriptor, one line at a time.

```get_next_line_bonus()``` function can manage multiple file descriptors at the same time without losing the reading thread of each
file descriptor or returning a line from another fd.

```get_next_line_utils.c``` and ```get_next_line_utils_bonus.c``` files contain all the helper functions.


These functions return the line that was read.
If there is nothing else to read or if an error occurred, they return NULL.

• Please note that the returned line include the terminating \n character, except if the end of file was reached and does not end with a \n character.


Prototype:
```
char *get_next_line(int fd);
```
Compiling code (example with 1):

```
cc -Wall -Wextra -Werror -D BUFFER_SIZE=1 <files>.c
```


• We consider that ```get_next_line()``` has an undefined behavior if the file pointed to by the file descriptor changed since the last call whereas ```read()``` didn’t reach the end of file.

• We also consider that ```get_next_line()``` has an undefined behavior when reading a binary file.


![tested-by-francinette](https://user-images.githubusercontent.com/109855801/203061253-176c5c43-450b-48a7-868b-9a46ecb24df1.svg)

