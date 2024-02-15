#!/usr/bin/python3
"""A Log Parser Script"""

import signal
import sys

# Global variables
loop_counter = 0
stats = {}
file_size_counter = 0


# The function to print stats
def printer():
    print(f"File size: {file_size_counter}")
    for k, v in dict(sorted(stats.items())).items():
        print(f"{k}: {v}")


# Ctrl-C signal handler
def ctrlc_handler(signal, frame):
    printer()


# Ctrl-C signal listener
signal.signal(signal.SIGINT, ctrlc_handler)

# The main loop
for line in sys.stdin:
    loop_counter += 1

    line_list = line.split()
    status_code = int(line_list[7])
    file_size = int(line_list[8])

    if status_code in stats:
        stats[status_code] += 1
    else:
        stats[status_code] = 1

    file_size_counter += file_size

    if loop_counter % 10 == 0:
        printer()
