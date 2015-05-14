#!/bin/bash
set -e
# Make sure that you have set Q_DOCROOT
Q_DOCROOT=$PWD/_QDIR
rm -r -f $Q_DOCROOT
mkdir    $Q_DOCROOT
q init $Q_DOCROOT ""
q list_tbls
# Load some data into T1
q dld T1 meta.csv in.csv ''
# Note that some values are null
q pr_fld T1 ifld:sfld:ffld:dfld
echo "---------------------------"
# Check whether field "ifld" has a null value or not 
q is_nn_fld T1 ifld 
echo ""
# Check whether field "dfld" has a null value or not 
q is_nn_fld T1 dfld 
echo ""
echo "---------------------------"
# Say we want to find number of rows where both ifld and ffld have non-null
# Q has a "hidden" field for this purpose, which can be treated as a regular field
q f1f2opf3 T1 .nn.ifld .nn.ffld '&&' x
n=`q f_to_s T1 x sum`
echo "Number of rows where ifld and ffld are non-null is $n"

echo "Successfully Completed $0 in $PWD"
