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
    for k, v in sorted(stats.items()):
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

    try:
        status_code = int(line_list[-2])
        if status_code in stats:
            stats[status_code] += 1
        else:
            stats[status_code] = 1
    except (e):
        pass

    try:
        file_size = int(line_list[-1])
        file_size_counter += file_size
    except (e):
        pass

    if loop_counter % 10 == 0 or line == "":
        printer()

if loop_counter == 0 or loop_counter % 10 != 0:
    printer()
