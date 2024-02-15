#!/usr/bin/python3

""" A script that reads stdin and formats data """

import signal
import sys

def printer(counter, dict_data):
    """ Affiche les informations nécessaires """

    print("File size: {}".format(counter))
    for k, v in dict(sorted(dict_data.items())).items():
        print("{}: {}".format(k, v))


def ctrlc_handler(signal, frame):
    """ Handler function that detects the signal"""
    printer(file_size_counter, stats)


# Ctrl-C signal listener
signal.signal(signal.SIGINT, ctrlc_handler)

# The main loop
def main():
    global loop_counter
    loop_counter = 0
    global stats
    stats = {}
    global file_size_counter
    file_size_counter = 0
    
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
            printer(file_size_counter, stats)

main()
