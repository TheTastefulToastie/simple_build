# @Compile python3 test.py Dave
import sys

def open_pod_bay_doors(name):
  print(f'I\'m sorry {name}, I\'m afraid I can\'t do that.')
  
if __name__ == '__main__':
  open_pod_bay_doors(sys.argv[1])
