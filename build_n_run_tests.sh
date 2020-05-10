#!/bin/bash

cmake . -DNEED_TEST=true
make
./bin/run_test