#! /bin/sh
#----------------------------------------------------------------------
# runalltests.sh
# Author: Horst Possegger
# Runs all test cases delivered with the framework

out_file="temporary_out"

passed_all=0
echo
echo

############################## PAD0 ###################################
./rno_a2 pad0 > $out_file
if [ $? = 0 ]
then
  echo "Test PAD0       passed"
else
  echo "Test PAD0       not passed"
  passed_all=-1
fi

./rno_a2 pad1 > $out_file
if [ $? = 0 ]
then
  echo "Test PAD1       passed"
else
  echo "Test PAD1       not passed"
  passed_all=-1
fi

./rno_a2 pad2 > $out_file
if [ $? = 0 ]
then
  echo "Test PAD2       passed"
else
  echo "Test PAD2       not passed"
  passed_all=-1
fi

./rno_a2 txt > $out_file
if [ $? = 0 ]
then
  echo "Test TXT        passed"
else
  echo "Test TXT        not passed"
  passed_all=-1
fi

./rno_a2 binary > $out_file
if [ $? = 0 ]
then
  echo "Test BINARY     passed"
else
  echo "Test BINARY     not passed"
  passed_all=-1
fi

############################## CONCLUSION ##############################
echo 
if [ $passed_all != 0 ]
then
  echo "ERROR: Not all tests passed"
  exit_value=126
else
  echo "ALL TESTS PASSED!"
  exit_value=0
fi
unlink $out_file
echo
exit $exit_value
