# Simple Build
_Tiny and dead-simple._
The aim of this tool is to tightly couple how code is compiled/built with the source code itself in a way that is both human and machine readable.
The first place one will look when checking out a new project is the program entry point, which make this the perfect place to put build instructions.
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

## Build Instructions
Have you been paying attention? It's in the source file!
