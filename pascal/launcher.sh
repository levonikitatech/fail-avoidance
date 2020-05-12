#!/bin/bash

echo . >> tester.lpr 
'/usr/bin/fpc'  -MObjFPC -Scghi -Cg -O1 -g -gl -l -vewnhibq -Filib/x86_64-linux -Fu/usr/lib/lazarus/lcl/units/x86_64-linux/qt5 -Fu/usr/lib/lazarus/lcl/units/x86_64-linux -Fu/usr/lib/lazarus/components/lazutils/lib/x86_64-linux -Fu/usr/lib/lazarus/packager/units/x86_64-linux -Fu. -FUlib/x86_64-linux -FE. -otester -dLCL -dLCLqt5 tester.lpr
if [ "$1" == "test" ]; then
    ./tester
fi