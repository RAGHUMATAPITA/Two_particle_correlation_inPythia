#!/bin/bash

rm -rf *.C~
rm -rf *.h~
rm -rf *.sh~
rm -rf *.txt~

#root -l -b -q "Tree_Analyzer_Condor.C(\"test.txt\", 0, \"/eos/user/r/rpradhan/Research/With_NirbhayBhai/Out_RootFile\", \"Step_3b_test\")" # old mac
root -l -b -q "Tree_Analyzer_Condor.C(\"Step_1_7TeV_AlwaysBaryon_New_nmin1_nmax2.txt\", 0, \"/eos/user/r/rpradhan/Research/With_NirbhayBhai/Out_RootFile\", \"Step_1_7TeV_test_AlwaysBaryon_New_nmin1_nmax2\")" # old mac
