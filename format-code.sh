#!/bin/bash

#Check if astyle is installed
command -v astyle >/dev/null 2>&1 || { printf >&2 "This script needs astyle to be installed.\nSee http://astyle.sourceforge.net/ for more informations.\n";exit 1; }


#format all .cc files
printf "\nFormatting all *.cc files...\n\n"
astyle -r "src/*.cc" -t -v


#format all header files
printf "\n\nFormatting all header files...\n\n"
astyle -r "src/*.h" -t -v

#delete all *.orig files created by astyle
printf "\n\nDeleting all temporary file...\n"
find src/ -name '*.orig' -delete
printf "Done.\n"