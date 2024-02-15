#!/usr/bin/python3

""" script qui lit l'entrée standard ligne par ligne et calcule des métriques """
# Ceci est une docstring qui décrit ce que fait le script

import signal
import sys

# Importation du module sys pour accéder à l'entrée standard

# Global variables
loop_counter = 0
stats = {}
file_size_counter = 0

def printer():
    """ Affiche les informations nécessaires """
    # Ceci est une fonction qui affiche les informations
    
    print(f"File size: {file_size_counter}")
    for k, v in dict(sorted(stats.items())).items():
        print(f"{k}: {v}")


def ctrlc_handler(signal, frame):
    """ Handler function that detects the signal"""
    # Ctrl-C signal handler that handles Ctrl
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
