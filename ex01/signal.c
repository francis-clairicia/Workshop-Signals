/*
** EPITECH PROJECT, 2021
** Workshop_Signals
** File description:
** signal
*/

#include <sys/types.h>
#include <stdbool.h>
#include <stdio.h>
#include <signal.h>

/*
Les globales c'est affreux mais c'est le seul moyen de communiquer
avec une fonction chargée de gérer un signal

A toi de comprendre pourquoi
*/
static bool GLOBAL_LOOP = false;

/*
Exercice 1:

Complete ce programme pour que le programme quitte normalement
lors d'un CTRL+C.

Fonction à utiliser : signal(2)
*/

/* Tu as une fonction à créer ici. */
void sigint_handler(int signum)
{
    GLOBAL_LOOP = false;
}

int main(void)
{
    /* Utilisation de signal */
    signal(SIGINT, &sigint_handler);

    GLOBAL_LOOP = true;
    while (GLOBAL_LOOP == true) {
        continue;
    }
    printf("Je vais m'arrêter correctement.\n");
    return 0;
}