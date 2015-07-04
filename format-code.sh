#!/bin/bash

#Check if astyle is installed
command -v astyle >/dev/null 2>&1 || { printf >&2 "This script needs astyle to be installed.\nSee http://astyle.sourceforge.net/ for more information.\n";exit 1; }


#format all .cc files
printf "\nFormatting all *.cc files...\n\n"
astyle -r "src/*.cc" -t -v -A14
astyle -r "test/*.cc" -t -v -A14


#format all header files
printf "\n\nFormatting all header files...\n\n"
astyle -r "include/*.h" -t -v -A14

#delete all *.orig files created by astyle
printf "\n\nDeleting all temporary files...\n"
find src/ -name '*.orig' -delete
find test/ -name '*.orig' -delete
find include/ -name '*.orig' -delete
printf "Done.\n"
