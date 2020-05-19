#!/bin/bash

cmake . -DNEED_TEST=true
make
mv Attempt.o pascal/Attempt.o
mv Tester_c.o pascal/Tester_c.o
mv libtester.so pascal/libtester.so
./bin/run_test