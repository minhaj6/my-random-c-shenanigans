# python code in c repository 
# because python is an abstraction of c code :p

import atexit
import sys

def exit_func():
    print("Exiting. Thank you!")

atexit.register(exit_func)

if (len(sys.argv) != 2):
    print(f"Usage: {sys.argv[0]} <number>")
    sys.exit(1)

value = int(sys.argv[1])
squared = value**2

print(f"{value}^2 == {squared}")