#!/bin/bash
set -e
# Make sure that you have set Q_DOCROOT
Q_DOCROOT=$PWD/_QDIR
rm -r -f $Q_DOCROOT
mkdir    $Q_DOCROOT
q init $Q_DOCROOT ""
# Load some data into T3
q dld T3 meta3.csv in3.csv ''
q fop T3 ifld sortA
q pr_fld T3 ifld
echo "--------------------------------"
# To print the 5th value of nfld (note that indexing starts frm 0)
q get_val T3 nfld 0
echo "--------------------------------"
q fop T3 ffld sortA
q pr_fld T3 ffld
echo "--------------------------------"
# Following will fail because sort cannot be applied if field has null values. 
set +e
q fop T3 nfld sortA
set -e
# If you change null values to some defined value, then you can sort
q wisifxthenyelsez T3 w .nn.nfld nfld 999
q rename T3 w nfld
q drop_nn_fld T3 nfld
q fop T3 nfld sortA
q pr_fld T3 nfld 
echo "--------------------------------"

# Note that sort modifies field in place. If you want both original 
# and sorted fields, you can do
q dup_fld T3 ffld xfld
q fop T3 ffld sortD
q pr_fld T3 ffld:xfld

echo "--------------------------------"
