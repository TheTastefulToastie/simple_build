# Simple Build
_Tiny and dead-simple._
The aim of this tool is to tightly couple how code is compiled/built with the source code itself in a way that is both human and machine readable.
The first place one will look when checking out a new project is the program entry point, which makes this the perfect place to put build instructions.
This is especially nice in small code excerpts like example programs, GitHub gists and forum posts.

## Usage
Place a comment on the first line of the file with the format `@Compile <shell command>`.
Then invoke the binary with the path to your source file:
`sbuild my_file.c`

### Examples
**test.c**
It's now obvious to anyone reading the source code that this is C99, without the need for additional documentation.
```C
// @Compile gcc -std=c99 test.c -o test && ./test Dave
#include <stdio.h>

void open_pod_bay_doors(char *name) {
  printf("I'm sorry %s, I'm afraid I can't do that.\n", name);
}

int main(int argc, char **argv) {
  open_pod_bay_doors(argv[1]);
  return 0;
}
```

**test.py**
...and it's now clear that this is python3 and not python2.
```python
# @Compile python3 test.py Dave
import sys

def open_pod_bay_doors(name):
  print(f'I\'m sorry {name}, I\'m afraid I can\'t do that.')

if __name__ == '__main__':
  open_pod_bay_doors(sys.argv[1])
```

**test.js**
```javascript
// @Compile node test.js Dave

function open_pod_bay_doors(name) {
  console.log(`I'm sorry ${name}, I'm afraid I can't do that.`);
}

open_pod_bay_doors(process.argv[2]);
```

### A more complex example
This will watch the project directories for changes, recompile and execute the program when files are saved or new files are added.
```C
// @Compile while true; do ls -d include/*.h src/*.c | entr -scrd "gcc -Iinclude src/*.c -o main && ./main"; done
```
and of course to get this functionality all that is required is to run `sbuild src/main.c` in a terminal (providing [entr](http://eradman.com/entrproject/) is installed).

Alternatively if you want to edit the build intructions and see feedback in real-time you can execute the following in a terminal:
```bash
while true; do ls -d include/*.h src/*.c | entr -scrd "sbuild src/main.c"; done
```
and use the following @Compile in your main.c:
```C
// @Compile gcc -Iinclude src/*.c -o main && ./main
```
...which means you can quickly check your program in valgrind like so:
```C
// @Compile gcc -Iinclude src/*.c -o main && valgrind ./main
```
and just save the file.


If the entr while loop is too much to remember I don't blame you. So put it in a second @Compile.
sbuild will only execute the first line, but you can commit them all to source control together with the code.
Then select which once gets executed by moving it to the first line.
```C
// @Compile echo "This gets executed!"
// @Compile echo "This does not!"
// @Compile echo "Neither does this!"
```

## Build Instructions
Have you been paying attention? It's in the source file!
