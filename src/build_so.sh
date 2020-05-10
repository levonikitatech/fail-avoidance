#!/bin/sh
#g++ -fPIC -c Answer.hpp -o Answer.o
g++ -fPIC -c Attempt.cpp -o Attempt.o
#g++ -fPIC -c Person.hpp -o Person.o
#g++ -fPIC -c Question.hpp -o Question.o
#g++ -fPIC -c Questions.hpp -o Questions.o
#g++ -fPIC -c Storage.hpp -o Storage.o
#wg++ -fPIC -c Tester.cpp -o Tester_cpp.o

#g++ -fPIC -c Tester.cc -o Tester_cc.o
gcc -fPIC -x c -c Tester.h -o Tester_c.o
mv Tester_c.o ../Tester_c.o
mv Attempt.o ../Attempt.o