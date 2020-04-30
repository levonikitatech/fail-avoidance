#!/bin/sh
g++ -c Tester.cc -o Tester_cc.o
gcc -x c -c Tester.h Tester_c.o
gcc -shared -o libtester.so Tester_c.o Tester_cc.o