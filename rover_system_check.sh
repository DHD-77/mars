#!/bin/bash
battery=$(( RANDOM % 101 ))
if [ $battery -lt 20 ]; then
echo "Low battery! Return to base."
exit 1
fi
ping -c 1 google.com >/dev/null
if [ $? -ne 0 ]; then
echo "Connection failure"
exit 1
fi
echo "All systems operational"
