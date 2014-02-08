html_file=leetcode.html
wget http://oj.leetcode.com/problems/ -O $html_file
file_list=`grep 'href="/problem' $html_file |awk -F'/' '{
printf("%s.cc\n",$(NF-3))}' |sed 's/-/_/g'`
for file in $file_list
do
  echo $file
  if [[ ! -f $file ]]; then
    touch $file
  fi
done
