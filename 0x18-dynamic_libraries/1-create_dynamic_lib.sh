#!/usr/bin/bash
gcc -Wall -c -fPIC && gcc *.o -shared liball.so
