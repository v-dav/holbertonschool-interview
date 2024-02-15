#!/usr/bin/python3

""" A script that reads stdin and formats data """

import signal
import sys


loop_counter = 0
stats = {}
file_size_counter = 0


def printer():
    """ Affiche les informations nécessaires """

    print("File size: {}".format(file_size_counter))
    for k, v in dict(sorted(stats.items())).items():
        print("{}: {}".format(k, v))


# The Ctrl-C handler
def ctrlc_handler(signal, frame):
    """ Handler function that detects the signal"""
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
    if loop_counter % 10 == 0 or line == "":
        printer()

if loop_counter % 10 != 0:
    printer()
