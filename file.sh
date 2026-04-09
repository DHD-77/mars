#!/bin/bash
mkdir rover_mission
cd rover_mission
touch log1.txt log2.txt log3.txt
mv log1.txt mission_log.txt
cat <<EOF > mission_log.txt
There is no ERROR
everything good
ERROR not found
okay okay
ERROR gg
EOF
ls *.log
cat mission_log.txt
grep ERROR mission_log.txt
wc -l mission_log.txt
date
top
sudo shutdown +10
