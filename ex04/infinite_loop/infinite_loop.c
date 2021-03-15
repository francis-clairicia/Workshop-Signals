/*
** EPITECH PROJECT, 2021
** Workshop_Signals
** File description:
** infinite_loop
*/

#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

int main(void)
{
    printf("Je suis une boucle infinie mangeur de carte graphique.\n");
    printf("Le seul moyen de m'arrêter est de me tuer à l'aide d'un signal.\n");
    printf("Voici mon PID: %d\n", getpid());
    while (1);
    return 0;
}