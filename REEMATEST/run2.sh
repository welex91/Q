#!/bin/bash
set -e
# Make sure that you have set Q_DOCROOT
Q_DOCROOT=$PWD/_QDIR
rm -r -f $Q_DOCROOT
mkdir    $Q_DOCROOT
q init $Q_DOCROOT ""
q list_tbls
# Load some data into T2
q dld T2 meta2.csv in2.csv ''
# Current restriction is that regex_match can be applied only to 
# fields of type SC or SV and that field must NOT have null values
# create column x to match where sfld = abc
str=abc
q regex_match T2 sfld "$str" exact x
n=`q f_to_s T2 x sum | cut -f 1 -d ":"`
echo "Number of rows where sfld = [$str] = $n"
# Often strings are not strings but just labels. In such cases, one 
# creates a dictionary or what I call a lookup table.
# In meta2.csv, you will see the last line being 
# xxx,LKP,'is_dict_old=[false]:dict=[lkp_SV]'
# What this does is to create a brand new table called lkp_SV which has
# fields idx and txt
q pr_fld lkp_SV idx:txt
echo "---------------------------------------------"
# It also creates a field fk_lkp_SV in T1 (a foreign key)
q pr_fld T2 fk_lkp_SV
echo "---------------------------------------------"
# Note that fk_lkp_SV is actually an integer field but the pr_fld command
# has been told (during dld) that it is a fk to lkp_SV
q describe T2 fk_lkp_SV
echo ""
#- So what we do is to do the regex match on the lookup table, find the 
# corresponding idx and then match fk_lkp_SV with that
str=abc111
q regex_match lkp_SV txt "$str" exact x
n=`q f_to_s lkp_SV x sum | cut -f 1 -d ":"`
if [ $n != 1 ]; then echo "ERR: n=$n, must match exactly 1 string"; exit 1; fi
# Find id corresponding to string of interest
idx_lkp_SV=`q pr_fld lkp_SV idx 'cond=[x]'`
# Match fk_lkp_SV against that id
q f1s1opf2 T2 fk_lkp_SV $idx_lkp_SV '==' x 
n=`q f_to_s T2 x sum | cut -f 1 -d ":"`
echo "Number of rows in T2 where fld = [$str] = $n"
# And just to double check
q mk_idx T2 idx I4
q pr_fld T2 idx:fk_lkp_SV 'cond=[x]' # print only rows where x is true

echo "Successfully Completed $0 in $PWD"
