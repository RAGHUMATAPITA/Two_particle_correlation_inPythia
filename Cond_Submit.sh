#!/bin/bash

rm -rf *.C~
rm -rf *.h~
rm -rf *.sh~
rm -rf *.txt~

#Run this--> sh Cond_Submit.sh step3b 4 0

#1st Arguments : wich step (step1, step2, step3a, step3b, step3c)
#2nd arguments : which file (1->Step_1.txt, 2->Step_2.txt, 3->Step_3a.txt, 4->Step_3b.txt, 5->Step_3c.txt)
#3rd arguments : is test run (1 or 0)

which_step=$2

file="Step_1.txt"

if [ $which_step == 1 ]; then
    file="Step_1.txt"
    #file="Step_1_7TeV_OneBaryon.txt"
    #file="Step_1_7TeV_OneBaryon_New.txt"
    echo ${file}
elif [ $which_step == 2 ]; then
    file="Step_2.txt"
    echo ${file}
elif [ $which_step == 3 ]; then
    file="Step_3b.txt"
    echo ${file}
elif [ $which_step == 4 ]; then
    file="Step_3b.txt"
    echo ${file}
elif [ $which_step == 5 ]; then
    file="Step_3c.txt"
    echo ${file}
else
    echo "There are not step included"
fi

istestrun=$3
testRun_condition=true

if [ $istestrun == 1 ]; then
    testRun_condition=true
else
    testRun_condition=false
fi

root -l -b -q "File_Write.C(${testRun_condition}, \"${file}\", \"$1\", \"/eos/user/r/rpradhan/Research/With_NirbhayBhai/Out_RootFile\", 4, \"workday\")"

condor_submit Submission_Files/$1/Submission_$1.sub
