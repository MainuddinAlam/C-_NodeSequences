#my_tests.sh
#Mainuddin Alam Irteja (A00446752) u11
#Testing script for Submission 5.

#So that the find_tabs and find_long_lines are available in this script
shopt -s expand_aliases
source /home/course_ps/u00/public/bashrc2341

clear
echo First run with no command-line input ...
read -p "(Pause from testing script) Press Enter to continue ... "
./node_sequence
read -p "(Pause from testing script) Press Enter to continue ... "

clear
echo Next we perform seven tests where the values will be 
echo added to the end.
read -p "(Pause from testing script) Press Enter to continue ... "

clear
echo First test adds values from 1 to 10 to the end,
echo then removes 1 if 1 is in the sequence, and inserts 17 after 4
echo if 4 is in the sequence.
echo ./node_sequence 1 10 e 1 17 4
./node_sequence 1 10 e 1 17 4
read -p "(Pause from testing script) Press Enter to continue ... "

clear
echo Second test adds values from 1 to 10 to the end,
echo then removes 7 if 7 is in the sequence, and inserts 17 after 4
echo if 4 is in the sequence.
echo ./node_sequence 1 10 e 7 17 4
./node_sequence 1 10 e 7 17 4
read -p "(Pause from testing script) Press Enter to continue ... "

clear
echo Third test adds values from 1 to 10 to the end,
echo then removes 10 if 10 is in the sequence, and inserts 17 after 4
echo if 4 is in the sequence.
echo ./node_sequence 1 10 e 10 17 4
./node_sequence 1 10 e 10 17 4
read -p "(Pause from testing script) Press Enter to continue ... "

clear
echo Fourth test add values from 1 to 10 to the end,
echo then removes 7 if 7 is in the sequence, and inserts 17 after 10
echo if 10 is in the sequence.
echo ./node_sequence 1 10 e 7 17 10
./node_sequence 1 10 e 7 17 10
read -p "(Pause from testing script) Press Enter to continue ... "

clear
echo Fifth test adds values from 1 to 10 to the end,
echo then removes 25 if 25 is in the sequence, and inserts 30 after 17
echo if 17 is in the sequence.
echo ./node_sequence 1 10 e 25 30 17
./node_sequence 1 10 e 25 30 17
read -p "(Pause from testing script) Press Enter to continue ... "

clear
echo Sixth test adds values from 24 to 36 to the end,
echo then removes 24 if 24 is in the sequence, and inserts 17 after 36
echo if 36 is in the sequence.
echo ./node_sequence 24 36 e 24 17 36
./node_sequence 24 36 e 24 17 36
read -p "(Pause from testing script) Press Enter to continue ... "

clear
echo Seventh test adds values from 60 to 72 to the end,
echo then removes 64 if 64 is in the sequence, and inserts 17 after 64
echo if 64 is in the sequence.
echo ./node_sequence 60 72 e 64 17 64
./node_sequence 60 72 e 64 17 64
read -p "(Pause from testing script) Press Enter to continue ... "

clear
echo Next we perform seven tests where the values will be
echo added to the beginning.
read -p "(Pause from testing script) Press Enter to continue ... "

clear
echo First test adds values from 1 to 10 to the beginning,
echo then removes 1 if 1 is in the sequence, and inserts 17 after 4
echo if 4 is in the sequence.
echo ./node_sequence 1 10 b 1 17 4
./node_sequence 1 10 b 1 17 4
read -p "(Pause from testing script) Press Enter to continue ... "

clear
echo Second test adds values from 1 to 10 to the beginning,
echo then removes 7 if 7 is in the sequence, and inserts 17 after 4
echo if 4 is in the sequence.
echo ./node_sequence 1 10 b 7 17 4
./node_sequence 1 10 b 7 17 4
read -p "(Pause from testing script) Press Enter to continue ... "

clear
echo Third test adds values from 1 to 10 to the beginning,
echo then removes 10 if 10 is in the sequence, and inserts 17 after 4
echo if 4 is in the sequence.
echo ./node_sequence 1 10 b 10 17 4
./node_sequence 1 10 b 10 17 4
read -p "(Pause from testing script) Press Enter to continue ... "

clear
echo Fourth test add values from 1 to 10 to the beginning,
echo then removes 7 if 7 is in the sequence, and inserts 17 after 10
echo if 10 is in the sequence.
echo ./node_sequence 1 10 b 7 17 10
./node_sequence 1 10 b 7 17 10
read -p "(Pause from testing script) Press Enter to continue ... "

clear
echo Fifth test adds values from 1 to 10 to the beginning,
echo then removes 25 if 25 is in the sequence, and inserts 30 after 17
echo if 17 is in the sequence.
echo ./node_sequence 1 10 b 25 30 17
./node_sequence 1 10 b 25 30 17
read -p "(Pause from testing script) Press Enter to continue ... "

clear
echo Sixth test adds values from 24 to 36 to the beginning,
echo then removes 24 if 24 is in the sequence, and inserts 17 after 36
echo if 36 is in the sequence.
echo ./node_sequence 24 36 b 24 17 36
./node_sequence 24 36 b 24 17 36
read -p "(Pause from testing script) Press Enter to continue ... "

clear
echo Seventh test adds values from 60 to 72 to the beginning,
echo then removes 64 if 64 is in the sequence, and inserts 17 after 64
echo if 64 is in the sequence.
echo ./node_sequence 60 72 b 64 17 64
./node_sequence 60 72 b 64 17 64
read -p "(Pause from testing script) Press Enter to continue ... "

clear
echo Check node_sequence.cpp for any TAB and long-line problems ...
read -p "(Pause from testing script) Press Enter to continue ... "
find_tabs node_sequence.cpp
find_long_lines node_sequence.cpp
read -p "(Pause from testing script) Press Enter to continue ... "

