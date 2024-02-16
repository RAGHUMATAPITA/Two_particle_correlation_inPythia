#!/bin/bash

cd /afs/cern.ch/work/r/rpradhan/With_NirbhayBhai/Pythia8_V1
echo "Submit skim jobs at "
echo PWD: $PWD

./Compiler_Files/Step3b/compile_Step3b.out "$1" "$2" "$3" "$4"

