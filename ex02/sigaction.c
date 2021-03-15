/*
** EPITECH PROJECT, 2021
** Workshop_Signals
** File description:
** sigaction
*/

/* Ce truc c'est pour que VS Code ne vous embête pas :) */
#ifndef _GNU_SOURCE
#define _GNU_SOURCE 1
#endif

#include <sys/types.h>
#include <stdbool.h>
#include <stdio.h>
#include <signal.h>

static bool GLOBAL_LOOP = false;

/*
Exercice 2:

Dans la même optique que l'exercice, fais la même chose mais avec sigaction.

Fonction à utiliser : sigaction(2)
*/

/* Normalement c'est exactement la même fonction que l'exercice 1. */
void sigint_handler(int signum)
{
    GLOBAL_LOOP = false;
}

int main(void)
{
    struct sigaction action;

    action.sa_flags = 0;          // Pas de flags en particulier
    sigemptyset(&action.sa_mask); // Pas de masque à appliquer aux signaux

    action.sa_handler = sigint_handler;

    /* Utilisation de sigaction */
    sigaction(SIGINT, &action, NULL);

    GLOBAL_LOOP = true;
    while (GLOBAL_LOOP == true) {
        continue;
    }
    printf("Je vais m'arrêter correctement.\n");
    return 0;
}