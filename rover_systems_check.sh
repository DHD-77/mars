#!/bin/bash

# rover_system_check.sh
# Performs pre-mission diagnostics for the rover.

# 1. Generate a random battery percentage (0-100)
BATTERY=$(( RANDOM % 101 ))

echo "--- Rover System Check ---"
echo "Current Battery: $BATTERY%"

# Check battery threshold
if [ "$BATTERY" -lt 20 ]; then
    echo "ERROR: Battery low! Return to base!"
    exit 1
fi

# 2. Ping google.com to check network connectivity
# -c 1: sends only 1 packet
# > /dev/null 2>&1: hides the ping output from the terminal
echo "Checking communication links..."

if ping -c 1 google.com > /dev/null 2>&1; then
    # 3. If both pass
    echo "SUCCESS: All systems operational!"
    exit 0
else
    # If ping fails
    echo "ERROR: Communication failure!"
    exit 1
fi
