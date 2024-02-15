#!/usr/bin/python3

""" script qui lit l'entrée standard ligne par ligne et calcule des métriques """
# Ceci est une docstring qui décrit ce que fait le script

import sys

# Importation du module sys pour accéder à l'entrée standard


def printsts(dic, size):
    """ Affiche les informations """
    # Ceci est une fonction qui affiche les informations

    print("Taille du fichier: {:d}".format(size))
    # Affiche la taille du fichier

    for i in sorted(dic.keys()):
        # Parcourt les clés du dictionnaire dans l'ordre

        if dic[i] != 0:
            # Si la valeur associée à la clé n'est pas 0

            print("{}: {:d}".format(i, dic[i]))
            # Affiche la clé et la valeur


sts = {
    "200": 0, "301": 0, "400": 0, "401": 0, "403": 0,
    "404": 0, "405": 0, "500": 0
}
# Initialisation du dictionnaire avec les codes de statut HTTP comme clés

count = 0
# Initialisation du compteur

size = 0
# Initialisation de la taille

try:
    # Début du bloc try

    for line in sys.stdin:
        # Parcourt chaque ligne de l'entrée standard

        if count != 0 and count % 10 == 0:
            # Si le compteur n'est pas 0 et est un multiple de 10

            printsts(sts, size)
            # Appelle la fonction printsts

        stlist = line.split()
        # Divise la ligne en une liste de mots

        count += 1
        # Incrémente le compteur

        try:
            # Début du bloc try interne

            size += int(stlist[-1])
            # Ajoute le dernier mot de la liste à la taille (après conversion en entier)

        except:
            # Si une exception est levée

            pass
            # Ignore l'exception

        try:
            # Début d'un autre bloc try interne

            if stlist[-2] in sts:
                # Si l'avant-dernier mot de la liste est une clé du dictionnaire

                sts[stlist[-2]] += 1
                # Incrémente la valeur associée à cette clé dans le dictionnaire

        except:
            # Si une exception est levée

            pass
            # Ignore l'exception

    printsts(sts, size)
    # Appelle la fonction printsts

except KeyboardInterrupt:
    # Si une exception KeyboardInterrupt est levée (lorsque l'utilisateur appuie sur Ctrl+C)

    printsts(sts, size)
    # Appelle la fonction printsts

    raise
    # Relève l'exception pour terminer le script

# #!/usr/bin/python3

# """ script qui lit l'entrée standard ligne par ligne et calcule des métriques """
# # Ceci est une docstring qui décrit ce que fait le script

# import signal
# import sys

# # Importation du module sys pour accéder à l'entrée standard


# # Global variables
# loop_counter = 0
# stats = {}
# file_size_counter = 0

# def printer():
#     """ Affiche les informations nécessaires """
#     # Ceci est une fonction qui affiche les informations
    
#     print(f"File size: {file_size_counter}")
#     for k, v in dict(sorted(stats.items())).items():
#         print(f"{k}: {v}")


# def ctrlc_handler(signal, frame):
#     """ Handler function that detects the signal"""
#     # Ctrl-C signal handler that handles Ctrl
#     printer()


# # Ctrl-C signal listener
# signal.signal(signal.SIGINT, ctrlc_handler)

# # The main loop
# for line in sys.stdin:
#     loop_counter += 1

#     line_list = line.split()
#     status_code = int(line_list[7])
#     file_size = int(line_list[8])

#     if status_code in stats:
#         stats[status_code] += 1
#     else:
#         stats[status_code] = 1

#     file_size_counter += file_size

#     if loop_counter % 10 == 0:
#         printer()
