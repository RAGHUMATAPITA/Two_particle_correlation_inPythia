#!/bin/bash

cd /afs/cern.ch/work/r/rpradhan/With_NirbhayBhai/Pythia8_V1
echo "Submit skim jobs at "
echo PWD: $PWD

./Compiler_Files/Step1_7TeV_OneBaryon_New/compile_Step1_7TeV_OneBaryon_New.out "$1" "$2" "$3" "$4"

